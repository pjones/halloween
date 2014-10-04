// #############################################################################
class Monster {
public:
    Monster (byte pin, unsigned long delay);
    unsigned long check (unsigned long elapsed);

private:
    byte m_pin;
    bool m_is_on;
    unsigned long m_delay;
};

// #############################################################################
unsigned long last_check_time = 0;
Monster monsters[] = {{3, 500}, {5, 1000}, {6, 2500}, {9, 4000}};

// #############################################################################
static const unsigned int num_monsters = sizeof(monsters) / sizeof(Monster);

// #############################################################################
void setup (void)
{
    randomSeed(analogRead(0));

#  ifdef DEBUG
    Serial.begin(9600);
    Serial.println(num_monsters);
    Serial.println("pin\tdelay\tis_on");
    Serial.flush();
#  endif
}

// #############################################################################
void loop (void)
{
    unsigned long now = millis();
    unsigned long elapsed = now - last_check_time;
    unsigned long next_delay = 500000;

    for (unsigned int i=0; i<num_monsters; ++i) {
        unsigned long delay = monsters[i].check(elapsed);
        if (delay < next_delay) next_delay = delay;
    }

#ifdef DEBUG
    Serial.print("-- ");
    Serial.print(next_delay/1000);
    Serial.println(" --");
#endif

    last_check_time = now;
    delay(next_delay);
}

// #############################################################################
Monster::Monster (byte pin, unsigned long delay)
    : m_pin(pin), m_is_on(false), m_delay(delay)
{
    pinMode(m_pin, OUTPUT);
    digitalWrite(pin, LOW);
}

// #############################################################################
unsigned long Monster::check (unsigned long elapsed)
{
    if (m_delay > elapsed) {
        m_delay -= elapsed;
    } else if (m_is_on) {
        digitalWrite(m_pin, LOW);
        m_is_on = false;
        m_delay = random(10 * 1000, 60 * 1000);
    } else {
        digitalWrite(m_pin, HIGH);
        m_is_on = true;
        m_delay = random(1 * 1000, 3 * 1000);
    }

#  ifdef DEBUG
    Serial.print(m_pin); Serial.print("\t");
    Serial.print(m_delay/1000); Serial.print("\t");
    Serial.print(m_is_on ? "on" : "off"); Serial.println("");
    Serial.flush();
#  endif

    return m_delay;
}

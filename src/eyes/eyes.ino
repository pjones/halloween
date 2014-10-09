// #############################################################################
class Monster {
public:
    Monster (byte pin, unsigned long delay);
    unsigned long check (unsigned long elapsed);
    unsigned long full_on (void);

private:
    unsigned long randomSeconds (int lower, int uppper, int multiplier=1000);

    byte m_pin;
    bool m_is_on;
    unsigned long m_delay;
};

// #############################################################################
unsigned long last_check_time = 0;
unsigned long next_full_on_time = 60000;
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
    unsigned long requested_delay = 0;
    unsigned long all_on = false;

    if (now >= next_full_on_time) {
        all_on = true;
        next_full_on_time = now + random(45, 60) * 1000;
    }

    for (unsigned int i=0; i<num_monsters; ++i) {
        if (all_on) {
            requested_delay = monsters[i].full_on();
        } else {
            requested_delay = monsters[i].check(elapsed);
        }

        if (requested_delay < next_delay) next_delay = requested_delay;
    }

#ifdef DEBUG
    Serial.print("-- ");
    Serial.print(elapsed);
    Serial.print(" | ");
    Serial.print(next_delay);
    Serial.print(" | ");
    Serial.print(next_full_on_time);
    Serial.print(" | ");
    Serial.print(now);
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
        m_delay = randomSeconds(5, 10);
    } else {
        analogWrite(m_pin, 20); // Less bright.
        m_is_on = true;
        m_delay = randomSeconds(2, 6, 100);
    }

#  ifdef DEBUG
    Serial.print(m_pin); Serial.print("\t");
    Serial.print(m_delay/1000); Serial.print("\t");
    Serial.print(m_is_on ? "on" : "off"); Serial.println("");
    Serial.flush();
#  endif

    return m_delay;
}

// #############################################################################
unsigned long Monster::full_on (void)
{
    digitalWrite(m_pin, HIGH);
    m_is_on = true;
    m_delay = randomSeconds(1, 2);

#  ifdef DEBUG
    Serial.print(m_pin); Serial.print("\t");
    Serial.print(m_delay/1000); Serial.print("\t");
    Serial.println("full");
    Serial.flush();
#  endif

    return m_delay;
}

// #############################################################################
// I think there's a bug in the avr-libc random function.  It refuses
// to generate large random numbers and instead just returns the lower
// number.  This gets around the problem.
unsigned long Monster::randomSeconds (int lower, int uppper, int multiplier)
{
    return random(lower, uppper) * multiplier + random(multiplier);
}

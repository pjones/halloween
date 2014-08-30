// #############################################################################
#define RANGE_PIN 3
#define LED_R_PIN 9
#define LED_G_PIN 10
#define LED_B_PIN 11

// #############################################################################
// Ardunio functions.
void setup (void);
void loop (void);

// #############################################################################
// Local functions.
void state_ready (void);
void state_fire (void);
void state_pause (void);
unsigned long sample_ranger_finder (void);
void set_led_color (int red, int green, int blue);

// #############################################################################
// Run once.
void setup()
{
    pinMode(RANGE_PIN, INPUT);
    Serial.begin(9600);
}

// #############################################################################
// Run over and over.
void loop()
{
    state_ready();

    unsigned long range = 0;
    range = sample_ranger_finder();
    // Serial.print(range); Serial.println("");

    if (range < 1000) {
        state_fire();
        state_pause();
    }

    delay(10);
}

// #############################################################################
unsigned long sample_ranger_finder (void)
{
    unsigned long pulse = pulseIn(RANGE_PIN, HIGH);
    return pulse;
}

// #############################################################################
void state_ready (void)
{
    set_led_color(0, 100, 0); // Green.
}

// #############################################################################
void state_fire (void)
{
    set_led_color(255, 0, 0); // Red.
    delay(350);
}

// #############################################################################
void state_pause (void)
{
    int delay_part=250;
    int delay_total=30000;
    int r=107, g=38, b=229; // Purple -> Blue;

    for (int i=0; i<(delay_total/delay_part); ++i) {
        set_led_color(r,g,b);
        delay(delay_part);
        if (r > 0) --r;
        if (g > 0) --g;
        if (b > 0) --b;
    }
}

// #############################################################################
void set_led_color (int red, int green, int blue)
{
    analogWrite(LED_R_PIN, red);
    analogWrite(LED_G_PIN, green);
    analogWrite(LED_B_PIN, blue);
}

// #############################################################################
// The inactive status LED, color red pin.
static const int PIN_STATUS_LED_RED = 3;

// #############################################################################
// The inactive status LED, color green pin.
static const int PIN_STATUS_LED_GREEN = 5;

// #############################################################################
// The inactive status LED, color blue pin.
static const int PIN_STATUS_LED_BLUE = 6;

// #############################################################################
// The solenoid which opens the air stream.
static const int PIN_SOLENOID = 2;

// #############################################################################
// The signal from the IR beam.
static const int PIN_IR_BEAM = 10;

// #############################################################################
// The remote trigger (for stuff like taking a picture and starting
// the smoke machine).
static const int PIN_REMOTE_TRIGGER_A = 11;
static const int PIN_REMOTE_TRIGGER_B = 12;
static const int PIN_REMOTE_TRIGGER_C = 13;

// #############################################################################
// Length of time to spray air.
static const unsigned long FIRE_TIME_MILLIS = 250;

// #############################################################################
// Length of time to remain inactive after spraying air.
static const unsigned long INACTIVE_TIME_MILLIS = 15000;

// #############################################################################
// Length of time to raise the remote trigger high.
static const unsigned long REMOTE_TRIGGER_MILLIS = 200;

// #############################################################################
enum states_t {
    STATE_READY,
    STATE_FIRING,
    STATE_INACTIVE
};

// #############################################################################
struct color_t {
    int color_red;
    int color_green;
    int color_blue;
};

static const struct color_t COLOR_READY    = {0,   255,   0};
static const struct color_t COLOR_FIRE     = {255, 0,     0};
static const struct color_t COLOR_INACTIVE = {107, 38,  229};

// #############################################################################
class TriggerState {
public:
    TriggerState (void);
    void check (void);
    void start_fire (void);
    void stop_fire (void);
    void update_inactive_indicator (unsigned long duration);
    void remote_trigger_on (void);
    void remote_trigger_off (void);
    void return_to_ready (void);
private:
    unsigned long m_last_event;
    unsigned long m_remote_trigger;
    enum states_t m_state;
    struct color_t m_inactive_color;
 };

TriggerState trigger_state_global; // Global state;

// #############################################################################
// Functions that the Ardunio preprocessor expects.
void setup (void);
void loop (void);

// #############################################################################
// Local functions.
void set_led_color (struct color_t color);

// #############################################################################
// Run once.
void setup()
{
    pinMode(PIN_SOLENOID, OUTPUT);
    digitalWrite(PIN_SOLENOID, LOW);

    // For debugging.
#  ifdef DEBUG
    Serial.begin(9600);
#  endif
}

// #############################################################################
// Run over and over.
void loop()
{
    trigger_state_global.check();
}

// #############################################################################
void set_led_color (struct color_t color)
{
    analogWrite(PIN_STATUS_LED_RED,   color.color_red);
    analogWrite(PIN_STATUS_LED_GREEN, color.color_green);
    analogWrite(PIN_STATUS_LED_BLUE,  color.color_blue);
}

// #############################################################################
TriggerState::TriggerState (void)
    : m_last_event(0),
      m_remote_trigger(0),
      m_state(STATE_READY),
      m_inactive_color(COLOR_INACTIVE)
{
    set_led_color(COLOR_READY);

    pinMode(PIN_REMOTE_TRIGGER_A, OUTPUT);
    digitalWrite(PIN_REMOTE_TRIGGER_A, LOW);

    pinMode(PIN_REMOTE_TRIGGER_B, OUTPUT);
    digitalWrite(PIN_REMOTE_TRIGGER_B, LOW);

    pinMode(PIN_REMOTE_TRIGGER_C, OUTPUT);
    digitalWrite(PIN_REMOTE_TRIGGER_C, LOW);
}

// #############################################################################
void TriggerState::check (void)
{
    int beam_status = digitalRead(PIN_IR_BEAM);
    unsigned long now = millis();

#  ifdef DEBUG
    Serial.println(distance);
#  endif

    switch (m_state) {
    case STATE_FIRING:
        if (now - m_last_event >= FIRE_TIME_MILLIS) {
            stop_fire();
            update_inactive_indicator(0);
            m_state = STATE_INACTIVE;
            m_last_event = now;
        }
        if (m_remote_trigger != 0 &&
            now - m_remote_trigger >= REMOTE_TRIGGER_MILLIS)
        {
            remote_trigger_off();
            m_remote_trigger = 0;
        }
        break;
    case STATE_INACTIVE:
        update_inactive_indicator(now - m_last_event);

        if (now - m_last_event >= INACTIVE_TIME_MILLIS) {
            return_to_ready();
            m_state = STATE_READY;
        }
        break;
    case STATE_READY:
        if (beam_status == LOW) {
            start_fire();
            remote_trigger_on();
            m_state = STATE_FIRING;
            m_last_event = now;
            m_remote_trigger = now;
        }
        break;
    }
}

// #############################################################################
void TriggerState::start_fire (void)
{
    set_led_color(COLOR_FIRE);
    digitalWrite(PIN_SOLENOID, HIGH);
}

// #############################################################################
void TriggerState::stop_fire (void)
{
    digitalWrite(PIN_SOLENOID, LOW);
}

// #############################################################################
void TriggerState::update_inactive_indicator (unsigned long duration) {
    if (duration == 0) {
        m_inactive_color = COLOR_INACTIVE;
    } else if (duration % 1000 == 0) {
        if (m_inactive_color.color_red   >   0) --m_inactive_color.color_red;
        if (m_inactive_color.color_green >   0) --m_inactive_color.color_green;
        if (m_inactive_color.color_blue  < 255) ++m_inactive_color.color_blue;
    }

    set_led_color(m_inactive_color);
}

// #############################################################################
void TriggerState::remote_trigger_on (void)
{
    digitalWrite(PIN_REMOTE_TRIGGER_A, HIGH);
    digitalWrite(PIN_REMOTE_TRIGGER_B, HIGH);
    digitalWrite(PIN_REMOTE_TRIGGER_C, HIGH);
}

// #############################################################################
void TriggerState::remote_trigger_off (void)
{
    digitalWrite(PIN_REMOTE_TRIGGER_A, LOW);
    digitalWrite(PIN_REMOTE_TRIGGER_B, LOW);
    digitalWrite(PIN_REMOTE_TRIGGER_C, LOW);
}

// #############################################################################
void TriggerState::return_to_ready (void)
{
    set_led_color(COLOR_READY);
}

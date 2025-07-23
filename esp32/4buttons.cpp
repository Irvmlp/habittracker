#define SWITCH1_PIN 15
#define LED1_PIN    4

#define SWITCH2_PIN 23
#define LED2_PIN    5

#define SWITCH3_PIN 22
#define LED3_PIN    6

#define SWITCH4_PIN 21
#define LED4_PIN    8

#define TOGGLE_SWITCH_PIN 20
#define TOGGLE_LED_PIN    10

bool lastState1 = HIGH;
bool lastState2 = HIGH;
bool lastState3 = HIGH;
bool lastState4 = HIGH;

void setup() {
  pinMode(SWITCH1_PIN, INPUT_PULLUP);
  pinMode(LED1_PIN, OUTPUT);

  pinMode(SWITCH2_PIN, INPUT_PULLUP);
  pinMode(LED2_PIN, OUTPUT);

  pinMode(SWITCH3_PIN, INPUT_PULLUP);
  pinMode(LED3_PIN, OUTPUT);

  pinMode(SWITCH4_PIN, INPUT_PULLUP);
  pinMode(LED4_PIN, OUTPUT);

  pinMode(TOGGLE_SWITCH_PIN, INPUT_PULLUP);
  pinMode(TOGGLE_LED_PIN, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // Read toggle switch
  bool toggleState = digitalRead(TOGGLE_SWITCH_PIN); // LOW = ON

  // Set LED indicator for toggle switch
  digitalWrite(TOGGLE_LED_PIN, toggleState == LOW ? HIGH : LOW);

  // If toggle is OFF, skip reading other buttons and make sure LEDs are off
  if (toggleState == HIGH) {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
    delay(10);
    return;
  }

  // Toggle is ON: now respond to button presses
  bool currentState1 = digitalRead(SWITCH1_PIN);
  bool currentState2 = digitalRead(SWITCH2_PIN);
  bool currentState3 = digitalRead(SWITCH3_PIN);
  bool currentState4 = digitalRead(SWITCH4_PIN);

  if (lastState1 == HIGH && currentState1 == LOW) {
    Serial.println("CLICK: Switch 1");
    digitalWrite(LED1_PIN, HIGH);
    delay(200);
    digitalWrite(LED1_PIN, LOW);
  }

  if (lastState2 == HIGH && currentState2 == LOW) {
    Serial.println("CLICK: Switch 2");
    digitalWrite(LED2_PIN, HIGH);
    delay(200);
    digitalWrite(LED2_PIN, LOW);
  }

  if (lastState3 == HIGH && currentState3 == LOW) {
    Serial.println("CLICK: Switch 3");
    digitalWrite(LED3_PIN, HIGH);
    delay(200);
    digitalWrite(LED3_PIN, LOW);
  }

  if (lastState4 == HIGH && currentState4 == LOW) {
    Serial.println("CLICK: Switch 4");
    digitalWrite(LED4_PIN, HIGH);
    delay(200);
    digitalWrite(LED4_PIN, LOW);
  }

  // Update last button states
  lastState1 = currentState1;
  lastState2 = currentState2;
  lastState3 = currentState3;
  lastState4 = currentState4;

  delay(10); // debounce
}

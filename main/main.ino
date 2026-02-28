const int TRIG_PIN = 6;
const int ECHO_PIN = 7;
const int BUZZER_PIN = 11;

const int MAX_VALID_DISTANCE = 200;

float duration_us, distance_cm;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration_us = pulseIn(ECHO_PIN, HIGH, 30000); // timeout
  distance_cm = duration_us * 0.017;

  Serial.print("distance: ");
  Serial.println(distance_cm);

  // Ignore invalid readings
  if (distance_cm <= 0 || distance_cm > MAX_VALID_DISTANCE) {
    noTone(BUZZER_PIN); // silent
    delay(100);
    return;
  }

  // ZONE 1: Very close (0–30 cm) → continuous alarm
  if (distance_cm <= 30) {
    tone(BUZZER_PIN, 2000); // high pitch
  }

  // ZONE 2: Near (31–80 cm) → fast beeping
  else if (distance_cm <= 80) {
    tone(BUZZER_PIN, 1500);
    delay(150);
    noTone(BUZZER_PIN);
    delay(150);
  }

  // ZONE 3: Medium (81–150 cm) → slow beeping
  else if (distance_cm <= 150) {
    tone(BUZZER_PIN, 1000);
    delay(400);
    noTone(BUZZER_PIN);
    delay(1600);
  }

  // ZONE 4: Far (>150 cm) → silent
  else {
    noTone(BUZZER_PIN);
    delay(100);
  }
}
// Pin numbers
const int buzzerPin = 11;
const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

// TODO: Change this to tune distance
const float threshold = 0.5;

void setup() {
    // put your setup code here, to run once:
    pinMode(buzzerPin, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  
    
    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;

    // Change the threshold here
    if (distance < threshold) {
        buzz();
    }
    else {
        delay(100);
    }
}

void buzz() {
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
}

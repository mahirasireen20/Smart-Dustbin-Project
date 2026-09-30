#include <Servo.h>

Servo lidServo;

// Pins
const int buttonPin = 2;
const int servoPin = 5;

const int trigPin = 6;
const int echoPin = 7;

const int redLED = 8;
const int yellowLED = 11;
const int greenLED = 12;

const int buzzer = 13;

void setup() {
  lidServo.attach(servoPin);

  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Lid starts closed
  lidServo.write(0);

  Serial.begin(9600);
}

void loop() {

  // ===== BUTTON: OPEN → 3 SEC → CLOSE =====

  if (digitalRead(buttonPin) == LOW) {

    lidServo.write(90);   // OPEN
    delay(3000);

    lidServo.write(0);    // CLOSE

    while (digitalRead(buttonPin) == LOW) {
      delay(10);
    }

    delay(200);
  }


  // ===== ULTRASONIC =====

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  float distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  // ===== BIN LEVEL =====

  if (distance <= 2.5) {

    // 🔴 FULL
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH);

  }

  else if (distance <= 5.0) {

    // 🟡 ALMOST FULL
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, LOW);

  }

  else {

    // 🟢 SPACE AVAILABLE
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW);
  }

  delay(200);
}
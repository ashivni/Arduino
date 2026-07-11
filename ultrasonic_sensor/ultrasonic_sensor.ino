/*
 * HC-SR04 example sketch
 *
 * Measures distance with an HC-SR04 ultrasonic sensor and lights an LED
 * whenever the nearest object is more than 10 cm away. Readings are printed
 * to the serial monitor at 9600 baud, twice a second.
 *
 * Wiring:
 *   HC-SR04 trig -> pin 9
 *   HC-SR04 echo -> pin 10
 *   LED          -> pin 2
 *
 * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
 *
 * by Isaac100
 * Modified by Ashivni Shekhawat
 */

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 2;

float duration, distance;  // echo pulse width (us) and the distance it implies (cm)

// Objects farther away than this (in cm) leave the LED lit.
const float thresholdCm = 10;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Fire a ping: the HC-SR04 needs a clean low, then a 10 us high pulse on trig.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo stays high for the round-trip flight time of the ping.
  duration = pulseIn(echoPin, HIGH);

  // Sound travels ~0.0343 cm/us; halve it because the ping goes out and back.
  distance = (duration * .0343) / 2;

  if (distance > thresholdCm) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Set High");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Set Low");
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}

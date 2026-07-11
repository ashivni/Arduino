/*
 * HC-SR04 + Servo Sketch
 *
 * Turn the servo away if a closeby object is detected. The ultrasonic sensor
 * is polled four times a second; whenever something comes within 15 cm the
 * servo is kicked 90 degrees onward, alternating between 0 and 90 degrees.
 *
 * Wiring:
 *   HC-SR04 trig -> pin 8
 *   HC-SR04 echo -> pin 9
 *   Servo signal -> pin 10
 *
 * Created by Ashivni Shekhawat
 */

#include <Servo.h>

Servo myservo;             // servo object used to control the servo
int pos = 0;               // current servo position, in degrees
float duration, distance;  // echo pulse width (us) and the distance it implies (cm)

// Trig and echo pins for the echo sensor
const int trigPin = 8;
const int echoPin = 9;

// Anything closer than this (in cm) counts as an obstacle worth turning away from.
const float triggerDistanceCm = 15;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object
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

  // Object nearby: advance the servo by 90 degrees, wrapping back to 0 after 90.
  if (distance < triggerDistanceCm) {
    pos = (pos + 90) % 180;
    myservo.write(pos);
  }

  Serial.print("Distance: ");
  Serial.println(distance);

  delay(250);
}

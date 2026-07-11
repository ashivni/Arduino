/*
 * LED Blink (scratch sketch)
 *
 * Flashes the on-board LED on pin 13 at 10 Hz (50 ms on, 50 ms off).
 * Same as the LED sketch; kept as a scratch pad for quick tests.
 *
 * Created by Ashivni Shekhawat
 */

const int ledPin = 13;  // on-board LED on most Arduino boards

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);  // LED on
  delay(50);
  digitalWrite(ledPin, LOW);   // LED off
  delay(50);
}

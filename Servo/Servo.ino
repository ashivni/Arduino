/*
* Servo Sweep
*
* Sweeps a servo back and forth between 0 and 180 degrees, one degree at a
* time, pausing 15 ms per step so the servo can keep up. A full sweep in one
* direction takes about 2.7 seconds.
*
* Wiring:
*   Servo signal -> pin 10
*
* Based on the Arduino "Sweep" example by BARRAGAN
* <http://www.barraganstudio.com>, modified by Scott Fitzgerald.
* Public domain.
*
* Modified by Ashivni Shekhawat
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);                  // tell servo to go to position in variable 'pos'
    delay(15);                           // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
    myservo.write(pos);                  // tell servo to go to position in variable 'pos'
    delay(15);                           // waits 15ms for the servo to reach the position
  }
}

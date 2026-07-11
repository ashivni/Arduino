# Arduino Sketches

A small collection of Arduino sketches: blinking an LED, sweeping a servo,
measuring distance with an HC-SR04 ultrasonic sensor, and combining the last
two so a servo turns away from anything that gets too close.

Written for an Arduino Uno, but nothing here is Uno-specific — any board with a
few digital pins and the standard `Servo` library will do.

## The sketches

| Sketch | What it does | Wiring |
| --- | --- | --- |
| [`LED`](LED/LED.ino) | Blinks the on-board LED at 10 Hz. | LED on pin 13 (on-board) |
| [`Servo`](Servo/Servo.ino) | Sweeps a servo back and forth between 0° and 180°. | Servo signal → pin 10 |
| [`ultrasonic_sensor`](ultrasonic_sensor/ultrasonic_sensor.ino) | Measures distance and lights an LED when the nearest object is more than 10 cm away. Prints readings to the serial monitor. | trig → 9, echo → 10, LED → 2 |
| [`servo_ultrasonic`](servo_ultrasonic/servo_ultrasonic.ino) | Turns the servo 90° whenever something comes within 15 cm. | trig → 8, echo → 9, servo → 10 |
| [`sketch_jul8a`](sketch_jul8a/sketch_jul8a.ino) | Scratch sketch — currently a copy of `LED`. | LED on pin 13 (on-board) |

## Hardware used

- Arduino Uno (or compatible)
- HC-SR04 ultrasonic distance sensor
- Hobby servo (SG90 or similar)
- LED + resistor, for the sketches that drive an external LED

## Running a sketch

1. Download this repository (**Code → Download ZIP**) or clone it:
   ```
   git clone https://github.com/ashivni/Arduino.git
   ```
2. Open the folder for the sketch you want in the Arduino IDE — each `.ino`
   lives in a folder of the same name, which is how the IDE expects sketches to
   be laid out.
3. Select your board and port under **Tools**, then click **Upload**.
4. For the sketches that print distances, open **Tools → Serial Monitor** and
   set it to **9600 baud**.

Both HC-SR04 sketches convert the echo pulse to a distance the same way: sound
travels roughly 0.0343 cm per microsecond, and the pulse is halved because the
ping travels out to the object and back.

## Credits

Sketches by Ashivni Shekhawat, except where noted:

- `Servo/Servo.ino` is based on the Arduino **Sweep** example by BARRAGAN,
  modified by Scott Fitzgerald (public domain), with the servo moved to pin 10.
- `ultrasonic_sensor/ultrasonic_sensor.ino` is based on
  [Isaac100's HC-SR04 getting-started sketch](https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380).

// Bench test for a brushless motor through its ESC.
// The throttle (1000-2000 us pulse) is set with a potentiometer on A0;
// the ESC signal is on pin 9. Remove the propeller before testing.

#include <Servo.h>

Servo esc;

int potPin = A0;
int throttle;

void setup() {
  esc.attach(9, 1000, 2000);
  // Arm the ESC: send minimum throttle for 3 s, whatever the potentiometer position
  esc.writeMicroseconds(1000);
  delay(3000);
}

void loop() {
  throttle = map(analogRead(potPin), 0, 1023, 1000, 2000);
  esc.writeMicroseconds(throttle);
  delay(10);
}

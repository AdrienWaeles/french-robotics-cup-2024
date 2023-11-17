
#include <Servo.h>

Servo esc;

int potPin = A0;
int throttle;

void setup() {
  esc.attach(9, 1000, 2000);
}

void loop() {
  throttle = map(analogRead(potPin), 0, 1023, 1000, 2000);
  esc.writeMicroseconds(throttle);
  delay(10);
}

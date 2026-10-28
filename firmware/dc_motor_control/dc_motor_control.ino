// Bench test for a DC motor with a Hall encoder.
// Measures the motor speed (RPM) from the time between two encoder pulses
// (interrupt on pin 2) and prints it on the serial monitor. Pin 5 is driven
// with a constant PWM (commande) and pin 3 with a PWM proportional to the
// measured speed (mesure).

#define ENCODER_PIN 2
#define ENCODER_N   20
// Written by the interrupt: volatile so the compiler always reads them from memory
volatile unsigned long T1 = 0, T2 = 0, T = 0;
volatile bool MeasDone = 0;
int Motor_RPM = 0;

int mot1 = 3;
int mot2 = 5;
int cod1 = 6;
int cod2 = 2;
int commande = 255;
int mesure;

void INT0_ISR(void)
{
  if(MeasDone)
  {
    T2 = micros();
    T = T2 - T1;
    MeasDone = 0;
  }
  else
  {
    T1 = micros();
    MeasDone = 1;
  }
}

void setup() {
  pinMode(mot1, OUTPUT);
  pinMode(mot2, OUTPUT);
  pinMode(cod1, INPUT);
  pinMode(cod2, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), INT0_ISR, RISING);
}

void loop() {
  // Copy T with interrupts disabled: on an 8-bit AVR a 32-bit read is not atomic
  noInterrupts();
  unsigned long period = T;
  interrupts();
  // No pulse measured yet: avoid a division by zero
  Motor_RPM = (period == 0) ? 0 : 60000000UL / (period * ENCODER_N);
  Serial.print("Motor RPM: ");
  Serial.println(Motor_RPM);
  delay(250);

  mesure = Motor_RPM*0.047;
  analogWrite(mot2, commande);
  analogWrite(mot1, mesure);
  Serial.println(mesure);

}

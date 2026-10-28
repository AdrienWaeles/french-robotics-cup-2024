// Manual control of a DC motor over Bluetooth.
// A Bluetooth serial module is connected on SoftwareSerial (RX pin 6, TX pin 11,
// 9600 baud). Sending 'A' followed by a number (0-255) sets the PWM command.
// The motor speed is measured from the encoder as in dc_motor_rpm.
// Note: pin 6 works as RX on an Uno; on a Mega, SoftwareSerial RX needs a
// pin-change-interrupt pin (10-15, 50-53, A8-A15).

// Encoder variables
#define ENCODER_PIN 2
#define ENCODER_N   20
// Written by the interrupt: volatile so the compiler always reads them from memory
volatile unsigned long T1 = 0, T2 = 0, T = 0;
volatile bool MeasDone = 0;
int Motor_RPM = 0;
// Bluetooth variables
#include<SoftwareSerial.h>
#define RX 6
#define TX 11
#define LED 9
SoftwareSerial BlueT(RX,TX);
char Data;
// Motor variables
int mot1 = 3;
int mot2 = 5;
//int cod1 = 10;
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
  //pinMode(cod1, INPUT);
  pinMode(cod2, INPUT);
  //Serial.begin(9600);
  BlueT.begin(9600);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), INT0_ISR, RISING);
}

void loop() {
  if (BlueT.available()){
    Data=BlueT.read();
  if (Data=='A') {
    // analogWrite only uses the low 8 bits: keep the command in 0-255
    commande = constrain(BlueT.parseInt(), 0, 255);
    //Serial.println(commande);
    }
  }

  // Copy T with interrupts disabled: on an 8-bit AVR a 32-bit read is not atomic
  noInterrupts();
  unsigned long period = T;
  interrupts();
  // No pulse measured yet: avoid a division by zero
  Motor_RPM = (period == 0) ? 0 : 60000000UL / (period * ENCODER_N);
  //Serial.print("Motor RPM: ");
  //Serial.println(Motor_RPM);

  mesure = Motor_RPM*0.047;
  analogWrite(mot2, commande);
  analogWrite(mot1, mesure);
  //Serial.println(mesure);
}

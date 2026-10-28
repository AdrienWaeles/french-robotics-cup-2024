//variable encodeur
#define ENCODER_PIN 2
#define ENCODER_N   20
unsigned long T1 = 0, T2 = 0, T;
bool MeasDone = 0;
int Motor_RPM = 0;
//variable bluetooth
#include<SoftwareSerial.h>
#define RX 6
#define TX 11
#define LED 9
SoftwareSerial BlueT(RX,TX);
char Data;
//variable moteur
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
    commande = BlueT.parseInt();
    //Serial.println(commande);
    }
  }

  Motor_RPM = (60000000) / (T * ENCODER_N);
  //Serial.print("Motor RPM: ");
  //Serial.println(Motor_RPM);

  mesure = Motor_RPM*0.047;
  analogWrite(mot2, commande);
  analogWrite(mot1, mesure);
  //Serial.println(mesure);
}

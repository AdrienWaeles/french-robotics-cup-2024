// MOTORS
#define L_MOTOR 6 // left motor
#define L_MOTOR_DIRECTION 7 // rotation direction of left motor
#define R_MOTOR 8 // right motor
#define R_MOTOR_DIRECTION 9 // rotation direction of right motor

//ENCODERS
#define L_ENCODER_A 2 // left encoder
#define L_ENCODER_B 4
#define R_ENCODER_A 3 // right encoder
#define R_ENCODER_B 5

#define L_ticks_perCm 50 // number of ticks (points) read by the left encoder per cm travelled
#define R_ticks_perCm 50 // same for right encoder

// Trigonometric direction rotation
#define L_trigo_ticks_perRad 1000 //  number of ticks (points) read by the left encoder processing a 1 radian rotation in trigo direction
#define R_trigo_ticks_perRad 1000 // by the right encoder

// Clockwise rotation
#define L_clockwise_ticks_perRad 1000 // number of ticks (points) read by the left encoder processing a 1 radian rotation in clockwise direction
#define R__clockwise_ticks_perRad 1000 // by the right encoder

long L_encoder_ticks = 0;
long L_encoder_previous_ticks = 0;
long L_encoder_deltaTicks =  0; // number of ticks measured by the left encoder after a short time
float L_angle_travelled_rad = 0; // angle travelled by the left wheel in radians

long R_encoder_ticks = 0;
long R_encoder_previous_ticks = 0;
long L_encoder_deltaTicks =  0; // number of ticks measured by the right encoder after a short time
float R_angle_travelled_rad = 0; // angle travelled by the right wheel in radians

float distance_travelled_cm = 0; // distance in cm travelled by the robot after a short time
float angle_travelled_rad = 0; // angle travelled by the robot in radians

float L_integral_error = 0;
float R_integral_error = 0;
float L_previous_speed_error = 0;
float R_previous_speed_error = 0;

float L_command;
float R_command;
float distance_command_cm;
float angle_command_rad;

float speed_coeff = 1; // Factor to convert the speed measured to a number between 0 et 255 (so we will be able to compare it with our command)

// PID coefficients
float P = 0.5; // PID proportional coefficient
float I = 0.5; // PID integrating coefficient
float D = 0.0; // PID derivative coefficient

unsigned long previousmillis = 0; // Last measured time


void setup() {
  //MOTORS
  pinMode(L_MOTOR, OUTPUT);
  pinMode(L_MOTOR_DIRECTION, OUTPUT);
  pinMode(R_MOTOR, OUTPUT);
  pinMode(R_MOTOR_DIRECTION, OUTPUT);

  //ENCODERS
  pinMode(L_ENCODER_A, INPUT_PULLUP); // INPUT_PULLUP so if there is no signal on this pin, we will receive the value 1, so when we will reveive something it will be 0
  pinMode(L_ENCODER_B, INPUT_PULLUP);
  pinMode(R_ENCODER_A, INPUT_PULLUP);
  pinMode(R_ENCODER_B, INPUT_PULLUP);

  // ENCODERS Interruptions
  // The macro CHANGE triggers an interrupt when the pin changes, whether from LOW to HIGH or HIGH to LOW
  attachInterrupt(digitalPinToInterrupt(L_ENCODER_A), L_Encoder_interrupt, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(R_ENCODER_A), R_Encoder_interrupt, CHANGE);

  //SERIAL COMMUNICATION
  Serial.begin(9600); // speed of communication
}

void motors_command(float L_command, float R_command){ // L_command and R_command between -255 and 255 (if negative the wheel goes backward)
  if (L_command>=0){
    digitalWrite(L_MOTOR_DIRECTION, LOW);
  }
  else{
    digitalWrite(L_MOTOR_DIRECTION, HIGH);
  }
  if (R_command>=0){
    digitalWrite(R_MOTOR_DIRECTION, LOW);
  }
  else{
    digitalWrite(R_MOTOR_DIRECTION, HIGH);
  }
  analogWrite(L_MOTOR, abs(L_command));
  analogWrite(R_MOTOR, abs(R_command));
}

void L_Encoder_interrupt(){ // called when there is an interruption on the left encoder pin A
  // L_ENCODER_A and L_ENCODER_B are the same signal but are out of phase. We defined the interruption on the L_ENCODER_A pin
  if (digitalRead(L_ENCODER_A)==digitalRead(L_ENCODER_B)){ 
  // So if the previous condition is true, it means that when the pin L_ENCODER_A detected a high value and interrupted the programm, the B pin was already detecting a high value
  // So the first signal to have a high value was the L_ENCODER_B, with our configuration it means the wheel is moving forward.
    L_encoder_ticks ++;
  }
  else{ // else the wheel is moving backward
    L_encoder_ticks --;
  }
}


void R_Encoder_interrupt(){ // called when there is an interruption on one of the right encoder pin
  // same explanation as left interrupt function
  if (digitalRead(R_ENCODER_A)==digitalRead(R_ENCODER_B)){ // the wheel is moving forward
    R_encoder_ticks ++;
  }
  else{ // the wheel is moving backward
    R_encoder_ticks --;
  }
}

void loop() {

  if (millis()-previousmillis>100){ // we measure the number of ticks every 100 milliseconds
    previousmillis = millis();

    L_encoder_deltaTicks = L_encoder_ticks - L_encoder_previous_ticks;
    R_encoder_deltaTicks = R_encoder_ticks - R_encoder_previous_ticks;
    L_encoder_previous_ticks = L_encoder_ticks;
    R_encoder_previous_ticks = R_encoder_ticks;

    distance_travelled_cm = (L_encoder_deltaTicks/L_ticks_perCm + R_encoder_deltaTicks/R_ticks_perCm)/2; // Distance travelled = average of distance travelled by each coding wheel

    if (L_encoder_deltaTicks>0){ // if the left wheel turns in trigonometric direction
      L_angle_travelled_rad = L_distance_travelled_cm/L_trigo_ticks_perRad;
    }
    else{ //clockwise direction
      L_angle_travelled_rad = L_encoder_speed/L_clockwise_ticks_perRad;
    }

    if (R_encoder_deltaTicks>0){ // if the right wheel turns in trigonometric direction
      R_angle_travelled_rad = R_encoder_speed/R_trigo_ticks_perRad;
    }
    else{ //clockwise direction
      R_angle_travelled_rad = R_encoder_speed/R_trigo_ticks_perRad;
    }

    angle_travelled_rad = (R_speed_error - L_speed_error)/2; // Angle travelled = average of angle travelled by each coding wheel (the two wheels turn in the opposite direction so there is a minus sign)

    distance_command_cm -= distance_travelled_cm; // Remaining distance to achieve
    angle_command_cm -= angle_travelled_rad; // Remaining angle to achieve

    
    //L_integral_error += L_speed_error;
    //L_command = P*L_speed_error + I*L_speed_error + D*(L_speed_error-L_previous_speed_error); //PID correction

  }
  
 

}

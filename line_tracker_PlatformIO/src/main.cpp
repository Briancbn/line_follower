/**
 * 
 * Line Following Robot
 * Author: Chen Bainian
 * E-mail: brian97cbn@gmail.com
 * 
 * 
 **/

#include "Arduino.h"

#include "Config.h"
#include "Motor.h"
#include "PID.h"

Motor robot;
PID pid_controller(KP, KI, KD);

void setup()
{
  Serial.begin(115200);
}

void print_sensor_readings(int16_t R2_reading, int16_t R1_reading, int16_t M_reading, int16_t L1_reading, int16_t L2_reading){

  // print out the readings for 
  Serial.print(L2_reading);
  Serial.print("    ");
  Serial.print(L1_reading);
  Serial.print("    ");
  Serial.print(M_reading);
  Serial.print("    ");
  Serial.print(R1_reading);
  Serial.print("    ");
  Serial.println(R2_reading);

}

void loop()
{
  int16_t R2_reading = analogRead(R_IR2)/IR_RATIO; //Manual calibration
  int16_t R1_reading = analogRead(R_IR1)/IR_RATIO;
  int16_t M_reading = analogRead(M_IR)/IR_RATIO;
  int16_t L1_reading = analogRead(L_IR1)/IR_RATIO;
  int16_t L2_reading = analogRead(L_IR2)/IR_RATIO;
  int16_t err = -(2 * R2_reading + R1_reading - L1_reading - 2 * L2_reading);

  /*int steer = (int)(KP * err);
  int speed = 150 - abs(steer);
  robot.write(speed, steer);
*/
  //print_sensor_readings(R_reading, L_reading);
  pid_controller.load_err(err);
  robot.write(pid_controller.get_linear(), pid_controller.get_angular());
//  print_sensor_readings(R2_reading, R1_reading, M_reading, L1_reading, L2_reading);
  delay(6);


}




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

void loop()
{
  int16_t R_reading = analogRead(R_IR) / 130;
  int16_t L_reading = analogRead(L_IR) / 130;
  int16_t err = R_reading - L_reading;
/*
  int steer = (int)(KP * err);
  int speed = 150 - abs(steer);
  robot.write(speed, steer);
*/
  //print_sensor_readings(R_reading, L_reading);
  pid_controller.load_err(err);
  robot.write(pid_controller.get_linear(), pid_controller.get_angular());

  delay(10);


}


void print_sensor_readings(int16_t R_reading, int16_t L_reading){

  // print out the readings for 
  Serial.print(R_reading);
  Serial.print("    ");
  Serial.println(L_reading);

}

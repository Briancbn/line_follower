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

#include "Adafruit_NeoPixel.h"
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Initialize motor controller
Motor robot;

// Initialize pid controller
PID pid_controller(KP, KI, KD);

// Initialize LED strip
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, LED, NEO_GRB + NEO_KHZ800);

// Initialize Functions
void LDR_trigger();
void LED_write(int r_value, int g_value, int b_value);
void print_sensor_readings(int16_t R2_reading, int16_t R1_reading, int16_t M_reading, int16_t L1_reading, int16_t L2_reading);


void setup()
{
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Initialize LDR Pin
  pinMode(LDR, INPUT);

  // Initialize IR Sensors
  pinMode(R_IR2, INPUT);
  pinMode(R_IR1, INPUT);
  pinMode(M_IR, INPUT);
  pinMode(L_IR1, INPUT);
  pinMode(L_IR2, INPUT);

  // Initialize pixel LED stip
  pixels.begin();
  LED_write(0,0,255);

  // Trigger the movement when there is light shine on the LDR sensor
  if(LIGHT_ACTIVATION){
    LDR_trigger();
  }

  LED_write(255,0,0);
}




void loop()
{
  
  // Read IR sensor readings
  int16_t R2_reading = analogRead(R_IR2)/IR_RATIO; //Manual calibration
  int16_t R1_reading = analogRead(R_IR1)/IR_RATIO;
  int16_t M_reading = analogRead(M_IR)/IR_RATIO;
  int16_t L1_reading = analogRead(L_IR1)/IR_RATIO;
  int16_t L2_reading = analogRead(L_IR2)/IR_RATIO;

  // Calculate error
  int16_t err = ERROR_DIRECTION * (2 * R2_reading + R1_reading - L1_reading - 2 * L2_reading);

  // pid controller calculate the correct linear and angular command based on input error
  pid_controller.load_err(err);

  // control the robot with the calculate linear and angular command
  robot.write(pid_controller.get_linear(), pid_controller.get_angular());

  // print out sensor readings
//  print_sensor_readings(R2_reading, R1_reading, M_reading, L1_reading, L2_reading);

  delay(6);


}



void LDR_trigger(){

  // break the dead loop when the LDR resistance is low enough
  while (true){
    uint16_t LDR_reading = analogRead(LDR);     
    Serial.println(LDR_reading);
    if(LDR_reading < THRESHOLD){
       break;
    }
  }
}

void LED_write(int r_value, int g_value, int b_value){
  for(int i=0;i<NUM_LEDS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(r_value, g_value, b_value));
  }  
  pixels.show();

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



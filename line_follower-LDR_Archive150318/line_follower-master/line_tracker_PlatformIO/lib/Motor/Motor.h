#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "Config.h"

enum Side {left, right};

class Motor
{
  private:
    int16_t angular; // anticlockwise is positive, clockwise is negative
    int16_t linear; // Forward is positive, backward is negative

  public:
    Motor(){
        // assign motor pins
        pinMode(L_DIRECTION, OUTPUT);
        pinMode(L_POWER, OUTPUT);
        pinMode(R_POWER, OUTPUT);
        pinMode(R_DIRECTION, OUTPUT);

        // set the initial state to still and forward
        digitalWrite(L_DIRECTION, L_FORWARD);
        digitalWrite(R_DIRECTION, R_FORWARD);
        analogWrite(L_POWER, 0);
        analogWrite(R_POWER, 0);
        
    }

    void write(int16_t linear, int16_t angular){
        // calculate the speed for each motor
        int16_t left_speed = constrain(linear - angular / 2, -255, 255);
        int16_t right_speed = constrain(linear + angular / 2, -255, 255);

        Side L = left;
        Side R = right;
        // out put the speed for each motor
        writemotor(L, left_speed);
        writemotor(R, right_speed);
    }

    void writemotor(Side side, int16_t speed){
        // write speed for left motor
        if(side == left){
            if(speed > 0 /* moving forward */){
                digitalWrite(L_DIRECTION, L_FORWARD);
                analogWrite(L_POWER, speed);
            }
            else/*stop or moving backward*/{
                speed = -speed; // get the absolute value of speed
                digitalWrite(L_DIRECTION, !L_FORWARD);
                analogWrite(L_POWER, speed);                
            }
        }
        // write speed for right motor
        else{
            if(speed > 0 /* moving forward */){
                digitalWrite(R_DIRECTION, R_FORWARD);
                analogWrite(R_POWER, speed-9);
            }
            else/*stop or moving backward*/{
                speed = -speed; // get the absolute value of speed
                digitalWrite(R_DIRECTION, !R_FORWARD);
                analogWrite(R_POWER, speed-9);                
            }
        }
    }


};

#endif

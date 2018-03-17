#ifndef CONFIG_H
#define CONFIG_H


/******** PIN ASSIGNMENT AND DEFAULT STATE DEFINATION ********/
// define positive direction
#define L_FORWARD LOW 
#define R_FORWARD HIGH

// assign motor left right pinout
#define L_DIRECTION 4
#define L_POWER 5
#define R_POWER 6
#define R_DIRECTION 7

// assign analog IR sensor pins
#define L_IR2 A1
#define L_IR1 A2
#define M_IR A3
#define R_IR1 A4
#define R_IR2 A5

// Manually elimiate noise from the sensor and make sure error is calculated with the correct sign
#define IR_RATIO 100
#define ERROR_DIRECTION -1



/******** Basic Tuning Parameters ********/

// max linear power
#define MAX_LINEAR_POWER 255

// max power for a single motor in an angular motion 
#define MAX_ANGULAR_POWER 255

// PID values
#define KP 11 
#define KI 0
#define KD 125




/******** Advance Tuning Parameters ********/

// according to history angular command to determine whether it is a straight line or a slow turn
#define LINE_STATE_DETERMINATION true
#define ANGULAR_HISTORY_LENGTH 70
#define STRAIGHT_THRESHOLD 30
#define GRADUAL_TURN_THRESHOLD 70




/******** Additional Features ********/

// define the light activation (act like pull-up switch) 
#define LIGHT_ACTIVATION true
#define LDR A0
#define THRESHOLD 300

// define the pins and number of LEDS for the system
#define LED 12
#define NUM_LEDS 8




#endif

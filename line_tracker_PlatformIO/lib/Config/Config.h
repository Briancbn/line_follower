#ifndef CONFIG_H
#define CONFIG_H


#define THRESHOLD 300

// Define positive direction
#define L_FORWARD LOW 
#define R_FORWARD HIGH

// Assign motor left right pinout
#define L_DIRECTION 4
#define L_POWER 5
#define R_POWER 6
#define R_DIRECTION 7

// Assign analog IR sensor pins
#define LDR A0
#define L_IR2 A1
#define L_IR1 A2
#define M_IR A3
#define R_IR1 A4
#define R_IR2 A5
#define IR_RATIO 100

// max linear power
#define MAX_LINEAR_POWER 255

// max power for a single motor in an angular motion 
#define MAX_ANGULAR_POWER 255


#define KP 11
#define KI 0
#define KD 125

#define LED 12
#define NUM_LEDS 8


/*
// max linear speed
#define MAX_LINEAR_SPEED 

// max speed for a single motor in an angular motion 
#define MAX_ANGULAR_SPEED
*/

#endif

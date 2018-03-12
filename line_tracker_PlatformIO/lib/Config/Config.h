#ifndef CONFIG_H
#define CONFIG_H


// Define positive direction
#define L_FORWARD LOW
#define R_FORWARD HIGH

// Assign motor left right pinout
#define L_DIRECTION 4
#define L_POWER 5
#define R_POWER 6
#define R_DIRECTION 7

// Assign analog IR sensor pins
#define L_IR A2
#define R_IR A4

// max linear power
#define MAX_LINEAR_POWER 255

// max power for a single motor in an angular motion 
#define MAX_ANGULAR_POWER 255


#define KP 70
#define KI 0
#define KD 0


/*
// max linear speed
#define MAX_LINEAR_SPEED 

// max speed for a single motor in an angular motion 
#define MAX_ANGULAR_SPEED
*/

#endif

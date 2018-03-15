#ifndef PID_H
#define PID_H

#include "Arduino.h"
#include "Config.h"

class PID
{
  private:
    float kp, ki, kd;
    float p_gain, i_gain, d_gain;
    int16_t err;
    int16_t angular, linear;

  public:
    PID(float _kp, float _ki, float _kd)
    : kp(_kp), ki(_ki), kd(_kd), 
      err(0),
      p_gain(0), i_gain(0), d_gain(0)
    {
    }

    const void load_err(int16_t new_err){
        p_gain = kp * new_err; // calculate p gain
        i_gain += ki * new_err; // integrate i gain
        d_gain = kd * (new_err - err); // calculate the d gain
        err = new_err; // update the error
        i_gain = constrain(i_gain, -255, 255);
        int16_t total_gain = p_gain + i_gain + d_gain;
        angular = total_gain;
        if(angular != 0){
            linear = MAX_ANGULAR_POWER - abs(angular) / 2;
        }
        else
        {
            linear = MAX_LINEAR_POWER;
        }
    }

    const int16_t get_angular() const{
        return angular;
    }

    const int16_t get_linear() const{
        return linear;
    }

};

#endif
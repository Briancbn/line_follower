#ifndef PID_H
#define PID_H

#include "Arduino.h"
#include "Config.h"

class PID
{
  private:
    int16_t kp, ki, kd;
    int16_t p_gain, i_gain, d_gain;
    int16_t err;
    int16_t angular, linear;

  public:
    PID(int16_t _kp, int16_t _ki, int16_t _kd)
    : kp(_kp), ki(_ki), kd(_kd), 
      err(0),
      p_gain(0), i_gain(0), d_gain(0)
    {
    }

    const void load_err(int16_t new_err){
        p_gain = kp * new_err; // calculate p gain
        i_gain += ki * new_err; // integrate i gain
        d_gain = ki * (new_err - err); // calculate the d gain
        err = new_err; // update the error
        int16_t total_gain = p_gain + i_gain + d_gain;
        angular = total_gain;
        if(angular != 0){
            linear = MAX_ANGULAR_POWER - angular / 2;
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

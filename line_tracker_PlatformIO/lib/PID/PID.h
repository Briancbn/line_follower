#ifndef PID_H
#define PID_H

#include "Arduino.h"
#include "Config.h"

#define err_length 70

class PID
{
  private:
    float kp, ki, kd;
    float p_gain, i_gain, d_gain;
    int16_t err;
    int16_t angular, linear;
    int16_t err_h[err_length];
    int16_t err_threshold = 70;
    int16_t err_threshold2 = 30;
    int16_t index;

  public:
    PID(float _kp, float _ki, float _kd)
    : kp(_kp), ki(_ki), kd(_kd), 
      err(0), index(0),
      p_gain(0), i_gain(0), d_gain(0)
    {
        for(int i = 0; i < err_length; i++){
            err_h[i] = 0;
        }
    }

    const void load_err(int16_t new_err){
        p_gain = kp * new_err; // calculate p gain
        i_gain += ki * new_err; // integrate i gain
        d_gain = kd * (new_err - err); // calculate the d gain
        err = new_err; // update the error
        i_gain = constrain(i_gain, -255, 255);
        int16_t total_gain = p_gain + i_gain + d_gain;
        angular = total_gain;
        err_h[index] = angular;
        index += 1;
        int angular_sum = sum_angular();
        if(abs(sum_angular()) < err_threshold){
            angular = angular_sum / err_length;
        }
        if(abs(sum_angular()) < err_threshold2){
            angular = 0;
        }
        if(index == err_length){
            index = 0;
        }
        if(angular != 0){
            linear = MAX_ANGULAR_POWER - abs(angular) / 1.5;
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

    int16_t sum_angular(){
        int sum = 0;
        for(int i  = 0; i < err_length; i++){
            sum += err_h[i];
        }
        return sum;
    }
};

#endif
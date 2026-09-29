#ifndef PID_H
#define PID_H

typedef struct
{
    float kp;
    float ki;
    float kd;

    float integral;
    float previous_error;

    float output_min;
    float output_max;

} PID_t;

void PID_Init(PID_t *pid,
              float kp,
              float ki,
              float kd,
              float output_min,
              float output_max);

float PID_Update(PID_t *pid,
                 float setpoint,
                 float measurement,
                 float dt);

void PID_Reset(PID_t *pid);

#endif

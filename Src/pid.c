#include "pid.h"

static float Limit(float value, float min, float max)
{
    if (value > max)
        return max;

    if (value < min)
        return min;

    return value;
}

void PID_Init(PID_t *pid,
              float kp,
              float ki,
              float kd,
              float output_min,
              float output_max)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;

    pid->integral = 0.0f;
    pid->previous_error = 0.0f;

    pid->output_min = output_min;
    pid->output_max = output_max;
}

float PID_Update(PID_t *pid,
                 float setpoint,
                 float measurement,
                 float dt)
{
    float error = setpoint - measurement;

    pid->integral += error * dt;

    float derivative = 0.0f;

    if (dt > 0.0f)
        derivative = (error - pid->previous_error) / dt;

    pid->previous_error = error;

    float output =
        (pid->kp * error) +
        (pid->ki * pid->integral) +
        (pid->kd * derivative);

    return Limit(output, pid->output_min, pid->output_max);
}

void PID_Reset(PID_t *pid)
{
    pid->integral = 0.0f;
    pid->previous_error = 0.0f;
}

#include "balance.h"
#include "config.h"
#include "gyro.h"
#include "motor.h"
#include "pid.h"

static PID_t balance_pid;
static IMU_Data_t imu;

void Balance_Init(void)
{
    PID_Init(
        &balance_pid,
        BALANCE_KP,
        BALANCE_KI,
        BALANCE_KD,
        MOTOR_MIN_OUTPUT,
        MOTOR_MAX_OUTPUT
    );
}

void Balance_Update(float dt)
{
    /*
     * 1. Read IMU
     */
    Gyro_Update(&imu);

    /*
     * 2. Calculate balance correction
     */
    float correction = PID_Update(
        &balance_pid,
        BALANCE_TARGET_ANGLE,
        imu.pitch,
        dt
    );

    /*
     * 3. Apply correction to both motors
     */
    Motor_SetBoth(
        (int)correction,
        (int)correction
    );
}

void Balance_Stop(void)
{
    PID_Reset(&balance_pid);
    Motor_Stop();
}

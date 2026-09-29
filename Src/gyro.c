#include "gyro.h"

/*
 * IMU driver
 *
 * Hardware-specific MPU6050 code goes here.
 * Do not put PID or motor code in this file.
 */

void Gyro_Init(void)
{
    /*
     * TODO:
     * - Initialize I2C
     * - Configure MPU6050
     * - Calibrate gyro
     */
}

void Gyro_Update(IMU_Data_t *imu)
{
    /*
     * TODO:
     * 1. Read accelerometer
     * 2. Read gyroscope
     * 3. Convert raw values
     * 4. Calculate/filter pitch
     */

    imu->pitch = 0.0f;
    imu->roll  = 0.0f;
    imu->yaw   = 0.0f;
}

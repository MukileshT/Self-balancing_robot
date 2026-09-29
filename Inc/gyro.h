#ifndef GYRO_H
#define GYRO_H

typedef struct
{
    float pitch;
    float roll;
    float yaw;

    float gyro_x;
    float gyro_y;
    float gyro_z;

    float accel_x;
    float accel_y;
    float accel_z;

} IMU_Data_t;

void Gyro_Init(void);
void Gyro_Update(IMU_Data_t *imu);

#endif

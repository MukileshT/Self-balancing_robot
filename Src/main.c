/*
 * main.c
 *
 * Application entry point.
 *
 * Hardware initialization is MCU/project specific.
 * Keep robot logic inside the modules:
 *
 * gyro.c     -> IMU
 * pid.c      -> PID controller
 * motor.c    -> motors
 * balance.c  -> balancing logic
 * config.h   -> tunable parameters
 */

#include "config.h"
#include "gyro.h"
#include "motor.h"
#include "balance.h"

int main(void)
{
    /*
     * TODO:
     * Initialize MCU/HAL/peripherals here.
     *
     * Example for STM32:
     *
     * HAL_Init();
     * SystemClock_Config();
     * MX_GPIO_Init();
     * MX_I2C1_Init();
     * MX_TIM1_Init();
     */

    Gyro_Init();
    Motor_Init();
    Balance_Init();

    while (1)
    {
        /*
         * Run this at a fixed period.
         * CONTROL_PERIOD_SEC = 5 ms = 200 Hz.
         *
         * Do not use a random delay for the final controller.
         */
        Balance_Update(CONTROL_PERIOD_SEC);
    }
}

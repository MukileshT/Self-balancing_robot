#include "motor.h"

/*
 * Motor driver
 *
 * Put PWM and direction GPIO code here.
 * Keep hardware details out of balance.c.
 */

void Motor_Init(void)
{
    /*
     * TODO:
     * - Configure PWM
     * - Configure direction pins
     */
}

void Motor_SetLeft(int speed)
{
    /*
     * TODO:
     * Convert signed speed to direction + PWM.
     */
    (void)speed;
}

void Motor_SetRight(int speed)
{
    /*
     * TODO:
     * Convert signed speed to direction + PWM.
     */
    (void)speed;
}

void Motor_SetBoth(int left, int right)
{
    Motor_SetLeft(left);
    Motor_SetRight(right);
}

void Motor_Stop(void)
{
    Motor_SetBoth(0, 0);
}

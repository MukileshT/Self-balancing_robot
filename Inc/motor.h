#ifndef MOTOR_H
#define MOTOR_H

void Motor_Init(void);

void Motor_SetLeft(int speed);
void Motor_SetRight(int speed);
void Motor_SetBoth(int left, int right);

void Motor_Stop(void);

#endif

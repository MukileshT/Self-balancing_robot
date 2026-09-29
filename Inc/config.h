#ifndef CONFIG_H
#define CONFIG_H

/* Control loop */
#define CONTROL_PERIOD_SEC    0.005f

/* Balance target */
#define BALANCE_TARGET_ANGLE  0.0f

/* PID gains - tune these */
#define BALANCE_KP             20.0f
#define BALANCE_KI              0.0f
#define BALANCE_KD              0.5f

/* Motor output limits */
#define MOTOR_MIN_OUTPUT    -1000
#define MOTOR_MAX_OUTPUT     1000

#endif

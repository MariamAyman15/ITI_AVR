
#ifndef HAL_STEPPER_MOTOR_STEP_MOTOR_INT_H_
#define HAL_STEPPER_MOTOR_STEP_MOTOR_INT_H_

#define HStepMotor_Initial 0
#define HStepMotor_Total 512

void HStepMotor_voidinit (void);
void HStepMotor_voidFullStepCW (void);
void HStepMotor_voidFullStepACW (void);
void HStepMotor_voidSpecificDegreeCW (u16 Copy_u16Degree);
void HStepMotor_voidSpecificDegreeACW (u16 Copy_u16Degree);
#endif /* HAL_STEPPER_MOTOR_STEP_MOTOR_INT_H_ */

/*
 * flightController_private.h
 *
 * Code generation for model "flightController".
 *
 * Model version              : 1.260
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Mon Nov  4 15:17:41 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flightController_private_h_
#define RTW_HEADER_flightController_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const real32_T rtCP_pooled_AiPFoGkd3zrs[16];
extern const real32_T rtCP_pooled_oEBofkCxx3u4[4];

#define rtCP_TorqueTotalThrustToThrustPerMotor_Value rtCP_pooled_AiPFoGkd3zrs/* Computed Parameter: rtCP_TorqueTotalThrustToThrustPerMotor_Value
                                                                      * Referenced by: '<S3>/TorqueTotalThrustToThrustPerMotor'
                                                                      */
#define rtCP_MotorDirections_Gain      rtCP_pooled_oEBofkCxx3u4  /* Computed Parameter: rtCP_MotorDirections_Gain
                                                                  * Referenced by: '<S7>/MotorDirections'
                                                                  */
#endif                                 /* RTW_HEADER_flightController_private_h_ */

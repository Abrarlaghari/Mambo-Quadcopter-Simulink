/*
 * File: stateEstimator_private.h
 *
 * Code generated for Simulink model 'stateEstimator'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Mar 19 23:38:34 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_stateEstimator_private_h_
#define RTW_HEADER_stateEstimator_private_h_
#include "rtwtypes.h"

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

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

extern P_stateEstimator_T stateEstimator_P_g;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/
#endif                                 /* RTW_HEADER_stateEstimator_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

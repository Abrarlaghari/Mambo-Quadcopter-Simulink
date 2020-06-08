/*
 * File: flightController_private.h
 *
 * Code generated for Simulink model 'flightController'.
 *
 * Model version                  : 1.311
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 21 14:05:17 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flightController_private_h_
#define RTW_HEADER_flightController_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

extern real32_T rt_powf_snf(real32_T u0, real32_T u1);

#endif                                 /* RTW_HEADER_flightController_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

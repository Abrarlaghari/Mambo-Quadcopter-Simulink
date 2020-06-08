/*
 * flightController_types.h
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

#ifndef RTW_HEADER_flightController_types_h_
#define RTW_HEADER_flightController_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_CommandBus_
#define DEFINED_TYPEDEF_FOR_CommandBus_

typedef struct {
  boolean_T controlModePosVSOrient;
  real32_T pos_ref[3];
  boolean_T takeoff_flag;
  real32_T orient_ref[3];
  uint32_T live_time_ticks;
} CommandBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_statesEstim_t_
#define DEFINED_TYPEDEF_FOR_statesEstim_t_

typedef struct {
  real32_T X;
  real32_T Y;
  real32_T Z;
  real32_T yaw;
  real32_T pitch;
  real32_T roll;
  real32_T dx;
  real32_T dy;
  real32_T dz;
  real32_T p;
  real32_T q;
  real32_T r;
} statesEstim_t;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_flightController_T RT_MODEL_flightController_T;

#endif                                 /* RTW_HEADER_flightController_types_h_ */

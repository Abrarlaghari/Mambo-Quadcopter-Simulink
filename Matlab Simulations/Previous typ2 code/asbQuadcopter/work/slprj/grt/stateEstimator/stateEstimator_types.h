/*
 * stateEstimator_types.h
 *
 * Code generation for model "stateEstimator".
 *
 * Model version              : 1.42
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Mon Nov  4 15:18:19 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_stateEstimator_types_h_
#define RTW_HEADER_stateEstimator_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_sensordata_t_
#define DEFINED_TYPEDEF_FOR_sensordata_t_

typedef struct {
  real32_T ddx;
  real32_T ddy;
  real32_T ddz;
  real32_T p;
  real32_T q;
  real32_T r;
  real32_T altitude_sonar;
  real32_T prs;
  real32_T vbat_V;
  uint32_T vbat_percentage;
} sensordata_t;

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
typedef struct tag_RTM_stateEstimator_T RT_MODEL_stateEstimator_T;

#endif                                 /* RTW_HEADER_stateEstimator_types_h_ */

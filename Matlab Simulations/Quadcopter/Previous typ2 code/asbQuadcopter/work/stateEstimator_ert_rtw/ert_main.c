/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'stateEstimator'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Nov 14 23:57:43 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stateEstimator.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* '<Root>/controlModePosVSOrient_flagin' */
  static boolean_T arg_controlModePosVSOrient_flagin = false;

  /* '<Root>/sensordata_datin' */
  static sensordata_t arg_sensordata_datin = {
    0.0F,                              /* ddx */
    0.0F,                              /* ddy */
    0.0F,                              /* ddz */
    0.0F,                              /* p */
    0.0F,                              /* q */
    0.0F,                              /* r */
    0.0F,                              /* altitude_sonar */
    0.0F,                              /* prs */
    0.0F,                              /* vbat_V */
    0U                                 /* vbat_percentage */
  } ;

  /* '<Root>/usePosVIS_flagin' */
  static real32_T arg_usePosVIS_flagin = 0.0F;

  /* '<Root>/opticalFlow_datin' */
  static real32_T arg_opticalFlow_datin[3] = { 0.0F, 0.0F, 0.0F };

  /* '<Root>/posVIS_datin' */
  static real32_T arg_posVIS_datin[4] = { 0.0F, 0.0F, 0.0F, 0.0F };

  /* '<Root>/sensorCalibration_datin' */
  static real32_T arg_sensorCalibration_datin[8] = { 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F };

  /* '<Root>/states_estimout' */
  static statesEstim_t arg_states_estimout;

  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  stateEstimator_run(arg_controlModePosVSOrient_flagin, &arg_sensordata_datin,
                     arg_usePosVIS_flagin, arg_opticalFlow_datin,
                     arg_posVIS_datin, &arg_states_estimout,
                     arg_sensorCalibration_datin);

  /* Get model outputs here */
  OverrunFlag--;
}

#define UNUSED(x)                      x = x

volatile boolean_T stopRequested = false;
int main(void)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 0.005;
  float systemClock = 416;
  UNUSED(modelBaseRate);
  UNUSED(systemClock);
  rtmSetErrorStatus(stateEstimator_M, 0);
  stateEstimator_initialize();
  runModel =
    rtmGetErrorStatus(stateEstimator_M) == (NULL);
  ;
  while (runModel) {
    rt_OneStep();
    stopRequested = !(
                      rtmGetErrorStatus(stateEstimator_M) == (NULL));
    runModel = !(stopRequested);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  stateEstimator_terminate();
  ;
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

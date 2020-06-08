/*
 * File: ert_main.c
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

#include "flightController.h"
#include "rtwtypes.h"
#include "rt_logging.h"
#define QUOTE1(name)                   #name
#define QUOTE(name)                    QUOTE1(name)              /* need to expand name */
#ifndef SAVEFILE
# define MATFILE2(file)                #file ".mat"
# define MATFILE1(file)                MATFILE2(file)
# define MATFILE                       MATFILE1(MODEL)
#else
# define MATFILE                       QUOTE(SAVEFILE)
#endif

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* '<Root>/ReferenceValueServerBus' */
  static CommandBus arg_ReferenceValueServerBus = {
    false,                             /* controlModePosVSOrient */

    {
      0.0F, 0.0F, 0.0F }
    ,                                  /* pos_ref */
    false,                             /* takeoff_flag */

    {
      0.0F, 0.0F, 0.0F }
    ,                                  /* orient_ref */
    0U                                 /* live_time_ticks */
  } ;

  /* '<Root>/states_estim' */
  static statesEstim_t arg_states_estim = {
    0.0F,                              /* X */
    0.0F,                              /* Y */
    0.0F,                              /* Z */
    0.0F,                              /* yaw */
    0.0F,                              /* pitch */
    0.0F,                              /* roll */
    0.0F,                              /* dx */
    0.0F,                              /* dy */
    0.0F,                              /* dz */
    0.0F,                              /* p */
    0.0F,                              /* q */
    0.0F                               /* r */
  } ;

  /* '<Root>/motors_refout' */
  static real32_T arg_motors_refout[4];

  /* '<Root>/pose_refout' */
  static real32_T arg_pose_refout[8];

  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  flightController_run(&arg_ReferenceValueServerBus, &arg_states_estim,
                       arg_motors_refout, arg_pose_refout);

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
  rtmSetErrorStatus(flightController_M, 0);
  flightController_initialize();
  runModel =
    rtmGetErrorStatus(flightController_M) == (NULL);
  ;
  while (runModel) {
    rt_OneStep();
    stopRequested = !(
                      rtmGetErrorStatus(flightController_M) == (NULL));
    runModel = !(stopRequested);
  }

  rt_StopDataLogging(MATFILE, flightController_M->rtwLogInfo);

  /* Disable rt_OneStep() here */

  /* Terminate model */
  flightController_terminate();
  ;
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

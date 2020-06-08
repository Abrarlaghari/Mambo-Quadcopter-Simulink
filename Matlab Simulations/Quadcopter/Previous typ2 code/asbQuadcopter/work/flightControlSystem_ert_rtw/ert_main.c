/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'flightControlSystem'.
 *
 * Model version                  : 1.157
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 19:07:35 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flightControlSystem.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  flightControlSystem_step();

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
  rtmSetErrorStatus(flightControlSystem_M, 0);
  flightControlSystem_initialize();
  runModel =
    rtmGetErrorStatus(flightControlSystem_M) == (NULL);
  ;
  while (runModel) {
    rt_OneStep();
    stopRequested = !(
                      rtmGetErrorStatus(flightControlSystem_M) == (NULL));
    runModel = !(stopRequested);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  flightControlSystem_terminate();
  ;
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

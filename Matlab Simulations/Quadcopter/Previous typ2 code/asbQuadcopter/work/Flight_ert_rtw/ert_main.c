/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'Flight'.
 *
 * Model version                  : 1.143
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Nov 15 00:06:37 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Flight.h"
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

  Flight_step();

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
  rtmSetErrorStatus(Flight_M, 0);
  Flight_initialize();
  runModel =
    rtmGetErrorStatus(Flight_M) == (NULL);
  ;
  while (runModel) {
    rt_OneStep();
    stopRequested = !(
                      rtmGetErrorStatus(Flight_M) == (NULL));
    runModel = !(stopRequested);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  Flight_terminate();
  ;
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

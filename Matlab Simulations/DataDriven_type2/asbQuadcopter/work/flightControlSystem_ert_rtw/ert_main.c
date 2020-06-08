/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'flightControlSystem'.
 *
 * Model version                  : 1.168
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 13:04:25 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flightControlSystem.h"
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

  rt_StopDataLogging(MATFILE, flightControlSystem_M->rtwLogInfo);

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

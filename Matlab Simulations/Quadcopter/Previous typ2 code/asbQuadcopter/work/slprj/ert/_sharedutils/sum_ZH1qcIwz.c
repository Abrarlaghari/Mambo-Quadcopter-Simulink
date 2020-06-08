/*
 * File: sum_ZH1qcIwz.c
 *
 * Code generated for Simulink model 'flightController'.
 *
 * Model version                  : 1.358
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Mar 17 15:32:07 2020
 */

#include "rtwtypes.h"
#include "sum_ZH1qcIwz.h"

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
real_T sum_ZH1qcIwz(const real_T x[26])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 25; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

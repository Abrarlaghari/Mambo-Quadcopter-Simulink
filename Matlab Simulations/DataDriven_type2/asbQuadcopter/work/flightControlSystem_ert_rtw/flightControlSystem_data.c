/*
 * File: flightControlSystem_data.c
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
#include "flightControlSystem_private.h"

/* Model block global parameters (default storage) */
struct_pAcs5k38eV6MpgiqrKAV4 rtP_Sensors = {
  { 1.00596, 1.00383, 0.99454 },

  { 0.99861, 1.00644, 0.99997 },

  {
    { 0.0, 0.0, 0.0 },

    { 0.0, 0.0, 0.0 },
    190.0,
    0.707,

    { 1.00596, 0.0, 0.0, 0.0, 1.00383, 0.0, 0.0, 0.0, 0.99454 },

    { 0.09, -0.06, 0.33699999999999974 },

    { -50.0, -50.0, -50.0, 50.0, 50.0, 50.0 },
    190.0,
    0.707,

    { 0.99861, 0.0, 0.0, 0.0, 1.00644, 0.0, 0.0, 0.0, 0.99997 },

    { -0.0095, -0.0075, 0.0015 },

    { 0.0, 0.0, 0.0 },

    { -10.0, -10.0, -10.0, 10.0, 10.0, 10.0 },

    { 41.0, 41.0, 41.0, 41.0, 41.0, 41.0 },

    { 0.8, 0.8, 0.8, 0.025, 0.025, 0.025 },

    { 0.00021831529882618725, 0.00018641345254680647, 0.00037251068300213613,
      1.0651514622688397e-8, 1.3021327403798377e-8, 1.1929474437781302e-8 }
  },

  {
    1.0,
    41.0
  },
  -99.0,
  -9.0,

  {
    { -99.0, 0.0, 0.0, -9.0 },
    0.0,

    { 3.5, 70.0 }
  },
  1.0,
  1.225,
  12.01725,
  101270.95,

  { 0.99407531114557246, 0.99618461293246863, 1.0054899752649467,
    1.0013919347893572, 0.99360120821906917, 1.0000300009000269 },
  0.44,
  1.0,

  { 160.0, 120.0 }
} ;                                    /* Variable: Sensors
                                        * Referenced by: '<S1>/estimator'
                                        */

/* Block parameters (default storage) */
P_flightControlSystem_T flightControlSystem_P = {
  /* Start of '<Root>/Flight Control System' */
  {
    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S6>/Constant'
     */
    10.0F,

    /* Mask Parameter: CompareToConstant1_const
     * Referenced by: '<S7>/Constant'
     */
    10.0F,

    /* Mask Parameter: CompareToConstant2_const
     * Referenced by: '<S8>/Constant'
     */
    6.0F,

    /* Mask Parameter: CompareToConstant4_const
     * Referenced by: '<S10>/Constant'
     */
    0.01F,

    /* Mask Parameter: CompareToConstant3_const
     * Referenced by: '<S9>/Constant'
     */
    6.0F,

    /* Mask Parameter: CompareToConstant5_const
     * Referenced by: '<S11>/Constant'
     */
    0.01F,

    /* Expression: 0
     * Referenced by: '<S15>/Step'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S15>/Step'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S15>/Step'
     */
    0.0,

    /* Expression: 40
     * Referenced by: '<S15>/Step1'
     */
    40.0,

    /* Expression: 0
     * Referenced by: '<S15>/Step1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S15>/Step1'
     */
    0.0,

    /* Expression: 60
     * Referenced by: '<S15>/Step2'
     */
    60.0,

    /* Expression: 0
     * Referenced by: '<S15>/Step2'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S15>/Step2'
     */
    -1.0,

    /* Computed Parameter: Constant6_Value
     * Referenced by: '<S15>/Constant6'
     */
    1.0F,

    /* Computed Parameter: Constant2_Value
     * Referenced by: '<S15>/Constant2'
     */
    { 0.0F, 0.0F, -1.0F },

    /* Computed Parameter: Constant3_Value
     * Referenced by: '<S4>/Constant3'
     */
    { 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: Gain_Gain
     * Referenced by: '<S2>/Gain'
     */
    1.0F,

    /* Computed Parameter: Gain1_Gain
     * Referenced by: '<S2>/Gain1'
     */
    1.0F,

    /* Computed Parameter: Constant5_Value
     * Referenced by: '<S4>/Constant5'
     */
    0U,

    /* Expression: true
     * Referenced by: '<S4>/Constant1'
     */
    1,

    /* Computed Parameter: Constant6_Value_m
     * Referenced by: '<S4>/Constant6'
     */
    0,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S2>/Merge'
     */
    0U,

    /* Start of '<S2>/Normal condition' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S13>/Constant'
       */
      0U
    }
    ,

    /* End of '<S2>/Normal condition' */

    /* Start of '<S2>/estimator//Optical flow error' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S14>/Constant'
       */
      99U
    }
    ,

    /* End of '<S2>/estimator//Optical flow error' */

    /* Start of '<S2>/Geofencing error' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S12>/Constant'
       */
      1U
    }
    /* End of '<S2>/Geofencing error' */
  }
  /* End of '<Root>/Flight Control System' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

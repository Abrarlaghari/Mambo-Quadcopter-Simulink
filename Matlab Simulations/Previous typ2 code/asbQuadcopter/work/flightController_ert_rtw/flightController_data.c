/*
 * File: flightController_data.c
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
#include "flightController_private.h"

/* Block parameters (default storage) */
P_flightController_T flightController_P = {
  /* Expression: Controller.Q2Ts
   * Referenced by: '<S3>/TorqueTotalThrustToThrustPerMotor'
   */
  { 0.25F, 0.25F, 0.25F, 0.25F, 103.573624F, -103.573624F, 103.573624F,
    -103.573624F, -5.66592F, -5.66592F, 5.66592F, 5.66592F, -5.66592F, 5.66592F,
    5.66592F, -5.66592F },

  /* Computed Parameter: w0_Value
   * Referenced by: '<S2>/w0'
   */
  -0.61803F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S2>/Gain3'
   */
  1.15F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S2>/Gain'
   */
  -1.0F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S2>/Gain1'
   */
  -1.0F,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S2>/Gain2'
   */
  -1.0F,

  /* Computed Parameter: SaturationThrust_UpperSat
   * Referenced by: '<S2>/SaturationThrust'
   */
  1.20204329F,

  /* Computed Parameter: SaturationThrust_LowerSat
   * Referenced by: '<S2>/SaturationThrust'
   */
  -1.20204329F,

  /* Computed Parameter: P_yaw_Gain
   * Referenced by: '<S10>/P_yaw'
   */
  0.004F,

  /* Computed Parameter: D_yaw_Gain
   * Referenced by: '<S10>/D_yaw'
   */
  0.0012F,

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<S9>/Gain'
   */
  -1.0F,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S9>/Saturation'
   */
  3.0F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S9>/Saturation'
   */
  -3.0F,

  /* Computed Parameter: P_xy_Gain
   * Referenced by: '<S9>/P_xy'
   */
  { -0.24F, 0.24F },

  /* Computed Parameter: D_xy_Gain
   * Referenced by: '<S9>/D_xy'
   */
  { 0.1F, -0.1F },

  /* Computed Parameter: P_pr_Gain
   * Referenced by: '<S4>/P_pr'
   */
  { 0.013F, 0.01F },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0.005F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  2.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  -2.0F,

  /* Computed Parameter: I_pr_Gain
   * Referenced by: '<S4>/I_pr'
   */
  0.01F,

  /* Computed Parameter: D_pr_Gain
   * Referenced by: '<S4>/D_pr'
   */
  { 0.002F, 0.0028F },

  /* Computed Parameter: ThrustToMotorCommand_Gain
   * Referenced by: '<S7>/ThrustToMotorCommand'
   */
  -1530.72681F,

  /* Expression: Vehicle.Motor.maxLimit
   * Referenced by: '<S7>/Saturation5'
   */
  500.0F,

  /* Expression: Vehicle.Motor.minLimit
   * Referenced by: '<S7>/Saturation5'
   */
  10.0F,

  /* Computed Parameter: MotorDirections_Gain
   * Referenced by: '<S7>/MotorDirections'
   */
  { 1.0F, -1.0F, 1.0F, -1.0F },

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S4>/Delay'
   */
  0.0F,

  /* Computed Parameter: antiWU_Gain_Gain
   * Referenced by: '<S4>/antiWU_Gain'
   */
  0.001F,

  /* Computed Parameter: Delay_DelayLength
   * Referenced by: '<S4>/Delay'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

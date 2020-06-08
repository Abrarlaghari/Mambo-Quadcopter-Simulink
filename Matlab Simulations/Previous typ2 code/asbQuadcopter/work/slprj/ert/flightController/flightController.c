/*
 * File: flightController.c
 *
 * Code generated for Simulink model 'flightController'.
 *
 * Model version                  : 1.314
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Mar 26 01:54:47 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flightController.h"
#include "flightController_private.h"
#include "rt_powf_snf.h"

P_flightController_T flightController_P_g = {
  /* Expression: Controller.Q2Ts
   * Referenced by: '<S3>/TorqueTotalThrustToThrustPerMotor'
   */
  { 0.25F, 0.25F, 0.25F, 0.25F, 103.573624F, -103.573624F, 103.573624F,
    -103.573624F, -5.66592F, -5.66592F, 5.66592F, 5.66592F, -5.66592F, 5.66592F,
    5.66592F, -5.66592F },

  /* Computed Parameter: Gain_Gain
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

  /* Computed Parameter: Gain_Gain_e
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

  /* Computed Parameter: w0_Value
   * Referenced by: '<S2>/w0'
   */
  -0.61803F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S2>/Gain3'
   */
  1.0F,

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

MdlrefDW_flightController_T flightController_MdlrefDW;

/* Block signals (default storage) */
B_flightController_c_T flightController_B;

/* Block states (default storage) */
DW_flightController_f_T flightController_DW;

/* System initialize for referenced model: 'flightController' */
void flightController_Init(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
    flightController_P_g.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[0] =
    flightController_P_g.Delay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
    flightController_P_g.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[1] =
    flightController_P_g.Delay_InitialCondition;
}

/* Output and update for referenced model: 'flightController' */
void flightController_run(const CommandBus *arg_ReferenceValueServerBus, const
  statesEstim_t *arg_states_estim, real32_T arg_motors_refout[4], real32_T
  arg_pose_refout[8])
{
  real32_T DEN;
  real32_T G11L;
  real32_T G21U;
  real32_T G21L;
  real32_T G31U;
  real32_T G12U;
  real32_T G12L;
  real32_T G32U;
  real32_T G32L;
  real32_T RNL;
  real32_T rtb_SaturationThrust;
  real32_T rtb_D_yaw;
  int32_T i;
  real32_T rtb_pitchrollerror_idx_0;

  /* Trigonometry: '<S9>/Trigonometric Function' */
  rtb_D_yaw = (real32_T)sin(arg_states_estim->yaw);
  rtb_SaturationThrust = (real32_T)cos(arg_states_estim->yaw);

  /* Sum: '<S9>/Sum17' */
  G11L = arg_ReferenceValueServerBus->pos_ref[0] - arg_states_estim->X;
  G21U = arg_ReferenceValueServerBus->pos_ref[1] - arg_states_estim->Y;

  /* Product: '<S9>/Product' incorporates:
   *  SignalConversion: '<S9>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S9>/ConcatBufferAtVector ConcatenateIn1'
   */
  G21L = rtb_SaturationThrust * G11L + rtb_D_yaw * G21U;

  /* Saturate: '<S9>/Saturation' */
  if (G21L > flightController_P_g.Saturation_UpperSat) {
    G21L = flightController_P_g.Saturation_UpperSat;
  } else {
    if (G21L < flightController_P_g.Saturation_LowerSat) {
      G21L = flightController_P_g.Saturation_LowerSat;
    }
  }

  /* Sum: '<S9>/Sum18' incorporates:
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   */
  rtb_pitchrollerror_idx_0 = flightController_P_g.P_xy_Gain[0] * G21L +
    flightController_P_g.D_xy_Gain[0] * arg_states_estim->dx;

  /* Product: '<S9>/Product' incorporates:
   *  Gain: '<S9>/Gain'
   *  SignalConversion: '<S9>/ConcatBufferAtVector Concatenate1In2'
   */
  G21L = flightController_P_g.Gain_Gain * rtb_D_yaw * G11L +
    rtb_SaturationThrust * G21U;

  /* Saturate: '<S9>/Saturation' */
  if (G21L > flightController_P_g.Saturation_UpperSat) {
    G21L = flightController_P_g.Saturation_UpperSat;
  } else {
    if (G21L < flightController_P_g.Saturation_LowerSat) {
      G21L = flightController_P_g.Saturation_LowerSat;
    }
  }

  /* Sum: '<S9>/Sum18' incorporates:
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   */
  rtb_D_yaw = flightController_P_g.P_xy_Gain[1] * G21L +
    flightController_P_g.D_xy_Gain[1] * arg_states_estim->dy;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtpose_refoutInport1' incorporates:
   *  SignalConversion: '<S1>/ReferenceValueServerBus_BusSelector'
   */
  arg_pose_refout[0] = arg_ReferenceValueServerBus->pos_ref[0];
  arg_pose_refout[3] = arg_ReferenceValueServerBus->orient_ref[0];
  arg_pose_refout[1] = arg_ReferenceValueServerBus->pos_ref[1];
  arg_pose_refout[4] = arg_ReferenceValueServerBus->orient_ref[1];
  arg_pose_refout[2] = arg_ReferenceValueServerBus->pos_ref[2];
  arg_pose_refout[5] = arg_ReferenceValueServerBus->orient_ref[2];

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Sum: '<S2>/Sum3'
   */
  flightController_B.EN = ((arg_ReferenceValueServerBus->pos_ref[2] -
    arg_states_estim->Z) * flightController_P_g.Gain_Gain_e - -1.1F) / 2.2F;
  DEN = (flightController_P_g.Gain1_Gain * arg_states_estim->dz - -2.0F) / 4.0F;
  G11L = 1.0F / ((real32_T)exp(100.0F * flightController_B.EN) + 1.0F);
  G21U = 1.0F / ((real32_T)exp(-100.0F * flightController_B.EN) + 1.0F);
  rtb_SaturationThrust = 1.0F / ((rt_powf_snf((real32_T)fabs(G11L *
    (flightController_B.EN / 0.5F)), 4.0F) * 4.0F + 1.0F) + rt_powf_snf
    ((real32_T)fabs(G21U * (flightController_B.EN / 0.5F)), 4.0F) * 4.0F);
  G11L = 1.0F / ((rt_powf_snf((real32_T)fabs(G11L * (flightController_B.EN /
    0.4F)), 4.0F) * 4.0F + 1.0F) + rt_powf_snf((real32_T)fabs(G21U *
    (flightController_B.EN / 0.4F)), 4.0F) * 4.0F);
  G21U = (flightController_B.EN - 0.5F) / 0.5F;
  G21L = 1.0F / ((real32_T)exp((flightController_B.EN - 0.5F) * 100.0F) + 1.0F);
  G31U = 1.0F / ((real32_T)exp((flightController_B.EN - 0.5F) * -100.0F) + 1.0F);
  G21U = 1.0F / ((rt_powf_snf((real32_T)fabs(G21L * G21U), 4.0F) * 4.0F + 1.0F)
                 + rt_powf_snf((real32_T)fabs(G31U * G21U), 4.0F) * 4.0F);
  G12L = (flightController_B.EN - 0.5F) / 0.4F;
  G21L = 1.0F / ((rt_powf_snf((real32_T)fabs(G21L * G12L), 4.0F) * 4.0F + 1.0F)
                 + rt_powf_snf((real32_T)fabs(G31U * G12L), 4.0F) * 4.0F);
  G31U = (flightController_B.EN - 1.0F) / 0.5F;
  G12L = 1.0F / ((real32_T)exp((flightController_B.EN - 1.0F) * 100.0F) + 1.0F);
  G12U = 1.0F / ((real32_T)exp((flightController_B.EN - 1.0F) * -100.0F) + 1.0F);
  G31U = 1.0F / ((rt_powf_snf((real32_T)fabs(G12L * G31U), 4.0F) * 4.0F + 1.0F)
                 + rt_powf_snf((real32_T)fabs(G12U * G31U), 4.0F) * 4.0F);
  flightController_B.EN = (flightController_B.EN - 1.0F) / 0.4F;
  flightController_B.EN = 1.0F / ((rt_powf_snf((real32_T)fabs(G12L *
    flightController_B.EN), 4.0F) * 4.0F + 1.0F) + rt_powf_snf((real32_T)fabs
    (G12U * flightController_B.EN), 4.0F) * 4.0F);
  G12L = 1.0F / ((real32_T)exp(100.0F * DEN) + 1.0F);
  G32U = 1.0F / ((real32_T)exp(-100.0F * DEN) + 1.0F);
  G12U = 1.0F / ((rt_powf_snf((real32_T)fabs(G12L * (DEN / 0.5F)), 4.0F) * 4.0F
                  + 1.0F) + rt_powf_snf((real32_T)fabs(G32U * (DEN / 0.5F)),
    4.0F) * 4.0F);
  G12L = 1.0F / ((rt_powf_snf((real32_T)fabs(G12L * (DEN / 0.4F)), 4.0F) * 4.0F
                  + 1.0F) + rt_powf_snf((real32_T)fabs(G32U * (DEN / 0.4F)),
    4.0F) * 4.0F);
  G32U = (DEN - 1.0F) / 0.5F;
  G32L = 1.0F / ((real32_T)exp((DEN - 1.0F) * 100.0F) + 1.0F);
  RNL = 1.0F / ((real32_T)exp((DEN - 1.0F) * -100.0F) + 1.0F);
  G32U = 1.0F / ((rt_powf_snf((real32_T)fabs(G32L * G32U), 4.0F) * 4.0F + 1.0F)
                 + rt_powf_snf((real32_T)fabs(RNL * G32U), 4.0F) * 4.0F);
  DEN = (DEN - 1.0F) / 0.4F;
  G32L = 1.0F / ((rt_powf_snf((real32_T)fabs(G32L * DEN), 4.0F) * 4.0F + 1.0F) +
                 rt_powf_snf((real32_T)fabs(RNL * DEN), 4.0F) * 4.0F);
  RNL = (1.0F - G21U) / G21U;
  DEN = 1.0F / (RNL + (1.0F - G32U) / G32U);
  G12U = 1.0F / (RNL + (1.0F - G12U) / G12U);
  RNL = (1.0F - G21L) / G21L;
  G32U = 1.0F / (RNL + (1.0F - G32L) / G32L);
  G12L = 1.0F / (RNL + (1.0F - G12L) / G12L);
  G32L = (((G31U + rtb_SaturationThrust) + G21U) + DEN) + G12U;
  RNL = (((flightController_B.EN + G11L) + G21L) + G32U) + G12L;

  /* Sum: '<S2>/Sum4' incorporates:
   *  Constant: '<S2>/w0'
   *  Gain: '<S2>/Gain2'
   *  Gain: '<S2>/Gain3'
   *  MATLAB Function: '<S2>/MATLAB Function'
   */
  rtb_SaturationThrust = (((((G31U / G32L * 0.9F + rtb_SaturationThrust / G32L *
    -0.95F) + G21U / G32L * 0.0F) + DEN / G32L * -0.7F) + G12U / G32L * 0.7F) +
    ((((flightController_B.EN / RNL * 0.9F + G11L / RNL * -0.95F) + G21L / RNL *
       0.0F) + G32U / RNL * -0.7F) + G12L / RNL * 0.7F)) / 2.0F *
    flightController_P_g.Gain2_Gain + flightController_P_g.Gain3_Gain *
    flightController_P_g.w0_Value;

  /* Saturate: '<S2>/SaturationThrust' */
  if (rtb_SaturationThrust > flightController_P_g.SaturationThrust_UpperSat) {
    rtb_SaturationThrust = flightController_P_g.SaturationThrust_UpperSat;
  } else {
    if (rtb_SaturationThrust < flightController_P_g.SaturationThrust_LowerSat) {
      rtb_SaturationThrust = flightController_P_g.SaturationThrust_LowerSat;
    }
  }

  /* SignalConversion: '<S3>/TmpSignal ConversionAtProductInport2' incorporates:
   *  Gain: '<S10>/D_yaw'
   *  Gain: '<S10>/P_yaw'
   *  Sum: '<S10>/Sum1'
   *  Sum: '<S10>/Sum2'
   */
  G11L = (arg_ReferenceValueServerBus->orient_ref[0] - arg_states_estim->yaw) *
    flightController_P_g.P_yaw_Gain - flightController_P_g.D_yaw_Gain *
    arg_states_estim->r;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtpose_refoutInport1' */
  arg_pose_refout[6] = rtb_pitchrollerror_idx_0;

  /* Sum: '<S4>/Sum19' incorporates:
   *  SignalConversion: '<Root>/TmpSignal ConversionAtpose_refoutInport1'
   */
  G21U = rtb_pitchrollerror_idx_0 - arg_states_estim->pitch;

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  G21L = flightController_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* SignalConversion: '<S3>/TmpSignal ConversionAtProductInport2' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Gain: '<S4>/D_pr'
   *  Gain: '<S4>/I_pr'
   *  Gain: '<S4>/P_pr'
   *  Sum: '<S4>/Sum16'
   */
  G31U = (flightController_P_g.P_pr_Gain[0] * G21U +
          flightController_P_g.I_pr_Gain *
          flightController_DW.DiscreteTimeIntegrator_DSTATE[0]) -
    flightController_P_g.D_pr_Gain[0] * arg_states_estim->q;

  /* Sum: '<S4>/Sum19' */
  rtb_pitchrollerror_idx_0 = G21U;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtpose_refoutInport1' */
  arg_pose_refout[7] = rtb_D_yaw;

  /* Sum: '<S4>/Sum19' incorporates:
   *  SignalConversion: '<Root>/TmpSignal ConversionAtpose_refoutInport1'
   */
  G21U = rtb_D_yaw - arg_states_estim->roll;

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  rtb_D_yaw = flightController_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* SignalConversion: '<S3>/TmpSignal ConversionAtProductInport2' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Gain: '<S4>/D_pr'
   *  Gain: '<S4>/I_pr'
   *  Gain: '<S4>/P_pr'
   *  Sum: '<S4>/Sum16'
   */
  DEN = (flightController_P_g.P_pr_Gain[1] * G21U +
         flightController_P_g.I_pr_Gain *
         flightController_DW.DiscreteTimeIntegrator_DSTATE[1]) -
    flightController_P_g.D_pr_Gain[1] * arg_states_estim->p;
  for (i = 0; i < 4; i++) {
    /* Product: '<S3>/Product' incorporates:
     *  Constant: '<S3>/TorqueTotalThrustToThrustPerMotor'
     *  Saturate: '<S2>/SaturationThrust'
     *  SignalConversion: '<S3>/TmpSignal ConversionAtProductInport2'
     */
    flightController_B.EN =
      flightController_P_g.TorqueTotalThrustToThrustPerMotor_Value[i + 12] * DEN
      + (flightController_P_g.TorqueTotalThrustToThrustPerMotor_Value[i + 8] *
         G31U + (flightController_P_g.TorqueTotalThrustToThrustPerMotor_Value[i
                 + 4] * G11L +
                 flightController_P_g.TorqueTotalThrustToThrustPerMotor_Value[i]
                 * rtb_SaturationThrust));

    /* Saturate: '<S7>/Saturation5' incorporates:
     *  Gain: '<S7>/ThrustToMotorCommand'
     */
    flightController_B.EN *= flightController_P_g.ThrustToMotorCommand_Gain;
    if (flightController_B.EN > flightController_P_g.Saturation5_UpperSat) {
      flightController_B.EN = flightController_P_g.Saturation5_UpperSat;
    } else {
      if (flightController_B.EN < flightController_P_g.Saturation5_LowerSat) {
        flightController_B.EN = flightController_P_g.Saturation5_LowerSat;
      }
    }

    /* End of Saturate: '<S7>/Saturation5' */

    /* Gain: '<S7>/MotorDirections' */
    arg_motors_refout[i] = flightController_P_g.MotorDirections_Gain[i] *
      flightController_B.EN;
  }

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S4>/Delay'
   *  Gain: '<S4>/antiWU_Gain'
   *  Sum: '<S4>/Add'
   */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] +=
    (rtb_pitchrollerror_idx_0 - flightController_P_g.antiWU_Gain_Gain *
     flightController_DW.Delay_DSTATE[0]) *
    flightController_P_g.DiscreteTimeIntegrator_gainval;
  if (flightController_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      flightController_P_g.DiscreteTimeIntegrator_UpperSat) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
      flightController_P_g.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (flightController_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        flightController_P_g.DiscreteTimeIntegrator_LowerSat) {
      flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
        flightController_P_g.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* Update for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[0] = G21L;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S4>/Delay'
   *  Gain: '<S4>/antiWU_Gain'
   *  Sum: '<S4>/Add'
   */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] += (G21U -
    flightController_P_g.antiWU_Gain_Gain * flightController_DW.Delay_DSTATE[1])
    * flightController_P_g.DiscreteTimeIntegrator_gainval;
  if (flightController_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      flightController_P_g.DiscreteTimeIntegrator_UpperSat) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
      flightController_P_g.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (flightController_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        flightController_P_g.DiscreteTimeIntegrator_LowerSat) {
      flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
        flightController_P_g.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* Update for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[1] = rtb_D_yaw;
}

/* Model initialize function */
void flightController_g_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_flightController_T *const flightController_M =
    &(flightController_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(flightController_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)&flightController_DW, 0,
                sizeof(DW_flightController_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

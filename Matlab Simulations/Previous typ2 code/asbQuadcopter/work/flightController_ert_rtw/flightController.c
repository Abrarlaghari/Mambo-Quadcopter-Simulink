/*
 * File: flightController.c
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

/* Block signals (default storage) */
B_flightController_T flightController_B;

/* Block states (default storage) */
DW_flightController_T flightController_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_flightController_T flightController_Y;

/* Real-time model */
RT_MODEL_flightController_T flightController_M_;
RT_MODEL_flightController_T *const flightController_M = &flightController_M_;
real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T tmp;
  real32_T tmp_0;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = (real32_T)fabs(u0);
    tmp_0 = (real32_T)fabs(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = (rtNaNF);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void flightController_run(const CommandBus *arg_ReferenceValueServerBus, const
  statesEstim_t *arg_states_estim, real32_T arg_motors_refout[4], real32_T
  arg_pose_refout[8])
{
  real32_T G31U;
  real32_T G12U;
  real32_T G12L;
  real32_T G32U;
  real32_T G32L;
  real32_T R5U;
  real32_T R5L;
  real32_T RNU;
  real32_T RNL;
  real32_T rtb_TrigonometricFunction_o1;
  real32_T rtb_TrigonometricFunction_o2;
  int32_T i;
  real32_T rtb_pitchrollerror_idx_0;
  real32_T rtb_pitchrollerror_idx_1;

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Inport: '<Root>/ReferenceValueServerBus'
   *  Inport: '<Root>/states_estim'
   *  Sum: '<S2>/Sum3'
   */
  flightController_B.EN = ((arg_ReferenceValueServerBus->pos_ref[2] -
    arg_states_estim->Z) * flightController_P.Gain_Gain - -1.1F) / 2.2F;
  flightController_B.DEN = (flightController_P.Gain1_Gain * arg_states_estim->dz
    - -2.0F) / 4.0F;
  flightController_B.G11L = 1.0F / ((real32_T)exp(100.0F * flightController_B.EN)
    + 1.0F);
  flightController_B.G21U = 1.0F / ((real32_T)exp(-100.0F *
    flightController_B.EN) + 1.0F);
  flightController_B.G11U = 1.0F / ((rt_powf_snf((real32_T)fabs
    (flightController_B.G11L * (flightController_B.EN / 0.5F)), 4.0F) * 4.0F +
    1.0F) + rt_powf_snf((real32_T)fabs(flightController_B.G21U *
    (flightController_B.EN / 0.5F)), 4.0F) * 4.0F);
  flightController_B.G11L = 1.0F / ((rt_powf_snf((real32_T)fabs
    (flightController_B.G11L * (flightController_B.EN / 0.4F)), 4.0F) * 4.0F +
    1.0F) + rt_powf_snf((real32_T)fabs(flightController_B.G21U *
    (flightController_B.EN / 0.4F)), 4.0F) * 4.0F);
  flightController_B.G21U = (flightController_B.EN - 0.5F) / 0.5F;
  flightController_B.G21L = 1.0F / ((real32_T)exp((flightController_B.EN - 0.5F)
    * 100.0F) + 1.0F);
  G31U = 1.0F / ((real32_T)exp((flightController_B.EN - 0.5F) * -100.0F) + 1.0F);
  flightController_B.G21U = 1.0F / ((rt_powf_snf((real32_T)fabs
    (flightController_B.G21L * flightController_B.G21U), 4.0F) * 4.0F + 1.0F) +
    rt_powf_snf((real32_T)fabs(G31U * flightController_B.G21U), 4.0F) * 4.0F);
  G12L = (flightController_B.EN - 0.5F) / 0.4F;
  flightController_B.G21L = 1.0F / ((rt_powf_snf((real32_T)fabs
    (flightController_B.G21L * G12L), 4.0F) * 4.0F + 1.0F) + rt_powf_snf
    ((real32_T)fabs(G31U * G12L), 4.0F) * 4.0F);
  G31U = (flightController_B.EN - 1.0F) / 0.5F;
  G12L = 1.0F / ((real32_T)exp((flightController_B.EN - 1.0F) * 100.0F) + 1.0F);
  G12U = 1.0F / ((real32_T)exp((flightController_B.EN - 1.0F) * -100.0F) + 1.0F);
  G31U = 1.0F / ((rt_powf_snf((real32_T)fabs(G12L * G31U), 4.0F) * 4.0F + 1.0F)
                 + rt_powf_snf((real32_T)fabs(G12U * G31U), 4.0F) * 4.0F);
  flightController_B.EN = (flightController_B.EN - 1.0F) / 0.4F;
  flightController_B.EN = 1.0F / ((rt_powf_snf((real32_T)fabs(G12L *
    flightController_B.EN), 4.0F) * 4.0F + 1.0F) + rt_powf_snf((real32_T)fabs
    (G12U * flightController_B.EN), 4.0F) * 4.0F);
  G12L = 1.0F / ((real32_T)exp(100.0F * flightController_B.DEN) + 1.0F);
  G32U = 1.0F / ((real32_T)exp(-100.0F * flightController_B.DEN) + 1.0F);
  G12U = 1.0F / ((rt_powf_snf((real32_T)fabs(G12L * (flightController_B.DEN /
    0.5F)), 4.0F) * 4.0F + 1.0F) + rt_powf_snf((real32_T)fabs(G32U *
    (flightController_B.DEN / 0.5F)), 4.0F) * 4.0F);
  G12L = 1.0F / ((rt_powf_snf((real32_T)fabs(G12L * (flightController_B.DEN /
    0.4F)), 4.0F) * 4.0F + 1.0F) + rt_powf_snf((real32_T)fabs(G32U *
    (flightController_B.DEN / 0.4F)), 4.0F) * 4.0F);
  G32U = (flightController_B.DEN - 1.0F) / 0.5F;
  R5U = 1.0F / ((real32_T)exp((flightController_B.DEN - 1.0F) * 100.0F) + 1.0F);
  G32L = 1.0F / ((real32_T)exp((flightController_B.DEN - 1.0F) * -100.0F) + 1.0F);
  G32U = 1.0F / ((rt_powf_snf((real32_T)fabs(R5U * G32U), 4.0F) * 4.0F + 1.0F) +
                 rt_powf_snf((real32_T)fabs(G32L * G32U), 4.0F) * 4.0F);
  flightController_B.DEN = (flightController_B.DEN - 1.0F) / 0.4F;
  G32L = 1.0F / ((rt_powf_snf((real32_T)fabs(R5U * flightController_B.DEN), 4.0F)
                  * 4.0F + 1.0F) + rt_powf_snf((real32_T)fabs(G32L *
    flightController_B.DEN), 4.0F) * 4.0F);
  R5U = (1.0F - flightController_B.G21U) / flightController_B.G21U;
  flightController_B.DEN = 1.0F / (R5U + (1.0F - G32U) / G32U);
  R5U = 1.0F / (R5U + (1.0F - G12U) / G12U);
  G12U = (1.0F - flightController_B.G21L) / flightController_B.G21L;
  G32L = 1.0F / (G12U + (1.0F - G32L) / G32L);
  R5L = 1.0F / (G12U + (1.0F - G12L) / G12L);
  RNU = (((G31U + flightController_B.G11U) + flightController_B.G21U) +
         flightController_B.DEN) + R5U;
  RNL = (((flightController_B.EN + flightController_B.G11L) +
          flightController_B.G21L) + G32L) + R5L;

  /* Trigonometry: '<S9>/Trigonometric Function' incorporates:
   *  Inport: '<Root>/states_estim'
   */
  rtb_TrigonometricFunction_o1 = (real32_T)sin(arg_states_estim->yaw);
  rtb_TrigonometricFunction_o2 = (real32_T)cos(arg_states_estim->yaw);

  /* Sum: '<S9>/Sum17' incorporates:
   *  Inport: '<Root>/ReferenceValueServerBus'
   *  Inport: '<Root>/states_estim'
   */
  rtb_pitchrollerror_idx_0 = arg_ReferenceValueServerBus->pos_ref[0] -
    arg_states_estim->X;
  G12L = arg_ReferenceValueServerBus->pos_ref[1] - arg_states_estim->Y;

  /* Product: '<S9>/Product' incorporates:
   *  SignalConversion: '<S9>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S9>/ConcatBufferAtVector ConcatenateIn1'
   */
  rtb_pitchrollerror_idx_1 = rtb_TrigonometricFunction_o2 *
    rtb_pitchrollerror_idx_0 + rtb_TrigonometricFunction_o1 * G12L;

  /* Saturate: '<S9>/Saturation' */
  if (rtb_pitchrollerror_idx_1 > flightController_P.Saturation_UpperSat) {
    rtb_pitchrollerror_idx_1 = flightController_P.Saturation_UpperSat;
  } else {
    if (rtb_pitchrollerror_idx_1 < flightController_P.Saturation_LowerSat) {
      rtb_pitchrollerror_idx_1 = flightController_P.Saturation_LowerSat;
    }
  }

  /* Sum: '<S9>/Sum18' incorporates:
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   *  Inport: '<Root>/states_estim'
   */
  G12U = flightController_P.P_xy_Gain[0] * rtb_pitchrollerror_idx_1 +
    flightController_P.D_xy_Gain[0] * arg_states_estim->dx;

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  G32U = flightController_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* Product: '<S9>/Product' incorporates:
   *  Gain: '<S9>/Gain'
   *  SignalConversion: '<S9>/ConcatBufferAtVector Concatenate1In2'
   */
  rtb_pitchrollerror_idx_1 = flightController_P.Gain_Gain_o *
    rtb_TrigonometricFunction_o1 * rtb_pitchrollerror_idx_0 +
    rtb_TrigonometricFunction_o2 * G12L;

  /* Saturate: '<S9>/Saturation' */
  if (rtb_pitchrollerror_idx_1 > flightController_P.Saturation_UpperSat) {
    rtb_pitchrollerror_idx_1 = flightController_P.Saturation_UpperSat;
  } else {
    if (rtb_pitchrollerror_idx_1 < flightController_P.Saturation_LowerSat) {
      rtb_pitchrollerror_idx_1 = flightController_P.Saturation_LowerSat;
    }
  }

  /* Sum: '<S9>/Sum18' incorporates:
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   *  Inport: '<Root>/states_estim'
   */
  rtb_TrigonometricFunction_o1 = flightController_P.P_xy_Gain[1] *
    rtb_pitchrollerror_idx_1 + flightController_P.D_xy_Gain[1] *
    arg_states_estim->dy;

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  rtb_TrigonometricFunction_o2 =
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* Sum: '<S4>/Sum19' incorporates:
   *  Inport: '<Root>/states_estim'
   */
  rtb_pitchrollerror_idx_0 = G12U - arg_states_estim->pitch;
  rtb_pitchrollerror_idx_1 = rtb_TrigonometricFunction_o1 -
    arg_states_estim->roll;

  /* Sum: '<S2>/Sum4' incorporates:
   *  Constant: '<S2>/w0'
   *  Gain: '<S2>/Gain2'
   *  Gain: '<S2>/Gain3'
   *  MATLAB Function: '<S2>/MATLAB Function'
   */
  flightController_B.G11U = (((((G31U / RNU * 0.9F + flightController_B.G11U /
    RNU * -0.95F) + flightController_B.G21U / RNU * 0.0F) +
    flightController_B.DEN / RNU * -0.7F) + R5U / RNU * 0.7F) +
    ((((flightController_B.EN / RNL * 0.9F + flightController_B.G11L / RNL *
        -0.95F) + flightController_B.G21L / RNL * 0.0F) + G32L / RNL * -0.7F) +
     R5L / RNL * 0.7F)) / 2.0F * flightController_P.Gain2_Gain +
    flightController_P.Gain3_Gain * flightController_P.w0_Value;

  /* Saturate: '<S2>/SaturationThrust' */
  if (flightController_B.G11U > flightController_P.SaturationThrust_UpperSat) {
    flightController_B.G11U = flightController_P.SaturationThrust_UpperSat;
  } else {
    if (flightController_B.G11U < flightController_P.SaturationThrust_LowerSat)
    {
      flightController_B.G11U = flightController_P.SaturationThrust_LowerSat;
    }
  }

  /* SignalConversion: '<S3>/TmpSignal ConversionAtProductInport2' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Gain: '<S10>/D_yaw'
   *  Gain: '<S10>/P_yaw'
   *  Gain: '<S4>/D_pr'
   *  Gain: '<S4>/I_pr'
   *  Gain: '<S4>/P_pr'
   *  Inport: '<Root>/ReferenceValueServerBus'
   *  Inport: '<Root>/states_estim'
   *  Sum: '<S10>/Sum1'
   *  Sum: '<S10>/Sum2'
   *  Sum: '<S4>/Sum16'
   */
  G12L = (arg_ReferenceValueServerBus->orient_ref[0] - arg_states_estim->yaw) *
    flightController_P.P_yaw_Gain - flightController_P.D_yaw_Gain *
    arg_states_estim->r;
  flightController_B.G11L = (flightController_P.P_pr_Gain[0] *
    rtb_pitchrollerror_idx_0 + flightController_P.I_pr_Gain *
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0]) -
    flightController_P.D_pr_Gain[0] * arg_states_estim->q;
  flightController_B.G21U = (flightController_P.P_pr_Gain[1] *
    rtb_pitchrollerror_idx_1 + flightController_P.I_pr_Gain *
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1]) -
    flightController_P.D_pr_Gain[1] * arg_states_estim->p;
  for (i = 0; i < 4; i++) {
    /* Product: '<S3>/Product' incorporates:
     *  Constant: '<S3>/TorqueTotalThrustToThrustPerMotor'
     *  Saturate: '<S2>/SaturationThrust'
     *  SignalConversion: '<S3>/TmpSignal ConversionAtProductInport2'
     */
    flightController_B.G21L =
      flightController_P.TorqueTotalThrustToThrustPerMotor_Value[i + 12] *
      flightController_B.G21U +
      (flightController_P.TorqueTotalThrustToThrustPerMotor_Value[i + 8] *
       flightController_B.G11L +
       (flightController_P.TorqueTotalThrustToThrustPerMotor_Value[i + 4] * G12L
        + flightController_P.TorqueTotalThrustToThrustPerMotor_Value[i] *
        flightController_B.G11U));

    /* Saturate: '<S7>/Saturation5' incorporates:
     *  Gain: '<S7>/ThrustToMotorCommand'
     */
    flightController_B.G21L *= flightController_P.ThrustToMotorCommand_Gain;
    if (flightController_B.G21L > flightController_P.Saturation5_UpperSat) {
      flightController_B.G21L = flightController_P.Saturation5_UpperSat;
    } else {
      if (flightController_B.G21L < flightController_P.Saturation5_LowerSat) {
        flightController_B.G21L = flightController_P.Saturation5_LowerSat;
      }
    }

    /* End of Saturate: '<S7>/Saturation5' */

    /* Outport: '<Root>/motors_refout' incorporates:
     *  Gain: '<S7>/MotorDirections'
     */
    flightController_Y.motors_refout[i] =
      flightController_P.MotorDirections_Gain[i] * flightController_B.G21L;
  }

  /* Outport: '<Root>/pose_refout' incorporates:
   *  Inport: '<Root>/ReferenceValueServerBus'
   */
  flightController_Y.pose_refout[0] = arg_ReferenceValueServerBus->pos_ref[0];
  flightController_Y.pose_refout[3] = arg_ReferenceValueServerBus->orient_ref[0];
  flightController_Y.pose_refout[1] = arg_ReferenceValueServerBus->pos_ref[1];
  flightController_Y.pose_refout[4] = arg_ReferenceValueServerBus->orient_ref[1];
  flightController_Y.pose_refout[2] = arg_ReferenceValueServerBus->pos_ref[2];
  flightController_Y.pose_refout[5] = arg_ReferenceValueServerBus->orient_ref[2];
  flightController_Y.pose_refout[6] = G12U;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S4>/Delay'
   *  Gain: '<S4>/antiWU_Gain'
   *  Sum: '<S4>/Add'
   */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] +=
    (rtb_pitchrollerror_idx_0 - flightController_P.antiWU_Gain_Gain *
     flightController_DW.Delay_DSTATE[0]) *
    flightController_P.DiscreteTimeIntegrator_gainval;
  if (flightController_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      flightController_P.DiscreteTimeIntegrator_UpperSat) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
      flightController_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (flightController_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        flightController_P.DiscreteTimeIntegrator_LowerSat) {
      flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
        flightController_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* Update for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[0] = G32U;

  /* Outport: '<Root>/pose_refout' */
  flightController_Y.pose_refout[7] = rtb_TrigonometricFunction_o1;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S4>/Delay'
   *  Gain: '<S4>/antiWU_Gain'
   *  Sum: '<S4>/Add'
   */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] +=
    (rtb_pitchrollerror_idx_1 - flightController_P.antiWU_Gain_Gain *
     flightController_DW.Delay_DSTATE[1]) *
    flightController_P.DiscreteTimeIntegrator_gainval;
  if (flightController_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      flightController_P.DiscreteTimeIntegrator_UpperSat) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
      flightController_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (flightController_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        flightController_P.DiscreteTimeIntegrator_LowerSat) {
      flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
        flightController_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* Update for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[1] = rtb_TrigonometricFunction_o2;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flightController_M->rtwLogInfo,
                      (&flightController_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightController_M)!=-1) &&
        !((rtmGetTFinal(flightController_M)-flightController_M->Timing.taskTime0)
          > flightController_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightController_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  flightController_M->Timing.taskTime0 =
    (++flightController_M->Timing.clockTick0) *
    flightController_M->Timing.stepSize0;

  /* Copy value for root outport '<Root>/motors_refout' since it is accessed globally */
  {
    int32_T i;
    for (i = 0; i < 4; i++)
      arg_motors_refout[i] = flightController_Y.motors_refout[i];
  }

  /* Copy value for root outport '<Root>/pose_refout' since it is accessed globally */
  {
    int32_T i;
    for (i = 0; i < 8; i++)
      arg_pose_refout[i] = flightController_Y.pose_refout[i];
  }
}

/* Model initialize function */
void flightController_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)flightController_M, 0,
                sizeof(RT_MODEL_flightController_T));
  rtmSetTFinal(flightController_M, 25.0);
  flightController_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    flightController_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(flightController_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(flightController_M->rtwLogInfo, (NULL));
    rtliSetLogT(flightController_M->rtwLogInfo, "tout");
    rtliSetLogX(flightController_M->rtwLogInfo, "");
    rtliSetLogXFinal(flightController_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(flightController_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(flightController_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(flightController_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(flightController_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &flightController_Y.motors_refout[0],
        &flightController_Y.pose_refout[0]
      };

      rtliSetLogYSignalPtrs(flightController_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        4,
        8
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        4,
        8
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_SINGLE,
        SS_SINGLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "flightController/motors_refout",
        "flightController/pose_refout" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(flightController_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(flightController_M->rtwLogInfo, "yout");
  }

  /* states (dwork) */
  (void) memset((void *)&flightController_DW, 0,
                sizeof(DW_flightController_T));

  /* external outputs */
  (void) memset((void *)&flightController_Y, 0,
                sizeof(ExtY_flightController_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightController_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightController_M), flightController_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightController_M)));

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
    flightController_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[0] =
    flightController_P.Delay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
    flightController_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[1] =
    flightController_P.Delay_InitialCondition;
}

/* Model terminate function */
void flightController_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

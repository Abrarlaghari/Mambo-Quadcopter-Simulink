/*
 * File: flightController.c
 *
 * Code generated for Simulink model 'flightController'.
 *
 * Model version                  : 1.361
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 13:03:28 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flightController.h"
#include "flightController_private.h"
#include "rt_powf_snf.h"
#include "sum_ZH1qcIwz.h"

P_flightController_T flightController_P_g = {
  /* Expression: -1
   * Referenced by: '<S2>/Gain2'
   */
  -1.0,

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
  /* local block i/o variables */
  real_T rtb_CU;
  real32_T DEN;
  int32_T i;
  static const real_T b[26] = { -0.2, 0.2, -0.45, 0.45, 0.0, -0.66, 0.22, 0.66,
    -0.28, 0.5, -0.59, -0.83, 0.88, 0.62, -0.45, -0.93, 0.39, 0.7, 0.82, -0.76,
    -0.38, 0.98, 1.28, 0.45, -0.98, -1.3 };

  static const real_T c[26] = { 1.793296089385475, 1.8176951253874332,
    1.8026905829596411, 1.8026905829596411, 1.8176951253874332,
    6.8492935635792778, 4.3106744556558683, 4.7372346528973033,
    3.3271311120726961, 18.999999999999996, 18.999999999999996,
    18.999999999999996, 18.999999999999996, 18.999999999999996,
    18.999999999999996, 18.999999999999996, 18.999999999999996,
    18.999999999999996, 18.999999999999996, 18.999999999999996,
    18.999999999999996, 18.999999999999996, 18.999999999999996,
    18.999999999999996, 18.999999999999996, 18.999999999999996 };

  static const real_T C[78] = { 0.0, 1.0, 0.0, 1.0, 0.5, 0.0, 0.311, 0.9732,
    0.6421, 0.4816, 0.4515, 0.0, 0.9732, 0.5618, 0.2709, 0.0, 0.602, 0.612,
    0.6822, 0.3311, 0.0, 0.9732, 0.9732, 0.9832, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.5, 0.38127, 0.0, 0.5819, 0.9832, 0.0, 0.993, 0.5418, 0.3812, 0.0, 0.5819,
    0.6321, 0.2842, 0.0, 0.0, 0.9732, 0.1137, 0.2842, 0.0, 0.8026, 0.6822,
    0.9832, -0.2, 0.2, -0.45, 0.45, 0.0, -0.66, 0.22, 0.66, -0.28, 0.5, -0.59,
    -0.83, 0.88, 0.62, -0.45, -0.93, 0.39, 0.7, 0.82, -0.76, -0.38, 0.98, 1.28,
    0.45, -0.98, -1.3 };

  real32_T rtb_SaturationThrust;
  real32_T rtb_D_yaw;
  real_T G12L;
  real32_T arg_ReferenceValueServerBus_idx_1;
  real32_T rtb_pitchrollerror_idx_0;
  real32_T rtb_DiscreteTimeIntegrator_idx_0;
  real32_T tmp;
  real32_T tmp_0;
  real32_T u0;

  /* Trigonometry: '<S9>/Trigonometric Function' */
  rtb_D_yaw = (real32_T)sin(arg_states_estim->yaw);
  rtb_SaturationThrust = (real32_T)cos(arg_states_estim->yaw);

  /* Sum: '<S9>/Sum17' */
  DEN = arg_ReferenceValueServerBus->pos_ref[0] - arg_states_estim->X;
  arg_ReferenceValueServerBus_idx_1 = arg_ReferenceValueServerBus->pos_ref[1] -
    arg_states_estim->Y;

  /* Product: '<S9>/Product' incorporates:
   *  SignalConversion: '<S9>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S9>/ConcatBufferAtVector ConcatenateIn1'
   */
  rtb_DiscreteTimeIntegrator_idx_0 = rtb_SaturationThrust * DEN + rtb_D_yaw *
    arg_ReferenceValueServerBus_idx_1;

  /* Saturate: '<S9>/Saturation' */
  if (rtb_DiscreteTimeIntegrator_idx_0 >
      flightController_P_g.Saturation_UpperSat) {
    rtb_DiscreteTimeIntegrator_idx_0 = flightController_P_g.Saturation_UpperSat;
  } else {
    if (rtb_DiscreteTimeIntegrator_idx_0 <
        flightController_P_g.Saturation_LowerSat) {
      rtb_DiscreteTimeIntegrator_idx_0 =
        flightController_P_g.Saturation_LowerSat;
    }
  }

  /* Sum: '<S9>/Sum18' incorporates:
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   */
  rtb_pitchrollerror_idx_0 = flightController_P_g.P_xy_Gain[0] *
    rtb_DiscreteTimeIntegrator_idx_0 + flightController_P_g.D_xy_Gain[0] *
    arg_states_estim->dx;

  /* Product: '<S9>/Product' incorporates:
   *  Gain: '<S9>/Gain'
   *  SignalConversion: '<S9>/ConcatBufferAtVector Concatenate1In2'
   */
  rtb_DiscreteTimeIntegrator_idx_0 = flightController_P_g.Gain_Gain * rtb_D_yaw *
    DEN + rtb_SaturationThrust * arg_ReferenceValueServerBus_idx_1;

  /* Saturate: '<S9>/Saturation' */
  if (rtb_DiscreteTimeIntegrator_idx_0 >
      flightController_P_g.Saturation_UpperSat) {
    rtb_DiscreteTimeIntegrator_idx_0 = flightController_P_g.Saturation_UpperSat;
  } else {
    if (rtb_DiscreteTimeIntegrator_idx_0 <
        flightController_P_g.Saturation_LowerSat) {
      rtb_DiscreteTimeIntegrator_idx_0 =
        flightController_P_g.Saturation_LowerSat;
    }
  }

  /* Sum: '<S9>/Sum18' incorporates:
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   */
  rtb_D_yaw = flightController_P_g.P_xy_Gain[1] *
    rtb_DiscreteTimeIntegrator_idx_0 + flightController_P_g.D_xy_Gain[1] *
    arg_states_estim->dy;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtpose_refoutInport1' incorporates:
   *  SignalConversion: '<S1>/ReferenceValueServerBus_BusSelector'
   */
  arg_pose_refout[0] = arg_ReferenceValueServerBus->pos_ref[0];
  arg_pose_refout[3] = arg_ReferenceValueServerBus->orient_ref[0];
  arg_pose_refout[1] = arg_ReferenceValueServerBus->pos_ref[1];
  arg_pose_refout[4] = arg_ReferenceValueServerBus->orient_ref[1];
  arg_pose_refout[2] = arg_ReferenceValueServerBus->pos_ref[2];
  arg_pose_refout[5] = arg_ReferenceValueServerBus->orient_ref[2];
  arg_pose_refout[6] = rtb_pitchrollerror_idx_0;
  arg_pose_refout[7] = rtb_D_yaw;

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Sum: '<S2>/Sum3'
   */
  rtb_SaturationThrust = ((arg_ReferenceValueServerBus->pos_ref[2] -
    arg_states_estim->Z) * flightController_P_g.Gain_Gain_e - -1.1F) / 2.0F;
  DEN = (flightController_P_g.Gain1_Gain * arg_states_estim->dz - -1.77F) / 3.0F;
  for (i = 0; i < 26; i++) {
    arg_ReferenceValueServerBus_idx_1 = rtb_SaturationThrust - (real32_T)C[i];
    rtb_DiscreteTimeIntegrator_idx_0 = arg_ReferenceValueServerBus_idx_1 / 0.33F;
    flightController_B.CL = 1.0F / ((rt_powf_snf((real32_T)fabs(1.0F /
      ((real32_T)exp(arg_ReferenceValueServerBus_idx_1 * 100.0F) + 1.0F) *
      rtb_DiscreteTimeIntegrator_idx_0), 4.0F) * (real32_T)c[i] + 1.0F) +
      rt_powf_snf((real32_T)fabs(1.0F / ((real32_T)exp
      (arg_ReferenceValueServerBus_idx_1 * -100.0F) + 1.0F) *
      rtb_DiscreteTimeIntegrator_idx_0), 4.0F) * (real32_T)c[i]);
    flightController_B.G11L = 1.0F / ((rt_powf_snf((real32_T)fabs(1.0F /
      ((real32_T)exp((arg_ReferenceValueServerBus_idx_1 - 0.1F) * 100.0F) + 1.0F)
      * (((rtb_SaturationThrust - (real32_T)C[i]) - 0.1F) / 0.33F)), 4.0F) *
      (real32_T)c[i] + 1.0F) + rt_powf_snf((real32_T)fabs(1.0F / ((real32_T)exp
      ((arg_ReferenceValueServerBus_idx_1 + 0.1F) * -100.0F) + 1.0F) *
      (((rtb_SaturationThrust - (real32_T)C[i]) + 0.1F) / 0.33F)), 4.0F) *
      (real32_T)c[i]);
    arg_ReferenceValueServerBus_idx_1 = DEN - (real32_T)C[26 + i];
    rtb_DiscreteTimeIntegrator_idx_0 = arg_ReferenceValueServerBus_idx_1 / 0.33F;
    flightController_B.G12U = 1.0F / ((rt_powf_snf((real32_T)fabs(1.0F /
      ((real32_T)exp(arg_ReferenceValueServerBus_idx_1 * 100.0F) + 1.0F) *
      rtb_DiscreteTimeIntegrator_idx_0), 4.0F) * (real32_T)c[i] + 1.0F) +
      rt_powf_snf((real32_T)fabs(1.0F / ((real32_T)exp
      (arg_ReferenceValueServerBus_idx_1 * -100.0F) + 1.0F) *
      rtb_DiscreteTimeIntegrator_idx_0), 4.0F) * (real32_T)c[i]);
    G12L = 1.0F / ((rt_powf_snf((real32_T)fabs(1.0F / ((real32_T)exp
      ((arg_ReferenceValueServerBus_idx_1 - 0.1F) * 100.0F) + 1.0F) * (((DEN -
      (real32_T)C[26 + i]) - 0.1F) / 0.33F)), 4.0F) * (real32_T)c[i] + 1.0F) +
                   rt_powf_snf((real32_T)fabs(1.0F / ((real32_T)exp
      ((arg_ReferenceValueServerBus_idx_1 + 0.1F) * -100.0F) + 1.0F) * (((DEN -
      (real32_T)C[26 + i]) + 0.1F) / 0.33F)), 4.0F) * (real32_T)c[i]);
    flightController_B.RU[i] = 1.0 / ((1.0 - flightController_B.CL) /
      flightController_B.CL + (1.0 - flightController_B.G12U) /
      flightController_B.G12U);
    flightController_B.RL[i] = 1.0 / ((1.0 - flightController_B.G11L) /
      flightController_B.G11L + (1.0 - G12L) / G12L);
  }

  flightController_B.G11L = sum_ZH1qcIwz(flightController_B.RU);
  flightController_B.G12U = sum_ZH1qcIwz(flightController_B.RL);
  G12L = 0.0;
  flightController_B.CL = 0.0;
  for (i = 0; i < 26; i++) {
    G12L += flightController_B.RU[i] / flightController_B.G11L * b[i];
    flightController_B.CL += flightController_B.RL[i] / flightController_B.G12U *
      b[i];
  }

  rtb_CU = G12L;

  /* Sum: '<S2>/Sum4' incorporates:
   *  Constant: '<S2>/w0'
   *  Gain: '<S2>/Gain2'
   *  Gain: '<S2>/Gain3'
   *  MATLAB Function: '<S2>/MATLAB Function'
   */
  rtb_SaturationThrust = (real32_T)((G12L + flightController_B.CL) / 2.0 *
    flightController_P_g.Gain2_Gain) + flightController_P_g.Gain3_Gain *
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
  DEN = (arg_ReferenceValueServerBus->orient_ref[0] - arg_states_estim->yaw) *
    flightController_P_g.P_yaw_Gain - flightController_P_g.D_yaw_Gain *
    arg_states_estim->r;

  /* Sum: '<S4>/Sum19' */
  arg_ReferenceValueServerBus_idx_1 = rtb_pitchrollerror_idx_0 -
    arg_states_estim->pitch;

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_idx_0 =
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* SignalConversion: '<S3>/TmpSignal ConversionAtProductInport2' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Gain: '<S4>/D_pr'
   *  Gain: '<S4>/I_pr'
   *  Gain: '<S4>/P_pr'
   *  Sum: '<S4>/Sum16'
   */
  tmp = (flightController_P_g.P_pr_Gain[0] * arg_ReferenceValueServerBus_idx_1 +
         flightController_P_g.I_pr_Gain *
         flightController_DW.DiscreteTimeIntegrator_DSTATE[0]) -
    flightController_P_g.D_pr_Gain[0] * arg_states_estim->q;

  /* Sum: '<S4>/Sum19' */
  rtb_pitchrollerror_idx_0 = arg_ReferenceValueServerBus_idx_1;
  arg_ReferenceValueServerBus_idx_1 = rtb_D_yaw - arg_states_estim->roll;

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  rtb_D_yaw = flightController_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* SignalConversion: '<S3>/TmpSignal ConversionAtProductInport2' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Gain: '<S4>/D_pr'
   *  Gain: '<S4>/I_pr'
   *  Gain: '<S4>/P_pr'
   *  Sum: '<S4>/Sum16'
   */
  tmp_0 = (flightController_P_g.P_pr_Gain[1] * arg_ReferenceValueServerBus_idx_1
           + flightController_P_g.I_pr_Gain *
           flightController_DW.DiscreteTimeIntegrator_DSTATE[1]) -
    flightController_P_g.D_pr_Gain[1] * arg_states_estim->p;
  for (i = 0; i < 4; i++) {
    /* Product: '<S3>/Product' incorporates:
     *  Constant: '<S3>/TorqueTotalThrustToThrustPerMotor'
     *  Saturate: '<S2>/SaturationThrust'
     *  SignalConversion: '<S3>/TmpSignal ConversionAtProductInport2'
     */
    u0 = flightController_P_g.TorqueTotalThrustToThrustPerMotor_Value[i + 12] *
      tmp_0 + (flightController_P_g.TorqueTotalThrustToThrustPerMotor_Value[i +
               8] * tmp +
               (flightController_P_g.TorqueTotalThrustToThrustPerMotor_Value[i +
                4] * DEN +
                flightController_P_g.TorqueTotalThrustToThrustPerMotor_Value[i] *
                rtb_SaturationThrust));

    /* Saturate: '<S7>/Saturation5' incorporates:
     *  Gain: '<S7>/ThrustToMotorCommand'
     */
    u0 *= flightController_P_g.ThrustToMotorCommand_Gain;
    if (u0 > flightController_P_g.Saturation5_UpperSat) {
      u0 = flightController_P_g.Saturation5_UpperSat;
    } else {
      if (u0 < flightController_P_g.Saturation5_LowerSat) {
        u0 = flightController_P_g.Saturation5_LowerSat;
      }
    }

    /* End of Saturate: '<S7>/Saturation5' */

    /* Gain: '<S7>/MotorDirections' */
    arg_motors_refout[i] = flightController_P_g.MotorDirections_Gain[i] * u0;
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
  flightController_DW.Delay_DSTATE[0] = rtb_DiscreteTimeIntegrator_idx_0;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S4>/Delay'
   *  Gain: '<S4>/antiWU_Gain'
   *  Sum: '<S4>/Add'
   */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] +=
    (arg_ReferenceValueServerBus_idx_1 - flightController_P_g.antiWU_Gain_Gain *
     flightController_DW.Delay_DSTATE[1]) *
    flightController_P_g.DiscreteTimeIntegrator_gainval;
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

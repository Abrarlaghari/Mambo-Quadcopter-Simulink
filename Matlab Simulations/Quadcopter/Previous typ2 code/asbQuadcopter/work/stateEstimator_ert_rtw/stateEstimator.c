/*
 * File: stateEstimator.c
 *
 * Code generated for Simulink model 'stateEstimator'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Nov 14 23:57:43 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stateEstimator.h"
#include "stateEstimator_private.h"

/* Block signals (default storage) */
B_stateEstimator_T stateEstimator_B;

/* Block states (default storage) */
DW_stateEstimator_T stateEstimator_DW;

/* External inputs (root inport signals with default storage) */
ExtU_stateEstimator_T stateEstimator_U;

/* Real-time model */
RT_MODEL_stateEstimator_T stateEstimator_M_;
RT_MODEL_stateEstimator_T *const stateEstimator_M = &stateEstimator_M_;

/*
 * System initialize for enable system:
 *    '<S106>/MeasurementUpdate'
 *    '<S153>/MeasurementUpdate'
 */
void stateEstimator_MeasurementUpdate_Init(real32_T rty_Lykyhatkk1[2],
  P_MeasurementUpdate_stateEstimator_T *localP)
{
  /* SystemInitialize for Outport: '<S131>/L*(y[k]-yhat[k|k-1])' */
  rty_Lykyhatkk1[0] = localP->Lykyhatkk1_Y0;
  rty_Lykyhatkk1[1] = localP->Lykyhatkk1_Y0;
}

/*
 * Disable for enable system:
 *    '<S106>/MeasurementUpdate'
 *    '<S153>/MeasurementUpdate'
 */
void stateEstimator_MeasurementUpdate_Disable(real32_T rty_Lykyhatkk1[2],
  DW_MeasurementUpdate_stateEstimator_T *localDW,
  P_MeasurementUpdate_stateEstimator_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S106>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S131>/Enable'
   */
  /* Disable for Outport: '<S131>/L*(y[k]-yhat[k|k-1])' */
  rty_Lykyhatkk1[0] = localP->Lykyhatkk1_Y0;
  rty_Lykyhatkk1[1] = localP->Lykyhatkk1_Y0;

  /* End of Outputs for SubSystem: '<S106>/MeasurementUpdate' */
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S106>/MeasurementUpdate'
 *    '<S153>/MeasurementUpdate'
 */
void stateEstimator_MeasurementUpdate(boolean_T rtu_Enable, const real32_T
  rtu_Lk[4], const real32_T rtu_yk[2], const real32_T rtu_Ck[4], const real32_T
  rtu_xhatkk1[2], const real32_T rtu_Dk[4], const real32_T rtu_uk[2], real32_T
  rty_Lykyhatkk1[2], DW_MeasurementUpdate_stateEstimator_T *localDW,
  P_MeasurementUpdate_stateEstimator_T *localP)
{
  real32_T rtu_yk_idx_0;
  real32_T rtu_yk_idx_1;

  /* Outputs for Enabled SubSystem: '<S106>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S131>/Enable'
   */
  if (rtu_Enable) {
    if (!localDW->MeasurementUpdate_MODE) {
      localDW->MeasurementUpdate_MODE = true;
    }

    /* Sum: '<S131>/Sum' incorporates:
     *  Product: '<S131>/C[k]*xhat[k|k-1]'
     *  Product: '<S131>/D[k]*u[k]'
     *  Sum: '<S131>/Add1'
     */
    rtu_yk_idx_0 = rtu_yk[0] - ((rtu_Ck[0] * rtu_xhatkk1[0] + rtu_Ck[2] *
      rtu_xhatkk1[1]) + (rtu_Dk[0] * rtu_uk[0] + rtu_Dk[2] * rtu_uk[1]));
    rtu_yk_idx_1 = rtu_yk[1] - ((rtu_Ck[1] * rtu_xhatkk1[0] + rtu_Ck[3] *
      rtu_xhatkk1[1]) + (rtu_Dk[1] * rtu_uk[0] + rtu_Dk[3] * rtu_uk[1]));

    /* Product: '<S131>/Product3' */
    rty_Lykyhatkk1[0] = 0.0F;
    rty_Lykyhatkk1[0] += rtu_Lk[0] * rtu_yk_idx_0;
    rty_Lykyhatkk1[0] += rtu_Lk[2] * rtu_yk_idx_1;
    rty_Lykyhatkk1[1] = 0.0F;
    rty_Lykyhatkk1[1] += rtu_Lk[1] * rtu_yk_idx_0;
    rty_Lykyhatkk1[1] += rtu_Lk[3] * rtu_yk_idx_1;
  } else {
    if (localDW->MeasurementUpdate_MODE) {
      stateEstimator_MeasurementUpdate_Disable(rty_Lykyhatkk1, localDW, localP);
    }
  }

  /* End of Outputs for SubSystem: '<S106>/MeasurementUpdate' */
}

/*
 * System initialize for enable system:
 *    '<S111>/Enabled Subsystem'
 *    '<S158>/Enabled Subsystem'
 */
void stateEstimator_EnabledSubsystem_Init(real32_T rty_deltax[2],
  P_EnabledSubsystem_stateEstimator_T *localP)
{
  /* SystemInitialize for Outport: '<S132>/deltax' */
  rty_deltax[0] = localP->deltax_Y0;
  rty_deltax[1] = localP->deltax_Y0;
}

/*
 * Disable for enable system:
 *    '<S111>/Enabled Subsystem'
 *    '<S158>/Enabled Subsystem'
 */
void stateEstimator_EnabledSubsystem_Disable(real32_T rty_deltax[2],
  DW_EnabledSubsystem_stateEstimator_T *localDW,
  P_EnabledSubsystem_stateEstimator_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S111>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S132>/Enable'
   */
  /* Disable for Outport: '<S132>/deltax' */
  rty_deltax[0] = localP->deltax_Y0;
  rty_deltax[1] = localP->deltax_Y0;

  /* End of Outputs for SubSystem: '<S111>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S111>/Enabled Subsystem'
 *    '<S158>/Enabled Subsystem'
 */
void stateEstimator_EnabledSubsystem(boolean_T rtu_Enable, const real32_T
  rtu_Mk[4], const real32_T rtu_Ck[4], const real32_T rtu_yk[2], const real32_T
  rtu_xhatkk1[2], real32_T rty_deltax[2], DW_EnabledSubsystem_stateEstimator_T
  *localDW, P_EnabledSubsystem_stateEstimator_T *localP)
{
  real32_T rtu_yk_idx_0;
  real32_T rtu_yk_idx_1;

  /* Outputs for Enabled SubSystem: '<S111>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S132>/Enable'
   */
  if (rtu_Enable) {
    if (!localDW->EnabledSubsystem_MODE) {
      localDW->EnabledSubsystem_MODE = true;
    }

    /* Sum: '<S132>/Add1' incorporates:
     *  Product: '<S132>/Product'
     */
    rtu_yk_idx_0 = rtu_yk[0] - (rtu_Ck[0] * rtu_xhatkk1[0] + rtu_Ck[2] *
      rtu_xhatkk1[1]);
    rtu_yk_idx_1 = rtu_yk[1] - (rtu_Ck[1] * rtu_xhatkk1[0] + rtu_Ck[3] *
      rtu_xhatkk1[1]);

    /* Product: '<S132>/Product2' */
    rty_deltax[0] = 0.0F;
    rty_deltax[0] += rtu_Mk[0] * rtu_yk_idx_0;
    rty_deltax[0] += rtu_Mk[2] * rtu_yk_idx_1;
    rty_deltax[1] = 0.0F;
    rty_deltax[1] += rtu_Mk[1] * rtu_yk_idx_0;
    rty_deltax[1] += rtu_Mk[3] * rtu_yk_idx_1;
  } else {
    if (localDW->EnabledSubsystem_MODE) {
      stateEstimator_EnabledSubsystem_Disable(rty_deltax, localDW, localP);
    }
  }

  /* End of Outputs for SubSystem: '<S111>/Enabled Subsystem' */
}

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
void stateEstimator_run(const boolean_T arg_controlModePosVSOrient_flagin, const
  sensordata_t *arg_sensordata_datin, const real32_T arg_usePosVIS_flagin, const
  real32_T arg_opticalFlow_datin[3], const real32_T arg_posVIS_datin[4],
  statesEstim_t *arg_states_estimout, const real32_T
  arg_sensorCalibration_datin[8])
{
  boolean_T rtb_LogicalOperator_cg;
  boolean_T rtb_Compare_i;
  boolean_T rtb_DataTypeConversionEnable_o;
  boolean_T rtb_DataTypeConversionEnable_n5;
  int32_T i;
  real32_T rtb_sincos_o2_idx_0;
  real32_T rtb_sincos_o2_idx_1;
  real32_T rtb_sincos_o2_idx_2;
  real32_T rtb_DataTypeConversion1_idx_1;
  real32_T rtb_DataTypeConversion1_idx_0;
  real32_T rtb_Sum_k_idx_2;
  real32_T y;
  real32_T rtb_VectorConcatenate_tmp;
  real32_T rtb_VectorConcatenate_tmp_0;
  real32_T rtb_sincos_o2_idx_2_tmp;

  /* Copy value for root inport '<Root>/posVIS_datin' since it is accessed globally */
  {
    int32_T i;
    for (i = 0; i < 4; i++)
      stateEstimator_U.posVIS_datin[i] = arg_posVIS_datin[i];
  }

  /* SignalConversion: '<S13>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S12>/Constant'
   */
  stateEstimator_B.VectorConcatenate[0] = stateEstimator_P.Constant_Value;

  /* SignalConversion: '<S13>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Constant: '<S12>/Constant'
   */
  stateEstimator_B.VectorConcatenate[1] = stateEstimator_P.Constant_Value;

  /* SignalConversion: '<S12>/TmpSignal ConversionAtTrigonometric FunctionInport1' incorporates:
   *  Memory: '<S2>/Memory'
   */
  rtb_sincos_o2_idx_0 = stateEstimator_DW.Memory_PreviousInput[2];
  rtb_sincos_o2_idx_1 = stateEstimator_DW.Memory_PreviousInput[1];
  rtb_sincos_o2_idx_2 = stateEstimator_DW.Memory_PreviousInput[0];

  /* Trigonometry: '<S12>/Trigonometric Function' incorporates:
   *  Memory: '<S2>/Memory'
   *  SignalConversion: '<S12>/TmpSignal ConversionAtTrigonometric FunctionInport1'
   */
  stateEstimator_DW.Memory_PreviousInput[0] = (real32_T)sin
    (stateEstimator_DW.Memory_PreviousInput[2]);
  rtb_DataTypeConversion1_idx_0 = (real32_T)cos
    (stateEstimator_DW.Memory_PreviousInput[2]);
  stateEstimator_DW.Memory_PreviousInput[1] = (real32_T)sin
    (stateEstimator_DW.Memory_PreviousInput[1]);
  rtb_DataTypeConversion1_idx_1 = (real32_T)cos(rtb_sincos_o2_idx_1);
  stateEstimator_DW.Memory_PreviousInput[2] = (real32_T)sin(rtb_sincos_o2_idx_2);

  /* SignalConversion: '<S13>/ConcatBufferAtVector ConcatenateIn3' */
  stateEstimator_B.VectorConcatenate[2] = rtb_DataTypeConversion1_idx_1;

  /* SignalConversion: '<S13>/ConcatBufferAtVector ConcatenateIn4' */
  stateEstimator_B.VectorConcatenate[3] =
    stateEstimator_DW.Memory_PreviousInput[0];

  /* Product: '<S12>/Product1' */
  stateEstimator_B.VectorConcatenate[4] = rtb_DataTypeConversion1_idx_0 *
    rtb_DataTypeConversion1_idx_1;

  /* Product: '<S12>/Product3' */
  stateEstimator_B.VectorConcatenate[5] =
    stateEstimator_DW.Memory_PreviousInput[0] *
    stateEstimator_DW.Memory_PreviousInput[1];

  /* SignalConversion: '<S13>/ConcatBufferAtVector ConcatenateIn7' */
  stateEstimator_B.VectorConcatenate[6] = rtb_DataTypeConversion1_idx_0;

  /* Product: '<S12>/Product2' incorporates:
   *  Gain: '<S12>/Gain'
   */
  stateEstimator_B.VectorConcatenate[7] = stateEstimator_P.Gain_Gain_c *
    stateEstimator_DW.Memory_PreviousInput[0] * rtb_DataTypeConversion1_idx_1;

  /* Product: '<S12>/Product4' */
  stateEstimator_B.VectorConcatenate[8] = rtb_DataTypeConversion1_idx_0 *
    stateEstimator_DW.Memory_PreviousInput[1];

  /* Product: '<S12>/Divide' incorporates:
   *  Reshape: '<S13>/Reshape (9) to [3x3] column-major'
   */
  for (stateEstimator_B.j = 0; stateEstimator_B.j < 9; stateEstimator_B.j++) {
    stateEstimator_B.VectorConcatenate[stateEstimator_B.j] /=
      rtb_DataTypeConversion1_idx_1;
  }

  /* End of Product: '<S12>/Divide' */

  /* Gain: '<S5>/inverseIMU_gain' incorporates:
   *  Bias: '<S5>/Assuming that calib was done level!'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Inport: '<Root>/sensorCalibration_datin'
   *  Inport: '<Root>/sensordata_datin'
   *  Sum: '<S5>/Sum1'
   */
  stateEstimator_B.inverseIMU_gain[0] = (arg_sensordata_datin->ddx -
    (arg_sensorCalibration_datin[0] +
     stateEstimator_P.Assumingthatcalibwasdonelevel_Bias[0])) *
    stateEstimator_P.inverseIMU_gain_Gain[0];
  stateEstimator_B.inverseIMU_gain[1] = (arg_sensordata_datin->ddy -
    (arg_sensorCalibration_datin[1] +
     stateEstimator_P.Assumingthatcalibwasdonelevel_Bias[1])) *
    stateEstimator_P.inverseIMU_gain_Gain[1];
  stateEstimator_B.inverseIMU_gain[2] = (arg_sensordata_datin->ddz -
    (arg_sensorCalibration_datin[2] +
     stateEstimator_P.Assumingthatcalibwasdonelevel_Bias[2])) *
    stateEstimator_P.inverseIMU_gain_Gain[2];
  stateEstimator_B.inverseIMU_gain[3] = (arg_sensordata_datin->p -
    (arg_sensorCalibration_datin[3] +
     stateEstimator_P.Assumingthatcalibwasdonelevel_Bias[3])) *
    stateEstimator_P.inverseIMU_gain_Gain[3];
  stateEstimator_B.inverseIMU_gain[4] = (arg_sensordata_datin->q -
    (arg_sensorCalibration_datin[4] +
     stateEstimator_P.Assumingthatcalibwasdonelevel_Bias[4])) *
    stateEstimator_P.inverseIMU_gain_Gain[4];
  stateEstimator_B.inverseIMU_gain[5] = (arg_sensordata_datin->r -
    (arg_sensorCalibration_datin[5] +
     stateEstimator_P.Assumingthatcalibwasdonelevel_Bias[5])) *
    stateEstimator_P.inverseIMU_gain_Gain[5];

  /* DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
  rtb_DataTypeConversion1_idx_0 = stateEstimator_B.inverseIMU_gain[5];
  stateEstimator_B.denIdx = 1;
  for (stateEstimator_B.j = 0; stateEstimator_B.j < 5; stateEstimator_B.j++) {
    rtb_DataTypeConversion1_idx_0 -=
      stateEstimator_P.IIR_IMUgyro_r_DenCoef[stateEstimator_B.denIdx] *
      stateEstimator_DW.IIR_IMUgyro_r_states[stateEstimator_B.j];
    stateEstimator_B.denIdx++;
  }

  rtb_DataTypeConversion1_idx_0 /= stateEstimator_P.IIR_IMUgyro_r_DenCoef[0];
  rtb_DataTypeConversion1_idx_1 = stateEstimator_P.IIR_IMUgyro_r_NumCoef[0] *
    rtb_DataTypeConversion1_idx_0;
  stateEstimator_B.denIdx = 1;
  for (stateEstimator_B.j = 0; stateEstimator_B.j < 5; stateEstimator_B.j++) {
    rtb_DataTypeConversion1_idx_1 +=
      stateEstimator_P.IIR_IMUgyro_r_NumCoef[stateEstimator_B.denIdx] *
      stateEstimator_DW.IIR_IMUgyro_r_states[stateEstimator_B.j];
    stateEstimator_B.denIdx++;
  }

  /* Product: '<S2>/Product' incorporates:
   *  DiscreteFilter: '<S5>/IIR_IMUgyro_r'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtProductInport2'
   */
  for (stateEstimator_B.j = 0; stateEstimator_B.j < 3; stateEstimator_B.j++) {
    stateEstimator_B.sincos_o1[stateEstimator_B.j] =
      stateEstimator_B.VectorConcatenate[stateEstimator_B.j + 6] *
      rtb_DataTypeConversion1_idx_1 +
      (stateEstimator_B.VectorConcatenate[stateEstimator_B.j + 3] *
       stateEstimator_B.inverseIMU_gain[4] +
       stateEstimator_B.VectorConcatenate[stateEstimator_B.j] *
       stateEstimator_B.inverseIMU_gain[3]);
  }

  /* End of Product: '<S2>/Product' */

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Gain'
   */
  rtb_Sum_k_idx_2 = stateEstimator_P.Gain_Gain_b * stateEstimator_B.sincos_o1[0]
    + rtb_sincos_o2_idx_2;

  /* DiscreteFir: '<S5>/FIR_IMUaccel' */
  rtb_sincos_o2_idx_2 = stateEstimator_B.inverseIMU_gain[0] *
    stateEstimator_P.FIR_IMUaccel_Coefficients[0];
  stateEstimator_B.cff = 1;
  stateEstimator_B.j = stateEstimator_DW.FIR_IMUaccel_circBuf;
  while (stateEstimator_B.j < 5) {
    rtb_sincos_o2_idx_2 +=
      stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_B.j] *
      stateEstimator_P.FIR_IMUaccel_Coefficients[stateEstimator_B.cff];
    stateEstimator_B.cff++;
    stateEstimator_B.j++;
  }

  stateEstimator_B.j = 0;
  while (stateEstimator_B.j < stateEstimator_DW.FIR_IMUaccel_circBuf) {
    rtb_sincos_o2_idx_2 +=
      stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_B.j] *
      stateEstimator_P.FIR_IMUaccel_Coefficients[stateEstimator_B.cff];
    stateEstimator_B.cff++;
    stateEstimator_B.j++;
  }

  stateEstimator_B.FIR_IMUaccel[0] = rtb_sincos_o2_idx_2;

  /* Math: '<S2>/Math Function' incorporates:
   *  Constant: '<S2>/Constant'
   *  DiscreteFir: '<S5>/FIR_IMUaccel'
   */
  stateEstimator_B.DataTypeConversion2 = (real32_T)floor
    (stateEstimator_P.Constant_Value_n);
  if ((rtb_sincos_o2_idx_2 < 0.0F) && (stateEstimator_P.Constant_Value_n >
       stateEstimator_B.DataTypeConversion2)) {
    stateEstimator_B.sincos_o1[0] = -rt_powf_snf(-rtb_sincos_o2_idx_2,
      stateEstimator_P.Constant_Value_n);
  } else {
    stateEstimator_B.sincos_o1[0] = rt_powf_snf(rtb_sincos_o2_idx_2,
      stateEstimator_P.Constant_Value_n);
  }

  /* DiscreteFir: '<S5>/FIR_IMUaccel' */
  rtb_sincos_o2_idx_2 = stateEstimator_B.inverseIMU_gain[1] *
    stateEstimator_P.FIR_IMUaccel_Coefficients[0];
  stateEstimator_B.cff = 1;
  stateEstimator_B.j = stateEstimator_DW.FIR_IMUaccel_circBuf;
  while (stateEstimator_B.j < 5) {
    rtb_sincos_o2_idx_2 += stateEstimator_DW.FIR_IMUaccel_states[5 +
      stateEstimator_B.j] *
      stateEstimator_P.FIR_IMUaccel_Coefficients[stateEstimator_B.cff];
    stateEstimator_B.cff++;
    stateEstimator_B.j++;
  }

  stateEstimator_B.j = 0;
  while (stateEstimator_B.j < stateEstimator_DW.FIR_IMUaccel_circBuf) {
    rtb_sincos_o2_idx_2 += stateEstimator_DW.FIR_IMUaccel_states[5 +
      stateEstimator_B.j] *
      stateEstimator_P.FIR_IMUaccel_Coefficients[stateEstimator_B.cff];
    stateEstimator_B.cff++;
    stateEstimator_B.j++;
  }

  stateEstimator_B.FIR_IMUaccel[1] = rtb_sincos_o2_idx_2;

  /* Math: '<S2>/Math Function' incorporates:
   *  Constant: '<S2>/Constant'
   *  DiscreteFir: '<S5>/FIR_IMUaccel'
   */
  if ((rtb_sincos_o2_idx_2 < 0.0F) && (stateEstimator_P.Constant_Value_n >
       stateEstimator_B.DataTypeConversion2)) {
    y = -rt_powf_snf(-rtb_sincos_o2_idx_2, stateEstimator_P.Constant_Value_n);
  } else {
    y = rt_powf_snf(rtb_sincos_o2_idx_2, stateEstimator_P.Constant_Value_n);
  }

  /* DiscreteFir: '<S5>/FIR_IMUaccel' */
  rtb_sincos_o2_idx_2 = stateEstimator_B.inverseIMU_gain[2] *
    stateEstimator_P.FIR_IMUaccel_Coefficients[0];
  stateEstimator_B.cff = 1;
  stateEstimator_B.j = stateEstimator_DW.FIR_IMUaccel_circBuf;
  while (stateEstimator_B.j < 5) {
    rtb_sincos_o2_idx_2 += stateEstimator_DW.FIR_IMUaccel_states[10 +
      stateEstimator_B.j] *
      stateEstimator_P.FIR_IMUaccel_Coefficients[stateEstimator_B.cff];
    stateEstimator_B.cff++;
    stateEstimator_B.j++;
  }

  stateEstimator_B.j = 0;
  while (stateEstimator_B.j < stateEstimator_DW.FIR_IMUaccel_circBuf) {
    rtb_sincos_o2_idx_2 += stateEstimator_DW.FIR_IMUaccel_states[10 +
      stateEstimator_B.j] *
      stateEstimator_P.FIR_IMUaccel_Coefficients[stateEstimator_B.cff];
    stateEstimator_B.cff++;
    stateEstimator_B.j++;
  }

  stateEstimator_B.FIR_IMUaccel[2] = rtb_sincos_o2_idx_2;

  /* Math: '<S2>/Math Function' incorporates:
   *  Constant: '<S2>/Constant'
   *  DiscreteFir: '<S5>/FIR_IMUaccel'
   */
  if ((rtb_sincos_o2_idx_2 < 0.0F) && (stateEstimator_P.Constant_Value_n >
       stateEstimator_B.DataTypeConversion2)) {
    stateEstimator_B.DataTypeConversion2 = -rt_powf_snf(-rtb_sincos_o2_idx_2,
      stateEstimator_P.Constant_Value_n);
  } else {
    stateEstimator_B.DataTypeConversion2 = rt_powf_snf(rtb_sincos_o2_idx_2,
      stateEstimator_P.Constant_Value_n);
  }

  /* Sqrt: '<S2>/Sqrt' incorporates:
   *  Math: '<S2>/Math Function'
   *  Sum: '<S2>/Sum of Elements'
   */
  stateEstimator_B.DataTypeConversion2 = (real32_T)sqrt
    ((stateEstimator_B.sincos_o1[0] + y) + stateEstimator_B.DataTypeConversion2);

  /* If: '<S2>/If' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Gain: '<S2>/Gain'
   *  Inport: '<S10>/prin'
   *  Logic: '<S2>/Logical Operator'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  Sum: '<S2>/Sum'
   */
  if ((stateEstimator_B.DataTypeConversion2 >
       stateEstimator_P.CompareToConstant_const) &&
      (stateEstimator_B.DataTypeConversion2 <
       stateEstimator_P.CompareToConstant1_const)) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Sum: '<S8>/Sum' incorporates:
     *  DiscreteFir: '<S5>/FIR_IMUaccel'
     *  Gain: '<S2>/Gain'
     *  Gain: '<S8>/Gain'
     *  Gain: '<S8>/Gain1'
     *  Product: '<S8>/Divide'
     *  Sum: '<S2>/Sum'
     *  Trigonometry: '<S8>/Trigonometric Function'
     */
    stateEstimator_B.Merge[1] = (stateEstimator_P.Gain_Gain_b *
      stateEstimator_B.sincos_o1[2] + rtb_sincos_o2_idx_0) *
      stateEstimator_P.Gain_Gain + (real32_T)atan(stateEstimator_B.FIR_IMUaccel
      [1] / rtb_sincos_o2_idx_2) * stateEstimator_P.Gain1_Gain;

    /* Gain: '<S8>/Gain2' */
    rtb_sincos_o2_idx_0 = stateEstimator_P.Gain2_Gain *
      stateEstimator_B.FIR_IMUaccel[0];

    /* Trigonometry: '<S8>/Trigonometric Function1' */
    if (rtb_sincos_o2_idx_0 > 1.0F) {
      rtb_sincos_o2_idx_0 = 1.0F;
    } else {
      if (rtb_sincos_o2_idx_0 < -1.0F) {
        rtb_sincos_o2_idx_0 = -1.0F;
      }
    }

    /* Sum: '<S8>/Sum1' incorporates:
     *  Gain: '<S2>/Gain'
     *  Gain: '<S8>/Gain3'
     *  Gain: '<S8>/Gain4'
     *  Sum: '<S2>/Sum'
     *  Trigonometry: '<S8>/Trigonometric Function1'
     */
    stateEstimator_B.Merge[0] = (stateEstimator_P.Gain_Gain_b *
      stateEstimator_B.sincos_o1[1] + rtb_sincos_o2_idx_1) *
      stateEstimator_P.Gain4_Gain + stateEstimator_P.Gain3_Gain * (real32_T)asin
      (rtb_sincos_o2_idx_0);

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    stateEstimator_B.Merge[0] = stateEstimator_P.Gain_Gain_b *
      stateEstimator_B.sincos_o1[1] + rtb_sincos_o2_idx_1;
    stateEstimator_B.Merge[1] = stateEstimator_P.Gain_Gain_b *
      stateEstimator_B.sincos_o1[2] + rtb_sincos_o2_idx_0;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
  }

  /* End of If: '<S2>/If' */

  /* If: '<S2>/If1' incorporates:
   *  Constant: '<S185>/Constant'
   *  Inport: '<Root>/posVIS_datin'
   *  Inport: '<Root>/usePosVIS_flagin'
   *  Logic: '<S5>/Logical Operator'
   *  RelationalOperator: '<S185>/Compare'
   */
  if ((stateEstimator_U.posVIS_datin[0] !=
       stateEstimator_P.Checkifvalidvisualpositionestimateavailable_const) &&
      (arg_usePosVIS_flagin != 0.0F)) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
     *  Gain: '<S9>/Gain'
     *  Gain: '<S9>/Gain1'
     *  Sum: '<S9>/Sum'
     */
    stateEstimator_DW.Memory_PreviousInput[0] = stateEstimator_P.Gain_Gain_i *
      rtb_Sum_k_idx_2 + stateEstimator_P.Gain1_Gain_k *
      stateEstimator_U.posVIS_datin[3];

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
     *  Inport: '<S11>/yawin'
     */
    stateEstimator_DW.Memory_PreviousInput[0] = rtb_Sum_k_idx_2;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
  }

  /* End of If: '<S2>/If1' */

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  stateEstimator_DW.Memory_PreviousInput[1] = stateEstimator_B.Merge[0];
  stateEstimator_DW.Memory_PreviousInput[2] = stateEstimator_B.Merge[1];

  /* Trigonometry: '<S16>/sincos' incorporates:
   *  Trigonometry: '<S135>/sincos'
   *  Trigonometry: '<S73>/sincos'
   */
  rtb_sincos_o2_idx_1 = (real32_T)sin(stateEstimator_DW.Memory_PreviousInput[0]);
  rtb_sincos_o2_idx_0 = (real32_T)cos(stateEstimator_DW.Memory_PreviousInput[0]);
  stateEstimator_B.DataTypeConversion2 = (real32_T)sin
    (stateEstimator_DW.Memory_PreviousInput[1]);
  rtb_Sum_k_idx_2 = (real32_T)cos(stateEstimator_DW.Memory_PreviousInput[1]);
  y = (real32_T)sin(stateEstimator_DW.Memory_PreviousInput[2]);
  rtb_sincos_o2_idx_2_tmp = (real32_T)cos
    (stateEstimator_DW.Memory_PreviousInput[2]);

  /* Fcn: '<S16>/Fcn11' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  stateEstimator_B.VectorConcatenate[0] = rtb_Sum_k_idx_2 * rtb_sincos_o2_idx_0;

  /* Fcn: '<S16>/Fcn21' incorporates:
   *  Fcn: '<S16>/Fcn22'
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_tmp = y * stateEstimator_B.DataTypeConversion2;
  stateEstimator_B.VectorConcatenate[1] = rtb_VectorConcatenate_tmp *
    rtb_sincos_o2_idx_0 - rtb_sincos_o2_idx_2_tmp * rtb_sincos_o2_idx_1;

  /* Fcn: '<S16>/Fcn31' incorporates:
   *  Fcn: '<S16>/Fcn32'
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_tmp_0 = rtb_sincos_o2_idx_2_tmp *
    stateEstimator_B.DataTypeConversion2;
  stateEstimator_B.VectorConcatenate[2] = rtb_VectorConcatenate_tmp_0 *
    rtb_sincos_o2_idx_0 + y * rtb_sincos_o2_idx_1;

  /* Fcn: '<S16>/Fcn12' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  stateEstimator_B.VectorConcatenate[3] = rtb_Sum_k_idx_2 * rtb_sincos_o2_idx_1;

  /* Fcn: '<S16>/Fcn22' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  stateEstimator_B.VectorConcatenate[4] = rtb_VectorConcatenate_tmp *
    rtb_sincos_o2_idx_1 + rtb_sincos_o2_idx_2_tmp * rtb_sincos_o2_idx_0;

  /* Fcn: '<S16>/Fcn32' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  stateEstimator_B.VectorConcatenate[5] = rtb_VectorConcatenate_tmp_0 *
    rtb_sincos_o2_idx_1 - y * rtb_sincos_o2_idx_0;

  /* Fcn: '<S16>/Fcn13' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  stateEstimator_B.VectorConcatenate[6] = -stateEstimator_B.DataTypeConversion2;

  /* Fcn: '<S16>/Fcn23' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  stateEstimator_B.VectorConcatenate[7] = y * rtb_Sum_k_idx_2;

  /* Fcn: '<S16>/Fcn33' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  stateEstimator_B.VectorConcatenate[8] = rtb_sincos_o2_idx_2_tmp *
    rtb_Sum_k_idx_2;

  /* Fcn: '<S73>/Fcn11' */
  stateEstimator_B.Reshape9to3x3columnmajor[0] = rtb_Sum_k_idx_2 *
    rtb_sincos_o2_idx_0;

  /* Fcn: '<S73>/Fcn21' incorporates:
   *  Fcn: '<S73>/Fcn22'
   */
  rtb_VectorConcatenate_tmp = y * stateEstimator_B.DataTypeConversion2;
  stateEstimator_B.Reshape9to3x3columnmajor[1] = rtb_VectorConcatenate_tmp *
    rtb_sincos_o2_idx_0 - rtb_sincos_o2_idx_2_tmp * rtb_sincos_o2_idx_1;

  /* Fcn: '<S73>/Fcn31' incorporates:
   *  Fcn: '<S73>/Fcn32'
   */
  rtb_VectorConcatenate_tmp_0 = rtb_sincos_o2_idx_2_tmp *
    stateEstimator_B.DataTypeConversion2;
  stateEstimator_B.Reshape9to3x3columnmajor[2] = rtb_VectorConcatenate_tmp_0 *
    rtb_sincos_o2_idx_0 + y * rtb_sincos_o2_idx_1;

  /* Fcn: '<S73>/Fcn12' */
  stateEstimator_B.Reshape9to3x3columnmajor[3] = rtb_Sum_k_idx_2 *
    rtb_sincos_o2_idx_1;

  /* Fcn: '<S73>/Fcn22' */
  stateEstimator_B.Reshape9to3x3columnmajor[4] = rtb_VectorConcatenate_tmp *
    rtb_sincos_o2_idx_1 + rtb_sincos_o2_idx_2_tmp * rtb_sincos_o2_idx_0;

  /* Fcn: '<S73>/Fcn32' */
  stateEstimator_B.Reshape9to3x3columnmajor[5] = rtb_VectorConcatenate_tmp_0 *
    rtb_sincos_o2_idx_1 - y * rtb_sincos_o2_idx_0;

  /* Fcn: '<S73>/Fcn13' */
  stateEstimator_B.Reshape9to3x3columnmajor[6] =
    -stateEstimator_B.DataTypeConversion2;

  /* Fcn: '<S73>/Fcn23' */
  stateEstimator_B.Reshape9to3x3columnmajor[7] = y * rtb_Sum_k_idx_2;

  /* Fcn: '<S73>/Fcn33' */
  stateEstimator_B.Reshape9to3x3columnmajor[8] = rtb_sincos_o2_idx_2_tmp *
    rtb_Sum_k_idx_2;

  /* Fcn: '<S135>/Fcn11' */
  stateEstimator_B.MathFunction_b[0] = rtb_Sum_k_idx_2 * rtb_sincos_o2_idx_0;

  /* Fcn: '<S135>/Fcn21' */
  stateEstimator_B.MathFunction_b[1] = y * stateEstimator_B.DataTypeConversion2 *
    rtb_sincos_o2_idx_0 - rtb_sincos_o2_idx_2_tmp * rtb_sincos_o2_idx_1;

  /* Fcn: '<S135>/Fcn31' */
  stateEstimator_B.MathFunction_b[2] = rtb_sincos_o2_idx_2_tmp *
    stateEstimator_B.DataTypeConversion2 * rtb_sincos_o2_idx_0 + y *
    rtb_sincos_o2_idx_1;

  /* Fcn: '<S135>/Fcn12' */
  stateEstimator_B.MathFunction_b[3] = rtb_Sum_k_idx_2 * rtb_sincos_o2_idx_1;

  /* Fcn: '<S135>/Fcn22' */
  stateEstimator_B.MathFunction_b[4] = y * stateEstimator_B.DataTypeConversion2 *
    rtb_sincos_o2_idx_1 + rtb_sincos_o2_idx_2_tmp * rtb_sincos_o2_idx_0;

  /* Fcn: '<S135>/Fcn32' */
  stateEstimator_B.MathFunction_b[5] = rtb_sincos_o2_idx_2_tmp *
    stateEstimator_B.DataTypeConversion2 * rtb_sincos_o2_idx_1 - y *
    rtb_sincos_o2_idx_0;

  /* Fcn: '<S135>/Fcn13' */
  stateEstimator_B.MathFunction_b[6] = -stateEstimator_B.DataTypeConversion2;

  /* Fcn: '<S135>/Fcn23' */
  stateEstimator_B.MathFunction_b[7] = y * rtb_Sum_k_idx_2;

  /* Fcn: '<S135>/Fcn33' */
  stateEstimator_B.MathFunction_b[8] = rtb_sincos_o2_idx_2_tmp * rtb_Sum_k_idx_2;

  /* Math: '<S68>/Math Function' */
  for (stateEstimator_B.j = 0; stateEstimator_B.j < 3; stateEstimator_B.j++) {
    stateEstimator_B.rtb_MathFunction_b_m[3 * stateEstimator_B.j] =
      stateEstimator_B.MathFunction_b[stateEstimator_B.j];
    stateEstimator_B.rtb_MathFunction_b_m[1 + 3 * stateEstimator_B.j] =
      stateEstimator_B.MathFunction_b[stateEstimator_B.j + 3];
    stateEstimator_B.rtb_MathFunction_b_m[2 + 3 * stateEstimator_B.j] =
      stateEstimator_B.MathFunction_b[stateEstimator_B.j + 6];
  }

  for (stateEstimator_B.j = 0; stateEstimator_B.j < 9; stateEstimator_B.j++) {
    stateEstimator_B.MathFunction_b[stateEstimator_B.j] =
      stateEstimator_B.rtb_MathFunction_b_m[stateEstimator_B.j];
  }

  /* End of Math: '<S68>/Math Function' */

  /* DataTypeConversion: '<S175>/Conversion' incorporates:
   *  Constant: '<S136>/KalmanGainM'
   */
  stateEstimator_B.rtb_Conversion_g_c[0] = (real32_T)
    stateEstimator_P.KalmanGainM_Value[0];

  /* DataTypeConversion: '<S128>/Conversion' incorporates:
   *  Constant: '<S89>/KalmanGainM'
   */
  stateEstimator_B.rtb_Conversion_p_b[0] = (real32_T)
    stateEstimator_P.KalmanGainM_Value_d[0];

  /* DataTypeConversion: '<S127>/Conversion' incorporates:
   *  Constant: '<S89>/KalmanGainL'
   */
  stateEstimator_B.rtb_Conversion_n4_p[0] = (real32_T)
    stateEstimator_P.KalmanGainL_Value[0];

  /* DataTypeConversion: '<S174>/Conversion' incorporates:
   *  Constant: '<S136>/KalmanGainL'
   */
  stateEstimator_B.rtb_Conversion_a_c[0] = (real32_T)
    stateEstimator_P.KalmanGainL_Value_h[0];

  /* DataTypeConversion: '<S175>/Conversion' incorporates:
   *  Constant: '<S136>/KalmanGainM'
   */
  stateEstimator_B.rtb_Conversion_g_c[1] = (real32_T)
    stateEstimator_P.KalmanGainM_Value[1];

  /* DataTypeConversion: '<S128>/Conversion' incorporates:
   *  Constant: '<S89>/KalmanGainM'
   */
  stateEstimator_B.rtb_Conversion_p_b[1] = (real32_T)
    stateEstimator_P.KalmanGainM_Value_d[1];

  /* DataTypeConversion: '<S127>/Conversion' incorporates:
   *  Constant: '<S89>/KalmanGainL'
   */
  stateEstimator_B.rtb_Conversion_n4_p[1] = (real32_T)
    stateEstimator_P.KalmanGainL_Value[1];

  /* DataTypeConversion: '<S174>/Conversion' incorporates:
   *  Constant: '<S136>/KalmanGainL'
   */
  stateEstimator_B.rtb_Conversion_a_c[1] = (real32_T)
    stateEstimator_P.KalmanGainL_Value_h[1];

  /* DataTypeConversion: '<S175>/Conversion' incorporates:
   *  Constant: '<S136>/KalmanGainM'
   */
  stateEstimator_B.rtb_Conversion_g_c[2] = (real32_T)
    stateEstimator_P.KalmanGainM_Value[2];

  /* DataTypeConversion: '<S128>/Conversion' incorporates:
   *  Constant: '<S89>/KalmanGainM'
   */
  stateEstimator_B.rtb_Conversion_p_b[2] = (real32_T)
    stateEstimator_P.KalmanGainM_Value_d[2];

  /* DataTypeConversion: '<S127>/Conversion' incorporates:
   *  Constant: '<S89>/KalmanGainL'
   */
  stateEstimator_B.rtb_Conversion_n4_p[2] = (real32_T)
    stateEstimator_P.KalmanGainL_Value[2];

  /* DataTypeConversion: '<S174>/Conversion' incorporates:
   *  Constant: '<S136>/KalmanGainL'
   */
  stateEstimator_B.rtb_Conversion_a_c[2] = (real32_T)
    stateEstimator_P.KalmanGainL_Value_h[2];

  /* DataTypeConversion: '<S175>/Conversion' incorporates:
   *  Constant: '<S136>/KalmanGainM'
   */
  stateEstimator_B.rtb_Conversion_g_c[3] = (real32_T)
    stateEstimator_P.KalmanGainM_Value[3];

  /* DataTypeConversion: '<S128>/Conversion' incorporates:
   *  Constant: '<S89>/KalmanGainM'
   */
  stateEstimator_B.rtb_Conversion_p_b[3] = (real32_T)
    stateEstimator_P.KalmanGainM_Value_d[3];

  /* DataTypeConversion: '<S127>/Conversion' incorporates:
   *  Constant: '<S89>/KalmanGainL'
   */
  stateEstimator_B.rtb_Conversion_n4_p[3] = (real32_T)
    stateEstimator_P.KalmanGainL_Value[3];

  /* DataTypeConversion: '<S174>/Conversion' incorporates:
   *  Constant: '<S136>/KalmanGainL'
   */
  stateEstimator_B.rtb_Conversion_a_c[3] = (real32_T)
    stateEstimator_P.KalmanGainL_Value_h[3];

  /* Delay: '<S71>/MemoryX' incorporates:
   *  Constant: '<S71>/X0'
   *  DiscreteFilter: '<S70>/IIRgyroz'
   *  Reshape: '<S71>/ReshapeX0'
   *  SampleTimeMath: '<S77>/TSamp'
   *
   * About '<S77>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  if (stateEstimator_DW.icLoad != 0) {
    stateEstimator_DW.MemoryX_DSTATE_d[0] = stateEstimator_P.X0_Value_e[0];
    stateEstimator_DW.MemoryX_DSTATE_d[1] = stateEstimator_P.X0_Value_e[1];
  }

  for (i = 0; i < 2; i++) {
    stateEstimator_B.rtb_MemoryX_m_g[i] = stateEstimator_DW.MemoryX_DSTATE_d[i];

    /* DiscreteFilter: '<S70>/IIRgyroz' */
    stateEstimator_B.cff = i * 5;
    rtb_sincos_o2_idx_1 = stateEstimator_B.inverseIMU_gain[i + 3];
    stateEstimator_B.denIdx = 1;
    for (stateEstimator_B.j = 0; stateEstimator_B.j < 5; stateEstimator_B.j++) {
      rtb_sincos_o2_idx_1 -=
        stateEstimator_DW.IIRgyroz_states[stateEstimator_B.cff +
        stateEstimator_B.j] *
        stateEstimator_P.IIRgyroz_DenCoef[stateEstimator_B.denIdx];
      stateEstimator_B.denIdx++;
    }

    rtb_sincos_o2_idx_1 /= stateEstimator_P.IIRgyroz_DenCoef[0];
    rtb_sincos_o2_idx_0 = stateEstimator_P.IIRgyroz_NumCoef[0] *
      rtb_sincos_o2_idx_1;
    stateEstimator_B.denIdx = 1;
    for (stateEstimator_B.j = 0; stateEstimator_B.j < 5; stateEstimator_B.j++) {
      rtb_sincos_o2_idx_0 +=
        stateEstimator_DW.IIRgyroz_states[stateEstimator_B.cff +
        stateEstimator_B.j] *
        stateEstimator_P.IIRgyroz_NumCoef[stateEstimator_B.denIdx];
      stateEstimator_B.denIdx++;
    }

    /* SampleTimeMath: '<S77>/TSamp' incorporates:
     *  DiscreteFilter: '<S70>/IIRgyroz'
     *
     * About '<S77>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_sincos_o2_idx_0 *= stateEstimator_P.TSamp_WtEt;

    /* Sum: '<S77>/Diff' incorporates:
     *  UnitDelay: '<S77>/UD'
     *
     * Block description for '<S77>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S77>/UD':
     *
     *  Store in Global RAM
     */
    stateEstimator_DW.UD_DSTATE[i] = rtb_sincos_o2_idx_0 -
      stateEstimator_DW.UD_DSTATE[i];
    stateEstimator_B.IIRgyroz_tmp[i] = rtb_sincos_o2_idx_1;
    stateEstimator_B.TSamp[i] = rtb_sincos_o2_idx_0;
  }

  /* End of Delay: '<S71>/MemoryX' */

  /* Gain: '<S67>/opticalFlowToVelocity_gain' incorporates:
   *  Inport: '<Root>/opticalFlow_datin'
   */
  stateEstimator_B.opticalFlowToVelocity_gain[0] =
    stateEstimator_P.opticalFlowToVelocity_gain_Gain * arg_opticalFlow_datin[0];
  stateEstimator_B.opticalFlowToVelocity_gain[1] =
    stateEstimator_P.opticalFlowToVelocity_gain_Gain * arg_opticalFlow_datin[1];
  stateEstimator_B.opticalFlowToVelocity_gain[2] =
    stateEstimator_P.opticalFlowToVelocity_gain_Gain * arg_opticalFlow_datin[2];

  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  Constant: '<S17>/Constant'
   *  Delay: '<S3>/Delay2'
   */
  stateEstimator_B.Compare = (stateEstimator_DW.Delay2_DSTATE >
    stateEstimator_P.outlierBelowFloor_const);

  /* Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S14>/X0'
   *  DataTypeConversion: '<S14>/DataTypeConversionReset'
   *  Reshape: '<S14>/ReshapeX0'
   */
  if (stateEstimator_B.Compare) {
    stateEstimator_DW.icLoad_p = 1U;
  }

  if (stateEstimator_DW.icLoad_p != 0) {
    stateEstimator_DW.MemoryX_DSTATE[0] = stateEstimator_P.X0_Value[0];
    stateEstimator_DW.MemoryX_DSTATE[1] = stateEstimator_P.X0_Value[1];
  }

  /* Gain: '<S3>/invertzaxisGain' incorporates:
   *  Inport: '<Root>/sensordata_datin'
   */
  stateEstimator_B.invertzaxisGain = (real_T)
    stateEstimator_P.invertzaxisGain_Gain * arg_sensordata_datin->altitude_sonar;

  /* DiscreteFilter: '<S15>/pressureFilter_IIR' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Gain: '<S3>/prsToAltGain'
   *  Inport: '<Root>/sensorCalibration_datin'
   *  Inport: '<Root>/sensordata_datin'
   *  Sum: '<S5>/Sum2'
   */
  rtb_sincos_o2_idx_1 = ((((arg_sensordata_datin->prs -
    arg_sensorCalibration_datin[6]) * stateEstimator_P.prsToAltGain_Gain -
    stateEstimator_P.pressureFilter_IIR_DenCoef[1] *
    stateEstimator_DW.pressureFilter_IIR_states[0]) -
    stateEstimator_P.pressureFilter_IIR_DenCoef[2] *
    stateEstimator_DW.pressureFilter_IIR_states[1]) -
    stateEstimator_P.pressureFilter_IIR_DenCoef[3] *
    stateEstimator_DW.pressureFilter_IIR_states[2]) /
    stateEstimator_P.pressureFilter_IIR_DenCoef[0];

  /* DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_B.denAccum = (((stateEstimator_B.invertzaxisGain -
    stateEstimator_P.soonarFilter_IIR_DenCoef[1] *
    stateEstimator_DW.soonarFilter_IIR_states[0]) -
    stateEstimator_P.soonarFilter_IIR_DenCoef[2] *
    stateEstimator_DW.soonarFilter_IIR_states[1]) -
    stateEstimator_P.soonarFilter_IIR_DenCoef[3] *
    stateEstimator_DW.soonarFilter_IIR_states[2]) /
    stateEstimator_P.soonarFilter_IIR_DenCoef[0];

  /* Saturate: '<S15>/SaturationSonar' */
  if (stateEstimator_B.invertzaxisGain > -stateEstimator_P.Sensors.altSensorMin)
  {
    stateEstimator_B.Sum_f = -stateEstimator_P.Sensors.altSensorMin;
  } else if (stateEstimator_B.invertzaxisGain <
             stateEstimator_P.SaturationSonar_LowerSat) {
    stateEstimator_B.Sum_f = stateEstimator_P.SaturationSonar_LowerSat;
  } else {
    stateEstimator_B.Sum_f = stateEstimator_B.invertzaxisGain;
  }

  /* End of Saturate: '<S15>/SaturationSonar' */

  /* Logic: '<S15>/nicemeasurementor newupdateneeded' incorporates:
   *  Abs: '<S15>/Absestdiff'
   *  Abs: '<S15>/Absestdiff1'
   *  Abs: '<S15>/Absestdiff2'
   *  Constant: '<S62>/Constant'
   *  Constant: '<S63>/Constant'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Delay: '<S3>/Delay2'
   *  DiscreteFilter: '<S15>/pressureFilter_IIR'
   *  DiscreteFilter: '<S15>/soonarFilter_IIR'
   *  Logic: '<S15>/findingoutliers'
   *  Logic: '<S15>/newupdateneeded'
   *  RelationalOperator: '<S62>/Compare'
   *  RelationalOperator: '<S63>/Compare'
   *  RelationalOperator: '<S64>/Compare'
   *  RelationalOperator: '<S65>/Compare'
   *  Sum: '<S15>/Add'
   *  Sum: '<S15>/Add1'
   *  Sum: '<S15>/Add2'
   */
  stateEstimator_B.nicemeasurementornewupdateneeded = (((fabs
    (stateEstimator_DW.Delay2_DSTATE - stateEstimator_B.Sum_f) <=
    stateEstimator_P.outlierJump_const) && (stateEstimator_B.invertzaxisGain <
    -stateEstimator_P.Sensors.altSensorMin)) || ((fabs
    ((((stateEstimator_P.pressureFilter_IIR_NumCoef[0] * rtb_sincos_o2_idx_1 +
        stateEstimator_P.pressureFilter_IIR_NumCoef[1] *
        stateEstimator_DW.pressureFilter_IIR_states[0]) +
       stateEstimator_P.pressureFilter_IIR_NumCoef[2] *
       stateEstimator_DW.pressureFilter_IIR_states[1]) +
      stateEstimator_P.pressureFilter_IIR_NumCoef[3] *
      stateEstimator_DW.pressureFilter_IIR_states[2]) -
     stateEstimator_DW.Delay2_DSTATE) >=
    stateEstimator_P.currentEstimateVeryOffFromPressure_const) && (fabs
    ((((stateEstimator_P.soonarFilter_IIR_NumCoef[0] * stateEstimator_B.denAccum
        + stateEstimator_P.soonarFilter_IIR_NumCoef[1] *
        stateEstimator_DW.soonarFilter_IIR_states[0]) +
       stateEstimator_P.soonarFilter_IIR_NumCoef[2] *
       stateEstimator_DW.soonarFilter_IIR_states[1]) +
      stateEstimator_P.soonarFilter_IIR_NumCoef[3] *
      stateEstimator_DW.soonarFilter_IIR_states[2]) -
     stateEstimator_DW.Delay2_DSTATE) >=
    stateEstimator_P.currentStateVeryOffsonarflt_const)));

  /* Outputs for Enabled SubSystem: '<S40>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S61>/Enable'
   */
  /* DataTypeConversion: '<S14>/DataTypeConversionEnable' */
  if (stateEstimator_B.nicemeasurementornewupdateneeded) {
    if (!stateEstimator_DW.EnabledSubsystem_MODE) {
      stateEstimator_DW.EnabledSubsystem_MODE = true;
    }

    /* Sum: '<S61>/Add1' incorporates:
     *  Constant: '<S14>/C'
     *  Delay: '<S14>/MemoryX'
     *  Product: '<S61>/Product'
     *  Reshape: '<S14>/Reshapey'
     */
    stateEstimator_B.Sum_f = stateEstimator_B.invertzaxisGain -
      (stateEstimator_P.C_Value[0] * stateEstimator_DW.MemoryX_DSTATE[0] +
       stateEstimator_P.C_Value[1] * stateEstimator_DW.MemoryX_DSTATE[1]);

    /* Product: '<S61>/Product2' incorporates:
     *  Constant: '<S18>/KalmanGainM'
     *  DataTypeConversion: '<S57>/Conversion'
     */
    stateEstimator_B.Product2[0] = stateEstimator_P.KalmanGainM_Value_p[0] *
      stateEstimator_B.Sum_f;
    stateEstimator_B.Product2[1] = stateEstimator_P.KalmanGainM_Value_p[1] *
      stateEstimator_B.Sum_f;
  } else {
    if (stateEstimator_DW.EnabledSubsystem_MODE) {
      /* Disable for Outport: '<S61>/deltax' */
      stateEstimator_B.Product2[0] = stateEstimator_P.deltax_Y0;
      stateEstimator_B.Product2[1] = stateEstimator_P.deltax_Y0;
      stateEstimator_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S40>/Enabled Subsystem' */

  /* Reshape: '<S14>/Reshapexhat' incorporates:
   *  Delay: '<S14>/MemoryX'
   *  Sum: '<S40>/Add'
   */
  stateEstimator_DW.Delay2_DSTATE = stateEstimator_B.Product2[0] +
    stateEstimator_DW.MemoryX_DSTATE[0];

  /* Reshape: '<S71>/Reshapey' */
  stateEstimator_B.rtb_Reshapey_o_g[0] =
    stateEstimator_B.opticalFlowToVelocity_gain[0];

  /* Sum: '<S40>/Add' incorporates:
   *  Delay: '<S14>/MemoryX'
   */
  stateEstimator_B.Sum_f = stateEstimator_B.Product2[1] +
    stateEstimator_DW.MemoryX_DSTATE[1];

  /* Reshape: '<S71>/Reshapey' */
  stateEstimator_B.rtb_Reshapey_o_g[1] =
    stateEstimator_B.opticalFlowToVelocity_gain[1];

  /* Abs: '<S70>/Abs' incorporates:
   *  Abs: '<S70>/Abs4'
   */
  rtb_sincos_o2_idx_0 = (real32_T)fabs(stateEstimator_B.inverseIMU_gain[3]);

  /* Abs: '<S70>/Abs1' incorporates:
   *  Abs: '<S70>/Abs5'
   */
  stateEstimator_B.DataTypeConversion2 = (real32_T)fabs
    (stateEstimator_B.inverseIMU_gain[4]);

  /* Abs: '<S70>/Abs2' incorporates:
   *  Abs: '<S134>/Abs'
   */
  rtb_Sum_k_idx_2 = (real32_T)fabs(stateEstimator_DW.Memory_PreviousInput[1]);

  /* Abs: '<S70>/Abs3' incorporates:
   *  Abs: '<S134>/Abs1'
   */
  y = (real32_T)fabs(stateEstimator_DW.Memory_PreviousInput[2]);

  /* Logic: '<S70>/Logical Operator3' incorporates:
   *  Abs: '<S70>/Abs'
   *  Abs: '<S70>/Abs1'
   *  Abs: '<S70>/Abs2'
   *  Abs: '<S70>/Abs3'
   *  Abs: '<S70>/Abs6'
   *  Abs: '<S70>/Abs7'
   *  Abs: '<S70>/Abs8'
   *  Abs: '<S70>/Abs9'
   *  Constant: '<S78>/Constant'
   *  Constant: '<S79>/Constant'
   *  Constant: '<S80>/Constant'
   *  Constant: '<S81>/Constant'
   *  Constant: '<S82>/Constant'
   *  Constant: '<S83>/Constant'
   *  Constant: '<S84>/Constant'
   *  Constant: '<S85>/Constant'
   *  Constant: '<S86>/Constant'
   *  Constant: '<S87>/Constant'
   *  Constant: '<S88>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Delay: '<S67>/Delay'
   *  Logic: '<S70>/Logical Operator'
   *  Logic: '<S70>/Logical Operator1'
   *  Logic: '<S70>/Logical Operator2'
   *  RelationalOperator: '<S78>/Compare'
   *  RelationalOperator: '<S79>/Compare'
   *  RelationalOperator: '<S80>/Compare'
   *  RelationalOperator: '<S81>/Compare'
   *  RelationalOperator: '<S82>/Compare'
   *  RelationalOperator: '<S83>/Compare'
   *  RelationalOperator: '<S84>/Compare'
   *  RelationalOperator: '<S85>/Compare'
   *  RelationalOperator: '<S86>/Compare'
   *  RelationalOperator: '<S87>/Compare'
   *  RelationalOperator: '<S88>/Compare'
   *  Reshape: '<S14>/Reshapexhat'
   *  Sum: '<S70>/Add'
   */
  stateEstimator_B.LogicalOperator3 = ((((rtb_Sum_k_idx_2 <=
    stateEstimator_P.maxp_const) && (y <= stateEstimator_P.maxq_const) &&
    (rtb_sincos_o2_idx_0 <= stateEstimator_P.maxw1_const) &&
    (stateEstimator_B.DataTypeConversion2 <= stateEstimator_P.maxw2_const) &&
    ((real32_T)fabs(stateEstimator_DW.UD_DSTATE[0]) <=
     stateEstimator_P.maxdw1_const) && ((real32_T)fabs
    (stateEstimator_DW.UD_DSTATE[1]) <= stateEstimator_P.maxdw2_const)) ||
    ((rtb_sincos_o2_idx_0 <= stateEstimator_P.maxp2_const) &&
     (stateEstimator_B.DataTypeConversion2 <= stateEstimator_P.maxq2_const))) &&
    ((real32_T)fabs(stateEstimator_B.opticalFlowToVelocity_gain[0] -
                    stateEstimator_DW.Delay_DSTATE[0]) <=
     stateEstimator_P.maxw3_const) && ((real32_T)fabs
    (stateEstimator_B.opticalFlowToVelocity_gain[1] -
     stateEstimator_DW.Delay_DSTATE[1]) <= stateEstimator_P.maxw4_const) &&
    ((real32_T)stateEstimator_DW.Delay2_DSTATE <=
     stateEstimator_P.minHeightforOF_const));

  /* DataTypeConversion: '<S71>/DataTypeConversionEnable' */
  rtb_DataTypeConversionEnable_o = stateEstimator_B.LogicalOperator3;

  /* Outputs for Enabled SubSystem: '<S111>/Enabled Subsystem' */
  /* Constant: '<S71>/C' */
  stateEstimator_EnabledSubsystem(rtb_DataTypeConversionEnable_o,
    stateEstimator_B.rtb_Conversion_p_b, stateEstimator_P.C_Value_f,
    stateEstimator_B.rtb_Reshapey_o_g, stateEstimator_B.rtb_MemoryX_m_g,
    stateEstimator_B.Product2_k, &stateEstimator_DW.EnabledSubsystem_f,
    &stateEstimator_P.EnabledSubsystem_f);

  /* End of Outputs for SubSystem: '<S111>/Enabled Subsystem' */

  /* Reshape: '<S71>/Reshapexhat' incorporates:
   *  Delay: '<S67>/Delay'
   *  Sum: '<S111>/Add'
   */
  stateEstimator_DW.Delay_DSTATE[0] = stateEstimator_B.Product2_k[0] +
    stateEstimator_B.rtb_MemoryX_m_g[0];
  stateEstimator_DW.Delay_DSTATE[1] = stateEstimator_B.Product2_k[1] +
    stateEstimator_B.rtb_MemoryX_m_g[1];

  /* Product: '<S3>/Product1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Delay: '<S1>/Delay1'
   *  Reshape: '<S14>/Reshapexhat'
   *  SignalConversion: '<S3>/TmpSignal ConversionAtProduct1Inport2'
   */
  for (stateEstimator_B.j = 0; stateEstimator_B.j < 3; stateEstimator_B.j++) {
    stateEstimator_B.rtb_VectorConcatenate_c[stateEstimator_B.j] =
      stateEstimator_B.VectorConcatenate[stateEstimator_B.j + 6] *
      stateEstimator_B.Sum_f + ((real_T)
      stateEstimator_B.VectorConcatenate[stateEstimator_B.j + 3] *
      stateEstimator_DW.Delay1_DSTATE[1] + (real_T)
      stateEstimator_B.VectorConcatenate[stateEstimator_B.j] *
      stateEstimator_DW.Delay1_DSTATE[0]);
  }

  /* End of Product: '<S3>/Product1' */

  /* RelationalOperator: '<S72>/Compare' incorporates:
   *  Constant: '<S72>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Reshape: '<S14>/Reshapexhat'
   */
  rtb_Compare_i = ((real32_T)stateEstimator_DW.Delay2_DSTATE <=
                   stateEstimator_P.DeactivateAccelerationIfOFisnotusedduetolowaltitude_const);

  /* Logic: '<S69>/Logical Operator' incorporates:
   *  Constant: '<S74>/Constant'
   *  Constant: '<S75>/Constant'
   *  RelationalOperator: '<S74>/Compare'
   *  RelationalOperator: '<S75>/Compare'
   */
  rtb_LogicalOperator_cg = ((stateEstimator_B.opticalFlowToVelocity_gain[0] !=
    stateEstimator_P.donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con)
    || (stateEstimator_B.opticalFlowToVelocity_gain[1] !=
        stateEstimator_P.donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co));
  for (stateEstimator_B.j = 0; stateEstimator_B.j < 3; stateEstimator_B.j++) {
    /* Product: '<S68>/Product' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion2'
     *  Delay: '<S67>/Delay'
     *  SignalConversion: '<S68>/TmpSignal ConversionAtProductInport2'
     */
    stateEstimator_B.Product[stateEstimator_B.j] = 0.0F;
    stateEstimator_B.Product[stateEstimator_B.j] +=
      stateEstimator_B.MathFunction_b[stateEstimator_B.j] *
      stateEstimator_DW.Delay_DSTATE[0];
    stateEstimator_B.Product[stateEstimator_B.j] +=
      stateEstimator_B.MathFunction_b[stateEstimator_B.j + 3] *
      stateEstimator_DW.Delay_DSTATE[1];
    stateEstimator_B.Product[stateEstimator_B.j] +=
      stateEstimator_B.MathFunction_b[stateEstimator_B.j + 6] * (real32_T)
      stateEstimator_B.rtb_VectorConcatenate_c[2];

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/gravity'
     *  DiscreteFir: '<S5>/FIR_IMUaccel'
     *  Math: '<S3>/Math Function'
     *  Product: '<S3>/Product'
     */
    stateEstimator_B.Sum[stateEstimator_B.j] =
      ((stateEstimator_B.VectorConcatenate[3 * stateEstimator_B.j + 1] *
        stateEstimator_B.FIR_IMUaccel[1] + stateEstimator_B.VectorConcatenate[3 *
        stateEstimator_B.j] * stateEstimator_B.FIR_IMUaccel[0]) +
       stateEstimator_B.VectorConcatenate[3 * stateEstimator_B.j + 2] *
       rtb_sincos_o2_idx_2) +
      stateEstimator_P.gravity_Value_k[stateEstimator_B.j];

    /* Sum: '<S69>/Add' incorporates:
     *  Constant: '<S69>/gravity'
     *  Product: '<S69>/Product1'
     */
    stateEstimator_B.rtb_FIR_IMUaccel_k[stateEstimator_B.j] =
      stateEstimator_B.FIR_IMUaccel[stateEstimator_B.j] -
      ((stateEstimator_B.Reshape9to3x3columnmajor[stateEstimator_B.j + 3] *
        stateEstimator_P.gravity_Value[1] +
        stateEstimator_B.Reshape9to3x3columnmajor[stateEstimator_B.j] *
        stateEstimator_P.gravity_Value[0]) +
       stateEstimator_B.Reshape9to3x3columnmajor[stateEstimator_B.j + 6] *
       stateEstimator_P.gravity_Value[2]);
  }

  /* Product: '<S69>/Product' incorporates:
   *  Gain: '<S69>/gainaccinput'
   */
  stateEstimator_B.Product_p[0] = (real32_T)(stateEstimator_P.gainaccinput_Gain *
    stateEstimator_B.rtb_FIR_IMUaccel_k[0]) * (real32_T)rtb_LogicalOperator_cg *
    (real32_T)rtb_Compare_i;

  /* Reshape: '<S71>/Reshapeu' */
  stateEstimator_B.rtb_Reshapeu_h_m[0] = stateEstimator_B.Product_p[0];

  /* DataTypeConversion: '<S102>/Conversion' */
  stateEstimator_B.rtb_Conversion_j_n[0] = stateEstimator_B.rtb_MemoryX_m_g[0];

  /* Product: '<S69>/Product' incorporates:
   *  Gain: '<S69>/gainaccinput'
   */
  stateEstimator_B.Product_p[1] = (real32_T)(stateEstimator_P.gainaccinput_Gain *
    stateEstimator_B.rtb_FIR_IMUaccel_k[1]) * (real32_T)rtb_LogicalOperator_cg *
    (real32_T)rtb_Compare_i;

  /* Reshape: '<S71>/Reshapeu' */
  stateEstimator_B.rtb_Reshapeu_h_m[1] = stateEstimator_B.Product_p[1];

  /* DataTypeConversion: '<S102>/Conversion' */
  stateEstimator_B.rtb_Conversion_j_n[1] = stateEstimator_B.rtb_MemoryX_m_g[1];

  /* Outputs for Enabled SubSystem: '<S106>/MeasurementUpdate' */
  /* Constant: '<S71>/C' incorporates:
   *  Constant: '<S71>/D'
   */
  stateEstimator_MeasurementUpdate(rtb_DataTypeConversionEnable_o,
    stateEstimator_B.rtb_Conversion_n4_p, stateEstimator_B.rtb_Reshapey_o_g,
    stateEstimator_P.C_Value_f, stateEstimator_B.rtb_Conversion_j_n,
    stateEstimator_P.D_Value_f, stateEstimator_B.rtb_Reshapeu_h_m,
    stateEstimator_B.Product3_m, &stateEstimator_DW.MeasurementUpdate_e,
    &stateEstimator_P.MeasurementUpdate_e);

  /* End of Outputs for SubSystem: '<S106>/MeasurementUpdate' */

  /* Reshape: '<S133>/Reshapeu' */
  stateEstimator_B.rtb_Reshapeu_i_p[0] = stateEstimator_B.Product[0];
  stateEstimator_B.rtb_Reshapeu_i_p[1] = stateEstimator_B.Product[1];

  /* Delay: '<S133>/MemoryX' incorporates:
   *  Constant: '<S133>/X0'
   *  Reshape: '<S133>/ReshapeX0'
   */
  if (stateEstimator_DW.icLoad_g != 0) {
    stateEstimator_DW.MemoryX_DSTATE_dl[0] = stateEstimator_P.X0_Value_j[0];
    stateEstimator_DW.MemoryX_DSTATE_dl[1] = stateEstimator_P.X0_Value_j[1];
  }

  /* DataTypeConversion: '<S149>/Conversion' incorporates:
   *  Delay: '<S133>/MemoryX'
   */
  stateEstimator_B.rtb_Conversion_pu_j[0] = stateEstimator_DW.MemoryX_DSTATE_dl
    [0];

  /* Sum: '<S134>/Add1' incorporates:
   *  Delay: '<S68>/Delay'
   *  Inport: '<Root>/posVIS_datin'
   */
  rtb_sincos_o2_idx_0 = stateEstimator_U.posVIS_datin[0] -
    stateEstimator_DW.Delay_DSTATE_l[0];

  /* Delay: '<S133>/MemoryX' */
  stateEstimator_B.rtb_MemoryX_f_l[0] = stateEstimator_DW.MemoryX_DSTATE_dl[0];

  /* DataTypeConversion: '<S149>/Conversion' incorporates:
   *  Delay: '<S133>/MemoryX'
   */
  stateEstimator_B.rtb_Conversion_pu_j[1] = stateEstimator_DW.MemoryX_DSTATE_dl
    [1];

  /* Sum: '<S134>/Add1' incorporates:
   *  Delay: '<S68>/Delay'
   *  Inport: '<Root>/posVIS_datin'
   */
  rtb_sincos_o2_idx_2 = stateEstimator_U.posVIS_datin[1] -
    stateEstimator_DW.Delay_DSTATE_l[1];

  /* Delay: '<S133>/MemoryX' */
  stateEstimator_B.rtb_MemoryX_f_l[1] = stateEstimator_DW.MemoryX_DSTATE_dl[1];

  /* Reshape: '<S133>/Reshapey' incorporates:
   *  Inport: '<Root>/posVIS_datin'
   */
  stateEstimator_B.rtb_Reshapey_a_d[0] = stateEstimator_U.posVIS_datin[0];
  stateEstimator_B.rtb_Reshapey_a_d[1] = stateEstimator_U.posVIS_datin[1];

  /* Math: '<S134>/Math Function' incorporates:
   *  Constant: '<S134>/Constant'
   */
  stateEstimator_B.DataTypeConversion2 = (real32_T)floor
    (stateEstimator_P.Constant_Value_e);
  if ((rtb_sincos_o2_idx_0 < 0.0F) && (stateEstimator_P.Constant_Value_e >
       stateEstimator_B.DataTypeConversion2)) {
    rtb_sincos_o2_idx_0 = -rt_powf_snf(-rtb_sincos_o2_idx_0,
      stateEstimator_P.Constant_Value_e);
  } else {
    rtb_sincos_o2_idx_0 = rt_powf_snf(rtb_sincos_o2_idx_0,
      stateEstimator_P.Constant_Value_e);
  }

  if ((rtb_sincos_o2_idx_2 < 0.0F) && (stateEstimator_P.Constant_Value_e >
       stateEstimator_B.DataTypeConversion2)) {
    rtb_sincos_o2_idx_2 = -rt_powf_snf(-rtb_sincos_o2_idx_2,
      stateEstimator_P.Constant_Value_e);
  } else {
    rtb_sincos_o2_idx_2 = rt_powf_snf(rtb_sincos_o2_idx_2,
      stateEstimator_P.Constant_Value_e);
  }

  /* End of Math: '<S134>/Math Function' */

  /* Logic: '<S134>/Logical Operator3' incorporates:
   *  Constant: '<S180>/Constant'
   *  Constant: '<S181>/Constant'
   *  Constant: '<S182>/Constant'
   *  Constant: '<S183>/Constant'
   *  Inport: '<Root>/posVIS_datin'
   *  RelationalOperator: '<S180>/Compare'
   *  RelationalOperator: '<S181>/Compare'
   *  RelationalOperator: '<S182>/Compare'
   *  RelationalOperator: '<S183>/Compare'
   *  Sqrt: '<S134>/Sqrt'
   *  Sum: '<S134>/Sum of Elements'
   */
  stateEstimator_B.LogicalOperator3_o = ((stateEstimator_U.posVIS_datin[0] !=
    stateEstimator_P.checkifPosavailable_const) && (rtb_Sum_k_idx_2 <=
    stateEstimator_P.maxp3_const) && (y <= stateEstimator_P.maxq3_const) &&
    ((real32_T)sqrt(rtb_sincos_o2_idx_0 + rtb_sincos_o2_idx_2) <
     stateEstimator_P.planarjumpsVISPOS_const));

  /* DataTypeConversion: '<S133>/DataTypeConversionEnable' */
  rtb_DataTypeConversionEnable_n5 = stateEstimator_B.LogicalOperator3_o;

  /* Outputs for Enabled SubSystem: '<S153>/MeasurementUpdate' */
  /* Constant: '<S133>/C' incorporates:
   *  Constant: '<S133>/D'
   */
  stateEstimator_MeasurementUpdate(rtb_DataTypeConversionEnable_n5,
    stateEstimator_B.rtb_Conversion_a_c, stateEstimator_B.rtb_Reshapey_a_d,
    stateEstimator_P.C_Value_p, stateEstimator_B.rtb_Conversion_pu_j,
    stateEstimator_P.D_Value_b, stateEstimator_B.rtb_Reshapeu_i_p,
    stateEstimator_B.Product3_j, &stateEstimator_DW.MeasurementUpdate_b,
    &stateEstimator_P.MeasurementUpdate_b);

  /* End of Outputs for SubSystem: '<S153>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S158>/Enabled Subsystem' */
  stateEstimator_EnabledSubsystem(rtb_DataTypeConversionEnable_n5,
    stateEstimator_B.rtb_Conversion_g_c, stateEstimator_P.C_Value_p,
    stateEstimator_B.rtb_Reshapey_a_d, stateEstimator_B.rtb_MemoryX_f_l,
    stateEstimator_B.Product2_e, &stateEstimator_DW.EnabledSubsystem_m,
    &stateEstimator_P.EnabledSubsystem_m);

  /* End of Outputs for SubSystem: '<S158>/Enabled Subsystem' */

  /* Reshape: '<S133>/Reshapexhat' incorporates:
   *  Delay: '<S68>/Delay'
   *  Sum: '<S158>/Add'
   */
  stateEstimator_DW.Delay_DSTATE_l[0] = stateEstimator_B.Product2_e[0] +
    stateEstimator_B.rtb_MemoryX_f_l[0];
  stateEstimator_DW.Delay_DSTATE_l[1] = stateEstimator_B.Product2_e[1] +
    stateEstimator_B.rtb_MemoryX_f_l[1];

  /* DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' incorporates:
   *  Inport: '<Root>/controlModePosVSOrient_flagin'
   */
  if (arg_controlModePosVSOrient_flagin &&
      (stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState <= 0)) {
    stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] =
      stateEstimator_P.SimplyIntegrateVelocity_IC;
    stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] =
      stateEstimator_P.SimplyIntegrateVelocity_IC;
  }

  /* Switch: '<S68>/UseIPPosSwitch' incorporates:
   *  Delay: '<S68>/Delay'
   *  DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity'
   *  Inport: '<Root>/usePosVIS_flagin'
   */
  if (arg_usePosVIS_flagin > stateEstimator_P.UseIPPosSwitch_Threshold) {
    stateEstimator_B.SimplyIntegrateVelocity[0] =
      stateEstimator_DW.Delay_DSTATE_l[0];
    stateEstimator_B.SimplyIntegrateVelocity[1] =
      stateEstimator_DW.Delay_DSTATE_l[1];
  } else {
    stateEstimator_B.SimplyIntegrateVelocity[0] =
      stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0];
    stateEstimator_B.SimplyIntegrateVelocity[1] =
      stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1];
  }

  /* End of Switch: '<S68>/UseIPPosSwitch' */

  /* Outputs for Enabled SubSystem: '<S35>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  /* DataTypeConversion: '<S14>/DataTypeConversionEnable' */
  if (stateEstimator_B.nicemeasurementornewupdateneeded) {
    if (!stateEstimator_DW.MeasurementUpdate_MODE) {
      stateEstimator_DW.MeasurementUpdate_MODE = true;
    }

    /* Sum: '<S60>/Sum' incorporates:
     *  Constant: '<S14>/C'
     *  Constant: '<S14>/D'
     *  Delay: '<S14>/MemoryX'
     *  Product: '<S60>/C[k]*xhat[k|k-1]'
     *  Product: '<S60>/D[k]*u[k]'
     *  Reshape: '<S14>/Reshapeu'
     *  Reshape: '<S14>/Reshapey'
     *  Sum: '<S60>/Add1'
     */
    stateEstimator_B.Sum_f = stateEstimator_B.invertzaxisGain -
      ((stateEstimator_P.C_Value[0] * stateEstimator_DW.MemoryX_DSTATE[0] +
        stateEstimator_P.C_Value[1] * stateEstimator_DW.MemoryX_DSTATE[1]) +
       stateEstimator_P.D_Value * stateEstimator_B.Sum[2]);

    /* Product: '<S60>/Product3' incorporates:
     *  Constant: '<S18>/KalmanGainL'
     *  DataTypeConversion: '<S56>/Conversion'
     */
    stateEstimator_B.Product3[0] = stateEstimator_P.KalmanGainL_Value_e[0] *
      stateEstimator_B.Sum_f;
    stateEstimator_B.Product3[1] = stateEstimator_P.KalmanGainL_Value_e[1] *
      stateEstimator_B.Sum_f;
  } else {
    if (stateEstimator_DW.MeasurementUpdate_MODE) {
      /* Disable for Outport: '<S60>/L*(y[k]-yhat[k|k-1])' */
      stateEstimator_B.Product3[0] = stateEstimator_P.Lykyhatkk1_Y0;
      stateEstimator_B.Product3[1] = stateEstimator_P.Lykyhatkk1_Y0;
      stateEstimator_DW.MeasurementUpdate_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S35>/MeasurementUpdate' */

  /* Outport: '<Root>/states_estimout' incorporates:
   *  BusCreator: '<Root>/BusConversion_InsertedFor_states_estimout_at_inport_0'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Delay: '<S67>/Delay'
   *  DiscreteFilter: '<S5>/IIR_IMUgyro_r'
   *  Reshape: '<S14>/Reshapexhat'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtProductInport2'
   */
  arg_states_estimout->X = stateEstimator_B.SimplyIntegrateVelocity[0];
  arg_states_estimout->Y = stateEstimator_B.SimplyIntegrateVelocity[1];
  arg_states_estimout->Z = (real32_T)stateEstimator_DW.Delay2_DSTATE;
  arg_states_estimout->yaw = stateEstimator_DW.Memory_PreviousInput[0];
  arg_states_estimout->pitch = stateEstimator_DW.Memory_PreviousInput[1];
  arg_states_estimout->roll = stateEstimator_DW.Memory_PreviousInput[2];
  arg_states_estimout->dx = stateEstimator_DW.Delay_DSTATE[0];
  arg_states_estimout->dy = stateEstimator_DW.Delay_DSTATE[1];
  arg_states_estimout->dz = (real32_T)stateEstimator_B.rtb_VectorConcatenate_c[2];
  arg_states_estimout->p = stateEstimator_B.inverseIMU_gain[3];
  arg_states_estimout->q = stateEstimator_B.inverseIMU_gain[4];
  arg_states_estimout->r = rtb_DataTypeConversion1_idx_1;

  /* Update for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
  stateEstimator_DW.IIR_IMUgyro_r_states[4] =
    stateEstimator_DW.IIR_IMUgyro_r_states[3];
  stateEstimator_DW.IIR_IMUgyro_r_states[3] =
    stateEstimator_DW.IIR_IMUgyro_r_states[2];
  stateEstimator_DW.IIR_IMUgyro_r_states[2] =
    stateEstimator_DW.IIR_IMUgyro_r_states[1];
  stateEstimator_DW.IIR_IMUgyro_r_states[1] =
    stateEstimator_DW.IIR_IMUgyro_r_states[0];
  stateEstimator_DW.IIR_IMUgyro_r_states[0] = rtb_DataTypeConversion1_idx_0;

  /* Update for DiscreteFir: '<S5>/FIR_IMUaccel' */
  /* Update circular buffer index */
  stateEstimator_DW.FIR_IMUaccel_circBuf--;
  if (stateEstimator_DW.FIR_IMUaccel_circBuf < 0) {
    stateEstimator_DW.FIR_IMUaccel_circBuf = 4;
  }

  /* Update circular buffer */
  stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_DW.FIR_IMUaccel_circBuf] =
    stateEstimator_B.inverseIMU_gain[0];
  stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_DW.FIR_IMUaccel_circBuf +
    5] = stateEstimator_B.inverseIMU_gain[1];
  stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_DW.FIR_IMUaccel_circBuf +
    10] = stateEstimator_B.inverseIMU_gain[2];

  /* End of Update for DiscreteFir: '<S5>/FIR_IMUaccel' */

  /* Update for Delay: '<S71>/MemoryX' incorporates:
   *  Constant: '<S71>/A'
   *  Constant: '<S71>/B'
   *  Product: '<S106>/A[k]*xhat[k|k-1]'
   *  Product: '<S106>/B[k]*u[k]'
   *  Sum: '<S106>/Add'
   */
  stateEstimator_DW.icLoad = 0U;
  stateEstimator_DW.MemoryX_DSTATE_d[0] = ((stateEstimator_P.B_Value_p[0] *
    stateEstimator_B.rtb_Reshapeu_h_m[0] + stateEstimator_P.B_Value_p[2] *
    stateEstimator_B.rtb_Reshapeu_h_m[1]) + (stateEstimator_P.A_Value_c[0] *
    stateEstimator_B.rtb_Conversion_j_n[0] + stateEstimator_P.A_Value_c[2] *
    stateEstimator_B.rtb_Conversion_j_n[1])) + stateEstimator_B.Product3_m[0];
  stateEstimator_DW.MemoryX_DSTATE_d[1] = ((stateEstimator_P.B_Value_p[1] *
    stateEstimator_B.rtb_Reshapeu_h_m[0] + stateEstimator_P.B_Value_p[3] *
    stateEstimator_B.rtb_Reshapeu_h_m[1]) + (stateEstimator_P.A_Value_c[1] *
    stateEstimator_B.rtb_Conversion_j_n[0] + stateEstimator_P.A_Value_c[3] *
    stateEstimator_B.rtb_Conversion_j_n[1])) + stateEstimator_B.Product3_m[1];

  /* Update for Delay: '<S14>/MemoryX' */
  stateEstimator_DW.icLoad_p = 0U;
  for (stateEstimator_B.j = 0; stateEstimator_B.j < 2; stateEstimator_B.j++) {
    /* Update for DiscreteFilter: '<S70>/IIRgyroz' */
    stateEstimator_B.cff = stateEstimator_B.j * 5;
    stateEstimator_DW.IIRgyroz_states[stateEstimator_B.cff + 4] =
      stateEstimator_DW.IIRgyroz_states[stateEstimator_B.cff + 3];
    stateEstimator_DW.IIRgyroz_states[stateEstimator_B.cff + 3] =
      stateEstimator_DW.IIRgyroz_states[stateEstimator_B.cff + 2];
    stateEstimator_DW.IIRgyroz_states[stateEstimator_B.cff + 2] =
      stateEstimator_DW.IIRgyroz_states[stateEstimator_B.cff + 1];
    stateEstimator_DW.IIRgyroz_states[stateEstimator_B.cff + 1] =
      stateEstimator_DW.IIRgyroz_states[stateEstimator_B.cff];
    stateEstimator_DW.IIRgyroz_states[stateEstimator_B.cff] =
      stateEstimator_B.IIRgyroz_tmp[stateEstimator_B.j];

    /* Update for UnitDelay: '<S77>/UD'
     *
     * Block description for '<S77>/UD':
     *
     *  Store in Global RAM
     */
    stateEstimator_DW.UD_DSTATE[stateEstimator_B.j] =
      stateEstimator_B.TSamp[stateEstimator_B.j];

    /* Product: '<S35>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S14>/A'
     *  Delay: '<S14>/MemoryX'
     */
    stateEstimator_B.dv0[stateEstimator_B.j] =
      stateEstimator_P.A_Value[stateEstimator_B.j + 2] *
      stateEstimator_DW.MemoryX_DSTATE[1] +
      stateEstimator_P.A_Value[stateEstimator_B.j] *
      stateEstimator_DW.MemoryX_DSTATE[0];
  }

  /* Update for Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S14>/B'
   *  Product: '<S35>/B[k]*u[k]'
   *  Reshape: '<S14>/Reshapeu'
   *  Sum: '<S35>/Add'
   */
  stateEstimator_DW.MemoryX_DSTATE[0] = (stateEstimator_P.B_Value[0] *
    stateEstimator_B.Sum[2] + stateEstimator_B.dv0[0]) +
    stateEstimator_B.Product3[0];

  /* Update for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[2] =
    stateEstimator_DW.pressureFilter_IIR_states[1];

  /* Update for Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S14>/B'
   *  Product: '<S35>/B[k]*u[k]'
   *  Reshape: '<S14>/Reshapeu'
   *  Sum: '<S35>/Add'
   */
  stateEstimator_DW.MemoryX_DSTATE[1] = (stateEstimator_P.B_Value[1] *
    stateEstimator_B.Sum[2] + stateEstimator_B.dv0[1]) +
    stateEstimator_B.Product3[1];

  /* Update for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[1] =
    stateEstimator_DW.pressureFilter_IIR_states[0];
  stateEstimator_DW.pressureFilter_IIR_states[0] = rtb_sincos_o2_idx_1;

  /* Update for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[2] =
    stateEstimator_DW.soonarFilter_IIR_states[1];

  /* Update for Delay: '<S1>/Delay1' incorporates:
   *  Delay: '<S67>/Delay'
   */
  stateEstimator_DW.Delay1_DSTATE[0] = stateEstimator_DW.Delay_DSTATE[0];

  /* Update for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[1] =
    stateEstimator_DW.soonarFilter_IIR_states[0];

  /* Update for Delay: '<S1>/Delay1' incorporates:
   *  Delay: '<S67>/Delay'
   */
  stateEstimator_DW.Delay1_DSTATE[1] = stateEstimator_DW.Delay_DSTATE[1];

  /* Update for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[0] = stateEstimator_B.denAccum;

  /* Update for Delay: '<S133>/MemoryX' incorporates:
   *  Constant: '<S133>/A'
   *  Constant: '<S133>/B'
   *  Product: '<S153>/A[k]*xhat[k|k-1]'
   *  Product: '<S153>/B[k]*u[k]'
   *  Sum: '<S153>/Add'
   */
  stateEstimator_DW.icLoad_g = 0U;
  stateEstimator_DW.MemoryX_DSTATE_dl[0] = ((stateEstimator_P.B_Value_pu[0] *
    stateEstimator_B.rtb_Reshapeu_i_p[0] + stateEstimator_P.B_Value_pu[2] *
    stateEstimator_B.rtb_Reshapeu_i_p[1]) + (stateEstimator_P.A_Value_b[0] *
    stateEstimator_B.rtb_Conversion_pu_j[0] + stateEstimator_P.A_Value_b[2] *
    stateEstimator_B.rtb_Conversion_pu_j[1])) + stateEstimator_B.Product3_j[0];
  stateEstimator_DW.MemoryX_DSTATE_dl[1] = ((stateEstimator_P.B_Value_pu[1] *
    stateEstimator_B.rtb_Reshapeu_i_p[0] + stateEstimator_P.B_Value_pu[3] *
    stateEstimator_B.rtb_Reshapeu_i_p[1]) + (stateEstimator_P.A_Value_b[1] *
    stateEstimator_B.rtb_Conversion_pu_j[0] + stateEstimator_P.A_Value_b[3] *
    stateEstimator_B.rtb_Conversion_pu_j[1])) + stateEstimator_B.Product3_j[1];

  /* Update for DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' incorporates:
   *  Inport: '<Root>/controlModePosVSOrient_flagin'
   */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] +=
    stateEstimator_P.SimplyIntegrateVelocity_gainval * stateEstimator_B.Product
    [0];
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] +=
    stateEstimator_P.SimplyIntegrateVelocity_gainval * stateEstimator_B.Product
    [1];
  stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState = (int8_T)
    arg_controlModePosVSOrient_flagin;
}

/* Model initialize function */
void stateEstimator_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  stateEstimator_P.SaturationSonar_LowerSat = rtMinusInf;

  /* initialize error status */
  rtmSetErrorStatus(stateEstimator_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &stateEstimator_B), 0,
                sizeof(B_stateEstimator_T));

  /* states (dwork) */
  (void) memset((void *)&stateEstimator_DW, 0,
                sizeof(DW_stateEstimator_T));

  {
    int32_T i;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    stateEstimator_DW.Memory_PreviousInput[0] =
      stateEstimator_P.Memory_InitialCondition[0];
    stateEstimator_DW.Memory_PreviousInput[1] =
      stateEstimator_P.Memory_InitialCondition[1];
    stateEstimator_DW.Memory_PreviousInput[2] =
      stateEstimator_P.Memory_InitialCondition[2];

    /* InitializeConditions for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
    for (i = 0; i < 5; i++) {
      stateEstimator_DW.IIR_IMUgyro_r_states[i] =
        stateEstimator_P.IIR_IMUgyro_r_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */

    /* InitializeConditions for DiscreteFir: '<S5>/FIR_IMUaccel' */
    stateEstimator_DW.FIR_IMUaccel_circBuf = 0;
    for (i = 0; i < 15; i++) {
      stateEstimator_DW.FIR_IMUaccel_states[i] =
        stateEstimator_P.FIR_IMUaccel_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFir: '<S5>/FIR_IMUaccel' */

    /* InitializeConditions for Delay: '<S71>/MemoryX' */
    stateEstimator_DW.icLoad = 1U;

    /* InitializeConditions for DiscreteFilter: '<S70>/IIRgyroz' */
    for (i = 0; i < 10; i++) {
      stateEstimator_DW.IIRgyroz_states[i] =
        stateEstimator_P.IIRgyroz_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFilter: '<S70>/IIRgyroz' */

    /* InitializeConditions for UnitDelay: '<S77>/UD'
     *
     * Block description for '<S77>/UD':
     *
     *  Store in Global RAM
     */
    stateEstimator_DW.UD_DSTATE[0] =
      stateEstimator_P.DiscreteDerivative_ICPrevScaledInput;

    /* InitializeConditions for Delay: '<S67>/Delay' */
    stateEstimator_DW.Delay_DSTATE[0] = stateEstimator_P.Delay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S77>/UD'
     *
     * Block description for '<S77>/UD':
     *
     *  Store in Global RAM
     */
    stateEstimator_DW.UD_DSTATE[1] =
      stateEstimator_P.DiscreteDerivative_ICPrevScaledInput;

    /* InitializeConditions for Delay: '<S67>/Delay' */
    stateEstimator_DW.Delay_DSTATE[1] = stateEstimator_P.Delay_InitialCondition;

    /* InitializeConditions for Reshape: '<S14>/Reshapexhat' incorporates:
     *  Delay: '<S3>/Delay2'
     */
    stateEstimator_DW.Delay2_DSTATE = stateEstimator_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S14>/MemoryX' */
    stateEstimator_DW.icLoad_p = 1U;

    /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
    stateEstimator_DW.pressureFilter_IIR_states[0] =
      stateEstimator_P.pressureFilter_IIR_InitialStates;

    /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
    stateEstimator_DW.soonarFilter_IIR_states[0] =
      stateEstimator_P.soonarFilter_IIR_InitialStates;

    /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
    stateEstimator_DW.pressureFilter_IIR_states[1] =
      stateEstimator_P.pressureFilter_IIR_InitialStates;

    /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
    stateEstimator_DW.soonarFilter_IIR_states[1] =
      stateEstimator_P.soonarFilter_IIR_InitialStates;

    /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
    stateEstimator_DW.pressureFilter_IIR_states[2] =
      stateEstimator_P.pressureFilter_IIR_InitialStates;

    /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
    stateEstimator_DW.soonarFilter_IIR_states[2] =
      stateEstimator_P.soonarFilter_IIR_InitialStates;

    /* InitializeConditions for Delay: '<S133>/MemoryX' */
    stateEstimator_DW.icLoad_g = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' */
    stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState = 2;

    /* InitializeConditions for Delay: '<S1>/Delay1' */
    stateEstimator_DW.Delay1_DSTATE[0] =
      stateEstimator_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S68>/Delay' */
    stateEstimator_DW.Delay_DSTATE_l[0] =
      stateEstimator_P.Delay_InitialCondition_n;

    /* InitializeConditions for DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' */
    stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] =
      stateEstimator_P.SimplyIntegrateVelocity_IC;

    /* SystemInitialize for Merge: '<S2>/Merge' */
    stateEstimator_B.Merge[0] = stateEstimator_P.Merge_InitialOutput;

    /* SystemInitialize for Enabled SubSystem: '<S40>/Enabled Subsystem' */
    /* SystemInitialize for Outport: '<S61>/deltax' */
    stateEstimator_B.Product2[0] = stateEstimator_P.deltax_Y0;

    /* End of SystemInitialize for SubSystem: '<S40>/Enabled Subsystem' */

    /* InitializeConditions for Delay: '<S1>/Delay1' */
    stateEstimator_DW.Delay1_DSTATE[1] =
      stateEstimator_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S68>/Delay' */
    stateEstimator_DW.Delay_DSTATE_l[1] =
      stateEstimator_P.Delay_InitialCondition_n;

    /* InitializeConditions for DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' */
    stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] =
      stateEstimator_P.SimplyIntegrateVelocity_IC;

    /* SystemInitialize for Merge: '<S2>/Merge' */
    stateEstimator_B.Merge[1] = stateEstimator_P.Merge_InitialOutput;

    /* SystemInitialize for Enabled SubSystem: '<S40>/Enabled Subsystem' */
    /* SystemInitialize for Outport: '<S61>/deltax' */
    stateEstimator_B.Product2[1] = stateEstimator_P.deltax_Y0;

    /* End of SystemInitialize for SubSystem: '<S40>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S111>/Enabled Subsystem' */
    stateEstimator_EnabledSubsystem_Init(stateEstimator_B.Product2_k,
      &stateEstimator_P.EnabledSubsystem_f);

    /* End of SystemInitialize for SubSystem: '<S111>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S106>/MeasurementUpdate' */
    stateEstimator_MeasurementUpdate_Init(stateEstimator_B.Product3_m,
      &stateEstimator_P.MeasurementUpdate_e);

    /* End of SystemInitialize for SubSystem: '<S106>/MeasurementUpdate' */

    /* SystemInitialize for Enabled SubSystem: '<S153>/MeasurementUpdate' */
    stateEstimator_MeasurementUpdate_Init(stateEstimator_B.Product3_j,
      &stateEstimator_P.MeasurementUpdate_b);

    /* End of SystemInitialize for SubSystem: '<S153>/MeasurementUpdate' */

    /* SystemInitialize for Enabled SubSystem: '<S158>/Enabled Subsystem' */
    stateEstimator_EnabledSubsystem_Init(stateEstimator_B.Product2_e,
      &stateEstimator_P.EnabledSubsystem_m);

    /* End of SystemInitialize for SubSystem: '<S158>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S35>/MeasurementUpdate' */
    /* SystemInitialize for Outport: '<S60>/L*(y[k]-yhat[k|k-1])' */
    stateEstimator_B.Product3[0] = stateEstimator_P.Lykyhatkk1_Y0;
    stateEstimator_B.Product3[1] = stateEstimator_P.Lykyhatkk1_Y0;

    /* End of SystemInitialize for SubSystem: '<S35>/MeasurementUpdate' */
  }
}

/* Model terminate function */
void stateEstimator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

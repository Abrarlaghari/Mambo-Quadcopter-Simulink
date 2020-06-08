/*
 * Code generation for system model 'stateEstimator'
 *
 * Model                      : stateEstimator
 * Model version              : 1.42
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Mon Nov  4 15:18:19 2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "stateEstimator.h"
#include "stateEstimator_private.h"
#include "rt_powf_snf.h"

MdlrefDW_stateEstimator_T stateEstimator_MdlrefDW;

/* Block signals (default storage) */
B_stateEstimator_c_T stateEstimator_B;

/* Block states (default storage) */
DW_stateEstimator_f_T stateEstimator_DW;

/*
 * System initialize for enable system:
 *    '<S106>/MeasurementUpdate'
 *    '<S153>/MeasurementUpdate'
 */
void stateEstimator_MeasurementUpdate_Init(B_MeasurementUpdate_stateEstimator_T *
  localB)
{
  /* SystemInitialize for Outport: '<S131>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3[0] = 0.0F;
  localB->Product3[1] = 0.0F;
}

/*
 * Disable for enable system:
 *    '<S106>/MeasurementUpdate'
 *    '<S153>/MeasurementUpdate'
 */
void stateEstimator_MeasurementUpdate_Disable
  (B_MeasurementUpdate_stateEstimator_T *localB,
   DW_MeasurementUpdate_stateEstimator_T *localDW)
{
  /* Disable for Outport: '<S131>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3[0] = 0.0F;
  localB->Product3[1] = 0.0F;
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S106>/MeasurementUpdate'
 *    '<S153>/MeasurementUpdate'
 */
void stateEstimator_MeasurementUpdate(boolean_T rtu_Enable, const real32_T
  rtu_Lk[4], const real32_T rtu_yk[2], const real32_T rtu_Ck[4], const real32_T
  rtu_xhatkk1[2], const real32_T rtu_Dk[4], const real32_T rtu_uk[2],
  B_MeasurementUpdate_stateEstimator_T *localB,
  DW_MeasurementUpdate_stateEstimator_T *localDW)
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
    localB->Product3[0] = 0.0F;
    localB->Product3[0] += rtu_Lk[0] * rtu_yk_idx_0;
    localB->Product3[0] += rtu_Lk[2] * rtu_yk_idx_1;
    localB->Product3[1] = 0.0F;
    localB->Product3[1] += rtu_Lk[1] * rtu_yk_idx_0;
    localB->Product3[1] += rtu_Lk[3] * rtu_yk_idx_1;
  } else {
    if (localDW->MeasurementUpdate_MODE) {
      stateEstimator_MeasurementUpdate_Disable(localB, localDW);
    }
  }

  /* End of Outputs for SubSystem: '<S106>/MeasurementUpdate' */
}

/*
 * System initialize for enable system:
 *    '<S111>/Enabled Subsystem'
 *    '<S158>/Enabled Subsystem'
 */
void stateEstimator_EnabledSubsystem_Init(B_EnabledSubsystem_stateEstimator_T
  *localB)
{
  /* SystemInitialize for Outport: '<S132>/deltax' */
  localB->Product2[0] = 0.0F;
  localB->Product2[1] = 0.0F;
}

/*
 * Disable for enable system:
 *    '<S111>/Enabled Subsystem'
 *    '<S158>/Enabled Subsystem'
 */
void stateEstimator_EnabledSubsystem_Disable(B_EnabledSubsystem_stateEstimator_T
  *localB, DW_EnabledSubsystem_stateEstimator_T *localDW)
{
  /* Disable for Outport: '<S132>/deltax' */
  localB->Product2[0] = 0.0F;
  localB->Product2[1] = 0.0F;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S111>/Enabled Subsystem'
 *    '<S158>/Enabled Subsystem'
 */
void stateEstimator_EnabledSubsystem(boolean_T rtu_Enable, const real32_T
  rtu_Mk[4], const real32_T rtu_Ck[4], const real32_T rtu_yk[2], const real32_T
  rtu_xhatkk1[2], B_EnabledSubsystem_stateEstimator_T *localB,
  DW_EnabledSubsystem_stateEstimator_T *localDW)
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
    localB->Product2[0] = 0.0F;
    localB->Product2[0] += rtu_Mk[0] * rtu_yk_idx_0;
    localB->Product2[0] += rtu_Mk[2] * rtu_yk_idx_1;
    localB->Product2[1] = 0.0F;
    localB->Product2[1] += rtu_Mk[1] * rtu_yk_idx_0;
    localB->Product2[1] += rtu_Mk[3] * rtu_yk_idx_1;
  } else {
    if (localDW->EnabledSubsystem_MODE) {
      stateEstimator_EnabledSubsystem_Disable(localB, localDW);
    }
  }

  /* End of Outputs for SubSystem: '<S111>/Enabled Subsystem' */
}

/* System initialize for referenced model: 'stateEstimator' */
void stateEstimator_Init(void)
{
  int32_T i;

  /* InitializeConditions for Delay: '<S133>/MemoryX' */
  stateEstimator_DW.icLoad = 1U;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  stateEstimator_DW.Memory_PreviousInput[0] = 0.0F;
  stateEstimator_DW.Memory_PreviousInput[1] = 0.0F;
  stateEstimator_DW.Memory_PreviousInput[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    stateEstimator_DW.IIR_IMUgyro_r_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */

  /* InitializeConditions for DiscreteFir: '<S5>/FIR_IMUaccel' */
  stateEstimator_DW.FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    stateEstimator_DW.FIR_IMUaccel_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFir: '<S5>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S68>/Delay' */
  stateEstimator_DW.Delay_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S68>/Delay' */
  stateEstimator_DW.Delay_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState = 2;

  /* InitializeConditions for Delay: '<S3>/Delay2' */
  stateEstimator_DW.Delay2_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S14>/MemoryX' */
  stateEstimator_DW.icLoad_p = 1U;

  /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[0] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[0] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[1] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[1] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[2] = 0.0;

  /* InitializeConditions for Delay: '<S71>/MemoryX' */
  stateEstimator_DW.icLoad_i = 1U;

  /* InitializeConditions for DiscreteFilter: '<S70>/IIRgyroz' */
  for (i = 0; i < 10; i++) {
    stateEstimator_DW.IIRgyroz_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S70>/IIRgyroz' */

  /* InitializeConditions for UnitDelay: '<S77>/UD' */
  stateEstimator_DW.UD_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S67>/Delay' */
  stateEstimator_DW.Delay_DSTATE_g[0] = 0.0F;

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  stateEstimator_DW.Delay1_DSTATE[0] = 0.0F;

  /* SystemInitialize for Merge: '<S2>/Merge' */
  stateEstimator_B.Merge[0] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S77>/UD' */
  stateEstimator_DW.UD_DSTATE[1] = 0.0F;

  /* InitializeConditions for Delay: '<S67>/Delay' */
  stateEstimator_DW.Delay_DSTATE_g[1] = 0.0F;

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  stateEstimator_DW.Delay1_DSTATE[1] = 0.0F;

  /* SystemInitialize for Merge: '<S2>/Merge' */
  stateEstimator_B.Merge[1] = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S158>/Enabled Subsystem' */
  stateEstimator_EnabledSubsystem_Init(&stateEstimator_B.EnabledSubsystem_m);

  /* End of SystemInitialize for SubSystem: '<S158>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S40>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S61>/deltax' */
  stateEstimator_B.Product2[0] = 0.0;
  stateEstimator_B.Product2[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S40>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S111>/Enabled Subsystem' */
  stateEstimator_EnabledSubsystem_Init(&stateEstimator_B.EnabledSubsystem_f);

  /* End of SystemInitialize for SubSystem: '<S111>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S35>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S60>/L*(y[k]-yhat[k|k-1])' */
  stateEstimator_B.Product3[0] = 0.0;
  stateEstimator_B.Product3[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S35>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S106>/MeasurementUpdate' */
  stateEstimator_MeasurementUpdate_Init(&stateEstimator_B.MeasurementUpdate_e);

  /* End of SystemInitialize for SubSystem: '<S106>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S153>/MeasurementUpdate' */
  stateEstimator_MeasurementUpdate_Init(&stateEstimator_B.MeasurementUpdate_b);

  /* End of SystemInitialize for SubSystem: '<S153>/MeasurementUpdate' */
}

/* System reset for referenced model: 'stateEstimator' */
void stateEstimator_Reset(void)
{
  int32_T i;

  /* InitializeConditions for Delay: '<S133>/MemoryX' */
  stateEstimator_DW.icLoad = 1U;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  stateEstimator_DW.Memory_PreviousInput[0] = 0.0F;
  stateEstimator_DW.Memory_PreviousInput[1] = 0.0F;
  stateEstimator_DW.Memory_PreviousInput[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    stateEstimator_DW.IIR_IMUgyro_r_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */

  /* InitializeConditions for DiscreteFir: '<S5>/FIR_IMUaccel' */
  stateEstimator_DW.FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    stateEstimator_DW.FIR_IMUaccel_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFir: '<S5>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S68>/Delay' */
  stateEstimator_DW.Delay_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S68>/Delay' */
  stateEstimator_DW.Delay_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState = 2;

  /* InitializeConditions for Delay: '<S3>/Delay2' */
  stateEstimator_DW.Delay2_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S14>/MemoryX' */
  stateEstimator_DW.icLoad_p = 1U;

  /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[0] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[0] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[1] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[1] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[2] = 0.0;

  /* InitializeConditions for Delay: '<S71>/MemoryX' */
  stateEstimator_DW.icLoad_i = 1U;

  /* InitializeConditions for DiscreteFilter: '<S70>/IIRgyroz' */
  for (i = 0; i < 10; i++) {
    stateEstimator_DW.IIRgyroz_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S70>/IIRgyroz' */

  /* InitializeConditions for UnitDelay: '<S77>/UD' */
  stateEstimator_DW.UD_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S67>/Delay' */
  stateEstimator_DW.Delay_DSTATE_g[0] = 0.0F;

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  stateEstimator_DW.Delay1_DSTATE[0] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S77>/UD' */
  stateEstimator_DW.UD_DSTATE[1] = 0.0F;

  /* InitializeConditions for Delay: '<S67>/Delay' */
  stateEstimator_DW.Delay_DSTATE_g[1] = 0.0F;

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  stateEstimator_DW.Delay1_DSTATE[1] = 0.0F;
}

/* Disable for referenced model: 'stateEstimator' */
void stateEstimator_Disable(void)
{
  /* Disable for Enabled SubSystem: '<S158>/Enabled Subsystem' */
  if (stateEstimator_DW.EnabledSubsystem_m.EnabledSubsystem_MODE) {
    stateEstimator_EnabledSubsystem_Disable(&stateEstimator_B.EnabledSubsystem_m,
      &stateEstimator_DW.EnabledSubsystem_m);
  }

  /* End of Disable for SubSystem: '<S158>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S40>/Enabled Subsystem' */
  if (stateEstimator_DW.EnabledSubsystem_MODE) {
    /* Disable for Outport: '<S61>/deltax' */
    stateEstimator_B.Product2[0] = 0.0;
    stateEstimator_B.Product2[1] = 0.0;
    stateEstimator_DW.EnabledSubsystem_MODE = false;
  }

  /* End of Disable for SubSystem: '<S40>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S111>/Enabled Subsystem' */
  if (stateEstimator_DW.EnabledSubsystem_f.EnabledSubsystem_MODE) {
    stateEstimator_EnabledSubsystem_Disable(&stateEstimator_B.EnabledSubsystem_f,
      &stateEstimator_DW.EnabledSubsystem_f);
  }

  /* End of Disable for SubSystem: '<S111>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S35>/MeasurementUpdate' */
  if (stateEstimator_DW.MeasurementUpdate_MODE) {
    /* Disable for Outport: '<S60>/L*(y[k]-yhat[k|k-1])' */
    stateEstimator_B.Product3[0] = 0.0;
    stateEstimator_B.Product3[1] = 0.0;
    stateEstimator_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Disable for SubSystem: '<S35>/MeasurementUpdate' */

  /* Disable for Enabled SubSystem: '<S106>/MeasurementUpdate' */
  if (stateEstimator_DW.MeasurementUpdate_e.MeasurementUpdate_MODE) {
    stateEstimator_MeasurementUpdate_Disable
      (&stateEstimator_B.MeasurementUpdate_e,
       &stateEstimator_DW.MeasurementUpdate_e);
  }

  /* End of Disable for SubSystem: '<S106>/MeasurementUpdate' */

  /* Disable for Enabled SubSystem: '<S153>/MeasurementUpdate' */
  if (stateEstimator_DW.MeasurementUpdate_b.MeasurementUpdate_MODE) {
    stateEstimator_MeasurementUpdate_Disable
      (&stateEstimator_B.MeasurementUpdate_b,
       &stateEstimator_DW.MeasurementUpdate_b);
  }

  /* End of Disable for SubSystem: '<S153>/MeasurementUpdate' */
}

/* Output and update for referenced model: 'stateEstimator' */
void stateEstimator(const boolean_T *rtu_controlModePosVSOrient_flagin, const
                    sensordata_t *rtu_sensordata_datin, const real32_T
                    *rtu_usePosVIS_flagin, const real32_T rtu_opticalFlow_datin
                    [3], const real32_T rtu_posVIS_datin[4], const real32_T
                    rtu_sensorCalibration_datin[8], statesEstim_t
                    *rty_states_estimout)
{
  /* local block i/o variables */
  real_T rtb_ManualSwitchPZ[4];
  real32_T rtb_Reshapey_a[2];
  real32_T rtb_MemoryX_f[2];
  real32_T rtb_Reshapey_o[2];
  real32_T rtb_MemoryX_m[2];
  real32_T rtb_Conversion_j[2];
  real32_T rtb_ManualSwitchPZ_m[4];
  real32_T rtb_Reshapeu_h[2];
  real32_T rtb_Conversion_p[2];
  real32_T rtb_ManualSwitchPZ_p[4];
  real32_T rtb_Reshapeu_i[2];
  boolean_T rtb_DataTypeConversionEnable;
  boolean_T rtb_DataTypeConversionEnable_i;
  real32_T acc1;
  int32_T denIdx;
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_Product_n[3];
  real32_T rtb_FIR_IMUaccel[3];
  int32_T i;
  real32_T rtb_Sqrt;
  int32_T i_0;
  int32_T tmp;
  real32_T rtb_TSamp[2];
  real32_T rtb_Diff[2];
  real32_T rtb_Add_hi[2];
  real32_T rtb_Add_m[2];
  real32_T rtb_VectorConcatenate_i[9];
  real32_T rtb_VectorConcatenate_h[9];
  boolean_T rtb_Compare_i;
  boolean_T rtb_LogicalOperator_cg;
  real32_T rtb_VectorConcatenate_p[9];
  real32_T rtb_Merge1;
  real_T rtb_Add1_g;
  real_T rtb_Sum;
  real32_T rtb_VectorConcatenate_3[9];
  real_T rtb_VectorConcatenate_h_0[3];
  real32_T rtb_TrigonometricFunction_o2_idx_1;
  real32_T rtb_TrigonometricFunction_o1_idx_0;
  real32_T rtb_TrigonometricFunction_o2_idx_0;
  real32_T rtb_TrigonometricFunction_o1_idx_1;
  real_T rtb_Add_a_idx_0;
  real32_T rtb_UseIPPosSwitch_idx_1;
  real_T rtb_Add_a_idx_1;
  real32_T LogicalOperator3_tmp;
  real32_T LogicalOperator3_tmp_0;
  real32_T LogicalOperator3_a_tmp;
  real32_T rtb_VectorConcatenate_h_tmp;
  real32_T rtb_VectorConcatenate_h_tmp_0;
  real32_T rtb_sincos_o1_idx_2_tmp;
  real32_T rtb_sincos_o2_idx_2_tmp;

  /* Reshape: '<S133>/Reshapey' */
  rtb_Reshapey_a[0] = rtu_posVIS_datin[0];
  rtb_Reshapey_a[1] = rtu_posVIS_datin[1];

  /* Delay: '<S133>/MemoryX' */
  if (stateEstimator_DW.icLoad != 0) {
    stateEstimator_DW.MemoryX_DSTATE_d[0] = stateEstimator_ConstB.ReshapeX0_b[0];
    stateEstimator_DW.MemoryX_DSTATE_d[1] = stateEstimator_ConstB.ReshapeX0_b[1];
  }

  rtb_MemoryX_f[0] = stateEstimator_DW.MemoryX_DSTATE_d[0];
  rtb_MemoryX_f[1] = stateEstimator_DW.MemoryX_DSTATE_d[1];

  /* End of Delay: '<S133>/MemoryX' */

  /* SignalConversion: '<S13>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_VectorConcatenate[0] = 0.0F;

  /* SignalConversion: '<S13>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_VectorConcatenate[1] = 0.0F;

  /* Trigonometry: '<S12>/Trigonometric Function' incorporates:
   *  Memory: '<S2>/Memory'
   *  SignalConversion: '<S12>/TmpSignal ConversionAtTrigonometric FunctionInport1'
   */
  rtb_TrigonometricFunction_o1_idx_0 = (real32_T)sin
    (stateEstimator_DW.Memory_PreviousInput[2]);
  rtb_TrigonometricFunction_o2_idx_0 = (real32_T)cos
    (stateEstimator_DW.Memory_PreviousInput[2]);
  rtb_TrigonometricFunction_o1_idx_1 = (real32_T)sin
    (stateEstimator_DW.Memory_PreviousInput[1]);
  rtb_TrigonometricFunction_o2_idx_1 = (real32_T)cos
    (stateEstimator_DW.Memory_PreviousInput[1]);

  /* SignalConversion: '<S13>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[2] = rtb_TrigonometricFunction_o2_idx_1;

  /* SignalConversion: '<S13>/ConcatBufferAtVector ConcatenateIn4' */
  rtb_VectorConcatenate[3] = rtb_TrigonometricFunction_o1_idx_0;

  /* Product: '<S12>/Product1' */
  rtb_VectorConcatenate[4] = rtb_TrigonometricFunction_o2_idx_0 *
    rtb_TrigonometricFunction_o2_idx_1;

  /* Product: '<S12>/Product3' */
  rtb_VectorConcatenate[5] = rtb_TrigonometricFunction_o1_idx_0 *
    rtb_TrigonometricFunction_o1_idx_1;

  /* SignalConversion: '<S13>/ConcatBufferAtVector ConcatenateIn7' */
  rtb_VectorConcatenate[6] = rtb_TrigonometricFunction_o2_idx_0;

  /* Product: '<S12>/Product2' incorporates:
   *  Gain: '<S12>/Gain'
   */
  rtb_VectorConcatenate[7] = (-1.0F) * rtb_TrigonometricFunction_o1_idx_0 *
    rtb_TrigonometricFunction_o2_idx_1;

  /* Product: '<S12>/Product4' */
  rtb_VectorConcatenate[8] = rtb_TrigonometricFunction_o2_idx_0 *
    rtb_TrigonometricFunction_o1_idx_1;

  /* Gain: '<S5>/inverseIMU_gain' incorporates:
   *  Bias: '<S5>/Assuming that calib was done level!'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Sum: '<S5>/Sum1'
   */
  stateEstimator_B.inverseIMU_gain[0] = (rtu_sensordata_datin->ddx -
    (rtu_sensorCalibration_datin[0] + 0.0F)) * 0.994075298F;
  stateEstimator_B.inverseIMU_gain[1] = (rtu_sensordata_datin->ddy -
    (rtu_sensorCalibration_datin[1] + 0.0F)) * 0.996184587F;
  stateEstimator_B.inverseIMU_gain[2] = (rtu_sensordata_datin->ddz -
    (rtu_sensorCalibration_datin[2] + 9.81F)) * 1.00549F;
  stateEstimator_B.inverseIMU_gain[3] = (rtu_sensordata_datin->p -
    (rtu_sensorCalibration_datin[3] + 0.0F)) * 1.00139189F;
  stateEstimator_B.inverseIMU_gain[4] = (rtu_sensordata_datin->q -
    (rtu_sensorCalibration_datin[4] + 0.0F)) * 0.993601203F;
  stateEstimator_B.inverseIMU_gain[5] = (rtu_sensordata_datin->r -
    (rtu_sensorCalibration_datin[5] + 0.0F)) * 1.00003F;

  /* DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
  stateEstimator_DW.IIR_IMUgyro_r_tmp = 0.0F;
  acc1 = stateEstimator_B.inverseIMU_gain[5];
  denIdx = 1;
  for (i_0 = 0; i_0 < 5; i_0++) {
    acc1 -= rtCP_IIR_IMUgyro_r_DenCoef[denIdx] *
      stateEstimator_DW.IIR_IMUgyro_r_states[i_0];
    denIdx++;
  }

  stateEstimator_DW.IIR_IMUgyro_r_tmp = acc1 / 1.0F;
  acc1 = 0.282124132F * stateEstimator_DW.IIR_IMUgyro_r_tmp;
  denIdx = 1;
  for (i_0 = 0; i_0 < 5; i_0++) {
    acc1 += rtCP_IIR_IMUgyro_r_NumCoef[denIdx] *
      stateEstimator_DW.IIR_IMUgyro_r_states[i_0];
    denIdx++;
  }

  /* SignalConversion: '<S2>/TmpSignal ConversionAtProductInport2' incorporates:
   *  DiscreteFilter: '<S5>/IIR_IMUgyro_r'
   */
  rtb_TrigonometricFunction_o1_idx_0 = acc1;

  /* Product: '<S12>/Divide' incorporates:
   *  Reshape: '<S13>/Reshape (9) to [3x3] column-major'
   */
  for (i_0 = 0; i_0 < 9; i_0++) {
    rtb_VectorConcatenate_3[i_0] = rtb_VectorConcatenate[i_0] /
      rtb_TrigonometricFunction_o2_idx_1;
  }

  /* End of Product: '<S12>/Divide' */

  /* Product: '<S2>/Product' incorporates:
   *  DiscreteFilter: '<S5>/IIR_IMUgyro_r'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtProductInport2'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_Product_n[i_0] = rtb_VectorConcatenate_3[i_0 + 6] * acc1 +
      (rtb_VectorConcatenate_3[i_0 + 3] * stateEstimator_B.inverseIMU_gain[4] +
       rtb_VectorConcatenate_3[i_0] * stateEstimator_B.inverseIMU_gain[3]);
  }

  /* End of Product: '<S2>/Product' */

  /* If: '<S2>/If1' incorporates:
   *  Constant: '<S185>/Constant'
   *  Gain: '<S2>/Gain'
   *  Inport: '<S11>/yawin'
   *  Logic: '<S5>/Logical Operator'
   *  Memory: '<S2>/Memory'
   *  RelationalOperator: '<S185>/Compare'
   *  SignalConversion: '<S12>/TmpSignal ConversionAtTrigonometric FunctionInport1'
   *  Sum: '<S2>/Sum'
   */
  if ((rtu_posVIS_datin[0] != (-99.0F)) && (*rtu_usePosVIS_flagin != 0.0F)) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Sum: '<S9>/Sum' incorporates:
     *  Gain: '<S2>/Gain'
     *  Gain: '<S9>/Gain'
     *  Gain: '<S9>/Gain1'
     *  Memory: '<S2>/Memory'
     *  SignalConversion: '<S12>/TmpSignal ConversionAtTrigonometric FunctionInport1'
     *  Sum: '<S2>/Sum'
     */
    rtb_Merge1 = 0.8F * (0.005F * rtb_Product_n[0] +
                         stateEstimator_DW.Memory_PreviousInput[0]) + 0.2F *
      rtu_posVIS_datin[3];

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    rtb_Merge1 = 0.005F * rtb_Product_n[0] +
      stateEstimator_DW.Memory_PreviousInput[0];

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
  }

  /* End of If: '<S2>/If1' */

  /* DiscreteFir: '<S5>/FIR_IMUaccel' */
  acc1 = stateEstimator_B.inverseIMU_gain[0] * 0.0264077242F;
  denIdx = 1;
  for (i_0 = stateEstimator_DW.FIR_IMUaccel_circBuf; i_0 < 5; i_0++) {
    acc1 += stateEstimator_DW.FIR_IMUaccel_states[i_0] *
      rtCP_FIR_IMUaccel_Coefficients[denIdx];
    denIdx++;
  }

  for (i_0 = 0; i_0 < stateEstimator_DW.FIR_IMUaccel_circBuf; i_0++) {
    acc1 += stateEstimator_DW.FIR_IMUaccel_states[i_0] *
      rtCP_FIR_IMUaccel_Coefficients[denIdx];
    denIdx++;
  }

  rtb_FIR_IMUaccel[0] = acc1;

  /* Math: '<S2>/Math Function' incorporates:
   *  DiscreteFir: '<S5>/FIR_IMUaccel'
   */
  rtb_TrigonometricFunction_o2_idx_1 = (real32_T)floor(2.0F);
  if ((acc1 < 0.0F) && (2.0F > rtb_TrigonometricFunction_o2_idx_1)) {
    rtb_TrigonometricFunction_o2_idx_0 = -rt_powf_snf(-acc1, 2.0F);
  } else {
    rtb_TrigonometricFunction_o2_idx_0 = rt_powf_snf(acc1, 2.0F);
  }

  /* DiscreteFir: '<S5>/FIR_IMUaccel' */
  acc1 = stateEstimator_B.inverseIMU_gain[1] * 0.0264077242F;
  denIdx = 1;
  for (i_0 = stateEstimator_DW.FIR_IMUaccel_circBuf; i_0 < 5; i_0++) {
    acc1 += stateEstimator_DW.FIR_IMUaccel_states[5 + i_0] *
      rtCP_FIR_IMUaccel_Coefficients[denIdx];
    denIdx++;
  }

  for (i_0 = 0; i_0 < stateEstimator_DW.FIR_IMUaccel_circBuf; i_0++) {
    acc1 += stateEstimator_DW.FIR_IMUaccel_states[5 + i_0] *
      rtCP_FIR_IMUaccel_Coefficients[denIdx];
    denIdx++;
  }

  rtb_FIR_IMUaccel[1] = acc1;

  /* Math: '<S2>/Math Function' incorporates:
   *  DiscreteFir: '<S5>/FIR_IMUaccel'
   */
  if ((acc1 < 0.0F) && (2.0F > rtb_TrigonometricFunction_o2_idx_1)) {
    rtb_TrigonometricFunction_o1_idx_1 = -rt_powf_snf(-acc1, 2.0F);
  } else {
    rtb_TrigonometricFunction_o1_idx_1 = rt_powf_snf(acc1, 2.0F);
  }

  /* DiscreteFir: '<S5>/FIR_IMUaccel' */
  acc1 = stateEstimator_B.inverseIMU_gain[2] * 0.0264077242F;
  denIdx = 1;
  for (i_0 = stateEstimator_DW.FIR_IMUaccel_circBuf; i_0 < 5; i_0++) {
    acc1 += stateEstimator_DW.FIR_IMUaccel_states[10 + i_0] *
      rtCP_FIR_IMUaccel_Coefficients[denIdx];
    denIdx++;
  }

  for (i_0 = 0; i_0 < stateEstimator_DW.FIR_IMUaccel_circBuf; i_0++) {
    acc1 += stateEstimator_DW.FIR_IMUaccel_states[10 + i_0] *
      rtCP_FIR_IMUaccel_Coefficients[denIdx];
    denIdx++;
  }

  rtb_FIR_IMUaccel[2] = acc1;

  /* Math: '<S2>/Math Function' incorporates:
   *  DiscreteFir: '<S5>/FIR_IMUaccel'
   */
  if ((acc1 < 0.0F) && (2.0F > rtb_TrigonometricFunction_o2_idx_1)) {
    rtb_TrigonometricFunction_o2_idx_1 = -rt_powf_snf(-acc1, 2.0F);
  } else {
    rtb_TrigonometricFunction_o2_idx_1 = rt_powf_snf(acc1, 2.0F);
  }

  /* Sqrt: '<S2>/Sqrt' incorporates:
   *  Sum: '<S2>/Sum of Elements'
   */
  rtb_Sqrt = (real32_T)sqrt((rtb_TrigonometricFunction_o2_idx_0 +
    rtb_TrigonometricFunction_o1_idx_1) + rtb_TrigonometricFunction_o2_idx_1);

  /* If: '<S2>/If' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Gain: '<S2>/Gain'
   *  Inport: '<S10>/prin'
   *  Logic: '<S2>/Logical Operator'
   *  Memory: '<S2>/Memory'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  SignalConversion: '<S12>/TmpSignal ConversionAtTrigonometric FunctionInport1'
   *  Sum: '<S2>/Sum'
   */
  if ((rtb_Sqrt > 9.79038F) && (rtb_Sqrt < 9.82962F)) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Sum: '<S8>/Sum' incorporates:
     *  DiscreteFir: '<S5>/FIR_IMUaccel'
     *  Gain: '<S2>/Gain'
     *  Gain: '<S8>/Gain'
     *  Gain: '<S8>/Gain1'
     *  Memory: '<S2>/Memory'
     *  Product: '<S8>/Divide'
     *  SignalConversion: '<S12>/TmpSignal ConversionAtTrigonometric FunctionInport1'
     *  Sum: '<S2>/Sum'
     *  Trigonometry: '<S8>/Trigonometric Function'
     */
    stateEstimator_B.Merge[1] = (0.005F * rtb_Product_n[2] +
      stateEstimator_DW.Memory_PreviousInput[2]) * 0.999F + (real32_T)atan
      (rtb_FIR_IMUaccel[1] / acc1) * 0.001F;

    /* Gain: '<S8>/Gain2' */
    rtb_TrigonometricFunction_o2_idx_0 = 0.101936802F * rtb_FIR_IMUaccel[0];

    /* Trigonometry: '<S8>/Trigonometric Function1' */
    if (rtb_TrigonometricFunction_o2_idx_0 > 1.0F) {
      rtb_TrigonometricFunction_o2_idx_0 = 1.0F;
    } else {
      if (rtb_TrigonometricFunction_o2_idx_0 < -1.0F) {
        rtb_TrigonometricFunction_o2_idx_0 = -1.0F;
      }
    }

    /* Sum: '<S8>/Sum1' incorporates:
     *  Gain: '<S2>/Gain'
     *  Gain: '<S8>/Gain3'
     *  Gain: '<S8>/Gain4'
     *  Memory: '<S2>/Memory'
     *  SignalConversion: '<S12>/TmpSignal ConversionAtTrigonometric FunctionInport1'
     *  Sum: '<S2>/Sum'
     *  Trigonometry: '<S8>/Trigonometric Function1'
     */
    stateEstimator_B.Merge[0] = (0.005F * rtb_Product_n[1] +
      stateEstimator_DW.Memory_PreviousInput[1]) * 0.999F + 0.001F * (real32_T)
      asin(rtb_TrigonometricFunction_o2_idx_0);

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    stateEstimator_B.Merge[0] = 0.005F * rtb_Product_n[1] +
      stateEstimator_DW.Memory_PreviousInput[1];
    stateEstimator_B.Merge[1] = 0.005F * rtb_Product_n[2] +
      stateEstimator_DW.Memory_PreviousInput[2];

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
  }

  /* End of If: '<S2>/If' */

  /* Sum: '<S134>/Add1' incorporates:
   *  Delay: '<S68>/Delay'
   */
  rtb_TrigonometricFunction_o2_idx_0 = rtu_posVIS_datin[0] -
    stateEstimator_DW.Delay_DSTATE[0];
  rtb_TrigonometricFunction_o1_idx_1 = rtu_posVIS_datin[1] -
    stateEstimator_DW.Delay_DSTATE[1];

  /* Math: '<S134>/Math Function' */
  rtb_TrigonometricFunction_o2_idx_1 = (real32_T)floor(2.0F);
  if ((rtb_TrigonometricFunction_o2_idx_0 < 0.0F) && (2.0F >
       rtb_TrigonometricFunction_o2_idx_1)) {
    rtb_TrigonometricFunction_o2_idx_0 = -rt_powf_snf
      (-rtb_TrigonometricFunction_o2_idx_0, 2.0F);
  } else {
    rtb_TrigonometricFunction_o2_idx_0 = rt_powf_snf
      (rtb_TrigonometricFunction_o2_idx_0, 2.0F);
  }

  if ((rtb_TrigonometricFunction_o1_idx_1 < 0.0F) && (2.0F >
       rtb_TrigonometricFunction_o2_idx_1)) {
    rtb_TrigonometricFunction_o1_idx_1 = -rt_powf_snf
      (-rtb_TrigonometricFunction_o1_idx_1, 2.0F);
  } else {
    rtb_TrigonometricFunction_o1_idx_1 = rt_powf_snf
      (rtb_TrigonometricFunction_o1_idx_1, 2.0F);
  }

  /* End of Math: '<S134>/Math Function' */

  /* Abs: '<S134>/Abs' incorporates:
   *  Abs: '<S70>/Abs2'
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  LogicalOperator3_tmp = (real32_T)fabs(stateEstimator_B.Merge[0]);

  /* Abs: '<S134>/Abs1' incorporates:
   *  Abs: '<S70>/Abs3'
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  LogicalOperator3_tmp_0 = (real32_T)fabs(stateEstimator_B.Merge[1]);

  /* Logic: '<S134>/Logical Operator3' incorporates:
   *  Abs: '<S134>/Abs'
   *  Abs: '<S134>/Abs1'
   *  Constant: '<S180>/Constant'
   *  Constant: '<S181>/Constant'
   *  Constant: '<S182>/Constant'
   *  Constant: '<S183>/Constant'
   *  RelationalOperator: '<S180>/Compare'
   *  RelationalOperator: '<S181>/Compare'
   *  RelationalOperator: '<S182>/Compare'
   *  RelationalOperator: '<S183>/Compare'
   *  Sqrt: '<S134>/Sqrt'
   *  Sum: '<S134>/Sum of Elements'
   */
  stateEstimator_B.LogicalOperator3 = ((rtu_posVIS_datin[0] != (-99.0F)) &&
    (LogicalOperator3_tmp <= 0.18F) && (LogicalOperator3_tmp_0 <= 0.18F) &&
    ((real32_T)sqrt(rtb_TrigonometricFunction_o2_idx_0 +
                    rtb_TrigonometricFunction_o1_idx_1) < 1.0F));

  /* DataTypeConversion: '<S133>/DataTypeConversionEnable' */
  rtb_DataTypeConversionEnable = stateEstimator_B.LogicalOperator3;

  /* Outputs for Enabled SubSystem: '<S158>/Enabled Subsystem' */
  /* Constant: '<S133>/C' */
  stateEstimator_EnabledSubsystem(rtb_DataTypeConversionEnable,
    stateEstimator_ConstB.Conversion_g, rtCP_C_Value_p, rtb_Reshapey_a,
    rtb_MemoryX_f, &stateEstimator_B.EnabledSubsystem_m,
    &stateEstimator_DW.EnabledSubsystem_m);

  /* End of Outputs for SubSystem: '<S158>/Enabled Subsystem' */

  /* Sum: '<S158>/Add' */
  rtb_TrigonometricFunction_o2_idx_1 =
    stateEstimator_B.EnabledSubsystem_m.Product2[0] + rtb_MemoryX_f[0];
  rtb_TrigonometricFunction_o2_idx_0 =
    stateEstimator_B.EnabledSubsystem_m.Product2[1] + rtb_MemoryX_f[1];

  /* DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' */
  if ((*rtu_controlModePosVSOrient_flagin) &&
      (stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState <= 0)) {
    stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] = 0.0F;
    stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  }

  /* Switch: '<S68>/UseIPPosSwitch' incorporates:
   *  DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity'
   *  Reshape: '<S133>/Reshapexhat'
   */
  if (*rtu_usePosVIS_flagin > 0.0F) {
    rtb_TrigonometricFunction_o1_idx_1 = rtb_TrigonometricFunction_o2_idx_1;
    rtb_UseIPPosSwitch_idx_1 = rtb_TrigonometricFunction_o2_idx_0;
  } else {
    rtb_TrigonometricFunction_o1_idx_1 =
      stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0];
    rtb_UseIPPosSwitch_idx_1 = stateEstimator_DW.SimplyIntegrateVelocity_DSTATE
      [1];
  }

  /* End of Switch: '<S68>/UseIPPosSwitch' */

  /* Gain: '<S3>/invertzaxisGain' */
  stateEstimator_B.invertzaxisGain = (real_T)(-1.0F) *
    rtu_sensordata_datin->altitude_sonar;

  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  Constant: '<S17>/Constant'
   *  Delay: '<S3>/Delay2'
   */
  stateEstimator_B.Compare = (stateEstimator_DW.Delay2_DSTATE > 0.0);

  /* Delay: '<S14>/MemoryX' incorporates:
   *  DataTypeConversion: '<S14>/DataTypeConversionReset'
   */
  if (stateEstimator_B.Compare) {
    stateEstimator_DW.icLoad_p = 1U;
  }

  if (stateEstimator_DW.icLoad_p != 0) {
    stateEstimator_DW.MemoryX_DSTATE[0] = stateEstimator_ConstB.ReshapeX0[0];
    stateEstimator_DW.MemoryX_DSTATE[1] = stateEstimator_ConstB.ReshapeX0[1];
  }

  /* DiscreteFilter: '<S15>/pressureFilter_IIR' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Gain: '<S3>/prsToAltGain'
   *  Sum: '<S5>/Sum2'
   */
  stateEstimator_DW.pressureFilter_IIR_tmp = ((((rtu_sensordata_datin->prs -
    rtu_sensorCalibration_datin[6]) * 0.0832137167F - (-2.93717074F) *
    stateEstimator_DW.pressureFilter_IIR_states[0]) - 2.87629962F *
    stateEstimator_DW.pressureFilter_IIR_states[1]) - (-0.939098954F) *
    stateEstimator_DW.pressureFilter_IIR_states[2]) / 1.0F;

  /* DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_tmp = (((stateEstimator_B.invertzaxisGain -
    (-2.9371707284498911) * stateEstimator_DW.soonarFilter_IIR_states[0]) -
    2.8762997234793324 * stateEstimator_DW.soonarFilter_IIR_states[1]) -
    (-0.93909894032528318) * stateEstimator_DW.soonarFilter_IIR_states[2]) / 1.0;

  /* Saturate: '<S15>/SaturationSonar' */
  if ((stateEstimator_B.invertzaxisGain >= (-0.44)) || rtIsNaN(-0.44)) {
    rtb_Add_a_idx_0 = (-0.44);
  } else {
    rtb_Add_a_idx_0 = stateEstimator_B.invertzaxisGain;
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
    (stateEstimator_DW.Delay2_DSTATE - rtb_Add_a_idx_0) <= 0.3) &&
    (stateEstimator_B.invertzaxisGain < (-0.44))) || ((fabs((((3.75683794E-6F *
    stateEstimator_DW.pressureFilter_IIR_tmp + 1.12705138E-5F *
    stateEstimator_DW.pressureFilter_IIR_states[0]) + 1.12705138E-5F *
    stateEstimator_DW.pressureFilter_IIR_states[1]) + 3.75683794E-6F *
    stateEstimator_DW.pressureFilter_IIR_states[2]) -
    stateEstimator_DW.Delay2_DSTATE) >= 0.8) && (fabs((((3.7568380197305906E-6 *
    stateEstimator_DW.soonarFilter_IIR_tmp + 1.1270514059191772E-5 *
    stateEstimator_DW.soonarFilter_IIR_states[0]) + 1.1270514059191772E-5 *
    stateEstimator_DW.soonarFilter_IIR_states[1]) + 3.7568380197305906E-6 *
    stateEstimator_DW.soonarFilter_IIR_states[2]) -
    stateEstimator_DW.Delay2_DSTATE) >= 0.4)));

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
    rtb_Add1_g = stateEstimator_B.invertzaxisGain - (1.0 *
      stateEstimator_DW.MemoryX_DSTATE[0] + 0.0 *
      stateEstimator_DW.MemoryX_DSTATE[1]);

    /* Product: '<S61>/Product2' */
    stateEstimator_B.Product2[0] = stateEstimator_ConstB.Conversion[0] *
      rtb_Add1_g;
    stateEstimator_B.Product2[1] = stateEstimator_ConstB.Conversion[1] *
      rtb_Add1_g;
  } else {
    if (stateEstimator_DW.EnabledSubsystem_MODE) {
      /* Disable for Outport: '<S61>/deltax' */
      stateEstimator_B.Product2[0] = 0.0;
      stateEstimator_B.Product2[1] = 0.0;
      stateEstimator_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S40>/Enabled Subsystem' */

  /* Sum: '<S40>/Add' incorporates:
   *  Delay: '<S14>/MemoryX'
   */
  rtb_Add_a_idx_0 = stateEstimator_B.Product2[0] +
    stateEstimator_DW.MemoryX_DSTATE[0];
  rtb_Add_a_idx_1 = stateEstimator_B.Product2[1] +
    stateEstimator_DW.MemoryX_DSTATE[1];

  /* Gain: '<S67>/opticalFlowToVelocity_gain' */
  stateEstimator_B.opticalFlowToVelocity_gain[0] = 1.0F * rtu_opticalFlow_datin
    [0];
  stateEstimator_B.opticalFlowToVelocity_gain[1] = 1.0F * rtu_opticalFlow_datin
    [1];
  stateEstimator_B.opticalFlowToVelocity_gain[2] = 1.0F * rtu_opticalFlow_datin
    [2];

  /* Reshape: '<S71>/Reshapey' */
  rtb_Reshapey_o[0] = stateEstimator_B.opticalFlowToVelocity_gain[0];
  rtb_Reshapey_o[1] = stateEstimator_B.opticalFlowToVelocity_gain[1];

  /* Delay: '<S71>/MemoryX' */
  if (stateEstimator_DW.icLoad_i != 0) {
    stateEstimator_DW.MemoryX_DSTATE_d5[0] = stateEstimator_ConstB.ReshapeX0_k[0];
    stateEstimator_DW.MemoryX_DSTATE_d5[1] = stateEstimator_ConstB.ReshapeX0_k[1];
  }

  rtb_MemoryX_m[0] = stateEstimator_DW.MemoryX_DSTATE_d5[0];
  rtb_MemoryX_m[1] = stateEstimator_DW.MemoryX_DSTATE_d5[1];

  /* End of Delay: '<S71>/MemoryX' */
  for (i = 0; i < 2; i++) {
    /* DiscreteFilter: '<S70>/IIRgyroz' */
    tmp = i * 5;
    acc1 = stateEstimator_B.inverseIMU_gain[i + 3];
    denIdx = 1;
    for (i_0 = 0; i_0 < 5; i_0++) {
      acc1 -= stateEstimator_DW.IIRgyroz_states[tmp + i_0] *
        rtCP_IIRgyroz_DenCoef[denIdx];
      denIdx++;
    }

    stateEstimator_DW.IIRgyroz_tmp[i] = acc1 / 1.0F;
    acc1 = 0.282124132F * stateEstimator_DW.IIRgyroz_tmp[i];
    denIdx = 1;
    for (i_0 = 0; i_0 < 5; i_0++) {
      acc1 += stateEstimator_DW.IIRgyroz_states[tmp + i_0] *
        rtCP_IIRgyroz_NumCoef[denIdx];
      denIdx++;
    }

    /* SampleTimeMath: '<S77>/TSamp' incorporates:
     *  DiscreteFilter: '<S70>/IIRgyroz'
     *
     * About '<S77>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    acc1 *= 200.0F;

    /* Sum: '<S77>/Diff' incorporates:
     *  UnitDelay: '<S77>/UD'
     */
    rtb_Diff[i] = acc1 - stateEstimator_DW.UD_DSTATE[i];

    /* Sum: '<S70>/Add' incorporates:
     *  Delay: '<S67>/Delay'
     */
    rtb_Add_hi[i] = stateEstimator_B.opticalFlowToVelocity_gain[i] -
      stateEstimator_DW.Delay_DSTATE_g[i];

    /* SampleTimeMath: '<S77>/TSamp'
     *
     * About '<S77>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp[i] = acc1;
  }

  /* Abs: '<S70>/Abs' incorporates:
   *  Abs: '<S70>/Abs4'
   */
  acc1 = (real32_T)fabs(stateEstimator_B.inverseIMU_gain[3]);

  /* Abs: '<S70>/Abs1' incorporates:
   *  Abs: '<S70>/Abs5'
   */
  LogicalOperator3_a_tmp = (real32_T)fabs(stateEstimator_B.inverseIMU_gain[4]);

  /* Logic: '<S70>/Logical Operator3' incorporates:
   *  Abs: '<S70>/Abs'
   *  Abs: '<S70>/Abs1'
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
   */
  stateEstimator_B.LogicalOperator3_a = ((((LogicalOperator3_tmp <= 0.6F) &&
    (LogicalOperator3_tmp_0 <= 0.6F) && (acc1 <= 7.0F) &&
    (LogicalOperator3_a_tmp <= 7.0F) && ((real32_T)fabs(rtb_Diff[0]) <= 80.0F) &&
    ((real32_T)fabs(rtb_Diff[1]) <= 80.0F)) || ((acc1 <= 0.5F) &&
    (LogicalOperator3_a_tmp <= 0.5F))) && ((real32_T)fabs(rtb_Add_hi[0]) <= 5.0F)
    && ((real32_T)fabs(rtb_Add_hi[1]) <= 5.0F) && ((real32_T)rtb_Add_a_idx_0 <=
    (-0.4F)));

  /* DataTypeConversion: '<S71>/DataTypeConversionEnable' */
  rtb_DataTypeConversionEnable_i = stateEstimator_B.LogicalOperator3_a;

  /* Outputs for Enabled SubSystem: '<S111>/Enabled Subsystem' */
  /* Constant: '<S71>/C' */
  stateEstimator_EnabledSubsystem(rtb_DataTypeConversionEnable_i,
    stateEstimator_ConstB.Conversion_p, rtCP_C_Value_f, rtb_Reshapey_o,
    rtb_MemoryX_m, &stateEstimator_B.EnabledSubsystem_f,
    &stateEstimator_DW.EnabledSubsystem_f);

  /* End of Outputs for SubSystem: '<S111>/Enabled Subsystem' */

  /* Sum: '<S111>/Add' */
  rtb_Add_m[0] = stateEstimator_B.EnabledSubsystem_f.Product2[0] +
    rtb_MemoryX_m[0];
  rtb_Add_m[1] = stateEstimator_B.EnabledSubsystem_f.Product2[1] +
    rtb_MemoryX_m[1];

  /* Trigonometry: '<S16>/sincos' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   *  Trigonometry: '<S135>/sincos'
   *  Trigonometry: '<S73>/sincos'
   */
  acc1 = (real32_T)sin(rtb_Merge1);
  LogicalOperator3_tmp = (real32_T)cos(rtb_Merge1);
  LogicalOperator3_tmp_0 = (real32_T)sin(stateEstimator_B.Merge[0]);
  LogicalOperator3_a_tmp = (real32_T)cos(stateEstimator_B.Merge[0]);
  rtb_sincos_o1_idx_2_tmp = (real32_T)sin(stateEstimator_B.Merge[1]);
  rtb_sincos_o2_idx_2_tmp = (real32_T)cos(stateEstimator_B.Merge[1]);

  /* Fcn: '<S16>/Fcn11' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[0] = LogicalOperator3_a_tmp * LogicalOperator3_tmp;

  /* Fcn: '<S16>/Fcn21' incorporates:
   *  Fcn: '<S16>/Fcn22'
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_h_tmp = rtb_sincos_o1_idx_2_tmp * LogicalOperator3_tmp_0;
  rtb_VectorConcatenate_i[1] = rtb_VectorConcatenate_h_tmp *
    LogicalOperator3_tmp - rtb_sincos_o2_idx_2_tmp * acc1;

  /* Fcn: '<S16>/Fcn31' incorporates:
   *  Fcn: '<S16>/Fcn32'
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_h_tmp_0 = rtb_sincos_o2_idx_2_tmp *
    LogicalOperator3_tmp_0;
  rtb_VectorConcatenate_i[2] = rtb_VectorConcatenate_h_tmp_0 *
    LogicalOperator3_tmp + rtb_sincos_o1_idx_2_tmp * acc1;

  /* Fcn: '<S16>/Fcn12' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[3] = LogicalOperator3_a_tmp * acc1;

  /* Fcn: '<S16>/Fcn22' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[4] = rtb_VectorConcatenate_h_tmp * acc1 +
    rtb_sincos_o2_idx_2_tmp * LogicalOperator3_tmp;

  /* Fcn: '<S16>/Fcn32' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[5] = rtb_VectorConcatenate_h_tmp_0 * acc1 -
    rtb_sincos_o1_idx_2_tmp * LogicalOperator3_tmp;

  /* Fcn: '<S16>/Fcn13' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[6] = -LogicalOperator3_tmp_0;

  /* Fcn: '<S16>/Fcn23' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[7] = rtb_sincos_o1_idx_2_tmp * LogicalOperator3_a_tmp;

  /* Fcn: '<S16>/Fcn33' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[8] = rtb_sincos_o2_idx_2_tmp * LogicalOperator3_a_tmp;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_states_estimout_at_inport_0' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Reshape: '<S14>/Reshapexhat'
   *  Reshape: '<S71>/Reshapexhat'
   */
  rty_states_estimout->X = rtb_TrigonometricFunction_o1_idx_1;
  rty_states_estimout->Y = rtb_UseIPPosSwitch_idx_1;
  rty_states_estimout->Z = (real32_T)rtb_Add_a_idx_0;
  rty_states_estimout->yaw = rtb_Merge1;
  rty_states_estimout->pitch = stateEstimator_B.Merge[0];
  rty_states_estimout->roll = stateEstimator_B.Merge[1];
  rty_states_estimout->dx = rtb_Add_m[0];
  rty_states_estimout->dy = rtb_Add_m[1];

  /* Product: '<S3>/Product1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Delay: '<S1>/Delay1'
   *  Reshape: '<S14>/Reshapexhat'
   *  Reshape: '<S66>/Reshape (9) to [3x3] column-major'
   *  SignalConversion: '<S3>/TmpSignal ConversionAtProduct1Inport2'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_VectorConcatenate_h_0[i_0] = rtb_VectorConcatenate_i[i_0 + 6] *
      rtb_Add_a_idx_1 + ((real_T)rtb_VectorConcatenate_i[i_0 + 3] *
                         stateEstimator_DW.Delay1_DSTATE[1] + (real_T)
                         rtb_VectorConcatenate_i[i_0] *
                         stateEstimator_DW.Delay1_DSTATE[0]);
  }

  /* BusCreator: '<Root>/BusConversion_InsertedFor_states_estimout_at_inport_0' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtProductInport2'
   */
  rty_states_estimout->dz = (real32_T)rtb_VectorConcatenate_h_0[2];
  rty_states_estimout->p = stateEstimator_B.inverseIMU_gain[3];
  rty_states_estimout->q = stateEstimator_B.inverseIMU_gain[4];
  rty_states_estimout->r = rtb_TrigonometricFunction_o1_idx_0;

  /* ManualSwitch: '<S14>/ManualSwitchPZ' incorporates:
   *  Constant: '<S14>/P0'
   */
  if (((uint8_T)1U) == 1) {
    rtb_ManualSwitchPZ[0] = stateEstimator_ConstB.Conversion_c[0];
    rtb_ManualSwitchPZ[1] = stateEstimator_ConstB.Conversion_c[1];
    rtb_ManualSwitchPZ[2] = stateEstimator_ConstB.Conversion_c[2];
    rtb_ManualSwitchPZ[3] = stateEstimator_ConstB.Conversion_c[3];
  } else {
    rtb_ManualSwitchPZ[0] = 0.0026948589925819225;
    rtb_ManualSwitchPZ[1] = 0.0071657120718246663;
    rtb_ManualSwitchPZ[2] = 0.0071657120718246663;
    rtb_ManualSwitchPZ[3] = 0.038107692935055663;
  }

  /* End of ManualSwitch: '<S14>/ManualSwitchPZ' */

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S3>/gravity'
   *  Math: '<S3>/Math Function'
   *  Product: '<S3>/Product'
   *  Reshape: '<S66>/Reshape (9) to [3x3] column-major'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    stateEstimator_B.Sum[i_0] = ((rtb_VectorConcatenate_i[3 * i_0 + 1] *
      rtb_FIR_IMUaccel[1] + rtb_VectorConcatenate_i[3 * i_0] * rtb_FIR_IMUaccel
      [0]) + rtb_VectorConcatenate_i[3 * i_0 + 2] * rtb_FIR_IMUaccel[2]) +
      rtCP_gravity_Value[i_0];
  }

  /* End of Sum: '<S3>/Sum' */

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
    rtb_Sum = stateEstimator_B.invertzaxisGain - ((1.0 *
      stateEstimator_DW.MemoryX_DSTATE[0] + 0.0 *
      stateEstimator_DW.MemoryX_DSTATE[1]) + 0.0 * stateEstimator_B.Sum[2]);

    /* Product: '<S60>/Product3' */
    stateEstimator_B.Product3[0] = stateEstimator_ConstB.Conversion_n[0] *
      rtb_Sum;
    stateEstimator_B.Product3[1] = stateEstimator_ConstB.Conversion_n[1] *
      rtb_Sum;
  } else {
    if (stateEstimator_DW.MeasurementUpdate_MODE) {
      /* Disable for Outport: '<S60>/L*(y[k]-yhat[k|k-1])' */
      stateEstimator_B.Product3[0] = 0.0;
      stateEstimator_B.Product3[1] = 0.0;
      stateEstimator_DW.MeasurementUpdate_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S35>/MeasurementUpdate' */

  /* Fcn: '<S73>/Fcn11' */
  rtb_VectorConcatenate_h[0] = LogicalOperator3_a_tmp * LogicalOperator3_tmp;

  /* Fcn: '<S73>/Fcn21' */
  rtb_VectorConcatenate_h[1] = rtb_sincos_o1_idx_2_tmp * LogicalOperator3_tmp_0 *
    LogicalOperator3_tmp - rtb_sincos_o2_idx_2_tmp * acc1;

  /* Fcn: '<S73>/Fcn31' */
  rtb_VectorConcatenate_h[2] = rtb_sincos_o2_idx_2_tmp * LogicalOperator3_tmp_0 *
    LogicalOperator3_tmp + rtb_sincos_o1_idx_2_tmp * acc1;

  /* Fcn: '<S73>/Fcn12' */
  rtb_VectorConcatenate_h[3] = LogicalOperator3_a_tmp * acc1;

  /* Fcn: '<S73>/Fcn22' */
  rtb_VectorConcatenate_h[4] = rtb_sincos_o1_idx_2_tmp * LogicalOperator3_tmp_0 *
    acc1 + rtb_sincos_o2_idx_2_tmp * LogicalOperator3_tmp;

  /* Fcn: '<S73>/Fcn32' */
  rtb_VectorConcatenate_h[5] = rtb_sincos_o2_idx_2_tmp * LogicalOperator3_tmp_0 *
    acc1 - rtb_sincos_o1_idx_2_tmp * LogicalOperator3_tmp;

  /* Fcn: '<S73>/Fcn13' */
  rtb_VectorConcatenate_h[6] = -LogicalOperator3_tmp_0;

  /* Fcn: '<S73>/Fcn23' */
  rtb_VectorConcatenate_h[7] = rtb_sincos_o1_idx_2_tmp * LogicalOperator3_a_tmp;

  /* Fcn: '<S73>/Fcn33' */
  rtb_VectorConcatenate_h[8] = rtb_sincos_o2_idx_2_tmp * LogicalOperator3_a_tmp;

  /* RelationalOperator: '<S72>/Compare' incorporates:
   *  Constant: '<S72>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Reshape: '<S14>/Reshapexhat'
   */
  rtb_Compare_i = ((real32_T)rtb_Add_a_idx_0 <= (-0.4F));

  /* Logic: '<S69>/Logical Operator' incorporates:
   *  Constant: '<S74>/Constant'
   *  Constant: '<S75>/Constant'
   *  RelationalOperator: '<S74>/Compare'
   *  RelationalOperator: '<S75>/Compare'
   */
  rtb_LogicalOperator_cg = ((stateEstimator_B.opticalFlowToVelocity_gain[0] !=
    0.0F) || (stateEstimator_B.opticalFlowToVelocity_gain[1] != 0.0F));

  /* Sum: '<S69>/Add' incorporates:
   *  Constant: '<S69>/gravity'
   *  Product: '<S69>/Product1'
   *  Reshape: '<S76>/Reshape (9) to [3x3] column-major'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_VectorConcatenate_h_0[i_0] = rtb_FIR_IMUaccel[i_0] -
      ((rtb_VectorConcatenate_h[i_0 + 3] * 0.0 + rtb_VectorConcatenate_h[i_0] *
        0.0) + rtb_VectorConcatenate_h[i_0 + 6] * (-9.81));
  }

  /* End of Sum: '<S69>/Add' */

  /* Product: '<S69>/Product' incorporates:
   *  Gain: '<S69>/gainaccinput'
   */
  stateEstimator_B.Product[0] = (real32_T)(0.2 * rtb_VectorConcatenate_h_0[0]) *
    (real32_T)rtb_LogicalOperator_cg * (real32_T)rtb_Compare_i;
  stateEstimator_B.Product[1] = (real32_T)(0.2 * rtb_VectorConcatenate_h_0[1]) *
    (real32_T)rtb_LogicalOperator_cg * (real32_T)rtb_Compare_i;

  /* DataTypeConversion: '<S102>/Conversion' */
  rtb_Conversion_j[0] = rtb_MemoryX_m[0];
  rtb_Conversion_j[1] = rtb_MemoryX_m[1];

  /* ManualSwitch: '<S71>/ManualSwitchPZ' incorporates:
   *  Constant: '<S71>/P0'
   */
  if (((uint8_T)1U) == 1) {
    rtb_ManualSwitchPZ_m[0] = stateEstimator_ConstB.Conversion_i[0];
    rtb_ManualSwitchPZ_m[1] = stateEstimator_ConstB.Conversion_i[1];
    rtb_ManualSwitchPZ_m[2] = stateEstimator_ConstB.Conversion_i[2];
    rtb_ManualSwitchPZ_m[3] = stateEstimator_ConstB.Conversion_i[3];
  } else {
    rtb_ManualSwitchPZ_m[0] = 0.717328072F;
    rtb_ManualSwitchPZ_m[1] = 0.0F;
    rtb_ManualSwitchPZ_m[2] = 0.0F;
    rtb_ManualSwitchPZ_m[3] = 0.717328072F;
  }

  /* End of ManualSwitch: '<S71>/ManualSwitchPZ' */

  /* Reshape: '<S71>/Reshapeu' */
  rtb_Reshapeu_h[0] = stateEstimator_B.Product[0];
  rtb_Reshapeu_h[1] = stateEstimator_B.Product[1];

  /* Outputs for Enabled SubSystem: '<S106>/MeasurementUpdate' */
  /* Constant: '<S71>/C' incorporates:
   *  Constant: '<S71>/D'
   */
  stateEstimator_MeasurementUpdate(rtb_DataTypeConversionEnable_i,
    stateEstimator_ConstB.Conversion_n4, rtb_Reshapey_o, rtCP_C_Value_f,
    rtb_Conversion_j, rtCP_D_Value_f, rtb_Reshapeu_h,
    &stateEstimator_B.MeasurementUpdate_e,
    &stateEstimator_DW.MeasurementUpdate_e);

  /* End of Outputs for SubSystem: '<S106>/MeasurementUpdate' */

  /* DataTypeConversion: '<S149>/Conversion' */
  rtb_Conversion_p[0] = rtb_MemoryX_f[0];
  rtb_Conversion_p[1] = rtb_MemoryX_f[1];

  /* ManualSwitch: '<S133>/ManualSwitchPZ' incorporates:
   *  Constant: '<S133>/P0'
   */
  if (((uint8_T)1U) == 1) {
    rtb_ManualSwitchPZ_p[0] = stateEstimator_ConstB.Conversion_ao[0];
    rtb_ManualSwitchPZ_p[1] = stateEstimator_ConstB.Conversion_ao[1];
    rtb_ManualSwitchPZ_p[2] = stateEstimator_ConstB.Conversion_ao[2];
    rtb_ManualSwitchPZ_p[3] = stateEstimator_ConstB.Conversion_ao[3];
  } else {
    rtb_ManualSwitchPZ_p[0] = 0.00173705805F;
    rtb_ManualSwitchPZ_p[1] = 0.0F;
    rtb_ManualSwitchPZ_p[2] = 0.0F;
    rtb_ManualSwitchPZ_p[3] = 0.00173705805F;
  }

  /* End of ManualSwitch: '<S133>/ManualSwitchPZ' */

  /* Fcn: '<S135>/Fcn11' */
  rtb_VectorConcatenate_p[0] = LogicalOperator3_a_tmp * LogicalOperator3_tmp;

  /* Fcn: '<S135>/Fcn21' */
  rtb_VectorConcatenate_p[1] = rtb_sincos_o1_idx_2_tmp * LogicalOperator3_tmp_0 *
    LogicalOperator3_tmp - rtb_sincos_o2_idx_2_tmp * acc1;

  /* Fcn: '<S135>/Fcn31' */
  rtb_VectorConcatenate_p[2] = rtb_sincos_o2_idx_2_tmp * LogicalOperator3_tmp_0 *
    LogicalOperator3_tmp + rtb_sincos_o1_idx_2_tmp * acc1;

  /* Fcn: '<S135>/Fcn12' */
  rtb_VectorConcatenate_p[3] = LogicalOperator3_a_tmp * acc1;

  /* Fcn: '<S135>/Fcn22' */
  rtb_VectorConcatenate_p[4] = rtb_sincos_o1_idx_2_tmp * LogicalOperator3_tmp_0 *
    acc1 + rtb_sincos_o2_idx_2_tmp * LogicalOperator3_tmp;

  /* Fcn: '<S135>/Fcn32' */
  rtb_VectorConcatenate_p[5] = rtb_sincos_o2_idx_2_tmp * LogicalOperator3_tmp_0 *
    acc1 - rtb_sincos_o1_idx_2_tmp * LogicalOperator3_tmp;

  /* Fcn: '<S135>/Fcn13' */
  rtb_VectorConcatenate_p[6] = -LogicalOperator3_tmp_0;

  /* Fcn: '<S135>/Fcn23' */
  rtb_VectorConcatenate_p[7] = rtb_sincos_o1_idx_2_tmp * LogicalOperator3_a_tmp;

  /* Fcn: '<S135>/Fcn33' */
  rtb_VectorConcatenate_p[8] = rtb_sincos_o2_idx_2_tmp * LogicalOperator3_a_tmp;

  /* Product: '<S3>/Product1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Delay: '<S1>/Delay1'
   *  Reshape: '<S14>/Reshapexhat'
   *  Reshape: '<S66>/Reshape (9) to [3x3] column-major'
   *  SignalConversion: '<S3>/TmpSignal ConversionAtProduct1Inport2'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_VectorConcatenate_h_0[i_0] = rtb_VectorConcatenate_i[i_0 + 6] *
      rtb_Add_a_idx_1 + ((real_T)rtb_VectorConcatenate_i[i_0 + 3] *
                         stateEstimator_DW.Delay1_DSTATE[1] + (real_T)
                         rtb_VectorConcatenate_i[i_0] *
                         stateEstimator_DW.Delay1_DSTATE[0]);
  }

  /* Product: '<S68>/Product' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Math: '<S68>/Math Function'
   *  Reshape: '<S184>/Reshape (9) to [3x3] column-major'
   *  Reshape: '<S71>/Reshapexhat'
   *  SignalConversion: '<S68>/TmpSignal ConversionAtProductInport2'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    stateEstimator_B.Product_l[i_0] = 0.0F;
    stateEstimator_B.Product_l[i_0] += rtb_VectorConcatenate_p[3 * i_0] *
      rtb_Add_m[0];
    stateEstimator_B.Product_l[i_0] += rtb_VectorConcatenate_p[3 * i_0 + 1] *
      rtb_Add_m[1];
    stateEstimator_B.Product_l[i_0] += rtb_VectorConcatenate_p[3 * i_0 + 2] *
      (real32_T)rtb_VectorConcatenate_h_0[2];
  }

  /* End of Product: '<S68>/Product' */

  /* Reshape: '<S133>/Reshapeu' */
  rtb_Reshapeu_i[0] = stateEstimator_B.Product_l[0];
  rtb_Reshapeu_i[1] = stateEstimator_B.Product_l[1];

  /* Outputs for Enabled SubSystem: '<S153>/MeasurementUpdate' */
  /* Constant: '<S133>/C' incorporates:
   *  Constant: '<S133>/D'
   */
  stateEstimator_MeasurementUpdate(rtb_DataTypeConversionEnable,
    stateEstimator_ConstB.Conversion_a, rtb_Reshapey_a, rtCP_C_Value_p,
    rtb_Conversion_p, rtCP_D_Value_b, rtb_Reshapeu_i,
    &stateEstimator_B.MeasurementUpdate_b,
    &stateEstimator_DW.MeasurementUpdate_b);

  /* End of Outputs for SubSystem: '<S153>/MeasurementUpdate' */

  /* Update for Delay: '<S133>/MemoryX' incorporates:
   *  Constant: '<S133>/A'
   *  Constant: '<S133>/B'
   *  Product: '<S153>/A[k]*xhat[k|k-1]'
   *  Product: '<S153>/B[k]*u[k]'
   *  Sum: '<S153>/Add'
   */
  stateEstimator_DW.icLoad = 0U;
  stateEstimator_DW.MemoryX_DSTATE_d[0] = ((0.005F * rtb_Reshapeu_i[0] + 0.0F *
    rtb_Reshapeu_i[1]) + (1.0F * rtb_Conversion_p[0] + 0.0F * rtb_Conversion_p[1]))
    + stateEstimator_B.MeasurementUpdate_b.Product3[0];
  stateEstimator_DW.MemoryX_DSTATE_d[1] = ((0.0F * rtb_Reshapeu_i[0] + 0.005F *
    rtb_Reshapeu_i[1]) + (0.0F * rtb_Conversion_p[0] + 1.0F * rtb_Conversion_p[1]))
    + stateEstimator_B.MeasurementUpdate_b.Product3[1];

  /* Update for Memory: '<S2>/Memory' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  stateEstimator_DW.Memory_PreviousInput[0] = rtb_Merge1;
  stateEstimator_DW.Memory_PreviousInput[1] = stateEstimator_B.Merge[0];
  stateEstimator_DW.Memory_PreviousInput[2] = stateEstimator_B.Merge[1];

  /* Update for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
  stateEstimator_DW.IIR_IMUgyro_r_states[4] =
    stateEstimator_DW.IIR_IMUgyro_r_states[3];
  stateEstimator_DW.IIR_IMUgyro_r_states[3] =
    stateEstimator_DW.IIR_IMUgyro_r_states[2];
  stateEstimator_DW.IIR_IMUgyro_r_states[2] =
    stateEstimator_DW.IIR_IMUgyro_r_states[1];
  stateEstimator_DW.IIR_IMUgyro_r_states[1] =
    stateEstimator_DW.IIR_IMUgyro_r_states[0];
  stateEstimator_DW.IIR_IMUgyro_r_states[0] =
    stateEstimator_DW.IIR_IMUgyro_r_tmp;

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

  /* Update for DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState = (int8_T)
    *rtu_controlModePosVSOrient_flagin;

  /* Update for Delay: '<S3>/Delay2' incorporates:
   *  Reshape: '<S14>/Reshapexhat'
   */
  stateEstimator_DW.Delay2_DSTATE = rtb_Add_a_idx_0;

  /* Update for Delay: '<S14>/MemoryX' */
  stateEstimator_DW.icLoad_p = 0U;

  /* Update for Delay: '<S68>/Delay' incorporates:
   *  Reshape: '<S133>/Reshapexhat'
   */
  stateEstimator_DW.Delay_DSTATE[0] = rtb_TrigonometricFunction_o2_idx_1;

  /* Update for DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] += 0.005F *
    stateEstimator_B.Product_l[0];

  /* Update for Delay: '<S68>/Delay' incorporates:
   *  Reshape: '<S133>/Reshapexhat'
   */
  stateEstimator_DW.Delay_DSTATE[1] = rtb_TrigonometricFunction_o2_idx_0;

  /* Update for DiscreteIntegrator: '<S68>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] += 0.005F *
    stateEstimator_B.Product_l[1];

  /* Product: '<S35>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S14>/A'
   *  Delay: '<S14>/MemoryX'
   */
  rtb_Add_a_idx_0 = 0.0 * stateEstimator_DW.MemoryX_DSTATE[0] + 1.0 *
    stateEstimator_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S14>/A'
   *  Constant: '<S14>/B'
   *  Product: '<S35>/A[k]*xhat[k|k-1]'
   *  Product: '<S35>/B[k]*u[k]'
   *  Reshape: '<S14>/Reshapeu'
   *  Sum: '<S35>/Add'
   */
  stateEstimator_DW.MemoryX_DSTATE[0] = ((1.0 *
    stateEstimator_DW.MemoryX_DSTATE[0] + 0.005 *
    stateEstimator_DW.MemoryX_DSTATE[1]) + 0.0 * stateEstimator_B.Sum[2]) +
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
  stateEstimator_DW.MemoryX_DSTATE[1] = (0.005 * stateEstimator_B.Sum[2] +
    rtb_Add_a_idx_0) + stateEstimator_B.Product3[1];

  /* Update for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[1] =
    stateEstimator_DW.pressureFilter_IIR_states[0];
  stateEstimator_DW.pressureFilter_IIR_states[0] =
    stateEstimator_DW.pressureFilter_IIR_tmp;

  /* Update for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[2] =
    stateEstimator_DW.soonarFilter_IIR_states[1];
  stateEstimator_DW.soonarFilter_IIR_states[1] =
    stateEstimator_DW.soonarFilter_IIR_states[0];
  stateEstimator_DW.soonarFilter_IIR_states[0] =
    stateEstimator_DW.soonarFilter_IIR_tmp;

  /* Update for Delay: '<S71>/MemoryX' incorporates:
   *  Constant: '<S71>/A'
   *  Constant: '<S71>/B'
   *  Product: '<S106>/A[k]*xhat[k|k-1]'
   *  Product: '<S106>/B[k]*u[k]'
   *  Sum: '<S106>/Add'
   */
  stateEstimator_DW.icLoad_i = 0U;
  stateEstimator_DW.MemoryX_DSTATE_d5[0] = ((0.005F * rtb_Reshapeu_h[0] + 0.0F *
    rtb_Reshapeu_h[1]) + (1.0F * rtb_Conversion_j[0] + 0.0F * rtb_Conversion_j[1]))
    + stateEstimator_B.MeasurementUpdate_e.Product3[0];
  stateEstimator_DW.MemoryX_DSTATE_d5[1] = ((0.0F * rtb_Reshapeu_h[0] + 0.005F *
    rtb_Reshapeu_h[1]) + (0.0F * rtb_Conversion_j[0] + 1.0F * rtb_Conversion_j[1]))
    + stateEstimator_B.MeasurementUpdate_e.Product3[1];
  for (i = 0; i < 2; i++) {
    /* Update for DiscreteFilter: '<S70>/IIRgyroz' */
    tmp = i * 5;
    stateEstimator_DW.IIRgyroz_states[tmp + 4] =
      stateEstimator_DW.IIRgyroz_states[tmp + 3];
    stateEstimator_DW.IIRgyroz_states[tmp + 3] =
      stateEstimator_DW.IIRgyroz_states[tmp + 2];
    stateEstimator_DW.IIRgyroz_states[tmp + 2] =
      stateEstimator_DW.IIRgyroz_states[tmp + 1];
    stateEstimator_DW.IIRgyroz_states[tmp + 1] =
      stateEstimator_DW.IIRgyroz_states[tmp];
    stateEstimator_DW.IIRgyroz_states[tmp] = stateEstimator_DW.IIRgyroz_tmp[i];

    /* Update for UnitDelay: '<S77>/UD' */
    stateEstimator_DW.UD_DSTATE[i] = rtb_TSamp[i];

    /* Update for Delay: '<S67>/Delay' incorporates:
     *  Reshape: '<S71>/Reshapexhat'
     */
    stateEstimator_DW.Delay_DSTATE_g[i] = rtb_Add_m[i];

    /* Update for Delay: '<S1>/Delay1' incorporates:
     *  Reshape: '<S71>/Reshapexhat'
     */
    stateEstimator_DW.Delay1_DSTATE[i] = rtb_Add_m[i];
  }
}

/* Model initialize function */
void stateEstimator_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_stateEstimator_T *const stateEstimator_M =
    &(stateEstimator_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(stateEstimator_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) &stateEstimator_B), 0,
                sizeof(B_stateEstimator_c_T));

  /* states (dwork) */
  (void) memset((void *)&stateEstimator_DW, 0,
                sizeof(DW_stateEstimator_f_T));
}

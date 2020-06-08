/*
 * File: flightControlSystem.c
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

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/controller' */
uint8_T flag_outport;                  /* '<S2>/Merge' */

/* Block signals (default storage) */
B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
DW_flightControlSystem_T flightControlSystem_DW;

/* External inputs (root inport signals with default storage) */
ExtU_flightControlSystem_T flightControlSystem_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_flightControlSystem_T flightControlSystem_Y;

/* Real-time model */
RT_MODEL_flightControlSystem_T flightControlSystem_M_;
RT_MODEL_flightControlSystem_T *const flightControlSystem_M =
  &flightControlSystem_M_;

/*
 * Output and update for action system:
 *    '<S2>/Geofencing error'
 *    '<S2>/estimator//Optical flow error'
 *    '<S2>/Normal condition'
 */
void flightControlSystem_Geofencingerror(uint8_T *rty_Out1,
  P_Geofencingerror_flightControlSystem_T *localP)
{
  /* SignalConversion: '<S12>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
   *  Constant: '<S12>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/* Start for atomic system: '<S1>/Logging' */
void flightControlSystem_Logging_Start(RT_MODEL_flightControlSystem_T * const
  flightControlSystem_M, DW_Logging_flightControlSystem_T *localDW)
{
  /* Start for ToWorkspace: '<S3>/To Workspace2' */
  {
    static int_T rt_ToWksWidths[] = { 12 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 12 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace2";
    localDW->ToWorkspace2_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "estim",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace2_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S3>/To Workspace6' */
  {
    static int_T rt_ToWksWidths[] = { 10 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 10 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace6";
    localDW->ToWorkspace6_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "sensor",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace6_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S3>/To Workspace3' */
  {
    static int_T rt_ToWksWidths[] = { 9 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 9 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace3";
    localDW->ToWorkspace3_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "cmd",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace3_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S3>/To Workspace4' */
  {
    static int_T rt_ToWksWidths[] = { 8 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 8 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace4";
    localDW->ToWorkspace4_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "optical",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace4_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S3>/To Workspace5' */
  {
    static int_T rt_ToWksWidths[] = { 8 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 8 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "SensorCalibration" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace5";
    localDW->ToWorkspace5_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "calib",
      1,
      0,
      100,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace5_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S3>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 4 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 4 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace";
    localDW->ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "motor",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S3>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 8 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 8 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace1";
    localDW->ToWorkspace1_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "posref",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }
}

/* Output and update for atomic system: '<S1>/Logging' */
void flightControlSystem_Logging(RT_MODEL_flightControlSystem_T * const
  flightControlSystem_M, const real32_T rtu_motorCmds[4], const real32_T
  rtu_posRef[8], const statesEstim_t *rtu_states_estim_Inport_3, const
  CommandBus *rtu_ReferenceValueServerBus_Inport_4, const SensorsBus
  *rtu_Sensors_Inport_5, real32_T rtu_sensordata_datin_Inport_6, uint32_T
  rtu_sensordata_datin_Inport_6_d, real32_T rtu_sensordata_datin_Inport_6_e,
  real32_T rtu_sensordata_datin_Inport_6_c, real32_T
  rtu_sensordata_datin_Inport_6_cg, real32_T rtu_sensordata_datin_Inport_6_i,
  real32_T rtu_sensordata_datin_Inport_6_h, real32_T
  rtu_sensordata_datin_Inport_6_b, real32_T rtu_sensordata_datin_Inport_6_dz,
  real32_T rtu_sensordata_datin_Inport_6_n, B_Logging_flightControlSystem_T
  *localB, DW_Logging_flightControlSystem_T *localDW)
{
  /* local block i/o variables */
  real32_T rtb_SigConversion_InsertedFor_Sensors_BusSelector_BusSelector_i[8];
  real32_T rtb_DataTypeConversion7;
  real32_T rtb_DataTypeConversion11;
  int32_T i;

  /* SignalConversion: '<S3>/states_estim_BusSelector' */
  rtb_DataTypeConversion7 = rtu_states_estim_Inport_3->q;
  rtb_DataTypeConversion11 = rtu_states_estim_Inport_3->r;

  /* SignalConversion: '<S3>/TmpSignal ConversionAtTo Workspace2Inport1' incorporates:
   *  SignalConversion: '<S3>/states_estim_BusSelector'
   */
  localB->TmpSignalConversionAtToWorkspace2Inport1[0] =
    rtu_states_estim_Inport_3->X;
  localB->TmpSignalConversionAtToWorkspace2Inport1[1] =
    rtu_states_estim_Inport_3->Y;
  localB->TmpSignalConversionAtToWorkspace2Inport1[2] =
    rtu_states_estim_Inport_3->Z;
  localB->TmpSignalConversionAtToWorkspace2Inport1[3] =
    rtu_states_estim_Inport_3->yaw;
  localB->TmpSignalConversionAtToWorkspace2Inport1[4] =
    rtu_states_estim_Inport_3->pitch;
  localB->TmpSignalConversionAtToWorkspace2Inport1[5] =
    rtu_states_estim_Inport_3->roll;
  localB->TmpSignalConversionAtToWorkspace2Inport1[6] =
    rtu_states_estim_Inport_3->dx;
  localB->TmpSignalConversionAtToWorkspace2Inport1[7] =
    rtu_states_estim_Inport_3->dy;
  localB->TmpSignalConversionAtToWorkspace2Inport1[8] =
    rtu_states_estim_Inport_3->dz;
  localB->TmpSignalConversionAtToWorkspace2Inport1[9] =
    rtu_states_estim_Inport_3->p;
  localB->TmpSignalConversionAtToWorkspace2Inport1[10] = rtb_DataTypeConversion7;
  localB->TmpSignalConversionAtToWorkspace2Inport1[11] =
    rtb_DataTypeConversion11;

  /* ToWorkspace: '<S3>/To Workspace2' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace2_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspace2Inport1[0]);
  }

  /* DataTypeConversion: '<S3>/Data Type Conversion1' */
  rtb_DataTypeConversion11 = rtu_sensordata_datin_Inport_6;

  /* DataTypeConversion: '<S3>/Data Type Conversion2' */
  rtb_DataTypeConversion7 = (real32_T)rtu_sensordata_datin_Inport_6_d;

  /* SignalConversion: '<S3>/TmpSignal ConversionAtTo Workspace6Inport1' */
  localB->TmpSignalConversionAtToWorkspace6Inport1[0] =
    rtu_sensordata_datin_Inport_6_e;
  localB->TmpSignalConversionAtToWorkspace6Inport1[1] =
    rtu_sensordata_datin_Inport_6_c;
  localB->TmpSignalConversionAtToWorkspace6Inport1[2] =
    rtu_sensordata_datin_Inport_6_cg;
  localB->TmpSignalConversionAtToWorkspace6Inport1[3] =
    rtu_sensordata_datin_Inport_6_i;
  localB->TmpSignalConversionAtToWorkspace6Inport1[4] =
    rtu_sensordata_datin_Inport_6_h;
  localB->TmpSignalConversionAtToWorkspace6Inport1[5] =
    rtu_sensordata_datin_Inport_6_b;
  localB->TmpSignalConversionAtToWorkspace6Inport1[6] =
    rtu_sensordata_datin_Inport_6_dz;
  localB->TmpSignalConversionAtToWorkspace6Inport1[7] =
    rtu_sensordata_datin_Inport_6_n;
  localB->TmpSignalConversionAtToWorkspace6Inport1[8] = rtb_DataTypeConversion11;
  localB->TmpSignalConversionAtToWorkspace6Inport1[9] = rtb_DataTypeConversion7;

  /* ToWorkspace: '<S3>/To Workspace6' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace6_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspace6Inport1[0]);
  }

  /* DataTypeConversion: '<S3>/Data Type Conversion3' */
  rtb_DataTypeConversion11 =
    rtu_ReferenceValueServerBus_Inport_4->controlModePosVSOrient;

  /* DataTypeConversion: '<S3>/Data Type Conversion7' */
  rtb_DataTypeConversion7 = rtu_ReferenceValueServerBus_Inport_4->takeoff_flag;

  /* SignalConversion: '<S3>/TmpSignal ConversionAtTo Workspace3Inport1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion9'
   *  SignalConversion: '<S3>/ReferenceValueServerBus_BusSelector'
   */
  localB->TmpSignalConversionAtToWorkspace3Inport1[0] = rtb_DataTypeConversion11;
  localB->TmpSignalConversionAtToWorkspace3Inport1[1] =
    rtu_ReferenceValueServerBus_Inport_4->pos_ref[0];
  localB->TmpSignalConversionAtToWorkspace3Inport1[2] =
    rtu_ReferenceValueServerBus_Inport_4->pos_ref[1];
  localB->TmpSignalConversionAtToWorkspace3Inport1[3] =
    rtu_ReferenceValueServerBus_Inport_4->pos_ref[2];
  localB->TmpSignalConversionAtToWorkspace3Inport1[4] = rtb_DataTypeConversion7;
  localB->TmpSignalConversionAtToWorkspace3Inport1[5] =
    rtu_ReferenceValueServerBus_Inport_4->orient_ref[0];
  localB->TmpSignalConversionAtToWorkspace3Inport1[6] =
    rtu_ReferenceValueServerBus_Inport_4->orient_ref[1];
  localB->TmpSignalConversionAtToWorkspace3Inport1[7] =
    rtu_ReferenceValueServerBus_Inport_4->orient_ref[2];
  localB->TmpSignalConversionAtToWorkspace3Inport1[8] = (real32_T)
    rtu_ReferenceValueServerBus_Inport_4->live_time_ticks;

  /* ToWorkspace: '<S3>/To Workspace3' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace3_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspace3Inport1[0]);
  }

  /* DataTypeConversion: '<S3>/Data Type Conversion11' */
  rtb_DataTypeConversion11 = rtu_Sensors_Inport_5->VisionSensors.usePosVIS_flag;

  /* SignalConversion: '<S3>/TmpSignal ConversionAtTo Workspace4Inport1' incorporates:
   *  SignalConversion: '<S3>/Sensors_BusSelector'
   */
  localB->TmpSignalConversionAtToWorkspace4Inport1[0] = rtb_DataTypeConversion11;
  localB->TmpSignalConversionAtToWorkspace4Inport1[1] =
    rtu_Sensors_Inport_5->VisionSensors.opticalFlow_data[0];
  localB->TmpSignalConversionAtToWorkspace4Inport1[2] =
    rtu_Sensors_Inport_5->VisionSensors.opticalFlow_data[1];
  localB->TmpSignalConversionAtToWorkspace4Inport1[3] =
    rtu_Sensors_Inport_5->VisionSensors.opticalFlow_data[2];
  localB->TmpSignalConversionAtToWorkspace4Inport1[4] =
    rtu_Sensors_Inport_5->VisionSensors.posVIS_data[0];
  localB->TmpSignalConversionAtToWorkspace4Inport1[5] =
    rtu_Sensors_Inport_5->VisionSensors.posVIS_data[1];
  localB->TmpSignalConversionAtToWorkspace4Inport1[6] =
    rtu_Sensors_Inport_5->VisionSensors.posVIS_data[2];
  localB->TmpSignalConversionAtToWorkspace4Inport1[7] =
    rtu_Sensors_Inport_5->VisionSensors.posVIS_data[3];

  /* ToWorkspace: '<S3>/To Workspace4' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace4_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspace4Inport1[0]);
  }

  /* SignalConversion: '<S3>/Sensors_BusSelector' */
  for (i = 0; i < 8; i++) {
    rtb_SigConversion_InsertedFor_Sensors_BusSelector_BusSelector_i[i] =
      rtu_Sensors_Inport_5->SensorCalibration[i];
  }

  /* ToWorkspace: '<S3>/To Workspace5' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace5_PWORK.LoggedData,
                          &locTime,
                          &rtb_SigConversion_InsertedFor_Sensors_BusSelector_BusSelector_i
                          [0]);
  }

  /* ToWorkspace: '<S3>/To Workspace' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace_PWORK.LoggedData,
                          &locTime, &rtu_motorCmds[0]);
  }

  /* ToWorkspace: '<S3>/To Workspace1' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace1_PWORK.LoggedData,
                          &locTime, &rtu_posRef[0]);
  }
}

/* System initialize for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem_Init(uint8_T *rty_Flag,
  P_FlightControlSystem_flightControlSystem_T *localP)
{
  /* SystemInitialize for ModelReference: '<S1>/estimator' */
  stateEstimator_Init();

  /* SystemInitialize for ModelReference: '<S1>/controller' */
  flightController_Init();

  /* SystemInitialize for Merge: '<S2>/Merge' */
  *rty_Flag = localP->Merge_InitialOutput;
}

/* Start for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem_Start
  (RT_MODEL_flightControlSystem_T * const flightControlSystem_M,
   DW_FlightControlSystem_flightControlSystem_T *localDW)
{
  /* Start for Atomic SubSystem: '<S1>/Logging' */
  flightControlSystem_Logging_Start(flightControlSystem_M, &localDW->Logging);

  /* End of Start for SubSystem: '<S1>/Logging' */
}

/* Output and update for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem(RT_MODEL_flightControlSystem_T *
  const flightControlSystem_M, const CommandBus *rtu_ReferenceValueServerCmds,
  const SensorsBus *rtu_Sensors, real32_T rty_motorCmds[4], uint8_T *rty_Flag,
  B_FlightControlSystem_flightControlSystem_T *localB,
  DW_FlightControlSystem_flightControlSystem_T *localDW,
  P_FlightControlSystem_flightControlSystem_T *localP)
{
  /* Step: '<S15>/Step' incorporates:
   *  Step: '<S15>/Step1'
   *  Step: '<S15>/Step2'
   */
  localB->currentTime_tmp = flightControlSystem_M->Timing.taskTime0;
  if (localB->currentTime_tmp < localP->Step_Time) {
    localB->Sum = localP->Step_Y0;
  } else {
    localB->Sum = localP->Step_YFinal;
  }

  /* End of Step: '<S15>/Step' */

  /* Step: '<S15>/Step1' */
  if (localB->currentTime_tmp < localP->Step1_Time) {
    localB->currentTime = localP->Step1_Y0;
  } else {
    localB->currentTime = localP->Step1_YFinal;
  }

  /* Step: '<S15>/Step2' */
  if (localB->currentTime_tmp < localP->Step2_Time) {
    localB->currentTime_tmp = localP->Step2_Y0;
  } else {
    localB->currentTime_tmp = localP->Step2_YFinal;
  }

  /* Sum: '<S15>/Sum' incorporates:
   *  Constant: '<S15>/Constant6'
   */
  localB->Sum = ((localP->Constant6_Value + localB->Sum) + localB->currentTime)
    + localB->currentTime_tmp;

  /* BusCreator: '<S4>/Bus Creator' incorporates:
   *  Constant: '<S15>/Constant2'
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S4>/Constant5'
   *  Constant: '<S4>/Constant6'
   *  Product: '<S15>/Product'
   */
  localB->BusCreator.controlModePosVSOrient = localP->Constant1_Value;
  localB->BusCreator.pos_ref[0] = (real32_T)(localP->Constant2_Value[0] *
    localB->Sum);
  localB->BusCreator.pos_ref[1] = (real32_T)(localP->Constant2_Value[1] *
    localB->Sum);
  localB->BusCreator.pos_ref[2] = (real32_T)(localP->Constant2_Value[2] *
    localB->Sum);
  localB->BusCreator.takeoff_flag = localP->Constant6_Value_m;
  localB->BusCreator.orient_ref[0] = localP->Constant3_Value[0];
  localB->BusCreator.orient_ref[1] = localP->Constant3_Value[1];
  localB->BusCreator.orient_ref[2] = localP->Constant3_Value[2];
  localB->BusCreator.live_time_ticks = localP->Constant5_Value;

  /* SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector3_at_outport_0' */
  localB->rtb_x_m = rtu_Sensors->HALSensors.HAL_acc_SI.x;

  /* SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector3_at_outport_1' */
  localB->rtb_y_c = rtu_Sensors->HALSensors.HAL_acc_SI.y;

  /* SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector3_at_outport_2' */
  localB->rtb_z_k = rtu_Sensors->HALSensors.HAL_acc_SI.z;

  /* SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector4_at_outport_0' */
  localB->rtb_x_c_c = rtu_Sensors->HALSensors.HAL_gyro_SI.x;

  /* SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector4_at_outport_1' */
  localB->rtb_y_n_b = rtu_Sensors->HALSensors.HAL_gyro_SI.y;

  /* SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector4_at_outport_2' */
  localB->rtb_z_p_p = rtu_Sensors->HALSensors.HAL_gyro_SI.z;

  /* SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector5_at_outport_0' */
  localB->rtb_altitude_c = rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude;

  /* SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector6_at_outport_0' */
  localB->rtb_pressure_f = rtu_Sensors->HALSensors.HAL_pressure_SI.pressure;

  /* SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector1_at_outport_0' */
  localB->rtb_vbat_V_g = rtu_Sensors->HALSensors.HAL_vbat_SI.vbat_V;

  /* SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector1_at_outport_1' */
  localB->rtb_vbat_percentage_g =
    rtu_Sensors->HALSensors.HAL_vbat_SI.vbat_percentage;

  /* BusCreator: '<S1>/BusConversion_InsertedFor_estimator_at_inport_1' */
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddx =
    localB->rtb_x_m;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddy =
    localB->rtb_y_c;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddz =
    localB->rtb_z_k;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.p =
    localB->rtb_x_c_c;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.q =
    localB->rtb_y_n_b;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.r =
    localB->rtb_z_p_p;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.altitude_sonar
    = localB->rtb_altitude_c;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.prs =
    localB->rtb_pressure_f;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_V =
    localB->rtb_vbat_V_g;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_percentage
    = localB->rtb_vbat_percentage_g;

  /* ModelReference: '<S1>/estimator' */
  stateEstimator_run(localB->BusCreator.controlModePosVSOrient,
                     &localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1,
                     rtu_Sensors->VisionSensors.usePosVIS_flag,
                     &rtu_Sensors->VisionSensors.opticalFlow_data[0],
                     &rtu_Sensors->VisionSensors.posVIS_data[0],
                     &localB->estimator, &rtu_Sensors->SensorCalibration[0]);

  /* ModelReference: '<S1>/controller' */
  flightController_run(&localB->BusCreator, &localB->estimator, &rty_motorCmds[0],
                       &localB->controller_o2[0]);

  /* Outputs for Atomic SubSystem: '<S1>/Logging' */
  flightControlSystem_Logging(flightControlSystem_M, rty_motorCmds,
    localB->controller_o2, &localB->estimator, rtu_ReferenceValueServerCmds,
    rtu_Sensors, localB->rtb_vbat_V_g, localB->rtb_vbat_percentage_g,
    localB->rtb_x_m, localB->rtb_y_c, localB->rtb_z_k, localB->rtb_x_c_c,
    localB->rtb_y_n_b, localB->rtb_z_p_p, localB->rtb_altitude_c,
    localB->rtb_pressure_f, &localB->Logging, &localDW->Logging);

  /* End of Outputs for SubSystem: '<S1>/Logging' */

  /* If: '<S2>/If' incorporates:
   *  Abs: '<S2>/Abs'
   *  Abs: '<S2>/Abs1'
   *  Abs: '<S2>/Abs2'
   *  Abs: '<S2>/Abs3'
   *  Abs: '<S2>/Abs4'
   *  Abs: '<S2>/Abs5'
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Logic: '<S2>/Logical Operator'
   *  Logic: '<S2>/Logical Operator1'
   *  Logic: '<S2>/Logical Operator2'
   *  Logic: '<S2>/Logical Operator3'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   *  Sum: '<S2>/Subtract'
   *  Sum: '<S2>/Subtract1'
   */
  if (((real32_T)fabs(localB->estimator.X) > localP->CompareToConstant_const) ||
      ((real32_T)fabs(localB->estimator.Y) > localP->CompareToConstant1_const))
  {
    /* Outputs for IfAction SubSystem: '<S2>/Geofencing error' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    flightControlSystem_Geofencingerror(rty_Flag, &localP->Geofencingerror);

    /* End of Outputs for SubSystem: '<S2>/Geofencing error' */
  } else if (((((real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[0]) >
                localP->CompareToConstant4_const) && ((real32_T)fabs
                (localP->Gain_Gain * rtu_Sensors->
                 VisionSensors.opticalFlow_data[0] - localB->estimator.dx) >
                localP->CompareToConstant2_const)) || (((real32_T)fabs
                (localP->Gain1_Gain *
                 rtu_Sensors->VisionSensors.opticalFlow_data[1] -
                 localB->estimator.dy) > localP->CompareToConstant3_const) &&
               ((real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[1]) >
                localP->CompareToConstant5_const))) > 0) {
    /* Outputs for IfAction SubSystem: '<S2>/estimator//Optical flow error' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    flightControlSystem_Geofencingerror(rty_Flag,
      &localP->estimatorOpticalflowerror);

    /* End of Outputs for SubSystem: '<S2>/estimator//Optical flow error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/Normal condition' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    flightControlSystem_Geofencingerror(rty_Flag, &localP->Normalcondition);

    /* End of Outputs for SubSystem: '<S2>/Normal condition' */
  }

  /* End of If: '<S2>/If' */
}

/* Model step function */
void flightControlSystem_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Flight Control System' */

  /* Inport: '<Root>/AC cmd' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  flightControlSystem_FlightControlSystem(flightControlSystem_M, &cmd_inport,
    &sensor_inport, motors_outport, &flag_outport,
    &flightControlSystem_B.FlightControlSystem,
    &flightControlSystem_DW.FlightControlSystem,
    &flightControlSystem_P.FlightControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Flight Control System' */

  /* Outport: '<Root>/Actuators' */
  flightControlSystem_Y.Actuators[0] = motors_outport[0];
  flightControlSystem_Y.Actuators[1] = motors_outport[1];
  flightControlSystem_Y.Actuators[2] = motors_outport[2];
  flightControlSystem_Y.Actuators[3] = motors_outport[3];

  /* Outport: '<Root>/Flag' */
  flightControlSystem_Y.Flag = flag_outport;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flightControlSystem_M->rtwLogInfo,
                      (&flightControlSystem_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightControlSystem_M)!=-1) &&
        !((rtmGetTFinal(flightControlSystem_M)-
           flightControlSystem_M->Timing.taskTime0) >
          flightControlSystem_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightControlSystem_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  flightControlSystem_M->Timing.taskTime0 =
    (++flightControlSystem_M->Timing.clockTick0) *
    flightControlSystem_M->Timing.stepSize0;
}

/* Model initialize function */
void flightControlSystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)flightControlSystem_M, 0,
                sizeof(RT_MODEL_flightControlSystem_T));
  rtmSetTFinal(flightControlSystem_M, 60.0);
  flightControlSystem_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    flightControlSystem_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogT(flightControlSystem_M->rtwLogInfo, "tout");
    rtliSetLogX(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogXFinal(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(flightControlSystem_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(flightControlSystem_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(flightControlSystem_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(flightControlSystem_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &flightControlSystem_Y.Actuators[0],
        &flightControlSystem_Y.Flag
      };

      rtliSetLogYSignalPtrs(flightControlSystem_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        4,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        4,
        1
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
        SS_UINT8
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
        "motors",
        "flag" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "flightControlSystem/Actuators",
        "flightControlSystem/Flag" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 0, 0, 0, 1.0, 0, 0.0 }
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

      rtliSetLogYSignalInfo(flightControlSystem_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(flightControlSystem_M->rtwLogInfo, "yout");
  }

  /* block I/O */

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (dwork) */
  (void) memset((void *)&flightControlSystem_DW, 0,
                sizeof(DW_flightControlSystem_T));

  /* external inputs */
  (void)memset(&flightControlSystem_U, 0, sizeof(ExtU_flightControlSystem_T));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));

  /* external outputs */
  (void) memset((void *)&flightControlSystem_Y, 0,
                sizeof(ExtY_flightControlSystem_T));

  /* Model Initialize function for ModelReference Block: '<S1>/controller' */
  flightController_g_initialize(rtmGetErrorStatusPointer(flightControlSystem_M));

  /* Model Initialize function for ModelReference Block: '<S1>/estimator' */
  stateEstimator_o_initialize(rtmGetErrorStatusPointer(flightControlSystem_M));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightControlSystem_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightControlSystem_M), flightControlSystem_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightControlSystem_M)));

  /* Start for Atomic SubSystem: '<Root>/Flight Control System' */
  flightControlSystem_FlightControlSystem_Start(flightControlSystem_M,
    &flightControlSystem_DW.FlightControlSystem);

  /* End of Start for SubSystem: '<Root>/Flight Control System' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Flight Control System' */

  /* SystemInitialize for Inport: '<Root>/Sensors' */
  flightControlSystem_FlightControlSystem_Init(&flag_outport,
    &flightControlSystem_P.FlightControlSystem);

  /* End of SystemInitialize for SubSystem: '<Root>/Flight Control System' */
}

/* Model terminate function */
void flightControlSystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

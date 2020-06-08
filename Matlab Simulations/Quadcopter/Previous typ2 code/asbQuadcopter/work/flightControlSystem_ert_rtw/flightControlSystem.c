/*
 * File: flightControlSystem.c
 *
 * Code generated for Simulink model 'flightControlSystem'.
 *
 * Model version                  : 1.157
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 19:07:35 2020
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

/* External inputs (root inport signals with default storage) */
ExtU_flightControlSystem_T flightControlSystem_U;

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

/* Output and update for atomic system: '<S1>/Logging' */
void flightControlSystem_Logging(const statesEstim_t *rtu_states_estim_Inport_3,
  const CommandBus *rtu_ReferenceValueServerBus_Inport_4, const SensorsBus
  *rtu_Sensors_Inport_5, real32_T rtu_sensordata_datin_Inport_6, uint32_T
  rtu_sensordata_datin_Inport_6_a, B_Logging_flightControlSystem_T *localB)
{
  real32_T rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSel_o;
  real32_T rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSel_j;
  real32_T rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSe_bz;
  real32_T rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSel_g;
  real32_T rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSe_hj;
  real32_T rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusS_bdq;
  real32_T rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSel_i;
  real32_T rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSe_p4;
  real32_T rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSe_oj;
  int32_T rtb_DataTypeConversion3;
  int32_T rtb_DataTypeConversion7;
  real32_T rtb_DataTypeConversion9;
  real32_T rtb_DataTypeConversion11;
  real32_T rtb_DataTypeConversion1_i;
  real32_T rtb_DataTypeConversion2;
  int32_T i;

  /* SignalConversion: '<S3>/Sensors_BusSelector' */
  for (i = 0; i < 8; i++) {
    localB->rtb_SigConversion_InsertedFor_Sensors_BusSelector_BusSelector_m[i] =
      rtu_Sensors_Inport_5->SensorCalibration[i];
  }

  localB->rtb_SigConversion_InsertedFor_Sensors_BusSelector_BusSelector_c[0] =
    rtu_Sensors_Inport_5->VisionSensors.posVIS_data[0];
  localB->rtb_SigConversion_InsertedFor_Sensors_BusSelector_BusSelector_c[1] =
    rtu_Sensors_Inport_5->VisionSensors.posVIS_data[1];
  localB->rtb_SigConversion_InsertedFor_Sensors_BusSelector_BusSelector_c[2] =
    rtu_Sensors_Inport_5->VisionSensors.posVIS_data[2];
  localB->rtb_SigConversion_InsertedFor_Sensors_BusSelector_BusSelector_c[3] =
    rtu_Sensors_Inport_5->VisionSensors.posVIS_data[3];

  /* SignalConversion: '<S3>/ReferenceValueServerBus_BusSelector' */
  localB->rtb_SigConversion_InsertedFor_ReferenceValueServerBus_BusSele_k[0] =
    rtu_ReferenceValueServerBus_Inport_4->pos_ref[0];
  localB->rtb_SigConversion_InsertedFor_ReferenceValueServerBus_BusSele_c[0] =
    rtu_ReferenceValueServerBus_Inport_4->orient_ref[0];

  /* SignalConversion: '<S3>/Sensors_BusSelector' */
  localB->rtb_SigConversion_InsertedFor_Sensors_BusSelector_BusSelector_b[0] =
    rtu_Sensors_Inport_5->VisionSensors.opticalFlow_data[0];

  /* SignalConversion: '<S3>/ReferenceValueServerBus_BusSelector' */
  localB->rtb_SigConversion_InsertedFor_ReferenceValueServerBus_BusSele_k[1] =
    rtu_ReferenceValueServerBus_Inport_4->pos_ref[1];
  localB->rtb_SigConversion_InsertedFor_ReferenceValueServerBus_BusSele_c[1] =
    rtu_ReferenceValueServerBus_Inport_4->orient_ref[1];

  /* SignalConversion: '<S3>/Sensors_BusSelector' */
  localB->rtb_SigConversion_InsertedFor_Sensors_BusSelector_BusSelector_b[1] =
    rtu_Sensors_Inport_5->VisionSensors.opticalFlow_data[1];

  /* SignalConversion: '<S3>/ReferenceValueServerBus_BusSelector' */
  localB->rtb_SigConversion_InsertedFor_ReferenceValueServerBus_BusSele_k[2] =
    rtu_ReferenceValueServerBus_Inport_4->pos_ref[2];
  localB->rtb_SigConversion_InsertedFor_ReferenceValueServerBus_BusSele_c[2] =
    rtu_ReferenceValueServerBus_Inport_4->orient_ref[2];

  /* SignalConversion: '<S3>/Sensors_BusSelector' */
  localB->rtb_SigConversion_InsertedFor_Sensors_BusSelector_BusSelector_b[2] =
    rtu_Sensors_Inport_5->VisionSensors.opticalFlow_data[2];

  /* SignalConversion: '<S3>/states_estim_BusSelector' */
  localB->rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSel_p =
    rtu_states_estim_Inport_3->X;
  localB->rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSel_c =
    rtu_states_estim_Inport_3->Y;
  localB->rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSel_f =
    rtu_states_estim_Inport_3->q;
  rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSel_o =
    rtu_states_estim_Inport_3->r;
  rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSel_j =
    rtu_states_estim_Inport_3->Z;
  rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSe_bz =
    rtu_states_estim_Inport_3->yaw;
  rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSel_g =
    rtu_states_estim_Inport_3->dx;
  rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSe_hj =
    rtu_states_estim_Inport_3->roll;
  rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusS_bdq =
    rtu_states_estim_Inport_3->pitch;
  rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSel_i =
    rtu_states_estim_Inport_3->dy;
  rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSe_p4 =
    rtu_states_estim_Inport_3->dz;
  rtb_SigConversion_InsertedFor_states_estim_BusSelector_BusSe_oj =
    rtu_states_estim_Inport_3->p;

  /* DataTypeConversion: '<S3>/Data Type Conversion3' */
  rtb_DataTypeConversion3 =
    rtu_ReferenceValueServerBus_Inport_4->controlModePosVSOrient;

  /* DataTypeConversion: '<S3>/Data Type Conversion7' */
  rtb_DataTypeConversion7 = rtu_ReferenceValueServerBus_Inport_4->takeoff_flag;

  /* DataTypeConversion: '<S3>/Data Type Conversion9' */
  rtb_DataTypeConversion9 = (real32_T)
    rtu_ReferenceValueServerBus_Inport_4->live_time_ticks;

  /* DataTypeConversion: '<S3>/Data Type Conversion11' */
  rtb_DataTypeConversion11 = rtu_Sensors_Inport_5->VisionSensors.usePosVIS_flag;

  /* DataTypeConversion: '<S3>/Data Type Conversion1' */
  rtb_DataTypeConversion1_i = rtu_sensordata_datin_Inport_6;

  /* DataTypeConversion: '<S3>/Data Type Conversion2' */
  rtb_DataTypeConversion2 = (real32_T)rtu_sensordata_datin_Inport_6_a;
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

/* Output and update for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem(RT_MODEL_flightControlSystem_T *
  const flightControlSystem_M, const CommandBus *rtu_ReferenceValueServerCmds,
  const SensorsBus *rtu_Sensors, real32_T rty_motorCmds[4], uint8_T *rty_Flag,
  B_FlightControlSystem_flightControlSystem_T *localB,
  P_FlightControlSystem_flightControlSystem_T *localP)
{
  /* Step: '<S15>/Step2' incorporates:
   *  Step: '<S15>/Step3'
   */
  localB->currentTime_tmp = ((flightControlSystem_M->Timing.clockTick0) * 0.005);
  if (localB->currentTime_tmp < localP->Step2_Time) {
    localB->Sum = localP->Step2_Y0;
  } else {
    localB->Sum = localP->Step2_YFinal;
  }

  /* End of Step: '<S15>/Step2' */

  /* Step: '<S15>/Step3' */
  if (localB->currentTime_tmp < localP->Step3_Time) {
    localB->currentTime_tmp = localP->Step3_Y0;
  } else {
    localB->currentTime_tmp = localP->Step3_YFinal;
  }

  /* Sum: '<S15>/Sum' incorporates:
   *  Constant: '<S15>/Constant6'
   */
  localB->Sum = (localP->Constant6_Value + localB->Sum) +
    localB->currentTime_tmp;

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

  /* SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector1_at_outport_0' */
  localB->rtb_vbat_V_m = rtu_Sensors->HALSensors.HAL_vbat_SI.vbat_V;

  /* SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector1_at_outport_1' */
  localB->rtb_vbat_percentage_c =
    rtu_Sensors->HALSensors.HAL_vbat_SI.vbat_percentage;

  /* BusCreator: '<S1>/BusConversion_InsertedFor_estimator_at_inport_1' incorporates:
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector3_at_outport_0'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector3_at_outport_1'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector3_at_outport_2'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector4_at_outport_0'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector4_at_outport_1'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector4_at_outport_2'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector5_at_outport_0'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector6_at_outport_0'
   */
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddx =
    rtu_Sensors->HALSensors.HAL_acc_SI.x;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddy =
    rtu_Sensors->HALSensors.HAL_acc_SI.y;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddz =
    rtu_Sensors->HALSensors.HAL_acc_SI.z;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.p =
    rtu_Sensors->HALSensors.HAL_gyro_SI.x;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.q =
    rtu_Sensors->HALSensors.HAL_gyro_SI.y;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.r =
    rtu_Sensors->HALSensors.HAL_gyro_SI.z;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.altitude_sonar
    = rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.prs =
    rtu_Sensors->HALSensors.HAL_pressure_SI.pressure;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_V =
    localB->rtb_vbat_V_m;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_percentage
    = localB->rtb_vbat_percentage_c;

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

  /* Outputs for Atomic SubSystem: '<S1>/Logging' */
  flightControlSystem_Logging(&localB->estimator, rtu_ReferenceValueServerCmds,
    rtu_Sensors, localB->rtb_vbat_V_m, localB->rtb_vbat_percentage_c,
    &localB->Logging);

  /* End of Outputs for SubSystem: '<S1>/Logging' */
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
    &flightControlSystem_P.FlightControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Flight Control System' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  flightControlSystem_M->Timing.clockTick0++;
}

/* Model initialize function */
void flightControlSystem_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)flightControlSystem_M, 0,
                sizeof(RT_MODEL_flightControlSystem_T));

  /* block I/O */

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* external inputs */
  (void)memset(&flightControlSystem_U, 0, sizeof(ExtU_flightControlSystem_T));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));

  /* Model Initialize function for ModelReference Block: '<S1>/controller' */
  flightController_g_initialize(rtmGetErrorStatusPointer(flightControlSystem_M));

  /* Model Initialize function for ModelReference Block: '<S1>/estimator' */
  stateEstimator_o_initialize(rtmGetErrorStatusPointer(flightControlSystem_M));

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

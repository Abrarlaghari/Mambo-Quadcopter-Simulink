/*
 * File: Flight.c
 *
 * Code generated for Simulink model 'Flight'.
 *
 * Model version                  : 1.143
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Nov 15 00:06:37 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Flight.h"
#include "Flight_private.h"

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/ReferenceValueServerCmds' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/controller' */
uint8_T flag_outport;                  /* '<S2>/Merge' */

/* Block signals (default storage) */
B_Flight_T Flight_B;

/* Block states (default storage) */
DW_Flight_T Flight_DW;

/* Real-time model */
RT_MODEL_Flight_T Flight_M_;
RT_MODEL_Flight_T *const Flight_M = &Flight_M_;

/* Forward declaration for local functions */
static real_T Flight_rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u,
  B_FlightControlSystem_Flight_T *localB);
static real_T Flight_rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u,
  B_FlightControlSystem_Flight_T *localB);

/*
 * Output and update for action system:
 *    '<S2>/Geofencing error'
 *    '<S2>/estimator//Optical flow error'
 *    '<S2>/Normal condition'
 */
void Flight_Geofencingerror(uint8_T *rty_Out1, P_Geofencingerror_Flight_T
  *localP)
{
  /* SignalConversion: '<S12>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
   *  Constant: '<S12>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/* Output and update for atomic system: '<S1>/Logging' */
void Flight_Logging(const statesEstim_t *rtu_states_estim_Inport_3, const
                    CommandBus *rtu_ReferenceValueServerBus_Inport_4, const
                    SensorsBus *rtu_Sensors_Inport_5, real32_T
                    rtu_sensordata_datin_Inport_6, uint32_T
                    rtu_sensordata_datin_Inport_6_a, B_Logging_Flight_T *localB)
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

static real_T Flight_rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u,
  B_FlightControlSystem_Flight_T *localB)
{
  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  localB->lo = *u % 127773U * 16807U;
  localB->hi = *u / 127773U * 2836U;
  if (localB->lo < localB->hi) {
    *u = 2147483647U - (localB->hi - localB->lo);
  } else {
    *u = localB->lo - localB->hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

static real_T Flight_rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u,
  B_FlightControlSystem_Flight_T *localB)
{
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    localB->sr = 2.0 * Flight_rt_urand_Upu32_Yd_f_pw_snf(u, localB) - 1.0;
    localB->si = 2.0 * Flight_rt_urand_Upu32_Yd_f_pw_snf(u, localB) - 1.0;
    localB->si = localB->sr * localB->sr + localB->si * localB->si;
  } while (localB->si > 1.0);

  y = sqrt(-2.0 * log(localB->si) / localB->si) * localB->sr;
  return y;
}

/* System initialize for atomic system: '<Root>/Flight Control System' */
void Flight_FlightControlSystem_Init(uint8_T *rty_Flag,
  B_FlightControlSystem_Flight_T *localB, DW_FlightControlSystem_Flight_T
  *localDW, P_FlightControlSystem_Flight_T *localP)
{
  uint32_T tseed;
  int32_T r;
  int32_T t;
  real_T tmp;

  /* InitializeConditions for RandomNumber: '<S16>/White Noise' */
  tmp = floor(localP->BandLimitedWhiteNoise1_seed);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
  r = (int32_T)(tseed >> 16U);
  t = (int32_T)(tseed & 32768U);
  localDW->RandSeed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
  if (localDW->RandSeed < 1U) {
    localDW->RandSeed = 1144108930U;
  } else {
    if (localDW->RandSeed > 2147483646U) {
      localDW->RandSeed = 2147483646U;
    }
  }

  localDW->NextOutput = Flight_rt_nrand_Upu32_Yd_f_pw_snf(&localDW->RandSeed,
    localB) * localP->WhiteNoise_StdDev + localP->WhiteNoise_Mean;

  /* End of InitializeConditions for RandomNumber: '<S16>/White Noise' */

  /* SystemInitialize for ModelReference: '<S1>/estimator' */
  stateEstimator_Init();

  /* SystemInitialize for ModelReference: '<S1>/controller' */
  flightController_Init();

  /* SystemInitialize for Merge: '<S2>/Merge' */
  *rty_Flag = localP->Merge_InitialOutput;
}

/* Output and update for atomic system: '<Root>/Flight Control System' */
void Flight_FlightControlSystem(RT_MODEL_Flight_T * const Flight_M, const
  CommandBus *rtu_ReferenceValueServerCmds, const SensorsBus *rtu_Sensors,
  real32_T rty_motorCmds[4], uint8_T *rty_Flag, B_FlightControlSystem_Flight_T
  *localB, DW_FlightControlSystem_Flight_T *localDW,
  P_FlightControlSystem_Flight_T *localP)
{
  /* Step: '<S15>/Step' incorporates:
   *  Step: '<S15>/Step1'
   *  Step: '<S15>/Step2'
   */
  localB->currentTime_tmp = ((Flight_M->Timing.clockTick0) * 0.005);
  if (localB->currentTime_tmp < localP->Step_Time) {
    localB->Output = localP->Step_Y0;
  } else {
    localB->Output = localP->Step_YFinal;
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
  localB->Output = ((localP->Constant6_Value + localB->Output) +
                    localB->currentTime) + localB->currentTime_tmp;

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
    localB->Output);
  localB->BusCreator.pos_ref[1] = (real32_T)(localP->Constant2_Value[1] *
    localB->Output);
  localB->BusCreator.pos_ref[2] = (real32_T)(localP->Constant2_Value[2] *
    localB->Output);
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
   *  Gain: '<S16>/Output'
   *  RandomNumber: '<S16>/White Noise'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector3_at_outport_0'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector3_at_outport_1'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector3_at_outport_2'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector4_at_outport_0'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector4_at_outport_1'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector4_at_outport_2'
   *  SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector6_at_outport_0'
   *  Sum: '<S5>/Sum'
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
    = (real32_T)(sqrt(localP->BandLimitedWhiteNoise1_Cov) / 0.070710678118654752
                 * localDW->NextOutput +
                 rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude);
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
    Flight_Geofencingerror(rty_Flag, &localP->Geofencingerror);

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
    Flight_Geofencingerror(rty_Flag, &localP->estimatorOpticalflowerror);

    /* End of Outputs for SubSystem: '<S2>/estimator//Optical flow error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/Normal condition' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    Flight_Geofencingerror(rty_Flag, &localP->Normalcondition);

    /* End of Outputs for SubSystem: '<S2>/Normal condition' */
  }

  /* End of If: '<S2>/If' */

  /* Outputs for Atomic SubSystem: '<S1>/Logging' */
  Flight_Logging(&localB->estimator, rtu_ReferenceValueServerCmds, rtu_Sensors,
                 localB->rtb_vbat_V_m, localB->rtb_vbat_percentage_c,
                 &localB->Logging);

  /* End of Outputs for SubSystem: '<S1>/Logging' */

  /* Update for RandomNumber: '<S16>/White Noise' */
  localDW->NextOutput = Flight_rt_nrand_Upu32_Yd_f_pw_snf(&localDW->RandSeed,
    localB) * localP->WhiteNoise_StdDev + localP->WhiteNoise_Mean;
}

/* Model step function */
void Flight_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Flight Control System' */

  /* Inport: '<Root>/ReferenceValueServerCmds' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  Flight_FlightControlSystem(Flight_M, &cmd_inport, &sensor_inport,
    motors_outport, &flag_outport, &Flight_B.FlightControlSystem,
    &Flight_DW.FlightControlSystem, &Flight_P.FlightControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Flight Control System' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Flight_M->Timing.clockTick0++;
}

/* Model initialize function */
void Flight_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Flight_M, 0,
                sizeof(RT_MODEL_Flight_T));

  /* block I/O */

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (dwork) */
  (void) memset((void *)&Flight_DW, 0,
                sizeof(DW_Flight_T));

  /* external inputs */
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));

  /* Model Initialize function for ModelReference Block: '<S1>/controller' */
  flightController_g_initialize(rtmGetErrorStatusPointer(Flight_M));

  /* Model Initialize function for ModelReference Block: '<S1>/estimator' */
  stateEstimator_o_initialize(rtmGetErrorStatusPointer(Flight_M));

  /* SystemInitialize for Atomic SubSystem: '<Root>/Flight Control System' */

  /* SystemInitialize for Inport: '<Root>/Sensors' */
  Flight_FlightControlSystem_Init(&flag_outport, &Flight_B.FlightControlSystem,
    &Flight_DW.FlightControlSystem, &Flight_P.FlightControlSystem);

  /* End of SystemInitialize for SubSystem: '<Root>/Flight Control System' */
}

/* Model terminate function */
void Flight_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

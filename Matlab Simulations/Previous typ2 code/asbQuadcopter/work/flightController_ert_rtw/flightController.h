/*
 * File: flightController.h
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

#ifndef RTW_HEADER_flightController_h_
#define RTW_HEADER_flightController_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef flightController_COMMON_INCLUDES_
# define flightController_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_logging.h"
#endif                                 /* flightController_COMMON_INCLUDES_ */

#include "flightController_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T EN;
  real32_T DEN;
  real32_T G11U;
  real32_T G11L;
  real32_T G21U;
  real32_T G21L;
} B_flightController_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE[2];/* '<S4>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE[2];            /* '<S4>/Delay' */
} DW_flightController_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T motors_refout[4];           /* '<Root>/motors_refout' */
  real32_T pose_refout[8];             /* '<Root>/pose_refout' */
} ExtY_flightController_T;

/* Parameters (default storage) */
struct P_flightController_T_ {
  real32_T TorqueTotalThrustToThrustPerMotor_Value[16];/* Expression: Controller.Q2Ts
                                                        * Referenced by: '<S3>/TorqueTotalThrustToThrustPerMotor'
                                                        */
  real32_T w0_Value;                   /* Computed Parameter: w0_Value
                                        * Referenced by: '<S2>/w0'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S2>/Gain'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real32_T SaturationThrust_UpperSat;  /* Computed Parameter: SaturationThrust_UpperSat
                                        * Referenced by: '<S2>/SaturationThrust'
                                        */
  real32_T SaturationThrust_LowerSat;  /* Computed Parameter: SaturationThrust_LowerSat
                                        * Referenced by: '<S2>/SaturationThrust'
                                        */
  real32_T P_yaw_Gain;                 /* Computed Parameter: P_yaw_Gain
                                        * Referenced by: '<S10>/P_yaw'
                                        */
  real32_T D_yaw_Gain;                 /* Computed Parameter: D_yaw_Gain
                                        * Referenced by: '<S10>/D_yaw'
                                        */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S9>/Gain'
                                        */
  real32_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real32_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real32_T P_xy_Gain[2];               /* Computed Parameter: P_xy_Gain
                                        * Referenced by: '<S9>/P_xy'
                                        */
  real32_T D_xy_Gain[2];               /* Computed Parameter: D_xy_Gain
                                        * Referenced by: '<S9>/D_xy'
                                        */
  real32_T P_pr_Gain[2];               /* Computed Parameter: P_pr_Gain
                                        * Referenced by: '<S4>/P_pr'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<S4>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S4>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperSat;/* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                                            * Referenced by: '<S4>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerSat;/* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                                            * Referenced by: '<S4>/Discrete-Time Integrator'
                                            */
  real32_T I_pr_Gain;                  /* Computed Parameter: I_pr_Gain
                                        * Referenced by: '<S4>/I_pr'
                                        */
  real32_T D_pr_Gain[2];               /* Computed Parameter: D_pr_Gain
                                        * Referenced by: '<S4>/D_pr'
                                        */
  real32_T ThrustToMotorCommand_Gain;  /* Computed Parameter: ThrustToMotorCommand_Gain
                                        * Referenced by: '<S7>/ThrustToMotorCommand'
                                        */
  real32_T Saturation5_UpperSat;       /* Expression: Vehicle.Motor.maxLimit
                                        * Referenced by: '<S7>/Saturation5'
                                        */
  real32_T Saturation5_LowerSat;       /* Expression: Vehicle.Motor.minLimit
                                        * Referenced by: '<S7>/Saturation5'
                                        */
  real32_T MotorDirections_Gain[4];    /* Computed Parameter: MotorDirections_Gain
                                        * Referenced by: '<S7>/MotorDirections'
                                        */
  real32_T Delay_InitialCondition;     /* Computed Parameter: Delay_InitialCondition
                                        * Referenced by: '<S4>/Delay'
                                        */
  real32_T antiWU_Gain_Gain;           /* Computed Parameter: antiWU_Gain_Gain
                                        * Referenced by: '<S4>/antiWU_Gain'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S4>/Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_flightController_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_flightController_T flightController_P;

/* Block signals (default storage) */
extern B_flightController_T flightController_B;

/* Block states (default storage) */
extern DW_flightController_T flightController_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_flightController_T flightController_Y;

/* Model entry point functions */
extern void flightController_initialize(void);
extern void flightController_terminate(void);

/* Customized model step function */
extern void flightController_run(const CommandBus *arg_ReferenceValueServerBus,
  const statesEstim_t *arg_states_estim, real32_T arg_motors_refout[4], real32_T
  arg_pose_refout[8]);

/* Real-time Model object */
extern RT_MODEL_flightController_T *const flightController_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'flightController'
 * '<S1>'   : 'flightController/Flight Controller'
 * '<S2>'   : 'flightController/Flight Controller/Altitude Controller'
 * '<S3>'   : 'flightController/Flight Controller/ControlMixer'
 * '<S4>'   : 'flightController/Flight Controller/Inner loop  pitch//roll Controller'
 * '<S5>'   : 'flightController/Flight Controller/XY Outer Loop Controller '
 * '<S6>'   : 'flightController/Flight Controller/Yaw'
 * '<S7>'   : 'flightController/Flight Controller/thrustsToMotorCommands'
 * '<S8>'   : 'flightController/Flight Controller/Altitude Controller/MATLAB Function'
 * '<S9>'   : 'flightController/Flight Controller/XY Outer Loop Controller /XY-to-reference-orientation'
 * '<S10>'  : 'flightController/Flight Controller/Yaw/Yaw'
 */
#endif                                 /* RTW_HEADER_flightController_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: flightControlSystem.h
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

#ifndef RTW_HEADER_flightControlSystem_h_
#define RTW_HEADER_flightControlSystem_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <float.h>
#ifndef flightControlSystem_COMMON_INCLUDES_
# define flightControlSystem_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rt_logging.h"
#endif                                 /* flightControlSystem_COMMON_INCLUDES_ */

#include "flightControlSystem_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#define stateEstimator_MDLREF_HIDE_CHILD_
#include "stateEstimator.h"
#define flightController_MDLREF_HIDE_CHILD_
#include "flightController.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"

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

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
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

/* Block signals for system '<S1>/Logging' */
typedef struct {
  real32_T TmpSignalConversionAtToWorkspace2Inport1[12];
  real32_T TmpSignalConversionAtToWorkspace6Inport1[10];
  real32_T TmpSignalConversionAtToWorkspace3Inport1[9];
  real32_T TmpSignalConversionAtToWorkspace4Inport1[8];
} B_Logging_flightControlSystem_T;

/* Block states (default storage) for system '<S1>/Logging' */
typedef struct {
  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S3>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace6_PWORK;                /* '<S3>/To Workspace6' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<S3>/To Workspace3' */

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                /* '<S3>/To Workspace4' */

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK;                /* '<S3>/To Workspace5' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S3>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S3>/To Workspace1' */
} DW_Logging_flightControlSystem_T;

/* Block signals for system '<Root>/Flight Control System' */
typedef struct {
  statesEstim_t estimator;             /* '<S1>/estimator' */
  sensordata_t BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1;
  real32_T controller_o2[8];           /* '<S1>/controller' */
  CommandBus BusCreator;               /* '<S4>/Bus Creator' */
  real_T Sum;                          /* '<S15>/Sum' */
  real_T currentTime;
  real_T currentTime_tmp;
  real32_T rtb_x_m;
  real32_T rtb_y_c;
  real32_T rtb_z_k;
  real32_T rtb_x_c_c;
  real32_T rtb_y_n_b;
  real32_T rtb_z_p_p;
  real32_T rtb_altitude_c;
  real32_T rtb_pressure_f;
  real32_T rtb_vbat_V_g;
  uint32_T rtb_vbat_percentage_g;
  B_Logging_flightControlSystem_T Logging;/* '<S1>/Logging' */
} B_FlightControlSystem_flightControlSystem_T;

/* Block states (default storage) for system '<Root>/Flight Control System' */
typedef struct {
  DW_Logging_flightControlSystem_T Logging;/* '<S1>/Logging' */
} DW_FlightControlSystem_flightControlSystem_T;

/* Block signals (default storage) */
typedef struct {
  B_FlightControlSystem_flightControlSystem_T FlightControlSystem;/* '<Root>/Flight Control System' */
} B_flightControlSystem_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_FlightControlSystem_flightControlSystem_T FlightControlSystem;/* '<Root>/Flight Control System' */
} DW_flightControlSystem_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T Y1UY2V[38400];               /* '<Root>/Image Data' */
} ExtU_flightControlSystem_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Actuators[4];               /* '<Root>/Actuators' */
  uint8_T Flag;                        /* '<Root>/Flag' */
} ExtY_flightControlSystem_T;

/* Parameters for system: '<S2>/Geofencing error' */
struct P_Geofencingerror_flightControlSystem_T_ {
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S12>/Constant'
                                        */
};

/* Parameters for system: '<Root>/Flight Control System' */
struct P_FlightControlSystem_flightControlSystem_T_ {
  real32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S6>/Constant'
                                        */
  real32_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S7>/Constant'
                                        */
  real32_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S8>/Constant'
                                        */
  real32_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S10>/Constant'
                                        */
  real32_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S9>/Constant'
                                        */
  real32_T CompareToConstant5_const;   /* Mask Parameter: CompareToConstant5_const
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Step_Time;                    /* Expression: 0
                                        * Referenced by: '<S15>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S15>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<S15>/Step'
                                        */
  real_T Step1_Time;                   /* Expression: 40
                                        * Referenced by: '<S15>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S15>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 0
                                        * Referenced by: '<S15>/Step1'
                                        */
  real_T Step2_Time;                   /* Expression: 60
                                        * Referenced by: '<S15>/Step2'
                                        */
  real_T Step2_Y0;                     /* Expression: 0
                                        * Referenced by: '<S15>/Step2'
                                        */
  real_T Step2_YFinal;                 /* Expression: -1
                                        * Referenced by: '<S15>/Step2'
                                        */
  real32_T Constant6_Value;            /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<S15>/Constant6'
                                        */
  real32_T Constant2_Value[3];         /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S15>/Constant2'
                                        */
  real32_T Constant3_Value[3];         /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S2>/Gain'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S2>/Gain1'
                                        */
  uint32_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S4>/Constant5'
                                        */
  boolean_T Constant1_Value;           /* Expression: true
                                        * Referenced by: '<S4>/Constant1'
                                        */
  boolean_T Constant6_Value_m;         /* Computed Parameter: Constant6_Value_m
                                        * Referenced by: '<S4>/Constant6'
                                        */
  uint8_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S2>/Merge'
                                        */
  P_Geofencingerror_flightControlSystem_T Normalcondition;/* '<S2>/Normal condition' */
  P_Geofencingerror_flightControlSystem_T estimatorOpticalflowerror;/* '<S2>/estimator//Optical flow error' */
  P_Geofencingerror_flightControlSystem_T Geofencingerror;/* '<S2>/Geofencing error' */
};

/* Parameters (default storage) */
struct P_flightControlSystem_T_ {
  P_FlightControlSystem_flightControlSystem_T FlightControlSystem;/* '<Root>/Flight Control System' */
};

/* Real-time Model Data Structure */
struct tag_RTM_flightControlSystem_T {
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
extern P_flightControlSystem_T flightControlSystem_P;

/* Block signals (default storage) */
extern B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
extern DW_flightControlSystem_T flightControlSystem_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_flightControlSystem_T flightControlSystem_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_flightControlSystem_T flightControlSystem_Y;

/* Model block global parameters (default storage) */
extern struct_pAcs5k38eV6MpgiqrKAV4 rtP_Sensors;/* Variable: Sensors
                                                 * Referenced by: '<S1>/estimator'
                                                 */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern CommandBus cmd_inport;          /* '<Root>/AC cmd' */
extern SensorsBus sensor_inport;       /* '<Root>/Sensors' */
extern real32_T motors_outport[4];     /* '<S1>/controller' */
extern uint8_T flag_outport;           /* '<S2>/Merge' */

/* Model entry point functions */
extern void flightControlSystem_initialize(void);
extern void flightControlSystem_step(void);
extern void flightControlSystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_flightControlSystem_T *const flightControlSystem_M;

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
 * '<Root>' : 'flightControlSystem'
 * '<S1>'   : 'flightControlSystem/Flight Control System'
 * '<S2>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags'
 * '<S3>'   : 'flightControlSystem/Flight Control System/Logging'
 * '<S4>'   : 'flightControlSystem/Flight Control System/landing logic'
 * '<S5>'   : 'flightControlSystem/Flight Control System/sensordata_group'
 * '<S6>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant'
 * '<S7>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant1'
 * '<S8>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant2'
 * '<S9>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant3'
 * '<S10>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant4'
 * '<S11>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant5'
 * '<S12>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Geofencing error'
 * '<S13>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Normal condition'
 * '<S14>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/estimator//Optical flow error'
 * '<S15>'  : 'flightControlSystem/Flight Control System/landing logic/Subsystem'
 */
#endif                                 /* RTW_HEADER_flightControlSystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

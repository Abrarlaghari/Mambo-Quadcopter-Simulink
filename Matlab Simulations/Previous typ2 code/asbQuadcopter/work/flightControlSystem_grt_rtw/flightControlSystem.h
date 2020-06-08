/*
 * flightControlSystem.h
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 1.174
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Mon Nov  4 15:18:47 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
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
#include "rtw_continuous.h"
#include "rtw_solver.h"
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

/* Block states (default storage) for system '<S1>/Logging' */
typedef struct {
  struct {
    void *LoggedData;
  } ToWorkspace6_PWORK;                /* '<S3>/To Workspace6' */

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                /* '<S3>/To Workspace4' */

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK;                /* '<S3>/To Workspace5' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<S3>/To Workspace3' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S3>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S3>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S3>/To Workspace1' */
} DW_Logging_flightControlSystem_T;

/* Block signals for system '<Root>/Flight Control System' */
typedef struct {
  real32_T pos_ref[3];
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
  real32_T Reference[3];               /* '<Root>/Reference' */
} ExtY_flightControlSystem_T;

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
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
extern DW_flightControlSystem_T flightControlSystem_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_flightControlSystem_T flightControlSystem_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_flightControlSystem_T flightControlSystem_Y;

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
 */
#endif                                 /* RTW_HEADER_flightControlSystem_h_ */

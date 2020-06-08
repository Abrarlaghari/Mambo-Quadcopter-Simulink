/*
 * Code generation for system model 'stateEstimator'
 * For more details, see corresponding source file stateEstimator.c
 *
 */

#ifndef RTW_HEADER_stateEstimator_h_
#define RTW_HEADER_stateEstimator_h_
#include <math.h>
#include <string.h>
#ifndef stateEstimator_COMMON_INCLUDES_
# define stateEstimator_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* stateEstimator_COMMON_INCLUDES_ */

#include "stateEstimator_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Block signals for system '<S106>/MeasurementUpdate' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T Product3[2];                /* '<S131>/Product3' */
} B_MeasurementUpdate_stateEstimator_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S106>/MeasurementUpdate' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  boolean_T MeasurementUpdate_MODE;    /* '<S106>/MeasurementUpdate' */
} DW_MeasurementUpdate_stateEstimator_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

/* Block signals for system '<S111>/Enabled Subsystem' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T Product2[2];                /* '<S132>/Product2' */
} B_EnabledSubsystem_stateEstimator_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S111>/Enabled Subsystem' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S111>/Enabled Subsystem' */
} DW_EnabledSubsystem_stateEstimator_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

/* Block signals for model 'stateEstimator' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  real_T invertzaxisGain;              /* '<S3>/invertzaxisGain' */
  real_T Sum[3];                       /* '<S3>/Sum' */
  real_T Product2[2];                  /* '<S61>/Product2' */
  real_T Product3[2];                  /* '<S60>/Product3' */
  real32_T inverseIMU_gain[6];         /* '<S5>/inverseIMU_gain' */
  real32_T Merge[2];                   /* '<S2>/Merge' */
  real32_T opticalFlowToVelocity_gain[3];/* '<S67>/opticalFlowToVelocity_gain' */
  real32_T Product[2];                 /* '<S69>/Product' */
  real32_T Product_l[3];               /* '<S68>/Product' */
  boolean_T LogicalOperator3;          /* '<S134>/Logical Operator3' */
  boolean_T Compare;                   /* '<S17>/Compare' */
  boolean_T nicemeasurementornewupdateneeded;/* '<S15>/nicemeasurementor newupdateneeded' */
  boolean_T LogicalOperator3_a;        /* '<S70>/Logical Operator3' */
  B_EnabledSubsystem_stateEstimator_T EnabledSubsystem_m;/* '<S158>/Enabled Subsystem' */
  B_MeasurementUpdate_stateEstimator_T MeasurementUpdate_b;/* '<S153>/MeasurementUpdate' */
  B_EnabledSubsystem_stateEstimator_T EnabledSubsystem_f;/* '<S111>/Enabled Subsystem' */
  B_MeasurementUpdate_stateEstimator_T MeasurementUpdate_e;/* '<S106>/MeasurementUpdate' */
} B_stateEstimator_c_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'stateEstimator' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  real_T Delay2_DSTATE;                /* '<S3>/Delay2' */
  real_T MemoryX_DSTATE[2];            /* '<S14>/MemoryX' */
  real_T soonarFilter_IIR_states[3];   /* '<S15>/soonarFilter_IIR' */
  real_T soonarFilter_IIR_tmp;         /* '<S15>/soonarFilter_IIR' */
  real32_T MemoryX_DSTATE_d[2];        /* '<S133>/MemoryX' */
  real32_T IIR_IMUgyro_r_states[5];    /* '<S5>/IIR_IMUgyro_r' */
  real32_T FIR_IMUaccel_states[15];    /* '<S5>/FIR_IMUaccel' */
  real32_T Delay_DSTATE[2];            /* '<S68>/Delay' */
  real32_T SimplyIntegrateVelocity_DSTATE[2];/* '<S68>/SimplyIntegrateVelocity' */
  real32_T pressureFilter_IIR_states[3];/* '<S15>/pressureFilter_IIR' */
  real32_T MemoryX_DSTATE_d5[2];       /* '<S71>/MemoryX' */
  real32_T IIRgyroz_states[10];        /* '<S70>/IIRgyroz' */
  real32_T UD_DSTATE[2];               /* '<S77>/UD' */
  real32_T Delay_DSTATE_g[2];          /* '<S67>/Delay' */
  real32_T Delay1_DSTATE[2];           /* '<S1>/Delay1' */
  int32_T FIR_IMUaccel_circBuf;        /* '<S5>/FIR_IMUaccel' */
  real32_T Memory_PreviousInput[3];    /* '<S2>/Memory' */
  real32_T IIR_IMUgyro_r_tmp;          /* '<S5>/IIR_IMUgyro_r' */
  real32_T pressureFilter_IIR_tmp;     /* '<S15>/pressureFilter_IIR' */
  real32_T IIRgyroz_tmp[2];            /* '<S70>/IIRgyroz' */
  int8_T SimplyIntegrateVelocity_PrevResetState;/* '<S68>/SimplyIntegrateVelocity' */
  uint8_T icLoad;                      /* '<S133>/MemoryX' */
  uint8_T icLoad_p;                    /* '<S14>/MemoryX' */
  uint8_T icLoad_i;                    /* '<S71>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S40>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S35>/MeasurementUpdate' */
  DW_EnabledSubsystem_stateEstimator_T EnabledSubsystem_m;/* '<S158>/Enabled Subsystem' */
  DW_MeasurementUpdate_stateEstimator_T MeasurementUpdate_b;/* '<S153>/MeasurementUpdate' */
  DW_EnabledSubsystem_stateEstimator_T EnabledSubsystem_f;/* '<S111>/Enabled Subsystem' */
  DW_MeasurementUpdate_stateEstimator_T MeasurementUpdate_e;/* '<S106>/MeasurementUpdate' */
} DW_stateEstimator_f_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for model 'stateEstimator' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  const real_T Conversion[2];          /* '<S57>/Conversion' */
  const real_T ReshapeX0[2];           /* '<S14>/ReshapeX0' */
  const real_T Conversion_n[2];        /* '<S56>/Conversion' */
  const real_T Conversion_k;           /* '<S58>/Conversion' */
  const real_T Conversion_c[4];        /* '<S59>/Conversion' */
  const real32_T Conversion_g[4];      /* '<S175>/Conversion' */
  const real32_T ReshapeX0_b[2];       /* '<S133>/ReshapeX0' */
  const real32_T Conversion_p[4];      /* '<S128>/Conversion' */
  const real32_T ReshapeX0_k[2];       /* '<S71>/ReshapeX0' */
  const real32_T Conversion_b[4];      /* '<S27>/Conversion' */
  const real32_T Conversion_n4[4];     /* '<S127>/Conversion' */
  const real32_T Conversion_d;         /* '<S129>/Conversion' */
  const real32_T Conversion_i[4];      /* '<S130>/Conversion' */
  const real32_T Conversion_m[4];      /* '<S98>/Conversion' */
  const real32_T Conversion_a[4];      /* '<S174>/Conversion' */
  const real32_T Conversion_l;         /* '<S176>/Conversion' */
  const real32_T Conversion_ao[4];     /* '<S177>/Conversion' */
  const real32_T Conversion_lk[4];     /* '<S145>/Conversion' */
  const boolean_T Reshapeyhat;         /* '<S14>/Reshapeyhat' */
  const boolean_T DataTypeConversionReset;/* '<S71>/DataTypeConversionReset' */
  const boolean_T Reshapeyhat_a;       /* '<S71>/Reshapeyhat' */
  const boolean_T DataTypeConversionReset_i;/* '<S133>/DataTypeConversionReset' */
  const boolean_T Reshapeyhat_l;       /* '<S133>/Reshapeyhat' */
} ConstB_stateEstimator_h_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_stateEstimator_T {
  const char_T **errorStatus;
};

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_stateEstimator_T rtm;
} MdlrefDW_stateEstimator_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

extern void stateEstimator_Init(void);
extern void stateEstimator_Reset(void);
extern void stateEstimator_Disable(void);
extern void stateEstimator(const boolean_T *rtu_controlModePosVSOrient_flagin,
  const sensordata_t *rtu_sensordata_datin, const real32_T *rtu_usePosVIS_flagin,
  const real32_T rtu_opticalFlow_datin[3], const real32_T rtu_posVIS_datin[4],
  const real32_T rtu_sensorCalibration_datin[8], statesEstim_t
  *rty_states_estimout);

/* Model reference registration function */
extern void stateEstimator_initialize(const char_T **rt_errorStatus);

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

extern void stateEstimator_MeasurementUpdate_Init
  (B_MeasurementUpdate_stateEstimator_T *localB);
extern void stateEstimator_MeasurementUpdate_Disable
  (B_MeasurementUpdate_stateEstimator_T *localB,
   DW_MeasurementUpdate_stateEstimator_T *localDW);
extern void stateEstimator_MeasurementUpdate(boolean_T rtu_Enable, const
  real32_T rtu_Lk[4], const real32_T rtu_yk[2], const real32_T rtu_Ck[4], const
  real32_T rtu_xhatkk1[2], const real32_T rtu_Dk[4], const real32_T rtu_uk[2],
  B_MeasurementUpdate_stateEstimator_T *localB,
  DW_MeasurementUpdate_stateEstimator_T *localDW);
extern void stateEstimator_EnabledSubsystem_Init
  (B_EnabledSubsystem_stateEstimator_T *localB);
extern void stateEstimator_EnabledSubsystem_Disable
  (B_EnabledSubsystem_stateEstimator_T *localB,
   DW_EnabledSubsystem_stateEstimator_T *localDW);
extern void stateEstimator_EnabledSubsystem(boolean_T rtu_Enable, const real32_T
  rtu_Mk[4], const real32_T rtu_Ck[4], const real32_T rtu_yk[2], const real32_T
  rtu_xhatkk1[2], B_EnabledSubsystem_stateEstimator_T *localB,
  DW_EnabledSubsystem_stateEstimator_T *localDW);

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

extern MdlrefDW_stateEstimator_T stateEstimator_MdlrefDW;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_stateEstimator_c_T stateEstimator_B;

/* Block states (default storage) */
extern DW_stateEstimator_f_T stateEstimator_DW;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'stateEstimator'
 * '<S1>'   : 'stateEstimator/State Estimator'
 * '<S2>'   : 'stateEstimator/State Estimator/Complementary Filter'
 * '<S3>'   : 'stateEstimator/State Estimator/EstimatorAltitude'
 * '<S4>'   : 'stateEstimator/State Estimator/EstimatorXYPosition'
 * '<S5>'   : 'stateEstimator/State Estimator/SensorPreprocessing'
 * '<S6>'   : 'stateEstimator/State Estimator/Complementary Filter/Compare To Constant'
 * '<S7>'   : 'stateEstimator/State Estimator/Complementary Filter/Compare To Constant1'
 * '<S8>'   : 'stateEstimator/State Estimator/Complementary Filter/If Action Subsystem'
 * '<S9>'   : 'stateEstimator/State Estimator/Complementary Filter/If Action Subsystem1'
 * '<S10>'  : 'stateEstimator/State Estimator/Complementary Filter/If Action Subsystem2'
 * '<S11>'  : 'stateEstimator/State Estimator/Complementary Filter/If Action Subsystem3'
 * '<S12>'  : 'stateEstimator/State Estimator/Complementary Filter/Wbe'
 * '<S13>'  : 'stateEstimator/State Estimator/Complementary Filter/Wbe/Create 3x3 Matrix'
 * '<S14>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude'
 * '<S15>'  : 'stateEstimator/State Estimator/EstimatorAltitude/OutlierHandling'
 * '<S16>'  : 'stateEstimator/State Estimator/EstimatorAltitude/Rotation Angles to Direction Cosine Matrix'
 * '<S17>'  : 'stateEstimator/State Estimator/EstimatorAltitude/outlierBelowFloor'
 * '<S18>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL'
 * '<S19>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculateYhat'
 * '<S20>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionA'
 * '<S21>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionB'
 * '<S22>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionC'
 * '<S23>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionD'
 * '<S24>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionG'
 * '<S25>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionH'
 * '<S26>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionN'
 * '<S27>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionP'
 * '<S28>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionP0'
 * '<S29>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionQ'
 * '<S30>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionR'
 * '<S31>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionX'
 * '<S32>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionX0'
 * '<S33>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionu'
 * '<S34>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/MemoryP'
 * '<S35>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/Observer'
 * '<S36>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ReducedQRN'
 * '<S37>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ScalarExpansionP0'
 * '<S38>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ScalarExpansionQ'
 * '<S39>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ScalarExpansionR'
 * '<S40>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/UseCurrentEstimator'
 * '<S41>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkA'
 * '<S42>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkB'
 * '<S43>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkC'
 * '<S44>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkD'
 * '<S45>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkEnable'
 * '<S46>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkG'
 * '<S47>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkH'
 * '<S48>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkN'
 * '<S49>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkP0'
 * '<S50>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkQ'
 * '<S51>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkR'
 * '<S52>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkReset'
 * '<S53>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkX0'
 * '<S54>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checku'
 * '<S55>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checky'
 * '<S56>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionL'
 * '<S57>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionM'
 * '<S58>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionP'
 * '<S59>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionZ'
 * '<S60>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/Observer/MeasurementUpdate'
 * '<S61>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/UseCurrentEstimator/Enabled Subsystem'
 * '<S62>'  : 'stateEstimator/State Estimator/EstimatorAltitude/OutlierHandling/check for min altitude'
 * '<S63>'  : 'stateEstimator/State Estimator/EstimatorAltitude/OutlierHandling/currentEstimateVeryOffFromPressure'
 * '<S64>'  : 'stateEstimator/State Estimator/EstimatorAltitude/OutlierHandling/currentStateVeryOffsonarflt'
 * '<S65>'  : 'stateEstimator/State Estimator/EstimatorAltitude/OutlierHandling/outlierJump'
 * '<S66>'  : 'stateEstimator/State Estimator/EstimatorAltitude/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S67>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity'
 * '<S68>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition'
 * '<S69>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling'
 * '<S70>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling'
 * '<S71>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy'
 * '<S72>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/Deactivate Acceleration If OF is not used due to low altitude'
 * '<S73>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix'
 * '<S74>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)'
 * '<S75>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)1'
 * '<S76>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S77>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/DiscreteDerivative'
 * '<S78>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxdw1'
 * '<S79>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxdw2'
 * '<S80>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxp'
 * '<S81>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxp2'
 * '<S82>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxq'
 * '<S83>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxq2'
 * '<S84>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxw1'
 * '<S85>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxw2'
 * '<S86>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxw3'
 * '<S87>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxw4'
 * '<S88>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/minHeightforOF'
 * '<S89>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL'
 * '<S90>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculateYhat'
 * '<S91>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionA'
 * '<S92>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionB'
 * '<S93>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionC'
 * '<S94>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionD'
 * '<S95>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionG'
 * '<S96>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionH'
 * '<S97>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionN'
 * '<S98>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionP'
 * '<S99>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionP0'
 * '<S100>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionQ'
 * '<S101>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionR'
 * '<S102>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionX'
 * '<S103>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionX0'
 * '<S104>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionu'
 * '<S105>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/MemoryP'
 * '<S106>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/Observer'
 * '<S107>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ReducedQRN'
 * '<S108>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionP0'
 * '<S109>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionQ'
 * '<S110>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionR'
 * '<S111>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/UseCurrentEstimator'
 * '<S112>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkA'
 * '<S113>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkB'
 * '<S114>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkC'
 * '<S115>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkD'
 * '<S116>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkEnable'
 * '<S117>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkG'
 * '<S118>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkH'
 * '<S119>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkN'
 * '<S120>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkP0'
 * '<S121>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkQ'
 * '<S122>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkR'
 * '<S123>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkReset'
 * '<S124>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkX0'
 * '<S125>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checku'
 * '<S126>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checky'
 * '<S127>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionL'
 * '<S128>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionM'
 * '<S129>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionP'
 * '<S130>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionZ'
 * '<S131>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/Observer/MeasurementUpdate'
 * '<S132>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/UseCurrentEstimator/Enabled Subsystem'
 * '<S133>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy'
 * '<S134>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/OutlierHandling'
 * '<S135>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix'
 * '<S136>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculatePL'
 * '<S137>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculateYhat'
 * '<S138>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionA'
 * '<S139>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionB'
 * '<S140>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionC'
 * '<S141>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionD'
 * '<S142>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionG'
 * '<S143>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionH'
 * '<S144>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionN'
 * '<S145>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionP'
 * '<S146>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionP0'
 * '<S147>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionQ'
 * '<S148>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionR'
 * '<S149>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionX'
 * '<S150>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionX0'
 * '<S151>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionu'
 * '<S152>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/MemoryP'
 * '<S153>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/Observer'
 * '<S154>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/ReducedQRN'
 * '<S155>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/ScalarExpansionP0'
 * '<S156>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/ScalarExpansionQ'
 * '<S157>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/ScalarExpansionR'
 * '<S158>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/UseCurrentEstimator'
 * '<S159>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkA'
 * '<S160>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkB'
 * '<S161>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkC'
 * '<S162>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkD'
 * '<S163>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkEnable'
 * '<S164>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkG'
 * '<S165>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkH'
 * '<S166>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkN'
 * '<S167>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkP0'
 * '<S168>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkQ'
 * '<S169>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkR'
 * '<S170>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkReset'
 * '<S171>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkX0'
 * '<S172>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checku'
 * '<S173>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checky'
 * '<S174>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculatePL/DataTypeConversionL'
 * '<S175>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculatePL/DataTypeConversionM'
 * '<S176>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculatePL/DataTypeConversionP'
 * '<S177>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculatePL/DataTypeConversionZ'
 * '<S178>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/Observer/MeasurementUpdate'
 * '<S179>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/UseCurrentEstimator/Enabled Subsystem'
 * '<S180>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/OutlierHandling/checkifPosavailable'
 * '<S181>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/OutlierHandling/maxp3'
 * '<S182>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/OutlierHandling/maxq3'
 * '<S183>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/OutlierHandling/planarjumpsVISPOS'
 * '<S184>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S185>' : 'stateEstimator/State Estimator/SensorPreprocessing/Check if valid visual position estimate available'
 */
#endif                                 /* RTW_HEADER_stateEstimator_h_ */

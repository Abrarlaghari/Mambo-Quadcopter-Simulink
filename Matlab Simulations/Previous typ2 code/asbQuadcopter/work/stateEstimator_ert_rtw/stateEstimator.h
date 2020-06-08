/*
 * File: stateEstimator.h
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

#ifndef RTW_HEADER_stateEstimator_h_
#define RTW_HEADER_stateEstimator_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef stateEstimator_COMMON_INCLUDES_
# define stateEstimator_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* stateEstimator_COMMON_INCLUDES_ */

#include "stateEstimator_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S106>/MeasurementUpdate' */
typedef struct {
  boolean_T MeasurementUpdate_MODE;    /* '<S106>/MeasurementUpdate' */
} DW_MeasurementUpdate_stateEstimator_T;

/* Block states (default storage) for system '<S111>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S111>/Enabled Subsystem' */
} DW_EnabledSubsystem_stateEstimator_T;

/* Block signals (default storage) */
typedef struct {
  real32_T VectorConcatenate[9];       /* '<S13>/Vector Concatenate' */
  real32_T Reshape9to3x3columnmajor[9];/* '<S76>/Reshape (9) to [3x3] column-major' */
  real32_T MathFunction_b[9];          /* '<S68>/Math Function' */
  real32_T rtb_MathFunction_b_m[9];
  real_T rtb_VectorConcatenate_c[3];
  real_T rtb_FIR_IMUaccel_k[3];
  real32_T inverseIMU_gain[6];
  real_T Product3[2];                  /* '<S60>/Product3' */
  real_T dv0[2];
  real32_T rtb_Conversion_g_c[4];
  real32_T rtb_Conversion_p_b[4];
  real32_T rtb_Conversion_n4_p[4];
  real32_T rtb_Conversion_a_c[4];
  real32_T sincos_o1[3];               /* '<S16>/sincos' */
  real32_T FIR_IMUaccel[3];            /* '<S5>/FIR_IMUaccel' */
  real_T invertzaxisGain;              /* '<S3>/invertzaxisGain' */
  real_T Sum[3];                       /* '<S3>/Sum' */
  real_T Product2[2];                  /* '<S61>/Product2' */
  real_T denAccum;
  real_T Sum_f;                        /* '<S60>/Sum' */
  real32_T Merge[2];                   /* '<S2>/Merge' */
  real32_T opticalFlowToVelocity_gain[3];/* '<S67>/opticalFlowToVelocity_gain' */
  real32_T Product[3];                 /* '<S68>/Product' */
  real32_T Product_p[2];               /* '<S69>/Product' */
  real32_T Product2_e[2];              /* '<S179>/Product2' */
  real32_T Product3_j[2];              /* '<S178>/Product3' */
  real32_T Product2_k[2];              /* '<S132>/Product2' */
  real32_T Product3_m[2];              /* '<S131>/Product3' */
  real32_T SimplyIntegrateVelocity[2]; /* '<S68>/SimplyIntegrateVelocity' */
  real32_T TSamp[2];                   /* '<S77>/TSamp' */
  real32_T rtb_Reshapey_o_g[2];
  real32_T rtb_MemoryX_m_g[2];
  real32_T rtb_Reshapeu_h_m[2];
  real32_T rtb_Conversion_j_n[2];
  real32_T rtb_Reshapeu_i_p[2];
  real32_T rtb_MemoryX_f_l[2];
  real32_T rtb_Conversion_pu_j[2];
  real32_T rtb_Reshapey_a_d[2];
  real32_T IIRgyroz_tmp[2];
  real32_T DataTypeConversion2;        /* '<S3>/Data Type Conversion2' */
  int32_T j;
  int32_T denIdx;
  int32_T cff;
  boolean_T Compare;                   /* '<S17>/Compare' */
  boolean_T nicemeasurementornewupdateneeded;/* '<S15>/nicemeasurementor newupdateneeded' */
  boolean_T LogicalOperator3;          /* '<S70>/Logical Operator3' */
  boolean_T LogicalOperator3_o;        /* '<S134>/Logical Operator3' */
} B_stateEstimator_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay2_DSTATE;                /* '<S3>/Delay2' */
  real_T MemoryX_DSTATE[2];            /* '<S14>/MemoryX' */
  real_T soonarFilter_IIR_states[3];   /* '<S15>/soonarFilter_IIR' */
  real32_T IIR_IMUgyro_r_states[5];    /* '<S5>/IIR_IMUgyro_r' */
  real32_T FIR_IMUaccel_states[15];    /* '<S5>/FIR_IMUaccel' */
  real32_T MemoryX_DSTATE_d[2];        /* '<S71>/MemoryX' */
  real32_T IIRgyroz_states[10];        /* '<S70>/IIRgyroz' */
  real32_T UD_DSTATE[2];               /* '<S77>/UD' */
  real32_T Delay_DSTATE[2];            /* '<S67>/Delay' */
  real32_T pressureFilter_IIR_states[3];/* '<S15>/pressureFilter_IIR' */
  real32_T Delay1_DSTATE[2];           /* '<S1>/Delay1' */
  real32_T MemoryX_DSTATE_dl[2];       /* '<S133>/MemoryX' */
  real32_T Delay_DSTATE_l[2];          /* '<S68>/Delay' */
  real32_T SimplyIntegrateVelocity_DSTATE[2];/* '<S68>/SimplyIntegrateVelocity' */
  int32_T FIR_IMUaccel_circBuf;        /* '<S5>/FIR_IMUaccel' */
  real32_T Memory_PreviousInput[3];    /* '<S2>/Memory' */
  int8_T SimplyIntegrateVelocity_PrevResetState;/* '<S68>/SimplyIntegrateVelocity' */
  uint8_T icLoad;                      /* '<S71>/MemoryX' */
  uint8_T icLoad_p;                    /* '<S14>/MemoryX' */
  uint8_T icLoad_g;                    /* '<S133>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S40>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S35>/MeasurementUpdate' */
  DW_EnabledSubsystem_stateEstimator_T EnabledSubsystem_m;/* '<S158>/Enabled Subsystem' */
  DW_MeasurementUpdate_stateEstimator_T MeasurementUpdate_b;/* '<S153>/MeasurementUpdate' */
  DW_EnabledSubsystem_stateEstimator_T EnabledSubsystem_f;/* '<S111>/Enabled Subsystem' */
  DW_MeasurementUpdate_stateEstimator_T MeasurementUpdate_e;/* '<S106>/MeasurementUpdate' */
} DW_stateEstimator_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T posVIS_datin[4];            /* '<Root>/posVIS_datin' */
} ExtU_stateEstimator_T;

/* Parameters for system: '<S106>/MeasurementUpdate' */
struct P_MeasurementUpdate_stateEstimator_T_ {
  real32_T Lykyhatkk1_Y0;              /* Computed Parameter: Lykyhatkk1_Y0
                                        * Referenced by: '<S131>/L*(y[k]-yhat[k|k-1])'
                                        */
};

/* Parameters for system: '<S111>/Enabled Subsystem' */
struct P_EnabledSubsystem_stateEstimator_T_ {
  real32_T deltax_Y0;                  /* Computed Parameter: deltax_Y0
                                        * Referenced by: '<S132>/deltax'
                                        */
};

/* Parameters (default storage) */
struct P_stateEstimator_T_ {
  struct_pAcs5k38eV6MpgiqrKAV4 Sensors;/* Variable: Sensors
                                        * Referenced by:
                                        *   '<S15>/SaturationSonar'
                                        *   '<S62>/Constant'
                                        */
  real_T outlierBelowFloor_const;      /* Mask Parameter: outlierBelowFloor_const
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T outlierJump_const;            /* Mask Parameter: outlierJump_const
                                        * Referenced by: '<S65>/Constant'
                                        */
  real_T currentEstimateVeryOffFromPressure_const;/* Mask Parameter: currentEstimateVeryOffFromPressure_const
                                                   * Referenced by: '<S63>/Constant'
                                                   */
  real_T currentStateVeryOffsonarflt_const;/* Mask Parameter: currentStateVeryOffsonarflt_const
                                            * Referenced by: '<S64>/Constant'
                                            */
  real32_T DiscreteDerivative_ICPrevScaledInput;/* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
                                                 * Referenced by: '<S77>/UD'
                                                 */
  real32_T Checkifvalidvisualpositionestimateavailable_const;/* Mask Parameter: Checkifvalidvisualpositionestimateavailable_const
                                                              * Referenced by: '<S185>/Constant'
                                                              */
  real32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S6>/Constant'
                                        */
  real32_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S7>/Constant'
                                        */
  real32_T maxp_const;                 /* Mask Parameter: maxp_const
                                        * Referenced by: '<S80>/Constant'
                                        */
  real32_T maxq_const;                 /* Mask Parameter: maxq_const
                                        * Referenced by: '<S82>/Constant'
                                        */
  real32_T maxw1_const;                /* Mask Parameter: maxw1_const
                                        * Referenced by: '<S84>/Constant'
                                        */
  real32_T maxw2_const;                /* Mask Parameter: maxw2_const
                                        * Referenced by: '<S85>/Constant'
                                        */
  real32_T maxdw1_const;               /* Mask Parameter: maxdw1_const
                                        * Referenced by: '<S78>/Constant'
                                        */
  real32_T maxdw2_const;               /* Mask Parameter: maxdw2_const
                                        * Referenced by: '<S79>/Constant'
                                        */
  real32_T maxp2_const;                /* Mask Parameter: maxp2_const
                                        * Referenced by: '<S81>/Constant'
                                        */
  real32_T maxq2_const;                /* Mask Parameter: maxq2_const
                                        * Referenced by: '<S83>/Constant'
                                        */
  real32_T maxw3_const;                /* Mask Parameter: maxw3_const
                                        * Referenced by: '<S86>/Constant'
                                        */
  real32_T maxw4_const;                /* Mask Parameter: maxw4_const
                                        * Referenced by: '<S87>/Constant'
                                        */
  real32_T minHeightforOF_const;       /* Mask Parameter: minHeightforOF_const
                                        * Referenced by: '<S88>/Constant'
                                        */
  real32_T DeactivateAccelerationIfOFisnotusedduetolowaltitude_const;/* Mask Parameter: DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
                                                                      * Referenced by: '<S72>/Constant'
                                                                      */
  real32_T donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con;/* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
                                                                      * Referenced by: '<S74>/Constant'
                                                                      */
  real32_T donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co;/* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
                                                                      * Referenced by: '<S75>/Constant'
                                                                      */
  real32_T checkifPosavailable_const;  /* Mask Parameter: checkifPosavailable_const
                                        * Referenced by: '<S180>/Constant'
                                        */
  real32_T maxp3_const;                /* Mask Parameter: maxp3_const
                                        * Referenced by: '<S181>/Constant'
                                        */
  real32_T maxq3_const;                /* Mask Parameter: maxq3_const
                                        * Referenced by: '<S182>/Constant'
                                        */
  real32_T planarjumpsVISPOS_const;    /* Mask Parameter: planarjumpsVISPOS_const
                                        * Referenced by: '<S183>/Constant'
                                        */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S60>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S61>/deltax'
                                        */
  real_T KalmanGainM_Value[4];         /* Expression: pInitialization.M
                                        * Referenced by: '<S136>/KalmanGainM'
                                        */
  real_T KalmanGainM_Value_d[4];       /* Expression: pInitialization.M
                                        * Referenced by: '<S89>/KalmanGainM'
                                        */
  real_T A_Value[4];                   /* Expression: pInitialization.A
                                        * Referenced by: '<S14>/A'
                                        */
  real_T KalmanGainL_Value[4];         /* Expression: pInitialization.L
                                        * Referenced by: '<S89>/KalmanGainL'
                                        */
  real_T KalmanGainL_Value_h[4];       /* Expression: pInitialization.L
                                        * Referenced by: '<S136>/KalmanGainL'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S3>/Delay2'
                                        */
  real_T X0_Value[2];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S14>/X0'
                                        */
  real_T SaturationSonar_LowerSat;     /* Expression: -inf
                                        * Referenced by: '<S15>/SaturationSonar'
                                        */
  real_T soonarFilter_IIR_NumCoef[4];  /* Expression: Estimator.alt.filterSonarNum
                                        * Referenced by: '<S15>/soonarFilter_IIR'
                                        */
  real_T soonarFilter_IIR_DenCoef[4];  /* Expression: Estimator.alt.filterSonarDen
                                        * Referenced by: '<S15>/soonarFilter_IIR'
                                        */
  real_T soonarFilter_IIR_InitialStates;/* Expression: 0
                                         * Referenced by: '<S15>/soonarFilter_IIR'
                                         */
  real_T KalmanGainM_Value_p[2];       /* Expression: pInitialization.M
                                        * Referenced by: '<S18>/KalmanGainM'
                                        */
  real_T C_Value[2];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S14>/C'
                                        */
  real_T gravity_Value[3];             /* Expression: [0 0 -g]
                                        * Referenced by: '<S69>/gravity'
                                        */
  real_T gravity_Value_k[3];           /* Expression: [0 0 g]
                                        * Referenced by: '<S3>/gravity'
                                        */
  real_T gainaccinput_Gain;            /* Expression: Estimator.pos.accelerationInputGain
                                        * Referenced by: '<S69>/gainaccinput'
                                        */
  real_T D_Value;                      /* Expression: pInitialization.D
                                        * Referenced by: '<S14>/D'
                                        */
  real_T KalmanGainL_Value_e[2];       /* Expression: pInitialization.L
                                        * Referenced by: '<S18>/KalmanGainL'
                                        */
  real_T B_Value[2];                   /* Expression: pInitialization.B
                                        * Referenced by: '<S14>/B'
                                        */
  real_T CovarianceZ_Value[4];         /* Expression: pInitialization.Z
                                        * Referenced by: '<S18>/CovarianceZ'
                                        */
  real_T P0_Value[4];                  /* Expression: pInitialization.P0
                                        * Referenced by: '<S14>/P0'
                                        */
  real_T CovarianceZ_Value_b[4];       /* Expression: pInitialization.Z
                                        * Referenced by: '<S89>/CovarianceZ'
                                        */
  real_T CovarianceZ_Value_l[4];       /* Expression: pInitialization.Z
                                        * Referenced by: '<S136>/CovarianceZ'
                                        */
  real_T G_Value[2];                   /* Expression: pInitialization.G
                                        * Referenced by: '<S14>/G'
                                        */
  real_T ConstantP_Value;              /* Expression: 0
                                        * Referenced by: '<S18>/ConstantP'
                                        */
  real_T H_Value;                      /* Expression: pInitialization.H
                                        * Referenced by: '<S14>/H'
                                        */
  real_T N_Value;                      /* Expression: pInitialization.N
                                        * Referenced by: '<S14>/N'
                                        */
  real_T Q_Value;                      /* Expression: pInitialization.Q
                                        * Referenced by: '<S14>/Q'
                                        */
  real_T R_Value;                      /* Expression: pInitialization.R
                                        * Referenced by: '<S14>/R'
                                        */
  real_T ConstantP_Value_h;            /* Expression: 0
                                        * Referenced by: '<S89>/ConstantP'
                                        */
  real_T ConstantP_Value_g;            /* Expression: 0
                                        * Referenced by: '<S136>/ConstantP'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S8>/Gain'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S8>/Gain3'
                                        */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S8>/Gain4'
                                        */
  real32_T Gain_Gain_i;                /* Computed Parameter: Gain_Gain_i
                                        * Referenced by: '<S9>/Gain'
                                        */
  real32_T Gain1_Gain_k;               /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real32_T Constant_Value;             /* Expression: single(0)
                                        * Referenced by: '<S12>/Constant'
                                        */
  real32_T Memory_InitialCondition[3]; /* Expression: single(Estimator.complementaryFilterInit)
                                        * Referenced by: '<S2>/Memory'
                                        */
  real32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S12>/Gain'
                                        */
  real32_T Assumingthatcalibwasdonelevel_Bias[6];/* Computed Parameter: Assumingthatcalibwasdonelevel_Bias
                                                  * Referenced by: '<S5>/Assuming that calib was done level!'
                                                  */
  real32_T inverseIMU_gain_Gain[6];    /* Computed Parameter: inverseIMU_gain_Gain
                                        * Referenced by: '<S5>/inverseIMU_gain'
                                        */
  real32_T IIR_IMUgyro_r_NumCoef[6];   /* Computed Parameter: IIR_IMUgyro_r_NumCoef
                                        * Referenced by: '<S5>/IIR_IMUgyro_r'
                                        */
  real32_T IIR_IMUgyro_r_DenCoef[6];   /* Computed Parameter: IIR_IMUgyro_r_DenCoef
                                        * Referenced by: '<S5>/IIR_IMUgyro_r'
                                        */
  real32_T IIR_IMUgyro_r_InitialStates;/* Computed Parameter: IIR_IMUgyro_r_InitialStates
                                        * Referenced by: '<S5>/IIR_IMUgyro_r'
                                        */
  real32_T Gain_Gain_b;                /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S2>/Gain'
                                        */
  real32_T FIR_IMUaccel_InitialStates; /* Computed Parameter: FIR_IMUaccel_InitialStates
                                        * Referenced by: '<S5>/FIR_IMUaccel'
                                        */
  real32_T FIR_IMUaccel_Coefficients[6];/* Computed Parameter: FIR_IMUaccel_Coefficients
                                         * Referenced by: '<S5>/FIR_IMUaccel'
                                         */
  real32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S2>/Constant'
                                        */
  real32_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S2>/Merge'
                                        */
  real32_T C_Value_p[4];               /* Computed Parameter: C_Value_p
                                        * Referenced by: '<S133>/C'
                                        */
  real32_T C_Value_f[4];               /* Computed Parameter: C_Value_f
                                        * Referenced by: '<S71>/C'
                                        */
  real32_T A_Value_c[4];               /* Computed Parameter: A_Value_c
                                        * Referenced by: '<S71>/A'
                                        */
  real32_T B_Value_p[4];               /* Computed Parameter: B_Value_p
                                        * Referenced by: '<S71>/B'
                                        */
  real32_T D_Value_f[4];               /* Computed Parameter: D_Value_f
                                        * Referenced by: '<S71>/D'
                                        */
  real32_T A_Value_b[4];               /* Computed Parameter: A_Value_b
                                        * Referenced by: '<S133>/A'
                                        */
  real32_T B_Value_pu[4];              /* Computed Parameter: B_Value_pu
                                        * Referenced by: '<S133>/B'
                                        */
  real32_T D_Value_b[4];               /* Computed Parameter: D_Value_b
                                        * Referenced by: '<S133>/D'
                                        */
  real32_T X0_Value_e[2];              /* Computed Parameter: X0_Value_e
                                        * Referenced by: '<S71>/X0'
                                        */
  real32_T IIRgyroz_NumCoef[6];        /* Computed Parameter: IIRgyroz_NumCoef
                                        * Referenced by: '<S70>/IIRgyroz'
                                        */
  real32_T IIRgyroz_DenCoef[6];        /* Computed Parameter: IIRgyroz_DenCoef
                                        * Referenced by: '<S70>/IIRgyroz'
                                        */
  real32_T IIRgyroz_InitialStates;     /* Computed Parameter: IIRgyroz_InitialStates
                                        * Referenced by: '<S70>/IIRgyroz'
                                        */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S77>/TSamp'
                                        */
  real32_T opticalFlowToVelocity_gain_Gain;/* Computed Parameter: opticalFlowToVelocity_gain_Gain
                                            * Referenced by: '<S67>/opticalFlowToVelocity_gain'
                                            */
  real32_T Delay_InitialCondition;     /* Computed Parameter: Delay_InitialCondition
                                        * Referenced by: '<S67>/Delay'
                                        */
  real32_T invertzaxisGain_Gain;       /* Computed Parameter: invertzaxisGain_Gain
                                        * Referenced by: '<S3>/invertzaxisGain'
                                        */
  real32_T prsToAltGain_Gain;          /* Computed Parameter: prsToAltGain_Gain
                                        * Referenced by: '<S3>/prsToAltGain'
                                        */
  real32_T pressureFilter_IIR_NumCoef[4];/* Computed Parameter: pressureFilter_IIR_NumCoef
                                          * Referenced by: '<S15>/pressureFilter_IIR'
                                          */
  real32_T pressureFilter_IIR_DenCoef[4];/* Computed Parameter: pressureFilter_IIR_DenCoef
                                          * Referenced by: '<S15>/pressureFilter_IIR'
                                          */
  real32_T pressureFilter_IIR_InitialStates;/* Computed Parameter: pressureFilter_IIR_InitialStates
                                             * Referenced by: '<S15>/pressureFilter_IIR'
                                             */
  real32_T Delay1_InitialCondition;    /* Computed Parameter: Delay1_InitialCondition
                                        * Referenced by: '<S1>/Delay1'
                                        */
  real32_T X0_Value_j[2];              /* Computed Parameter: X0_Value_j
                                        * Referenced by: '<S133>/X0'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S134>/Constant'
                                        */
  real32_T Delay_InitialCondition_n;   /* Computed Parameter: Delay_InitialCondition_n
                                        * Referenced by: '<S68>/Delay'
                                        */
  real32_T SimplyIntegrateVelocity_gainval;/* Computed Parameter: SimplyIntegrateVelocity_gainval
                                            * Referenced by: '<S68>/SimplyIntegrateVelocity'
                                            */
  real32_T SimplyIntegrateVelocity_IC; /* Computed Parameter: SimplyIntegrateVelocity_IC
                                        * Referenced by: '<S68>/SimplyIntegrateVelocity'
                                        */
  real32_T UseIPPosSwitch_Threshold;   /* Computed Parameter: UseIPPosSwitch_Threshold
                                        * Referenced by: '<S68>/UseIPPosSwitch'
                                        */
  real32_T P0_Value_m[4];              /* Computed Parameter: P0_Value_m
                                        * Referenced by: '<S71>/P0'
                                        */
  real32_T G_Value_h[4];               /* Computed Parameter: G_Value_h
                                        * Referenced by: '<S71>/G'
                                        */
  real32_T H_Value_c[4];               /* Computed Parameter: H_Value_c
                                        * Referenced by: '<S71>/H'
                                        */
  real32_T N_Value_g[4];               /* Computed Parameter: N_Value_g
                                        * Referenced by: '<S71>/N'
                                        */
  real32_T Q_Value_f[4];               /* Computed Parameter: Q_Value_f
                                        * Referenced by: '<S71>/Q'
                                        */
  real32_T R_Value_k[4];               /* Computed Parameter: R_Value_k
                                        * Referenced by: '<S71>/R'
                                        */
  real32_T P0_Value_h[4];              /* Computed Parameter: P0_Value_h
                                        * Referenced by: '<S133>/P0'
                                        */
  real32_T G_Value_p[4];               /* Computed Parameter: G_Value_p
                                        * Referenced by: '<S133>/G'
                                        */
  real32_T H_Value_d[4];               /* Computed Parameter: H_Value_d
                                        * Referenced by: '<S133>/H'
                                        */
  real32_T N_Value_j[4];               /* Computed Parameter: N_Value_j
                                        * Referenced by: '<S133>/N'
                                        */
  real32_T Q_Value_n[4];               /* Computed Parameter: Q_Value_n
                                        * Referenced by: '<S133>/Q'
                                        */
  real32_T R_Value_kf[4];              /* Computed Parameter: R_Value_kf
                                        * Referenced by: '<S133>/R'
                                        */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S36>/Constant'
                                        */
  real32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S107>/Constant'
                                        */
  real32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S154>/Constant'
                                        */
  uint32_T MemoryX_DelayLength;        /* Computed Parameter: MemoryX_DelayLength
                                        * Referenced by: '<S71>/MemoryX'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S67>/Delay'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S3>/Delay2'
                                        */
  uint32_T MemoryX_DelayLength_e;      /* Computed Parameter: MemoryX_DelayLength_e
                                        * Referenced by: '<S14>/MemoryX'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S1>/Delay1'
                                        */
  uint32_T MemoryX_DelayLength_ez;     /* Computed Parameter: MemoryX_DelayLength_ez
                                        * Referenced by: '<S133>/MemoryX'
                                        */
  uint32_T Delay_DelayLength_e;        /* Computed Parameter: Delay_DelayLength_e
                                        * Referenced by: '<S68>/Delay'
                                        */
  boolean_T Constant_Value_a;          /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S19>/Constant'
                                        */
  boolean_T Constant_Value_mn;         /* Computed Parameter: Constant_Value_mn
                                        * Referenced by: '<S90>/Constant'
                                        */
  boolean_T Reset_Value;               /* Expression: false()
                                        * Referenced by: '<S71>/Reset'
                                        */
  boolean_T Constant_Value_l;          /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S137>/Constant'
                                        */
  boolean_T Reset_Value_a;             /* Expression: false()
                                        * Referenced by: '<S133>/Reset'
                                        */
  uint8_T ManualSwitchPZ_CurrentSetting;/* Computed Parameter: ManualSwitchPZ_CurrentSetting
                                         * Referenced by: '<S14>/ManualSwitchPZ'
                                         */
  uint8_T ManualSwitchPZ_CurrentSetting_i;/* Computed Parameter: ManualSwitchPZ_CurrentSetting_i
                                           * Referenced by: '<S71>/ManualSwitchPZ'
                                           */
  uint8_T ManualSwitchPZ_CurrentSetting_b;/* Computed Parameter: ManualSwitchPZ_CurrentSetting_b
                                           * Referenced by: '<S133>/ManualSwitchPZ'
                                           */
  P_EnabledSubsystem_stateEstimator_T EnabledSubsystem_m;/* '<S158>/Enabled Subsystem' */
  P_MeasurementUpdate_stateEstimator_T MeasurementUpdate_b;/* '<S153>/MeasurementUpdate' */
  P_EnabledSubsystem_stateEstimator_T EnabledSubsystem_f;/* '<S111>/Enabled Subsystem' */
  P_MeasurementUpdate_stateEstimator_T MeasurementUpdate_e;/* '<S106>/MeasurementUpdate' */
};

/* Real-time Model Data Structure */
struct tag_RTM_stateEstimator_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_stateEstimator_T stateEstimator_P;

/* Block signals (default storage) */
extern B_stateEstimator_T stateEstimator_B;

/* Block states (default storage) */
extern DW_stateEstimator_T stateEstimator_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_stateEstimator_T stateEstimator_U;

/* Model entry point functions */
extern void stateEstimator_initialize(void);
extern void stateEstimator_terminate(void);

/* Customized model step function */
extern void stateEstimator_run(const boolean_T arg_controlModePosVSOrient_flagin,
  const sensordata_t *arg_sensordata_datin, const real32_T arg_usePosVIS_flagin,
  const real32_T arg_opticalFlow_datin[3], const real32_T arg_posVIS_datin[4],
  statesEstim_t *arg_states_estimout, const real32_T
  arg_sensorCalibration_datin[8]);

/* Real-time Model object */
extern RT_MODEL_stateEstimator_T *const stateEstimator_M;

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

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

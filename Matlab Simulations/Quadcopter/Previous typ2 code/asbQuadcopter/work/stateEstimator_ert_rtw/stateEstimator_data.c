/*
 * File: stateEstimator_data.c
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

/* Block parameters (default storage) */
P_stateEstimator_T stateEstimator_P = {
  /* Variable: Sensors
   * Referenced by:
   *   '<S15>/SaturationSonar'
   *   '<S62>/Constant'
   */
  {
    { 1.00596, 1.00383, 0.99454 },

    { 0.99861, 1.00644, 0.99997 },

    {
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0 },
      190.0,
      0.707,

      { 1.00596, 0.0, 0.0, 0.0, 1.00383, 0.0, 0.0, 0.0, 0.99454 },

      { 0.09, -0.06, 0.33699999999999974 },

      { -50.0, -50.0, -50.0, 50.0, 50.0, 50.0 },
      190.0,
      0.707,

      { 0.99861, 0.0, 0.0, 0.0, 1.00644, 0.0, 0.0, 0.0, 0.99997 },

      { -0.0095, -0.0075, 0.0015 },

      { 0.0, 0.0, 0.0 },

      { -10.0, -10.0, -10.0, 10.0, 10.0, 10.0 },

      { 41.0, 41.0, 41.0, 41.0, 41.0, 41.0 },

      { 0.8, 0.8, 0.8, 0.025, 0.025, 0.025 },

      { 0.00021831529882618725, 0.00018641345254680647, 0.00037251068300213613,
        1.0651514622688397e-8, 1.3021327403798377e-8, 1.1929474437781302e-8 }
    },

    {
      1.0,
      41.0
    },
    -99.0,
    -9.0,

    {
      { -99.0, 0.0, 0.0, -9.0 },
      0.0,

      { 3.5, 70.0 }
    },
    1.0,
    1.225,
    12.01725,
    101270.95,

    { 0.99407531114557246, 0.99618461293246863, 1.0054899752649467,
      1.0013919347893572, 0.99360120821906917, 1.0000300009000269 },
    0.44,
    1.0,

    { 160.0, 120.0 }
  },

  /* Mask Parameter: outlierBelowFloor_const
   * Referenced by: '<S17>/Constant'
   */
  0.0,

  /* Mask Parameter: outlierJump_const
   * Referenced by: '<S65>/Constant'
   */
  0.3,

  /* Mask Parameter: currentEstimateVeryOffFromPressure_const
   * Referenced by: '<S63>/Constant'
   */
  0.8,

  /* Mask Parameter: currentStateVeryOffsonarflt_const
   * Referenced by: '<S64>/Constant'
   */
  0.4,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
   * Referenced by: '<S77>/UD'
   */
  0.0F,

  /* Mask Parameter: Checkifvalidvisualpositionestimateavailable_const
   * Referenced by: '<S185>/Constant'
   */
  -99.0F,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S6>/Constant'
   */
  9.79038F,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S7>/Constant'
   */
  9.82962F,

  /* Mask Parameter: maxp_const
   * Referenced by: '<S80>/Constant'
   */
  0.6F,

  /* Mask Parameter: maxq_const
   * Referenced by: '<S82>/Constant'
   */
  0.6F,

  /* Mask Parameter: maxw1_const
   * Referenced by: '<S84>/Constant'
   */
  7.0F,

  /* Mask Parameter: maxw2_const
   * Referenced by: '<S85>/Constant'
   */
  7.0F,

  /* Mask Parameter: maxdw1_const
   * Referenced by: '<S78>/Constant'
   */
  80.0F,

  /* Mask Parameter: maxdw2_const
   * Referenced by: '<S79>/Constant'
   */
  80.0F,

  /* Mask Parameter: maxp2_const
   * Referenced by: '<S81>/Constant'
   */
  0.5F,

  /* Mask Parameter: maxq2_const
   * Referenced by: '<S83>/Constant'
   */
  0.5F,

  /* Mask Parameter: maxw3_const
   * Referenced by: '<S86>/Constant'
   */
  5.0F,

  /* Mask Parameter: maxw4_const
   * Referenced by: '<S87>/Constant'
   */
  5.0F,

  /* Mask Parameter: minHeightforOF_const
   * Referenced by: '<S88>/Constant'
   */
  -0.4F,

  /* Mask Parameter: DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
   * Referenced by: '<S72>/Constant'
   */
  -0.4F,

  /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
   * Referenced by: '<S74>/Constant'
   */
  0.0F,

  /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
   * Referenced by: '<S75>/Constant'
   */
  0.0F,

  /* Mask Parameter: checkifPosavailable_const
   * Referenced by: '<S180>/Constant'
   */
  -99.0F,

  /* Mask Parameter: maxp3_const
   * Referenced by: '<S181>/Constant'
   */
  0.18F,

  /* Mask Parameter: maxq3_const
   * Referenced by: '<S182>/Constant'
   */
  0.18F,

  /* Mask Parameter: planarjumpsVISPOS_const
   * Referenced by: '<S183>/Constant'
   */
  1.0F,

  /* Expression: 0
   * Referenced by: '<S60>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S61>/deltax'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S136>/KalmanGainM'
   */
  { 0.0057568600814406484, 0.0, 0.0, 0.0057568600814406484 },

  /* Expression: pInitialization.M
   * Referenced by: '<S89>/KalmanGainM'
   */
  { 0.12546560898608936, 0.0, 0.0, 0.12546560898608936 },

  /* Expression: pInitialization.A
   * Referenced by: '<S14>/A'
   */
  { 1.0, 0.0, 0.005, 1.0 },

  /* Expression: pInitialization.L
   * Referenced by: '<S89>/KalmanGainL'
   */
  { 0.12546560898608936, 0.0, 0.0, 0.12546560898608936 },

  /* Expression: pInitialization.L
   * Referenced by: '<S136>/KalmanGainL'
   */
  { 0.0057568600814406484, 0.0, 0.0, 0.0057568600814406484 },

  /* Expression: 0
   * Referenced by: '<S3>/Delay2'
   */
  0.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S14>/X0'
   */
  { -0.046, 0.0 },

  /* Expression: -inf
   * Referenced by: '<S15>/SaturationSonar'
   */
  0.0,

  /* Expression: Estimator.alt.filterSonarNum
   * Referenced by: '<S15>/soonarFilter_IIR'
   */
  { 3.7568380197305906E-6, 1.1270514059191772E-5, 1.1270514059191772E-5,
    3.7568380197305906E-6 },

  /* Expression: Estimator.alt.filterSonarDen
   * Referenced by: '<S15>/soonarFilter_IIR'
   */
  { 1.0, -2.9371707284498911, 2.8762997234793324, -0.93909894032528318 },

  /* Expression: 0
   * Referenced by: '<S15>/soonarFilter_IIR'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S18>/KalmanGainM'
   */
  { 0.026241420641870527, 0.069776736071493844 },

  /* Expression: pInitialization.C
   * Referenced by: '<S14>/C'
   */
  { 1.0, 0.0 },

  /* Expression: [0 0 -g]
   * Referenced by: '<S69>/gravity'
   */
  { 0.0, 0.0, -9.81 },

  /* Expression: [0 0 g]
   * Referenced by: '<S3>/gravity'
   */
  { 0.0, 0.0, 9.81 },

  /* Expression: Estimator.pos.accelerationInputGain
   * Referenced by: '<S69>/gainaccinput'
   */
  0.2,

  /* Expression: pInitialization.D
   * Referenced by: '<S14>/D'
   */
  0.0,

  /* Expression: pInitialization.L
   * Referenced by: '<S18>/KalmanGainL'
   */
  { 0.026590304322227993, 0.069776736071493844 },

  /* Expression: pInitialization.B
   * Referenced by: '<S14>/B'
   */
  { 0.0, 0.005 },

  /* Expression: pInitialization.Z
   * Referenced by: '<S18>/CovarianceZ'
   */
  { 0.0026241420641870527, 0.0069776736071493857, 0.0069776736071493857,
    0.037607692935055635 },

  /* Expression: pInitialization.P0
   * Referenced by: '<S14>/P0'
   */
  { 0.0026948589925819225, 0.0071657120718246663, 0.0071657120718246663,
    0.038107692935055663 },

  /* Expression: pInitialization.Z
   * Referenced by: '<S89>/CovarianceZ'
   */
  { 0.6273280449304468, 0.0, 0.0, 0.6273280449304468 },

  /* Expression: pInitialization.Z
   * Referenced by: '<S136>/CovarianceZ'
   */
  { 0.0017270580244321944, 0.0, 0.0, 0.0017270580244321944 },

  /* Expression: pInitialization.G
   * Referenced by: '<S14>/G'
   */
  { 0.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S18>/ConstantP'
   */
  0.0,

  /* Expression: pInitialization.H
   * Referenced by: '<S14>/H'
   */
  0.0,

  /* Expression: pInitialization.N
   * Referenced by: '<S14>/N'
   */
  0.0,

  /* Expression: pInitialization.Q
   * Referenced by: '<S14>/Q'
   */
  0.0005,

  /* Expression: pInitialization.R
   * Referenced by: '<S14>/R'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S89>/ConstantP'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S136>/ConstantP'
   */
  0.0,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S8>/Gain1'
   */
  0.001F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S8>/Gain'
   */
  0.999F,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S8>/Gain2'
   */
  0.101936802F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S8>/Gain3'
   */
  0.001F,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S8>/Gain4'
   */
  0.999F,

  /* Computed Parameter: Gain_Gain_i
   * Referenced by: '<S9>/Gain'
   */
  0.8F,

  /* Computed Parameter: Gain1_Gain_k
   * Referenced by: '<S9>/Gain1'
   */
  0.2F,

  /* Expression: single(0)
   * Referenced by: '<S12>/Constant'
   */
  0.0F,

  /* Expression: single(Estimator.complementaryFilterInit)
   * Referenced by: '<S2>/Memory'
   */
  { 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: Gain_Gain_c
   * Referenced by: '<S12>/Gain'
   */
  -1.0F,

  /* Computed Parameter: Assumingthatcalibwasdonelevel_Bias
   * Referenced by: '<S5>/Assuming that calib was done level!'
   */
  { 0.0F, 0.0F, 9.81F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: inverseIMU_gain_Gain
   * Referenced by: '<S5>/inverseIMU_gain'
   */
  { 0.994075298F, 0.996184587F, 1.00549F, 1.00139189F, 0.993601203F, 1.00003F },

  /* Computed Parameter: IIR_IMUgyro_r_NumCoef
   * Referenced by: '<S5>/IIR_IMUgyro_r'
   */
  { 0.282124132F, 1.27253926F, 2.42084408F, 2.42084408F, 1.27253926F,
    0.282124132F },

  /* Computed Parameter: IIR_IMUgyro_r_DenCoef
   * Referenced by: '<S5>/IIR_IMUgyro_r'
   */
  { 1.0F, 2.22871494F, 2.52446198F, 1.57725322F, 0.54102242F, 0.0795623958F },

  /* Computed Parameter: IIR_IMUgyro_r_InitialStates
   * Referenced by: '<S5>/IIR_IMUgyro_r'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_b
   * Referenced by: '<S2>/Gain'
   */
  0.005F,

  /* Computed Parameter: FIR_IMUaccel_InitialStates
   * Referenced by: '<S5>/FIR_IMUaccel'
   */
  0.0F,

  /* Computed Parameter: FIR_IMUaccel_Coefficients
   * Referenced by: '<S5>/FIR_IMUaccel'
   */
  { 0.0264077242F, 0.140531361F, 0.33306092F, 0.33306092F, 0.140531361F,
    0.0264077242F },

  /* Computed Parameter: Constant_Value_n
   * Referenced by: '<S2>/Constant'
   */
  2.0F,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S2>/Merge'
   */
  0.0F,

  /* Computed Parameter: C_Value_p
   * Referenced by: '<S133>/C'
   */
  { 1.0F, 0.0F, 0.0F, 1.0F },

  /* Computed Parameter: C_Value_f
   * Referenced by: '<S71>/C'
   */
  { 1.0F, 0.0F, 0.0F, 1.0F },

  /* Computed Parameter: A_Value_c
   * Referenced by: '<S71>/A'
   */
  { 1.0F, 0.0F, 0.0F, 1.0F },

  /* Computed Parameter: B_Value_p
   * Referenced by: '<S71>/B'
   */
  { 0.005F, 0.0F, 0.0F, 0.005F },

  /* Computed Parameter: D_Value_f
   * Referenced by: '<S71>/D'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: A_Value_b
   * Referenced by: '<S133>/A'
   */
  { 1.0F, 0.0F, 0.0F, 1.0F },

  /* Computed Parameter: B_Value_pu
   * Referenced by: '<S133>/B'
   */
  { 0.005F, 0.0F, 0.0F, 0.005F },

  /* Computed Parameter: D_Value_b
   * Referenced by: '<S133>/D'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: X0_Value_e
   * Referenced by: '<S71>/X0'
   */
  { 0.0F, 0.0F },

  /* Computed Parameter: IIRgyroz_NumCoef
   * Referenced by: '<S70>/IIRgyroz'
   */
  { 0.282124132F, 1.27253926F, 2.42084408F, 2.42084408F, 1.27253926F,
    0.282124132F },

  /* Computed Parameter: IIRgyroz_DenCoef
   * Referenced by: '<S70>/IIRgyroz'
   */
  { 1.0F, 2.22871494F, 2.52446198F, 1.57725322F, 0.54102242F, 0.0795623958F },

  /* Computed Parameter: IIRgyroz_InitialStates
   * Referenced by: '<S70>/IIRgyroz'
   */
  0.0F,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S77>/TSamp'
   */
  200.0F,

  /* Computed Parameter: opticalFlowToVelocity_gain_Gain
   * Referenced by: '<S67>/opticalFlowToVelocity_gain'
   */
  1.0F,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S67>/Delay'
   */
  0.0F,

  /* Computed Parameter: invertzaxisGain_Gain
   * Referenced by: '<S3>/invertzaxisGain'
   */
  -1.0F,

  /* Computed Parameter: prsToAltGain_Gain
   * Referenced by: '<S3>/prsToAltGain'
   */
  0.0832137167F,

  /* Computed Parameter: pressureFilter_IIR_NumCoef
   * Referenced by: '<S15>/pressureFilter_IIR'
   */
  { 3.75683794E-6F, 1.12705138E-5F, 1.12705138E-5F, 3.75683794E-6F },

  /* Computed Parameter: pressureFilter_IIR_DenCoef
   * Referenced by: '<S15>/pressureFilter_IIR'
   */
  { 1.0F, -2.93717074F, 2.87629962F, -0.939098954F },

  /* Computed Parameter: pressureFilter_IIR_InitialStates
   * Referenced by: '<S15>/pressureFilter_IIR'
   */
  0.0F,

  /* Computed Parameter: Delay1_InitialCondition
   * Referenced by: '<S1>/Delay1'
   */
  0.0F,

  /* Computed Parameter: X0_Value_j
   * Referenced by: '<S133>/X0'
   */
  { 0.1F, 0.0F },

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S134>/Constant'
   */
  2.0F,

  /* Computed Parameter: Delay_InitialCondition_n
   * Referenced by: '<S68>/Delay'
   */
  0.0F,

  /* Computed Parameter: SimplyIntegrateVelocity_gainval
   * Referenced by: '<S68>/SimplyIntegrateVelocity'
   */
  0.005F,

  /* Computed Parameter: SimplyIntegrateVelocity_IC
   * Referenced by: '<S68>/SimplyIntegrateVelocity'
   */
  0.0F,

  /* Computed Parameter: UseIPPosSwitch_Threshold
   * Referenced by: '<S68>/UseIPPosSwitch'
   */
  0.0F,

  /* Computed Parameter: P0_Value_m
   * Referenced by: '<S71>/P0'
   */
  { 0.717328072F, 0.0F, 0.0F, 0.717328072F },

  /* Computed Parameter: G_Value_h
   * Referenced by: '<S71>/G'
   */
  { 1.0F, 0.0F, 0.0F, 1.0F },

  /* Computed Parameter: H_Value_c
   * Referenced by: '<S71>/H'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: N_Value_g
   * Referenced by: '<S71>/N'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: Q_Value_f
   * Referenced by: '<S71>/Q'
   */
  { 0.09F, 0.0F, 0.0F, 0.09F },

  /* Computed Parameter: R_Value_k
   * Referenced by: '<S71>/R'
   */
  { 5.0F, 0.0F, 0.0F, 5.0F },

  /* Computed Parameter: P0_Value_h
   * Referenced by: '<S133>/P0'
   */
  { 0.00173705805F, 0.0F, 0.0F, 0.00173705805F },

  /* Computed Parameter: G_Value_p
   * Referenced by: '<S133>/G'
   */
  { 0.1F, 0.0F, 0.0F, 0.1F },

  /* Computed Parameter: H_Value_d
   * Referenced by: '<S133>/H'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: N_Value_j
   * Referenced by: '<S133>/N'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: Q_Value_n
   * Referenced by: '<S133>/Q'
   */
  { 0.001F, 0.0F, 0.0F, 0.001F },

  /* Computed Parameter: R_Value_kf
   * Referenced by: '<S133>/R'
   */
  { 0.3F, 0.0F, 0.0F, 0.3F },

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S36>/Constant'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S107>/Constant'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_f
   * Referenced by: '<S154>/Constant'
   */
  0.0F,

  /* Computed Parameter: MemoryX_DelayLength
   * Referenced by: '<S71>/MemoryX'
   */
  1U,

  /* Computed Parameter: Delay_DelayLength
   * Referenced by: '<S67>/Delay'
   */
  1U,

  /* Computed Parameter: Delay2_DelayLength
   * Referenced by: '<S3>/Delay2'
   */
  1U,

  /* Computed Parameter: MemoryX_DelayLength_e
   * Referenced by: '<S14>/MemoryX'
   */
  1U,

  /* Computed Parameter: Delay1_DelayLength
   * Referenced by: '<S1>/Delay1'
   */
  1U,

  /* Computed Parameter: MemoryX_DelayLength_ez
   * Referenced by: '<S133>/MemoryX'
   */
  1U,

  /* Computed Parameter: Delay_DelayLength_e
   * Referenced by: '<S68>/Delay'
   */
  1U,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S19>/Constant'
   */
  0,

  /* Computed Parameter: Constant_Value_mn
   * Referenced by: '<S90>/Constant'
   */
  0,

  /* Expression: false()
   * Referenced by: '<S71>/Reset'
   */
  0,

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<S137>/Constant'
   */
  0,

  /* Expression: false()
   * Referenced by: '<S133>/Reset'
   */
  0,

  /* Computed Parameter: ManualSwitchPZ_CurrentSetting
   * Referenced by: '<S14>/ManualSwitchPZ'
   */
  1U,

  /* Computed Parameter: ManualSwitchPZ_CurrentSetting_i
   * Referenced by: '<S71>/ManualSwitchPZ'
   */
  1U,

  /* Computed Parameter: ManualSwitchPZ_CurrentSetting_b
   * Referenced by: '<S133>/ManualSwitchPZ'
   */
  1U,

  /* Start of '<S158>/Enabled Subsystem' */
  {
    /* Computed Parameter: deltax_Y0
     * Referenced by: '<S179>/deltax'
     */
    0.0F
  }
  ,

  /* End of '<S158>/Enabled Subsystem' */

  /* Start of '<S153>/MeasurementUpdate' */
  {
    /* Computed Parameter: Lykyhatkk1_Y0
     * Referenced by: '<S178>/L*(y[k]-yhat[k|k-1])'
     */
    0.0F
  }
  ,

  /* End of '<S153>/MeasurementUpdate' */

  /* Start of '<S111>/Enabled Subsystem' */
  {
    /* Computed Parameter: deltax_Y0
     * Referenced by: '<S132>/deltax'
     */
    0.0F
  }
  ,

  /* End of '<S111>/Enabled Subsystem' */

  /* Start of '<S106>/MeasurementUpdate' */
  {
    /* Computed Parameter: Lykyhatkk1_Y0
     * Referenced by: '<S131>/L*(y[k]-yhat[k|k-1])'
     */
    0.0F
  }
  /* End of '<S106>/MeasurementUpdate' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

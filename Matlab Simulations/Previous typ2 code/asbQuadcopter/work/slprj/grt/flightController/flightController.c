/*
 * Code generation for system model 'flightController'
 *
 * Model                      : flightController
 * Model version              : 1.260
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Mon Nov  4 15:17:41 2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "flightController.h"
#include "flightController_private.h"
#include "rt_powf_snf.h"

MdlrefDW_flightController_T flightController_MdlrefDW;

/* Block states (default storage) */
DW_flightController_f_T flightController_DW;

/* System initialize for referenced model: 'flightController' */
void flightController_Init(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[1] = 0.0F;
}

/* System reset for referenced model: 'flightController' */
void flightController_Reset(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[1] = 0.0F;
}

/* Output and update for referenced model: 'flightController' */
void flightController(const CommandBus *rtu_ReferenceValueServerBus, const
                      statesEstim_t *rtu_states_estim, real32_T
                      rty_motors_refout[4], real32_T rty_pose_refout[8])
{
  /* local block i/o variables */
  real32_T rtb_Sum15;
  real32_T rtb_y1;
  real32_T EN;
  real32_T DEN;
  real32_T G11U;
  real32_T G11L;
  real32_T G21U;
  real32_T G21L;
  real32_T G31U;
  real32_T G12U;
  real32_T G12L;
  real32_T G32U;
  real32_T G32L;
  real32_T RNU;
  real32_T rtb_Gain;
  real32_T rtb_Gain1;
  real32_T rtb_TrigonometricFunction_o2;
  real32_T rtb_TrigonometricFunction_o1;
  int32_T i;
  real32_T rtb_pitchrollerror_idx_1;

  /* Gain: '<S2>/Gain' incorporates:
   *  Sum: '<S2>/Sum3'
   */
  rtb_Gain = (rtu_ReferenceValueServerBus->pos_ref[2] - rtu_states_estim->Z) * (
    -1.0F);

  /* Gain: '<S2>/Gain1' */
  rtb_Gain1 = (-1.0F) * rtu_states_estim->dz;

  /* Sum: '<S2>/Sum15' incorporates:
   *  Gain: '<S2>/D_z'
   *  Gain: '<S2>/P_z'
   */
  rtb_Sum15 = 0.8F * rtb_Gain - 0.3F * rtb_Gain1;

  /* MATLAB Function: '<S2>/MATLAB Function' */
  /* MATLAB Function 'Flight Controller/Altitude Controller/MATLAB Function': '<S8>:1' */
  /* '<S8>:1:4' EN = (E - (-1.1))/2.2 ; */
  EN = (rtb_Gain - -1.1F) / 2.2F;

  /* '<S8>:1:5' DEN = (DE - (-2))/4; */
  DEN = (rtb_Gain1 - -2.0F) / 4.0F;

  /* '<S8>:1:6' mu=0.2; */
  /* '<S8>:1:7' mu1= (1-mu)/mu; */
  /* '<S8>:1:8' lambda = 4; */
  /* '<S8>:1:9' e = 0.5; */
  /* '<S8>:1:10' Noise1 = 0.15; */
  /* '<S8>:1:11' Noise2= 20* Noise1; */
  /* '<S8>:1:12' Noise=0.05; */
  /* '<S8>:1:17' deltal1 = abs(((EN-(0))/ e ) * (1 / (1 + exp(100*((EN-(0)))))))^lambda; */
  /* '<S8>:1:18' deltar1 = abs(((EN-(0))/ e ) * (1 / (1 + exp(-100*((EN-(0)))))))^lambda; */
  /* '<S8>:1:19' G11U = 1/(1+ (mu1 * deltal1) + (mu1 *deltar1)); */
  G11U = 1.0F / ((rt_powf_snf((real32_T)fabs(1.0F / ((real32_T)exp(100.0F * EN)
    + 1.0F) * (EN / 0.5F)), 4.0F) * 4.0F + 1.0F) + rt_powf_snf((real32_T)fabs
    (1.0F / ((real32_T)exp(-100.0F * EN) + 1.0F) * (EN / 0.5F)), 4.0F) * 4.0F);

  /* '<S8>:1:20' deltal2 = abs((((EN-(0))- Noise)/ (e- Noise1) ) * (1 / (1 + exp(100*(((EN-(0))- Noise))))))^(lambda+Noise2); */
  /* '<S8>:1:21' deltar2 = abs((((EN-(0))+ Noise)/ (e- Noise1) ) * (1 / (1 + exp(-100*(((EN-(0))+ Noise))))))^(lambda+Noise2); */
  /* '<S8>:1:22' G11L = 1/(1+ (mu1 * deltal2) + (mu1 *deltar2)); */
  G11L = 1.0F / ((rt_powf_snf((real32_T)fabs(1.0F / ((real32_T)exp((EN - 0.05F) *
    100.0F) + 1.0F) * ((EN - 0.05F) / 0.35F)), 7.0F) * 4.0F + 1.0F) +
                 rt_powf_snf((real32_T)fabs(1.0F / ((real32_T)exp((EN + 0.05F) *
    -100.0F) + 1.0F) * ((EN + 0.05F) / 0.35F)), 7.0F) * 4.0F);

  /* '<S8>:1:26' deltal1 = abs(((EN-(0.5))/ e ) * (1 / (1 + exp(100*((EN-(0.5)))))))^lambda; */
  /* '<S8>:1:27' deltar1 = abs(((EN-(0.5))/ e ) * (1 / (1 + exp(-100*((EN-(0.5)))))))^lambda; */
  /* '<S8>:1:28' G21U = 1/(1+ (mu1 * deltal1) + (mu1 *deltar1)); */
  G21L = (EN - 0.5F) / 0.5F;
  G21U = 1.0F / ((rt_powf_snf((real32_T)fabs(1.0F / ((real32_T)exp((EN - 0.5F) *
    100.0F) + 1.0F) * G21L), 4.0F) * 4.0F + 1.0F) + rt_powf_snf((real32_T)fabs
    (1.0F / ((real32_T)exp((EN - 0.5F) * -100.0F) + 1.0F) * G21L), 4.0F) * 4.0F);

  /* '<S8>:1:29' deltal2 = abs((((EN-(0.5))- Noise)/ (e- Noise1) ) * (1 / (1 + exp(100*(((EN-(0.5))- Noise))))))^(lambda-Noise2); */
  /* '<S8>:1:30' deltar2 = abs((((EN-(0.5))+ Noise)/ (e- Noise1) ) * (1 / (1 + exp(-100*(((EN-(0.5))+ Noise))))))^(lambda-Noise2); */
  /* '<S8>:1:31' G21L = 1/(1+ (mu1 * deltal2) + (mu1 *deltar2)); */
  G21L = 1.0F / (((real32_T)fabs(1.0F / ((real32_T)exp(((EN - 0.5F) - 0.05F) *
    100.0F) + 1.0F) * (((EN - 0.5F) - 0.05F) / 0.35F)) * 4.0F + 1.0F) +
                 (real32_T)fabs(1.0F / ((real32_T)exp(((EN - 0.5F) + 0.05F) *
    -100.0F) + 1.0F) * (((EN - 0.5F) + 0.05F) / 0.35F)) * 4.0F);

  /* '<S8>:1:34' deltal1 = abs(((EN-(1))/ e ) * (1 / (1 + exp(100*((EN-(1)))))))^lambda; */
  /* '<S8>:1:35' deltar1 = abs(((EN-(1))/ e ) * (1 / (1 + exp(-100*((EN-(1)))))))^lambda; */
  /* '<S8>:1:36' G31U = 1/(1+ (mu1 * deltal1) + (mu1 *deltar1)); */
  G12L = (EN - 1.0F) / 0.5F;
  G31U = 1.0F / ((rt_powf_snf((real32_T)fabs(1.0F / ((real32_T)exp((EN - 1.0F) *
    100.0F) + 1.0F) * G12L), 4.0F) * 4.0F + 1.0F) + rt_powf_snf((real32_T)fabs
    (1.0F / ((real32_T)exp((EN - 1.0F) * -100.0F) + 1.0F) * G12L), 4.0F) * 4.0F);

  /* '<S8>:1:37' deltal2 = abs((((EN-(1))- Noise)/ (e- Noise1) ) * (1 / (1 + exp(100*(((EN-(1))- Noise))))))^(lambda-Noise2); */
  /* '<S8>:1:38' deltar2 = abs((((EN-(1))+ Noise)/ (e- Noise1) ) * (1 / (1 + exp(-100*(((EN-(1))+ Noise))))))^(lambda-Noise2); */
  /* '<S8>:1:39' G31L = 1/(1+ (mu1 * deltal2) + (mu1 *deltar2)); */
  EN = 1.0F / (((real32_T)fabs(1.0F / ((real32_T)exp(((EN - 1.0F) - 0.05F) *
    100.0F) + 1.0F) * (((EN - 1.0F) - 0.05F) / 0.35F)) * 4.0F + 1.0F) +
               (real32_T)fabs(1.0F / ((real32_T)exp(((EN - 1.0F) + 0.05F) *
    -100.0F) + 1.0F) * (((EN - 1.0F) + 0.05F) / 0.35F)) * 4.0F);

  /* '<S8>:1:48' deltal1 = abs(((DEN-(0))/ e ) * (1 / (1 + exp(100*((DEN-(0)))))))^lambda; */
  /* '<S8>:1:49' deltar1 = abs(((DEN-(0))/ e ) * (1 / (1 + exp(-100*((DEN-(0)))))))^lambda; */
  /* '<S8>:1:50' G12U = 1/(1+ (mu1 * deltal1) + (mu1 *deltar1)); */
  G12U = 1.0F / ((rt_powf_snf((real32_T)fabs(1.0F / ((real32_T)exp(100.0F * DEN)
    + 1.0F) * (DEN / 0.5F)), 4.0F) * 4.0F + 1.0F) + rt_powf_snf((real32_T)fabs
    (1.0F / ((real32_T)exp(-100.0F * DEN) + 1.0F) * (DEN / 0.5F)), 4.0F) * 4.0F);

  /* '<S8>:1:51' deltal2 = abs((((DEN-(0))- Noise)/ (e- Noise1) ) * (1 / (1 + exp(100*(((DEN-(0))- Noise))))))^(lambda-Noise2); */
  /* '<S8>:1:52' deltar2 = abs((((DEN-(0))+ Noise)/ (e- Noise1) ) * (1 / (1 + exp(-100*(((DEN-(0))+ Noise))))))^(lambda-Noise2); */
  /* '<S8>:1:53' G12L = 1/(1+ (mu1 * deltal2) + (mu1 *deltar2)); */
  G12L = 1.0F / (((real32_T)fabs(1.0F / ((real32_T)exp((DEN - 0.05F) * 100.0F) +
    1.0F) * ((DEN - 0.05F) / 0.35F)) * 4.0F + 1.0F) + (real32_T)fabs(1.0F /
    ((real32_T)exp((DEN + 0.05F) * -100.0F) + 1.0F) * ((DEN + 0.05F) / 0.35F)) *
                 4.0F);

  /* '<S8>:1:57' deltal1 = abs(((DEN-(0.5))/ e ) * (1 / (1 + exp(100*((DEN-(0.5)))))))^lambda; */
  /* '<S8>:1:58' deltar1 = abs(((DEN-(0.5))/ e ) * (1 / (1 + exp(-100*((DEN-(0.5)))))))^lambda; */
  /* '<S8>:1:59' G22U = 1/(1+ (mu1 * deltal1) + (mu1 *deltar1)); */
  /* '<S8>:1:60' deltal2 = abs((((DEN-(0.5))- Noise)/ (e- Noise1) ) * (1 / (1 + exp(100*(((DEN-(0.5))- Noise))))))^(lambda-Noise2); */
  /* '<S8>:1:61' deltar2 = abs((((DEN-(0.5))+ Noise)/ (e- Noise1) ) * (1 / (1 + exp(-100*(((DEN-(0.5))+ Noise))))))^(lambda-Noise2); */
  /* '<S8>:1:62' G22L = 1/(1+ (mu1 * deltal2) + (mu1 *deltar2)); */
  /* '<S8>:1:65' deltal1 = abs(((DEN-(1))/ e ) * (1 / (1 + exp(100*((DEN-(1)))))))^lambda; */
  /* '<S8>:1:66' deltar1 = abs(((DEN-(1))/ e ) * (1 / (1 + exp(-100*((DEN-(1)))))))^lambda; */
  /* '<S8>:1:67' G32U = 1/(1+ (mu1 * deltal1) + (mu1 *deltar1)); */
  G32L = (DEN - 1.0F) / 0.5F;
  G32U = 1.0F / ((rt_powf_snf((real32_T)fabs(1.0F / ((real32_T)exp((DEN - 1.0F) *
    100.0F) + 1.0F) * G32L), 4.0F) * 4.0F + 1.0F) + rt_powf_snf((real32_T)fabs
    (1.0F / ((real32_T)exp((DEN - 1.0F) * -100.0F) + 1.0F) * G32L), 4.0F) * 4.0F);

  /* '<S8>:1:68' deltal2 = abs((((DEN-(1))- Noise)/ (e- Noise1) ) * (1 / (1 + exp(100*(((DEN-(1))- Noise))))))^(lambda-Noise2); */
  /* '<S8>:1:69' deltar2 = abs((((DEN-(1))+ Noise)/ (e- Noise1) ) * (1 / (1 + exp(-100*(((DEN-(1))+ Noise))))))^(lambda-Noise2); */
  /* '<S8>:1:70' G32L = 1/(1+ (mu1 * deltal2) + (mu1 *deltar2)); */
  G32L = 1.0F / (((real32_T)fabs(1.0F / ((real32_T)exp(((DEN - 1.0F) - 0.05F) *
    100.0F) + 1.0F) * (((DEN - 1.0F) - 0.05F) / 0.35F)) * 4.0F + 1.0F) +
                 (real32_T)fabs(1.0F / ((real32_T)exp(((DEN - 1.0F) + 0.05F) *
    -100.0F) + 1.0F) * (((DEN - 1.0F) + 0.05F) / 0.35F)) * 4.0F);

  /* '<S8>:1:75' C1= -.9; */
  /* '<S8>:1:76' C2= -.7; */
  /* '<S8>:1:77' C3 = 0; */
  /* '<S8>:1:78' C4 = 0.7; */
  /* '<S8>:1:79' C5 = .9; */
  /* '<S8>:1:85' R1U = G31U; */
  /* '<S8>:1:86' R2U = G11U; */
  /* '<S8>:1:87' R3U = G21U; */
  /* '<S8>:1:88' R4U = 1/(((1-G21U)/G21U) + ((1-G32U)/G32U)) ; */
  RNU = (1.0F - G21U) / G21U;
  DEN = 1.0F / (RNU + (1.0F - G32U) / G32U);

  /* '<S8>:1:89' R5U = 1/(((1-G21U)/G21U) + ((1-G12U)/G12U)) ; */
  G12U = 1.0F / (RNU + (1.0F - G12U) / G12U);

  /* '<S8>:1:92' R1L = G31L; */
  /* '<S8>:1:93' R2L = G11L; */
  /* '<S8>:1:94' R3L = G21L; */
  /* '<S8>:1:95' R4L = 1/(((1-G21L)/G21L) + ((1-G32L)/G32L)) ; */
  G32U = (1.0F - G21L) / G21L;
  G32L = 1.0F / (G32U + (1.0F - G32L) / G32L);

  /* '<S8>:1:96' R5L = 1/(((1-G21L)/G21L) + ((1-G12L)/G12L)) ; */
  G12L = 1.0F / (G32U + (1.0F - G12L) / G12L);

  /* '<S8>:1:100' RNU = (R1U + R2U + R3U + R4U + R5U); */
  RNU = (((G31U + G11U) + G21U) + DEN) + G12U;

  /* '<S8>:1:102' R1UN = R1U/ RNU ; */
  /* '<S8>:1:103' R2UN = R2U/ RNU ; */
  /* '<S8>:1:104' R3UN = R3U/ RNU ; */
  /* '<S8>:1:105' R4UN = R4U/ RNU ; */
  /* '<S8>:1:106' R5UN = R5U/ RNU ; */
  /* '<S8>:1:109' RNL = (R1L + R2L + R3L + R4L + R5L); */
  G32U = (((EN + G11L) + G21L) + G32L) + G12L;

  /* '<S8>:1:112' R1LN = R1L/ RNL ; */
  /* '<S8>:1:113' R2LN = R2L/ RNL ; */
  /* '<S8>:1:114' R3LN = R3L/ RNL ; */
  /* '<S8>:1:115' R4LN = R4L/ RNL ; */
  /* '<S8>:1:116' R5LN = R5L/ RNL ; */
  /* '<S8>:1:122' ConU = (R1UN * C5) + (R2UN * C1) +(R3UN * C3) +(R4UN * C2) +(R5UN * C4) ; */
  G11U = (((G31U / RNU * 0.9F + G11U / RNU * -0.9F) + G21U / RNU * 0.0F) + DEN /
          RNU * -0.7F) + G12U / RNU * 0.7F;

  /* '<S8>:1:125' ConL = (R1LN * C5) + (R2LN * C1) +(R3LN * C3) +(R4LN * C2) +(R5LN * C4) ; */
  /* '<S8>:1:129' Con = (ConU + ConL)/ 2; */
  /* '<S8>:1:131' y1 = ConU; */
  rtb_y1 = G11U;

  /* Trigonometry: '<S9>/Trigonometric Function' */
  /* '<S8>:1:132' y = Con; */
  rtb_TrigonometricFunction_o1 = (real32_T)sin(rtu_states_estim->yaw);
  rtb_TrigonometricFunction_o2 = (real32_T)cos(rtu_states_estim->yaw);

  /* Sum: '<S9>/Sum17' */
  G31U = rtu_ReferenceValueServerBus->pos_ref[0] - rtu_states_estim->X;
  G12U = rtu_ReferenceValueServerBus->pos_ref[1] - rtu_states_estim->Y;

  /* Product: '<S9>/Product' incorporates:
   *  SignalConversion: '<S9>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S9>/ConcatBufferAtVector ConcatenateIn1'
   */
  RNU = rtb_TrigonometricFunction_o2 * G31U + rtb_TrigonometricFunction_o1 *
    G12U;

  /* Saturate: '<S9>/Saturation' */
  if (RNU > 3.0F) {
    RNU = 3.0F;
  } else {
    if (RNU < (-3.0F)) {
      RNU = (-3.0F);
    }
  }

  /* Sum: '<S9>/Sum18' incorporates:
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   */
  DEN = (-0.24F) * RNU + 0.1F * rtu_states_estim->dx;

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  G21U = flightController_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* Product: '<S9>/Product' incorporates:
   *  Gain: '<S9>/Gain'
   *  SignalConversion: '<S9>/ConcatBufferAtVector Concatenate1In2'
   */
  RNU = (-1.0F) * rtb_TrigonometricFunction_o1 * G31U +
    rtb_TrigonometricFunction_o2 * G12U;

  /* Saturate: '<S9>/Saturation' */
  if (RNU > 3.0F) {
    RNU = 3.0F;
  } else {
    if (RNU < (-3.0F)) {
      RNU = (-3.0F);
    }
  }

  /* Sum: '<S9>/Sum18' incorporates:
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   */
  G31U = 0.24F * RNU + (-0.1F) * rtu_states_estim->dy;

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  G12U = flightController_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* Sum: '<S4>/Sum19' */
  RNU = DEN - rtu_states_estim->pitch;
  rtb_pitchrollerror_idx_1 = G31U - rtu_states_estim->roll;

  /* Sum: '<S2>/Sum4' incorporates:
   *  Constant: '<S2>/w0'
   *  Gain: '<S2>/Gain2'
   *  MATLAB Function: '<S2>/MATLAB Function'
   */
  EN = (((((EN / G32U * 0.9F + G11L / G32U * -0.9F) + G21L / G32U * 0.0F) + G32L
          / G32U * -0.7F) + G12L / G32U * 0.7F) + G11U) / 2.0F * (-1.0F) +
    (-0.61803F);

  /* Saturate: '<S2>/SaturationThrust' */
  if (EN > 1.20204329F) {
    EN = 1.20204329F;
  } else {
    if (EN < (-1.20204329F)) {
      EN = (-1.20204329F);
    }
  }

  /* SignalConversion: '<S3>/TmpSignal ConversionAtProductInport2' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Gain: '<S10>/D_yaw'
   *  Gain: '<S10>/P_yaw'
   *  Gain: '<S4>/D_pr'
   *  Gain: '<S4>/I_pr'
   *  Gain: '<S4>/P_pr'
   *  Sum: '<S10>/Sum1'
   *  Sum: '<S10>/Sum2'
   *  Sum: '<S4>/Sum16'
   */
  G11U = (rtu_ReferenceValueServerBus->orient_ref[0] - rtu_states_estim->yaw) *
    0.004F - 0.0012F * rtu_states_estim->r;
  G11L = (0.013F * RNU + 0.01F *
          flightController_DW.DiscreteTimeIntegrator_DSTATE[0]) - 0.002F *
    rtu_states_estim->q;
  G21L = (0.01F * rtb_pitchrollerror_idx_1 + 0.01F *
          flightController_DW.DiscreteTimeIntegrator_DSTATE[1]) - 0.0028F *
    rtu_states_estim->p;
  for (i = 0; i < 4; i++) {
    /* Product: '<S3>/Product' incorporates:
     *  Constant: '<S3>/TorqueTotalThrustToThrustPerMotor'
     *  Saturate: '<S2>/SaturationThrust'
     *  SignalConversion: '<S3>/TmpSignal ConversionAtProductInport2'
     */
    G12L = rtCP_TorqueTotalThrustToThrustPerMotor_Value[i + 12] * G21L +
      (rtCP_TorqueTotalThrustToThrustPerMotor_Value[i + 8] * G11L +
       (rtCP_TorqueTotalThrustToThrustPerMotor_Value[i + 4] * G11U +
        rtCP_TorqueTotalThrustToThrustPerMotor_Value[i] * EN));

    /* Saturate: '<S7>/Saturation5' incorporates:
     *  Gain: '<S7>/ThrustToMotorCommand'
     */
    G12L *= (-1530.72681F);
    if (G12L > 500.0F) {
      G12L = 500.0F;
    } else {
      if (G12L < 10.0F) {
        G12L = 10.0F;
      }
    }

    /* End of Saturate: '<S7>/Saturation5' */

    /* Gain: '<S7>/MotorDirections' */
    rty_motors_refout[i] = rtCP_MotorDirections_Gain[i] * G12L;
  }

  /* SignalConversion: '<Root>/TmpSignal ConversionAtpose_refoutInport1' incorporates:
   *  SignalConversion: '<S1>/ReferenceValueServerBus_BusSelector'
   */
  rty_pose_refout[0] = rtu_ReferenceValueServerBus->pos_ref[0];
  rty_pose_refout[3] = rtu_ReferenceValueServerBus->orient_ref[0];
  rty_pose_refout[1] = rtu_ReferenceValueServerBus->pos_ref[1];
  rty_pose_refout[4] = rtu_ReferenceValueServerBus->orient_ref[1];
  rty_pose_refout[2] = rtu_ReferenceValueServerBus->pos_ref[2];
  rty_pose_refout[5] = rtu_ReferenceValueServerBus->orient_ref[2];
  rty_pose_refout[6] = DEN;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S4>/Delay'
   *  Gain: '<S4>/antiWU_Gain'
   *  Sum: '<S4>/Add'
   */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] += (RNU - 0.001F *
    flightController_DW.Delay_DSTATE[0]) * 0.005F;
  if (flightController_DW.DiscreteTimeIntegrator_DSTATE[0] >= 2.0F) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = 2.0F;
  } else {
    if (flightController_DW.DiscreteTimeIntegrator_DSTATE[0] <= (-2.0F)) {
      flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = (-2.0F);
    }
  }

  /* Update for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[0] = G21U;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtpose_refoutInport1' */
  rty_pose_refout[7] = G31U;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S4>/Delay'
   *  Gain: '<S4>/antiWU_Gain'
   *  Sum: '<S4>/Add'
   */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] +=
    (rtb_pitchrollerror_idx_1 - 0.001F * flightController_DW.Delay_DSTATE[1]) *
    0.005F;
  if (flightController_DW.DiscreteTimeIntegrator_DSTATE[1] >= 2.0F) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = 2.0F;
  } else {
    if (flightController_DW.DiscreteTimeIntegrator_DSTATE[1] <= (-2.0F)) {
      flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = (-2.0F);
    }
  }

  /* Update for Delay: '<S4>/Delay' */
  flightController_DW.Delay_DSTATE[1] = G12U;
}

/* Model initialize function */
void flightController_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_flightController_T *const flightController_M =
    &(flightController_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(flightController_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)&flightController_DW, 0,
                sizeof(DW_flightController_f_T));
}

/*
 * File: flightControlSystem_private.h
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

#ifndef RTW_HEADER_flightControlSystem_private_h_
#define RTW_HEADER_flightControlSystem_private_h_
#include "rtwtypes.h"
#include "flightControlSystem.h"

extern void flightControlSystem_Geofencingerror(uint8_T *rty_Out1,
  P_Geofencingerror_flightControlSystem_T *localP);
extern void flightControlSystem_Logging(const statesEstim_t
  *rtu_states_estim_Inport_3, const CommandBus
  *rtu_ReferenceValueServerBus_Inport_4, const SensorsBus *rtu_Sensors_Inport_5,
  real32_T rtu_sensordata_datin_Inport_6, uint32_T
  rtu_sensordata_datin_Inport_6_a, B_Logging_flightControlSystem_T *localB);
extern void flightControlSystem_FlightControlSystem_Init(uint8_T *rty_Flag,
  P_FlightControlSystem_flightControlSystem_T *localP);
extern void flightControlSystem_FlightControlSystem
  (RT_MODEL_flightControlSystem_T * const flightControlSystem_M, const
   CommandBus *rtu_ReferenceValueServerCmds, const SensorsBus *rtu_Sensors,
   real32_T rty_motorCmds[4], uint8_T *rty_Flag,
   B_FlightControlSystem_flightControlSystem_T *localB,
   P_FlightControlSystem_flightControlSystem_T *localP);

#endif                                 /* RTW_HEADER_flightControlSystem_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

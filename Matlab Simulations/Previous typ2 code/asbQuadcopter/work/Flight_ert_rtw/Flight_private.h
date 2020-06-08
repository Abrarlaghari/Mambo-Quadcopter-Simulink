/*
 * File: Flight_private.h
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

#ifndef RTW_HEADER_Flight_private_h_
#define RTW_HEADER_Flight_private_h_
#include "rtwtypes.h"
#include "Flight.h"

extern void Flight_Geofencingerror(uint8_T *rty_Out1, P_Geofencingerror_Flight_T
  *localP);
extern void Flight_Logging(const statesEstim_t *rtu_states_estim_Inport_3, const
  CommandBus *rtu_ReferenceValueServerBus_Inport_4, const SensorsBus
  *rtu_Sensors_Inport_5, real32_T rtu_sensordata_datin_Inport_6, uint32_T
  rtu_sensordata_datin_Inport_6_a, B_Logging_Flight_T *localB);
extern void Flight_FlightControlSystem_Init(uint8_T *rty_Flag,
  B_FlightControlSystem_Flight_T *localB, DW_FlightControlSystem_Flight_T
  *localDW, P_FlightControlSystem_Flight_T *localP);
extern void Flight_FlightControlSystem(RT_MODEL_Flight_T * const Flight_M, const
  CommandBus *rtu_ReferenceValueServerCmds, const SensorsBus *rtu_Sensors,
  real32_T rty_motorCmds[4], uint8_T *rty_Flag, B_FlightControlSystem_Flight_T
  *localB, DW_FlightControlSystem_Flight_T *localDW,
  P_FlightControlSystem_Flight_T *localP);

#endif                                 /* RTW_HEADER_Flight_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

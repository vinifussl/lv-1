/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: imu_private.h
 *
 * Code generated for Simulink model 'imu'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Apr 30 20:39:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_imu_private_h_
#define RTW_HEADER_imu_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void gy521_read_Start_wrapper(real_T *xD);
SFB_EXTERN_C void gy521_read_Outputs_wrapper(real_T *gx,
  real_T *gy,
  real_T *gz,
  const real_T *xD);
SFB_EXTERN_C void gy521_read_Update_wrapper(real_T *gx,
  real_T *gy,
  real_T *gz,
  real_T *xD);
SFB_EXTERN_C void gy521_read_Terminate_wrapper(real_T *xD);

#undef SFB_EXTERN_C

extern real_T rt_roundd_snf(real_T u);

#endif                                 /* RTW_HEADER_imu_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

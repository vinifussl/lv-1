/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pwm_test_types.h
 *
 * Code generated for Simulink model 'pwm_test'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu May  5 23:12:24 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pwm_test_types_h_
#define RTW_HEADER_pwm_test_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Model Code Variants */
#ifndef struct_tag_hWmK6HY8Mmd26WUBxd61gD
#define struct_tag_hWmK6HY8Mmd26WUBxd61gD

struct tag_hWmK6HY8Mmd26WUBxd61gD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /* struct_tag_hWmK6HY8Mmd26WUBxd61gD */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_hWmK6HY8Mmd26WUBxd61gD codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

/* Custom Type definition for MATLABSystem: '<Root>/PWM' */
#include "MW_SVD.h"
#ifndef struct_tag_g1WX34VPn8QzVKQriB4HN
#define struct_tag_g1WX34VPn8QzVKQriB4HN

struct tag_g1WX34VPn8QzVKQriB4HN
{
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_g1WX34VPn8QzVKQriB4HN */

#ifndef typedef_g_matlabshared_ioclient_perip_T
#define typedef_g_matlabshared_ioclient_perip_T

typedef struct tag_g1WX34VPn8QzVKQriB4HN g_matlabshared_ioclient_perip_T;

#endif                             /* typedef_g_matlabshared_ioclient_perip_T */

#ifndef struct_tag_4eDVzK5FiryyCjvjjvrZGB
#define struct_tag_4eDVzK5FiryyCjvjjvrZGB

struct tag_4eDVzK5FiryyCjvjjvrZGB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  g_matlabshared_ioclient_perip_T PWMDriverObj;
};

#endif                                 /* struct_tag_4eDVzK5FiryyCjvjjvrZGB */

#ifndef typedef_codertarget_arduinobase_int_n_T
#define typedef_codertarget_arduinobase_int_n_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_int_n_T;

#endif                             /* typedef_codertarget_arduinobase_int_n_T */

/* Parameters (default storage) */
typedef struct P_pwm_test_T_ P_pwm_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_pwm_test_T RT_MODEL_pwm_test_T;

#endif                                 /* RTW_HEADER_pwm_test_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

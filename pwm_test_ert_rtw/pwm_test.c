/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pwm_test.c
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

#include "pwm_test.h"
#include "pwm_test_types.h"
#include "rtwtypes.h"
#include "pwm_test_private.h"

/* Block signals (default storage) */
B_pwm_test_T pwm_test_B;

/* Block states (default storage) */
DW_pwm_test_T pwm_test_DW;

/* Real-time model */
static RT_MODEL_pwm_test_T pwm_test_M_;
RT_MODEL_pwm_test_T *const pwm_test_M = &pwm_test_M_;

/* Model step function */
void pwm_test_step(void)
{
  codertarget_arduinobase_int_n_T *obj;
  real_T y;

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  Constant: '<Root>/Constant'
   */
  obj = &pwm_test_DW.obj_o;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2UL);
  if (pwm_test_P.Constant_Value <= 255.0) {
    y = pwm_test_P.Constant_Value;
  } else {
    y = 255.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  MW_PWM_SetDutyCycle(pwm_test_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, y);

  /* End of MATLABSystem: '<Root>/PWM' */

  /* MATLABSystem: '<Root>/Input Capture' */
  computeFrequencyAndDutycycle(48, &pwm_test_B.InputCapture_o1,
    &pwm_test_B.InputCapture_o2);

  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  pwm_test_M->Timing.taskTime0 =
    ((time_T)(++pwm_test_M->Timing.clockTick0)) * pwm_test_M->Timing.stepSize0;
}

/* Model initialize function */
void pwm_test_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(pwm_test_M, -1);
  pwm_test_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  pwm_test_M->Sizes.checksums[0] = (2037412650U);
  pwm_test_M->Sizes.checksums[1] = (587466441U);
  pwm_test_M->Sizes.checksums[2] = (3872849101U);
  pwm_test_M->Sizes.checksums[3] = (2905268639U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    pwm_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pwm_test_M->extModeInfo,
      &pwm_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pwm_test_M->extModeInfo, pwm_test_M->Sizes.checksums);
    rteiSetTPtr(pwm_test_M->extModeInfo, rtmGetTPtr(pwm_test_M));
  }

  {
    codertarget_arduinobase_int_n_T *obj;

    /* Start for MATLABSystem: '<Root>/PWM' */
    pwm_test_DW.obj_o.matlabCodegenIsDeleted = true;
    pwm_test_DW.obj_o.isInitialized = 0L;
    pwm_test_DW.obj_o.matlabCodegenIsDeleted = false;
    obj = &pwm_test_DW.obj_o;
    pwm_test_DW.obj_o.isSetupComplete = false;
    pwm_test_DW.obj_o.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(2UL, 0.0, 0.0);
    pwm_test_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Input Capture' */
    pwm_test_DW.obj.matlabCodegenIsDeleted = false;
    pwm_test_DW.obj.isInitialized = 1L;
    setupInputCapture(48);
    pwm_test_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void pwm_test_terminate(void)
{
  codertarget_arduinobase_int_n_T *obj;

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj = &pwm_test_DW.obj_o;
  if (!pwm_test_DW.obj_o.matlabCodegenIsDeleted) {
    pwm_test_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((pwm_test_DW.obj_o.isInitialized == 1L) &&
        pwm_test_DW.obj_o.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2UL);
      MW_PWM_SetDutyCycle(pwm_test_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2UL);
      MW_PWM_Close(pwm_test_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Input Capture' */
  if (!pwm_test_DW.obj.matlabCodegenIsDeleted) {
    pwm_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((pwm_test_DW.obj.isInitialized == 1L) && pwm_test_DW.obj.isSetupComplete)
    {
      teardownInputCapture(48);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Input Capture' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

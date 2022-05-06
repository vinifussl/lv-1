/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: baroTest.c
 *
 * Code generated for Simulink model 'baroTest'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Apr 25 21:16:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "baroTest.h"
#include "rtwtypes.h"
#include "baroTest_private.h"
#include <math.h>

/* Block states (default storage) */
DW_baroTest_T baroTest_DW;

/* Real-time model */
static RT_MODEL_baroTest_T baroTest_M_;
RT_MODEL_baroTest_T *const baroTest_M = &baroTest_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void baroTest_step(void)
{
  real_T rtb_PulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (baroTest_DW.clockTickCounter <
                        baroTest_P.PulseGenerator_Duty) &&
    (baroTest_DW.clockTickCounter >= 0L) ? baroTest_P.PulseGenerator_Amp : 0.0;
  if (baroTest_DW.clockTickCounter >= baroTest_P.PulseGenerator_Period - 1.0) {
    baroTest_DW.clockTickCounter = 0L;
  } else {
    baroTest_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output' */
  rtb_PulseGenerator = rt_roundd_snf(rtb_PulseGenerator);
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      tmp = (uint8_T)rtb_PulseGenerator;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */
}

/* Model initialize function */
void baroTest_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Digital Output' */
  baroTest_DW.obj.matlabCodegenIsDeleted = false;
  baroTest_DW.obj.isInitialized = 1L;
  digitalIOSetup(13, 1);
  baroTest_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void baroTest_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!baroTest_DW.obj.matlabCodegenIsDeleted) {
    baroTest_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

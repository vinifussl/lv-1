/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: imu.c
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

#include "imu.h"
#include "rtwtypes.h"
#include "imu_private.h"
#include <math.h>

/* Block signals (default storage) */
B_imu_T imu_B;

/* Block states (default storage) */
DW_imu_T imu_DW;

/* Real-time model */
static RT_MODEL_imu_T imu_M_;
RT_MODEL_imu_T *const imu_M = &imu_M_;
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
void imu_step(void)
{
  real_T rtb_PulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (imu_DW.clockTickCounter < imu_P.PulseGenerator_Duty) &&
    (imu_DW.clockTickCounter >= 0L) ? imu_P.PulseGenerator_Amp : 0.0;
  if (imu_DW.clockTickCounter >= imu_P.PulseGenerator_Period - 1.0) {
    imu_DW.clockTickCounter = 0L;
  } else {
    imu_DW.clockTickCounter++;
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

  /* S-Function (gy521_read): '<Root>/S-Function Builder' */
  gy521_read_Outputs_wrapper(&imu_B.gx, &imu_B.gy, &imu_B.gz,
    &imu_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (gy521_read): '<Root>/S-Function Builder' */

  /* S-Function "gy521_read_wrapper" Block: <Root>/S-Function Builder */
  gy521_read_Update_wrapper(&imu_B.gx, &imu_B.gy, &imu_B.gz,
    &imu_DW.SFunctionBuilder_DSTATE);

  {                                    /* Sample time: [0.1s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  imu_M->Timing.taskTime0 =
    ((time_T)(++imu_M->Timing.clockTick0)) * imu_M->Timing.stepSize0;
}

/* Model initialize function */
void imu_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(imu_M, -1);
  imu_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  imu_M->Sizes.checksums[0] = (4064768413U);
  imu_M->Sizes.checksums[1] = (3606759690U);
  imu_M->Sizes.checksums[2] = (3135256943U);
  imu_M->Sizes.checksums[3] = (83870444U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    imu_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(imu_M->extModeInfo,
      &imu_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(imu_M->extModeInfo, imu_M->Sizes.checksums);
    rteiSetTPtr(imu_M->extModeInfo, rtmGetTPtr(imu_M));
  }

  /* Start for S-Function (gy521_read): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  gy521_read_Start_wrapper(&imu_DW.SFunctionBuilder_DSTATE);

  /* InitializeConditions for S-Function (gy521_read): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        imu_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  imu_DW.obj.matlabCodegenIsDeleted = false;
  imu_DW.obj.isInitialized = 1L;
  digitalIOSetup(13, 1);
  imu_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void imu_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!imu_DW.obj.matlabCodegenIsDeleted) {
    imu_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

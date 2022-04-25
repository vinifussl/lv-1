/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: baroTest.c
 *
 * Code generated for Simulink model 'baroTest'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Apr 22 08:59:31 2022
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

/* Block signals (default storage) */
B_baroTest_T baroTest_B;

/* Block states (default storage) */
DW_baroTest_T baroTest_DW;

/* Real-time model */
static RT_MODEL_baroTest_T baroTest_M_;
RT_MODEL_baroTest_T *const baroTest_M = &baroTest_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void baroTest_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(baroTest_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (baroTest_M->Timing.TaskCounters.TID[1])++;
  if ((baroTest_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    baroTest_M->Timing.TaskCounters.TID[1] = 0;
  }
}

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

/* Model step function for TID0 */
void baroTest_step0(void)              /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (abc): '<Root>/S-Function Builder' */
  abc_Outputs_wrapper(&baroTest_B.P, &baroTest_B.T,
                      &baroTest_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (abc): '<Root>/S-Function Builder' */

  /* S-Function "abc_wrapper" Block: <Root>/S-Function Builder */
  abc_Update_wrapper(&baroTest_B.P, &baroTest_B.T,
                     &baroTest_DW.SFunctionBuilder_DSTATE);

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  baroTest_M->Timing.taskTime0 =
    ((time_T)(++baroTest_M->Timing.clockTick0)) * baroTest_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void baroTest_step1(void)              /* Sample time: [0.1s, 0.0s] */
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

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  baroTest_M->Timing.clockTick1++;
}

/* Model initialize function */
void baroTest_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(baroTest_M, -1);
  baroTest_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  baroTest_M->Sizes.checksums[0] = (4181767603U);
  baroTest_M->Sizes.checksums[1] = (997391310U);
  baroTest_M->Sizes.checksums[2] = (948423231U);
  baroTest_M->Sizes.checksums[3] = (2221192789U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    baroTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(baroTest_M->extModeInfo,
      &baroTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(baroTest_M->extModeInfo, baroTest_M->Sizes.checksums);
    rteiSetTPtr(baroTest_M->extModeInfo, rtmGetTPtr(baroTest_M));
  }

  /* Start for S-Function (abc): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  abc_Start_wrapper(&baroTest_DW.SFunctionBuilder_DSTATE);

  /* InitializeConditions for S-Function (abc): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        baroTest_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }

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

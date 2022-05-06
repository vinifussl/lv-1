/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: barometric_sensors.c
 *
 * Code generated for Simulink model 'barometric_sensors'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu May  5 11:49:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "barometric_sensors.h"
#include "barometric_sensors_types.h"
#include "rtwtypes.h"
#include "barometric_sensors_private.h"
#include <math.h>
#include <string.h>

/* Block signals (default storage) */
B_barometric_sensors_T barometric_sensors_B;

/* Block states (default storage) */
DW_barometric_sensors_T barometric_sensors_DW;

/* Real-time model */
static RT_MODEL_barometric_sensors_T barometric_sensors_M_;
RT_MODEL_barometric_sensors_T *const barometric_sensors_M =
  &barometric_sensors_M_;

/* Forward declaration for local functions */
static void barome_MedianFilterCG_resetImpl(c_dsp_internal_MedianFilterCG_T *obj);
static void b_MedianFilterCG_trickleDownMax(c_dsp_internal_MedianFilterCG_T *obj,
  real_T i);
static void b_MedianFilterCG_trickleDownMin(c_dsp_internal_MedianFilterCG_T *obj,
  real_T i);
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

static void barome_MedianFilterCG_resetImpl(c_dsp_internal_MedianFilterCG_T *obj)
{
  real_T cnt1;
  real_T cnt2;
  int16_T i;
  memset(&obj->pBuf[0], 0, 12U * sizeof(real_T));
  memset(&obj->pPos[0], 0, 12U * sizeof(real_T));
  memset(&obj->pHeap[0], 0, 12U * sizeof(real_T));
  obj->pWinLen = 12.0;
  obj->pIdx = obj->pWinLen;
  obj->pMidHeap = ceil((obj->pWinLen + 1.0) / 2.0);
  cnt1 = (obj->pWinLen - 1.0) / 2.0;
  if (cnt1 < 0.0) {
    obj->pMinHeapLength = ceil(cnt1);
  } else {
    obj->pMinHeapLength = floor(cnt1);
  }

  cnt1 = obj->pWinLen / 2.0;
  if (cnt1 < 0.0) {
    obj->pMaxHeapLength = ceil(cnt1);
  } else {
    obj->pMaxHeapLength = floor(cnt1);
  }

  cnt1 = 1.0;
  cnt2 = obj->pWinLen;
  for (i = 0; i < 12; i++) {
    if ((int16_T)fmod(-(real_T)i + 12.0, 2.0) == 0) {
      obj->pPos[11 - i] = cnt1;
      cnt1++;
    } else {
      obj->pPos[11 - i] = cnt2;
      cnt2--;
    }

    obj->pHeap[(int16_T)obj->pPos[11 - i] - 1] = -(real_T)i + 12.0;
  }
}

static void b_MedianFilterCG_trickleDownMax(c_dsp_internal_MedianFilterCG_T *obj,
  real_T i)
{
  real_T ind2;
  real_T tmp;
  real_T u;
  real_T u_tmp;
  boolean_T exitg1;
  exitg1 = false;
  while ((!exitg1) && (i >= -obj->pMaxHeapLength)) {
    if ((i < -1.0) && (i > -obj->pMaxHeapLength) && (obj->pBuf[(int16_T)
         obj->pHeap[(int16_T)(i + obj->pMidHeap) - 1] - 1] < obj->pBuf[(int16_T)
         obj->pHeap[(int16_T)((i - 1.0) + obj->pMidHeap) - 1] - 1])) {
      i--;
    }

    u_tmp = i / 2.0;
    if (u_tmp < 0.0) {
      u = ceil(u_tmp);
    } else {
      u = floor(u_tmp);
    }

    ind2 = i + obj->pMidHeap;
    tmp = obj->pHeap[(int16_T)ind2 - 1];
    if (!(obj->pBuf[(int16_T)obj->pHeap[(int16_T)(u + obj->pMidHeap) - 1] - 1] <
          obj->pBuf[(int16_T)tmp - 1])) {
      exitg1 = true;
    } else {
      if (u_tmp < 0.0) {
        u = ceil(u_tmp);
      } else {
        u = floor(u_tmp);
      }

      u_tmp = u + obj->pMidHeap;
      u = obj->pHeap[(int16_T)u_tmp - 1];
      obj->pHeap[(int16_T)u_tmp - 1] = tmp;
      obj->pHeap[(int16_T)ind2 - 1] = u;
      obj->pPos[(int16_T)obj->pHeap[(int16_T)u_tmp - 1] - 1] = u_tmp;
      obj->pPos[(int16_T)obj->pHeap[(int16_T)ind2 - 1] - 1] = ind2;
      i *= 2.0;
    }
  }
}

static void b_MedianFilterCG_trickleDownMin(c_dsp_internal_MedianFilterCG_T *obj,
  real_T i)
{
  real_T ind1;
  real_T temp;
  real_T tmp;
  real_T u_tmp;
  boolean_T exitg1;
  exitg1 = false;
  while ((!exitg1) && (i <= obj->pMinHeapLength)) {
    if ((i > 1.0) && (i < obj->pMinHeapLength) && (obj->pBuf[(int16_T)obj->
         pHeap[(int16_T)((i + 1.0) + obj->pMidHeap) - 1] - 1] < obj->pBuf
         [(int16_T)obj->pHeap[(int16_T)(i + obj->pMidHeap) - 1] - 1])) {
      i++;
    }

    u_tmp = i / 2.0;
    if (u_tmp < 0.0) {
      temp = ceil(u_tmp);
    } else {
      temp = floor(u_tmp);
    }

    ind1 = i + obj->pMidHeap;
    tmp = obj->pHeap[(int16_T)ind1 - 1];
    if (!(obj->pBuf[(int16_T)tmp - 1] < obj->pBuf[(int16_T)obj->pHeap[(int16_T)
          (temp + obj->pMidHeap) - 1] - 1])) {
      exitg1 = true;
    } else {
      if (u_tmp < 0.0) {
        temp = ceil(u_tmp);
      } else {
        temp = floor(u_tmp);
      }

      u_tmp = temp + obj->pMidHeap;
      obj->pHeap[(int16_T)ind1 - 1] = obj->pHeap[(int16_T)u_tmp - 1];
      obj->pHeap[(int16_T)u_tmp - 1] = tmp;
      obj->pPos[(int16_T)obj->pHeap[(int16_T)ind1 - 1] - 1] = ind1;
      obj->pPos[(int16_T)obj->pHeap[(int16_T)u_tmp - 1] - 1] = u_tmp;
      i *= 2.0;
    }
  }
}

/* Model step function */
void barometric_sensors_step(void)
{
  c_dsp_internal_MedianFilterCG_T *obj;
  real_T rtb_PulseGenerator;
  real_T u;
  uint8_T tmp;
  boolean_T exitg1;
  boolean_T flag;

  /* S-Function (baro_read): '<Root>/S-Function Builder' */
  baro_read_Outputs_wrapper(&barometric_sensors_B.SFunctionBuilder_o1,
    &barometric_sensors_B.SFunctionBuilder_o2,
    &barometric_sensors_DW.SFunctionBuilder_DSTATE);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (barometric_sensors_DW.clockTickCounter <
                        barometric_sensors_P.PulseGenerator_Duty) &&
    (barometric_sensors_DW.clockTickCounter >= 0L) ?
    barometric_sensors_P.PulseGenerator_Amp : 0.0;
  if (barometric_sensors_DW.clockTickCounter >=
      barometric_sensors_P.PulseGenerator_Period - 1.0) {
    barometric_sensors_DW.clockTickCounter = 0L;
  } else {
    barometric_sensors_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  RelationalOperator: '<Root>/GreaterThan'
   */
  if (barometric_sensors_B.SFunctionBuilder_o1 >
      barometric_sensors_P.Constant1_Value) {
    rtb_PulseGenerator = barometric_sensors_P.Constant_Value;
  }

  /* End of Switch: '<Root>/Switch' */

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

  /* MATLABSystem: '<Root>/Median Filter' */
  obj = &barometric_sensors_DW.obj.pMID;
  if (barometric_sensors_DW.obj.pMID.isInitialized != 1L) {
    barometric_sensors_DW.obj.pMID.isSetupComplete = false;
    barometric_sensors_DW.obj.pMID.isInitialized = 1L;
    barometric_sensors_DW.obj.pMID.isSetupComplete = true;
    barome_MedianFilterCG_resetImpl(&barometric_sensors_DW.obj.pMID);
  }

  rtb_PulseGenerator = barometric_sensors_DW.obj.pMID.pBuf[(int16_T)
    barometric_sensors_DW.obj.pMID.pIdx - 1];
  barometric_sensors_DW.obj.pMID.pBuf[(int16_T)
    barometric_sensors_DW.obj.pMID.pIdx - 1] =
    barometric_sensors_B.SFunctionBuilder_o1;
  barometric_sensors_B.p = barometric_sensors_DW.obj.pMID.pPos[(int16_T)
    barometric_sensors_DW.obj.pMID.pIdx - 1];
  barometric_sensors_DW.obj.pMID.pIdx++;
  if (barometric_sensors_DW.obj.pMID.pWinLen + 1.0 ==
      barometric_sensors_DW.obj.pMID.pIdx) {
    barometric_sensors_DW.obj.pMID.pIdx = 1.0;
  }

  if (barometric_sensors_B.p > barometric_sensors_DW.obj.pMID.pMidHeap) {
    if (rtb_PulseGenerator < barometric_sensors_B.SFunctionBuilder_o1) {
      b_MedianFilterCG_trickleDownMin(&barometric_sensors_DW.obj.pMID,
        (barometric_sensors_B.p - barometric_sensors_DW.obj.pMID.pMidHeap) * 2.0);
    } else {
      rtb_PulseGenerator = barometric_sensors_B.p -
        barometric_sensors_DW.obj.pMID.pMidHeap;
      exitg1 = false;
      while ((!exitg1) && (rtb_PulseGenerator > 0.0)) {
        flag = (obj->pBuf[(int16_T)obj->pHeap[(int16_T)(rtb_PulseGenerator +
                 obj->pMidHeap) - 1] - 1] < obj->pBuf[(int16_T)obj->pHeap
                [(int16_T)(floor(rtb_PulseGenerator / 2.0) + obj->pMidHeap) - 1]
                - 1]);
        if (!flag) {
          exitg1 = true;
        } else {
          u = rtb_PulseGenerator + obj->pMidHeap;
          barometric_sensors_B.ind2 = floor(rtb_PulseGenerator / 2.0) +
            obj->pMidHeap;
          barometric_sensors_B.temp = obj->pHeap[(int16_T)u - 1];
          obj->pHeap[(int16_T)u - 1] = obj->pHeap[(int16_T)
            barometric_sensors_B.ind2 - 1];
          obj->pHeap[(int16_T)barometric_sensors_B.ind2 - 1] =
            barometric_sensors_B.temp;
          obj->pPos[(int16_T)obj->pHeap[(int16_T)u - 1] - 1] = u;
          obj->pPos[(int16_T)obj->pHeap[(int16_T)barometric_sensors_B.ind2 - 1]
            - 1] = barometric_sensors_B.ind2;
          rtb_PulseGenerator = floor(rtb_PulseGenerator / 2.0);
        }
      }

      if (rtb_PulseGenerator == 0.0) {
        b_MedianFilterCG_trickleDownMax(&barometric_sensors_DW.obj.pMID, -1.0);
      }
    }
  } else if (barometric_sensors_B.p < barometric_sensors_DW.obj.pMID.pMidHeap) {
    if (barometric_sensors_B.SFunctionBuilder_o1 < rtb_PulseGenerator) {
      b_MedianFilterCG_trickleDownMax(&barometric_sensors_DW.obj.pMID,
        (barometric_sensors_B.p - barometric_sensors_DW.obj.pMID.pMidHeap) * 2.0);
    } else {
      rtb_PulseGenerator = barometric_sensors_B.p -
        barometric_sensors_DW.obj.pMID.pMidHeap;
      exitg1 = false;
      while ((!exitg1) && (rtb_PulseGenerator < 0.0)) {
        barometric_sensors_B.p = rtb_PulseGenerator / 2.0;
        if (barometric_sensors_B.p < 0.0) {
          u = ceil(barometric_sensors_B.p);
        } else {
          u = -0.0;
        }

        flag = (obj->pBuf[(int16_T)obj->pHeap[(int16_T)(u + obj->pMidHeap) - 1]
                - 1] < obj->pBuf[(int16_T)obj->pHeap[(int16_T)
                (rtb_PulseGenerator + obj->pMidHeap) - 1] - 1]);
        if (!flag) {
          exitg1 = true;
        } else {
          if (barometric_sensors_B.p < 0.0) {
            u = ceil(barometric_sensors_B.p);
          } else {
            u = -0.0;
          }

          u += obj->pMidHeap;
          barometric_sensors_B.ind2 = rtb_PulseGenerator + obj->pMidHeap;
          barometric_sensors_B.temp = obj->pHeap[(int16_T)u - 1];
          obj->pHeap[(int16_T)u - 1] = obj->pHeap[(int16_T)
            barometric_sensors_B.ind2 - 1];
          obj->pHeap[(int16_T)barometric_sensors_B.ind2 - 1] =
            barometric_sensors_B.temp;
          obj->pPos[(int16_T)obj->pHeap[(int16_T)u - 1] - 1] = u;
          obj->pPos[(int16_T)obj->pHeap[(int16_T)barometric_sensors_B.ind2 - 1]
            - 1] = barometric_sensors_B.ind2;
          if (barometric_sensors_B.p < 0.0) {
            rtb_PulseGenerator = ceil(barometric_sensors_B.p);
          } else {
            rtb_PulseGenerator = -0.0;
          }
        }
      }

      if (rtb_PulseGenerator == 0.0) {
        b_MedianFilterCG_trickleDownMin(&barometric_sensors_DW.obj.pMID, 1.0);
      }
    }
  } else {
    if (barometric_sensors_DW.obj.pMID.pMaxHeapLength != 0.0) {
      b_MedianFilterCG_trickleDownMax(&barometric_sensors_DW.obj.pMID, -1.0);
    }

    if (barometric_sensors_DW.obj.pMID.pMinHeapLength > 0.0) {
      b_MedianFilterCG_trickleDownMin(&barometric_sensors_DW.obj.pMID, 1.0);
    }
  }

  rtb_PulseGenerator = barometric_sensors_DW.obj.pMID.pBuf[(int16_T)
    barometric_sensors_DW.obj.pMID.pHeap[(int16_T)
    barometric_sensors_DW.obj.pMID.pMidHeap - 1] - 1];

  /* MATLABSystem: '<Root>/Median Filter' */
  barometric_sensors_B.MedianFilter = (barometric_sensors_DW.obj.pMID.pBuf
    [(int16_T)barometric_sensors_DW.obj.pMID.pHeap[(int16_T)
    (barometric_sensors_DW.obj.pMID.pMidHeap - 1.0) - 1] - 1] +
    rtb_PulseGenerator) / 2.0;

  /* Update for S-Function (baro_read): '<Root>/S-Function Builder' */

  /* S-Function "baro_read_wrapper" Block: <Root>/S-Function Builder */
  baro_read_Update_wrapper(&barometric_sensors_B.SFunctionBuilder_o1,
    &barometric_sensors_B.SFunctionBuilder_o2,
    &barometric_sensors_DW.SFunctionBuilder_DSTATE);

  {                                    /* Sample time: [0.1s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  barometric_sensors_M->Timing.taskTime0 =
    ((time_T)(++barometric_sensors_M->Timing.clockTick0)) *
    barometric_sensors_M->Timing.stepSize0;
}

/* Model initialize function */
void barometric_sensors_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(barometric_sensors_M, -1);
  barometric_sensors_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  barometric_sensors_M->Sizes.checksums[0] = (3956177614U);
  barometric_sensors_M->Sizes.checksums[1] = (1662447397U);
  barometric_sensors_M->Sizes.checksums[2] = (3529059359U);
  barometric_sensors_M->Sizes.checksums[3] = (1546744891U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    barometric_sensors_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(barometric_sensors_M->extModeInfo,
      &barometric_sensors_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(barometric_sensors_M->extModeInfo,
                        barometric_sensors_M->Sizes.checksums);
    rteiSetTPtr(barometric_sensors_M->extModeInfo, rtmGetTPtr
                (barometric_sensors_M));
  }

  /* Start for S-Function (baro_read): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  baro_read_Start_wrapper(&barometric_sensors_DW.SFunctionBuilder_DSTATE);

  /* InitializeConditions for S-Function (baro_read): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        barometric_sensors_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  barometric_sensors_DW.obj_h.matlabCodegenIsDeleted = false;
  barometric_sensors_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(13, 1);
  barometric_sensors_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Median Filter' */
  barometric_sensors_DW.obj.matlabCodegenIsDeleted = false;
  barometric_sensors_DW.obj.isInitialized = 1L;
  barometric_sensors_DW.obj.NumChannels = 1L;
  barometric_sensors_DW.obj.pMID.isInitialized = 0L;
  barometric_sensors_DW.obj.isSetupComplete = true;

  /* InitializeConditions for MATLABSystem: '<Root>/Median Filter' */
  if (barometric_sensors_DW.obj.pMID.isInitialized == 1L) {
    barome_MedianFilterCG_resetImpl(&barometric_sensors_DW.obj.pMID);
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/Median Filter' */
}

/* Model terminate function */
void barometric_sensors_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!barometric_sensors_DW.obj_h.matlabCodegenIsDeleted) {
    barometric_sensors_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Median Filter' */
  if (!barometric_sensors_DW.obj.matlabCodegenIsDeleted) {
    barometric_sensors_DW.obj.matlabCodegenIsDeleted = true;
    if ((barometric_sensors_DW.obj.isInitialized == 1L) &&
        barometric_sensors_DW.obj.isSetupComplete) {
      barometric_sensors_DW.obj.NumChannels = -1L;
      if (barometric_sensors_DW.obj.pMID.isInitialized == 1L) {
        barometric_sensors_DW.obj.pMID.isInitialized = 2L;
      }
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Median Filter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

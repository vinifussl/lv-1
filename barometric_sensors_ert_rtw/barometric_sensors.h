/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: barometric_sensors.h
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

#ifndef RTW_HEADER_barometric_sensors_h_
#define RTW_HEADER_barometric_sensors_h_
#ifndef barometric_sensors_COMMON_INCLUDES_
#define barometric_sensors_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* barometric_sensors_COMMON_INCLUDES_ */

#include "barometric_sensors_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T SFunctionBuilder_o1;          /* '<Root>/S-Function Builder' */
  real_T SFunctionBuilder_o2;          /* '<Root>/S-Function Builder' */
  real_T MedianFilter;                 /* '<Root>/Median Filter' */
  real_T p;
  real_T ind2;
  real_T temp;
} B_barometric_sensors_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_MedianFilter_barometric_s_T obj; /* '<Root>/Median Filter' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Output' */
  real_T SFunctionBuilder_DSTATE;      /* '<Root>/S-Function Builder' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_barometric_sensors_T;

/* Parameters (default storage) */
struct P_barometric_sensors_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 960
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 4
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_barometric_sensors_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_barometric_sensors_T barometric_sensors_P;

/* Block signals (default storage) */
extern B_barometric_sensors_T barometric_sensors_B;

/* Block states (default storage) */
extern DW_barometric_sensors_T barometric_sensors_DW;

/* Model entry point functions */
extern void barometric_sensors_initialize(void);
extern void barometric_sensors_step(void);
extern void barometric_sensors_terminate(void);

/* Real-time Model object */
extern RT_MODEL_barometric_sensors_T *const barometric_sensors_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'barometric_sensors'
 */
#endif                                 /* RTW_HEADER_barometric_sensors_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

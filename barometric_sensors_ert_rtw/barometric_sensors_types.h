/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: barometric_sensors_types.h
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

#ifndef RTW_HEADER_barometric_sensors_types_h_
#define RTW_HEADER_barometric_sensors_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_04b6x6tDldj9IrIH2gmbjG
#define struct_tag_04b6x6tDldj9IrIH2gmbjG

struct tag_04b6x6tDldj9IrIH2gmbjG
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_04b6x6tDldj9IrIH2gmbjG */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_04b6x6tDldj9IrIH2gmbjG b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_AYWgtFscQm3mLUJYb3A20C
#define struct_tag_AYWgtFscQm3mLUJYb3A20C

struct tag_AYWgtFscQm3mLUJYb3A20C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_AYWgtFscQm3mLUJYb3A20C */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_AYWgtFscQm3mLUJYb3A20C codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

#ifndef struct_tag_Znk8nNkbfEUsHLZjbym0RF
#define struct_tag_Znk8nNkbfEUsHLZjbym0RF

struct tag_Znk8nNkbfEUsHLZjbym0RF
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pWinLen;
  real_T pBuf[12];
  real_T pHeap[12];
  real_T pMidHeap;
  real_T pIdx;
  real_T pPos[12];
  real_T pMinHeapLength;
  real_T pMaxHeapLength;
};

#endif                                 /* struct_tag_Znk8nNkbfEUsHLZjbym0RF */

#ifndef typedef_c_dsp_internal_MedianFilterCG_T
#define typedef_c_dsp_internal_MedianFilterCG_T

typedef struct tag_Znk8nNkbfEUsHLZjbym0RF c_dsp_internal_MedianFilterCG_T;

#endif                             /* typedef_c_dsp_internal_MedianFilterCG_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_barometric_sensors_T
#define typedef_cell_wrap_barometric_sensors_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_barometric_sensors_T;

#endif                              /* typedef_cell_wrap_barometric_sensors_T */

#ifndef struct_tag_QotlDYg6NZF4rJeaQHZjlG
#define struct_tag_QotlDYg6NZF4rJeaQHZjlG

struct tag_QotlDYg6NZF4rJeaQHZjlG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_barometric_sensors_T inputVarSize;
  int32_T NumChannels;
  c_dsp_internal_MedianFilterCG_T pMID;
};

#endif                                 /* struct_tag_QotlDYg6NZF4rJeaQHZjlG */

#ifndef typedef_dsp_MedianFilter_barometric_s_T
#define typedef_dsp_MedianFilter_barometric_s_T

typedef struct tag_QotlDYg6NZF4rJeaQHZjlG dsp_MedianFilter_barometric_s_T;

#endif                             /* typedef_dsp_MedianFilter_barometric_s_T */

/* Parameters (default storage) */
typedef struct P_barometric_sensors_T_ P_barometric_sensors_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_barometric_sensors_T RT_MODEL_barometric_sensors_T;

#endif                              /* RTW_HEADER_barometric_sensors_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri May  6 09:51:10 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_types.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "untitled_private.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_untitled_T untitled_Y;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static void untitled_SystemCore_setup(codertarget_arduinobase_inter_T *obj);
static void untitled_SystemCore_setup(codertarget_arduinobase_inter_T *obj)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  i_codertarget_arduinobase_int_T *obj_0;
  uint32_T varargin_1;
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T SwappedDataBytes_0;
  uint8_T regSet;
  uint8_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1L;
  obj->InitializationFlag = true;
  obj_0 = &obj->i2cObjmpu;
  modename = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, modename);
  obj->i2cObjmpu.BusSpeed = 100000UL;
  varargin_1 = obj->i2cObjmpu.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  regSet = 128U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint16_T)((size_t)1 *
          sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint16_T)
         ((size_t)2 * sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes[0], 2UL, false, false);
  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  MW_delay_in_milliseconds(1UL);
  regSet = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint16_T)((size_t)1 *
          sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint16_T)
         ((size_t)2 * sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes[0], 2UL, false, false);
  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  MW_delay_in_milliseconds(100UL);
  status = 117U;
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint16_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes_0, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                      &SwappedDataBytes_0, 1UL, false, true);
    memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (uint16_T)((size_t)1 *
            sizeof(uint8_T)));
  } else {
    regSet = 0U;
  }

  if (status != 0) {
    if (obj->InitializationFlag) {
      obj->InitError = true;
    } else if (obj->I2CReadWriteError == 0) {
      obj->I2CReadWriteError = status;
    }
  }

  obj->MPUConnect = (regSet == 104);
  if (obj->MPUConnect) {
    regSet = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint16_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 25U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    status = 28U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint16_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (uint16_T)((size_t)1 *
              sizeof(uint8_T)));
    } else {
      regSet = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    regSet = (uint8_T)((regSet & 231) | 8);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint16_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 28U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    status = 27U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint16_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (uint16_T)((size_t)1 *
              sizeof(uint8_T)));
    } else {
      regSet = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    regSet = (uint8_T)((regSet & 231) | 8);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint16_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 27U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    status = 26U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint16_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      memcpy((void *)&regSet, (void *)&SwappedDataBytes_0, (uint16_T)((size_t)1 *
              sizeof(uint8_T)));
    } else {
      regSet = 0U;
    }

    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }

    regSet = (uint8_T)((regSet & 248) | 1);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (uint16_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 26U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.I2CDriverObj.MW_I2C_HANDLE, 104UL,
      &SwappedDataBytes[0], 2UL, false, false);
    if (status != 0) {
      if (obj->InitializationFlag) {
        obj->InitError = true;
      } else if (obj->I2CReadWriteError == 0) {
        obj->I2CReadWriteError = status;
      }
    }
  } else {
    obj->InitError = true;
  }

  obj->InitializationFlag = false;
  obj->isSetupComplete = true;
}

/* Model step function */
void untitled_step(void)
{
  i_codertarget_arduinobase_int_T *obj;
  int16_T i;
  uint8_T b_RegisterValue[6];
  uint8_T output_raw[6];
  uint8_T b_RegisterValue_0[2];
  uint8_T output_raw_0[2];
  uint8_T Data;
  uint8_T SwappedDataBytes;

  /* MATLABSystem: '<Root>/MPU6050 IMU Sensor' */
  if (untitled_DW.obj.SampleTime != untitled_P.MPU6050IMUSensor_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.MPU6050IMUSensor_SampleTime;
  }

  untitled_DW.obj.I2CReadWriteError = 0U;
  obj = &untitled_DW.obj.i2cObjmpu;
  Data = 59U;
  memcpy((void *)&SwappedDataBytes, (void *)&Data, (uint16_T)((size_t)1 * sizeof
          (uint8_T)));
  untitled_B.status = MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes, 1UL, true, false);
  if (untitled_B.status == 0) {
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 104UL, &output_raw[0],
                      6UL, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (uint16_T)
           ((size_t)6 * sizeof(uint8_T)));
  } else {
    for (i = 0; i < 6; i++) {
      b_RegisterValue[i] = 0U;
    }
  }

  if (untitled_B.status != 0) {
    if (untitled_DW.obj.InitializationFlag) {
      untitled_DW.obj.InitError = true;
    } else if (untitled_DW.obj.I2CReadWriteError == 0) {
      untitled_DW.obj.I2CReadWriteError = untitled_B.status;
    }
  }

  untitled_B.acc[0] = b_RegisterValue[0] << 8 | b_RegisterValue[1];
  untitled_B.acc[1] = b_RegisterValue[2] << 8 | b_RegisterValue[3];
  untitled_B.acc[2] = b_RegisterValue[4] << 8 | b_RegisterValue[5];
  if (untitled_DW.obj.InitError) {
    /* MATLABSystem: '<Root>/MPU6050 IMU Sensor' */
    untitled_B.acc[0] = 0.0;
    untitled_B.acc[1] = 0.0;
    untitled_B.acc[2] = 0.0;
  } else {
    /* MATLABSystem: '<Root>/MPU6050 IMU Sensor' */
    untitled_B.acc[0] = untitled_B.acc[0] * 9.80665 / 8192.0;
    untitled_B.acc[1] = untitled_B.acc[1] * 9.80665 / 8192.0;
    untitled_B.acc[2] = untitled_B.acc[2] * 9.80665 / 8192.0;
  }

  obj = &untitled_DW.obj.i2cObjmpu;
  Data = 67U;
  memcpy((void *)&SwappedDataBytes, (void *)&Data, (uint16_T)((size_t)1 * sizeof
          (uint8_T)));
  untitled_B.status = MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes, 1UL, true, false);
  if (untitled_B.status == 0) {
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 104UL, &output_raw[0],
                      6UL, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (uint16_T)
           ((size_t)6 * sizeof(uint8_T)));
  } else {
    for (i = 0; i < 6; i++) {
      b_RegisterValue[i] = 0U;
    }
  }

  if (untitled_B.status != 0) {
    if (untitled_DW.obj.InitializationFlag) {
      untitled_DW.obj.InitError = true;
    } else if (untitled_DW.obj.I2CReadWriteError == 0) {
      untitled_DW.obj.I2CReadWriteError = untitled_B.status;
    }
  }

  untitled_B.angrate[0] = b_RegisterValue[0] << 8 | b_RegisterValue[1];
  untitled_B.angrate[1] = b_RegisterValue[2] << 8 | b_RegisterValue[3];
  untitled_B.angrate[2] = b_RegisterValue[4] << 8 | b_RegisterValue[5];
  if (untitled_DW.obj.InitError) {
    /* MATLABSystem: '<Root>/MPU6050 IMU Sensor' */
    untitled_B.angrate[0] = 0.0;
    untitled_B.angrate[1] = 0.0;
    untitled_B.angrate[2] = 0.0;
  } else {
    /* MATLABSystem: '<Root>/MPU6050 IMU Sensor' */
    untitled_B.angrate[0] *= 0.0152587890625;
    untitled_B.angrate[1] *= 0.0152587890625;
    untitled_B.angrate[2] *= 0.0152587890625;
  }

  obj = &untitled_DW.obj.i2cObjmpu;
  Data = 65U;
  memcpy((void *)&SwappedDataBytes, (void *)&Data, (uint16_T)((size_t)1 * sizeof
          (uint8_T)));
  untitled_B.status = MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 104UL,
    &SwappedDataBytes, 1UL, true, false);
  if (untitled_B.status == 0) {
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 104UL, &output_raw_0[0],
                      2UL, false, true);
    memcpy((void *)&b_RegisterValue_0[0], (void *)&output_raw_0[0], (uint16_T)
           ((size_t)2 * sizeof(uint8_T)));
  } else {
    b_RegisterValue_0[0] = 0U;
    b_RegisterValue_0[1] = 0U;
  }

  if (untitled_B.status != 0) {
    if (untitled_DW.obj.InitializationFlag) {
      untitled_DW.obj.InitError = true;
    } else if (untitled_DW.obj.I2CReadWriteError == 0) {
      untitled_DW.obj.I2CReadWriteError = untitled_B.status;
    }
  }

  if (untitled_DW.obj.InitError) {
    /* MATLABSystem: '<Root>/MPU6050 IMU Sensor' */
    untitled_B.temp = 0.0;
  } else {
    /* MATLABSystem: '<Root>/MPU6050 IMU Sensor' */
    untitled_B.temp = (real_T)(b_RegisterValue_0[0] << 8 | b_RegisterValue_0[1])
      / 340.0 + 36.53;
  }

  if (untitled_DW.obj.InitError) {
    /* MATLABSystem: '<Root>/MPU6050 IMU Sensor' */
    untitled_B.status = 32U;
  } else {
    /* MATLABSystem: '<Root>/MPU6050 IMU Sensor' */
    untitled_B.status = untitled_DW.obj.I2CReadWriteError;
  }

  /* End of MATLABSystem: '<Root>/MPU6050 IMU Sensor' */

  /* Outport: '<Root>/Out1' incorporates:
   *  MATLABSystem: '<Root>/MPU6050 IMU Sensor'
   */
  untitled_Y.Out1[0] = untitled_B.acc[0];

  /* Outport: '<Root>/Out2' incorporates:
   *  MATLABSystem: '<Root>/MPU6050 IMU Sensor'
   */
  untitled_Y.Out2[0] = untitled_B.angrate[0];

  /* Outport: '<Root>/Out1' incorporates:
   *  MATLABSystem: '<Root>/MPU6050 IMU Sensor'
   */
  untitled_Y.Out1[1] = untitled_B.acc[1];

  /* Outport: '<Root>/Out2' incorporates:
   *  MATLABSystem: '<Root>/MPU6050 IMU Sensor'
   */
  untitled_Y.Out2[1] = untitled_B.angrate[1];

  /* Outport: '<Root>/Out1' incorporates:
   *  MATLABSystem: '<Root>/MPU6050 IMU Sensor'
   */
  untitled_Y.Out1[2] = untitled_B.acc[2];

  /* Outport: '<Root>/Out2' incorporates:
   *  MATLABSystem: '<Root>/MPU6050 IMU Sensor'
   */
  untitled_Y.Out2[2] = untitled_B.angrate[2];

  /* Outport: '<Root>/Out3' */
  untitled_Y.Out3 = untitled_B.temp;

  /* Outport: '<Root>/Out4' */
  untitled_Y.Out4 = untitled_B.status;

  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (660198707U);
  untitled_M->Sizes.checksums[1] = (2015508235U);
  untitled_M->Sizes.checksums[2] = (1570922686U);
  untitled_M->Sizes.checksums[3] = (1805280633U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  {
    i_codertarget_arduinobase_int_T *obj;

    /* Start for MATLABSystem: '<Root>/MPU6050 IMU Sensor' */
    untitled_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    untitled_DW.obj.I2CReadWriteError = 0U;
    untitled_DW.obj.InitError = false;
    untitled_DW.obj.isInitialized = 0L;
    untitled_DW.obj.SampleTime = -1.0;
    obj = &untitled_DW.obj.i2cObjmpu;
    untitled_DW.obj.i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
    untitled_DW.obj.i2cObjmpu.isInitialized = 0L;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    untitled_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = false;
    untitled_DW.obj.matlabCodegenIsDeleted = false;
    untitled_DW.obj.SampleTime = untitled_P.MPU6050IMUSensor_SampleTime;
    untitled_SystemCore_setup(&untitled_DW.obj);
  }
}

/* Model terminate function */
void untitled_terminate(void)
{
  i_codertarget_arduinobase_int_T *obj;

  /* Terminate for MATLABSystem: '<Root>/MPU6050 IMU Sensor' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1L) && untitled_DW.obj.isSetupComplete)
    {
      obj = &untitled_DW.obj.i2cObjmpu;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &untitled_DW.obj.i2cObjmpu;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1L) {
      obj->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/MPU6050 IMU Sensor' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

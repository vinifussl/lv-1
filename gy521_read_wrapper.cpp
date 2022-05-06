
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
#include <Arduino.h>
#include "Wire.h"
#include "Wire.cpp"
#include "utility/twi.h"
#include "utility/twi.c"
#include "MPU6050_light.h"
#include "MPU6050_light.cpp"

#define ARDUINO 100

MPU6050 mpu(Wire);
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
extern "C" void gy521_read_Start_wrapper(real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
    #ifndef MATLAB_MEX_FILE
    Wire.begin();
    byte status = mpu.begin();
    while(status!=0){ } // stop everything if could not connect to MPU6050 
    delay(1000);
    // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
    mpu.calcOffsets(); // gyro and accelero
    #endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
extern "C" void gy521_read_Outputs_wrapper(real_T *gx,
			real_T *gy,
			real_T *gz,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
    #ifndef MATLAB_MEX_FILE
    mpu.update();
    gx[0] = mpu.getAngleX();
    gy[0] = mpu.getAngleY();
    gz[0] = mpu.getAngleZ();
    #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void gy521_read_Update_wrapper(real_T *gx,
			real_T *gy,
			real_T *gz,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Update code goes here.
 */
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}


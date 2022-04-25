
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
#include "SFE_BMP180.h"
#include "SFE_BMP180.cpp"

#define ARDUINO 100

SFE_BMP180 pressure;
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
extern "C" void abc_Start_wrapper(real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
    pressure.begin();
    #endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
extern "C" void abc_Outputs_wrapper(real_T *P,
			real_T *T,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
    #ifndef MATLAB_MEX_FILE
    double p,t;
    delay(pressure.startTemperature());
    pressure.getTemperature(t);
    delay(pressure.startPressure(3));
    pressure.getPressure(p,t);
    P[0] = p;
    T[0] = t;
    #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void abc_Update_wrapper(real_T *P,
			real_T *T,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}


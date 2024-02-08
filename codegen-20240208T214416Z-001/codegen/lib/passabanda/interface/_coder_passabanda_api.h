//
// Student License - for use by students to meet course requirements and
// perform academic research at degree granting institutions only.  Not
// for government, commercial, or other organizational use.
//
// _coder_passabanda_api.h
//
// Code generation for function 'passabanda'
//

#ifndef _CODER_PASSABANDA_API_H
#define _CODER_PASSABANDA_API_H

// Include files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void passabanda(real_T OrigECG[5000], real_T LPassDataFile[5000]);

void passabanda_api(const mxArray *prhs, const mxArray **plhs);

void passabanda_atexit();

void passabanda_initialize();

void passabanda_terminate();

void passabanda_xil_shutdown();

void passabanda_xil_terminate();

#endif
// End of code generation (_coder_passabanda_api.h)

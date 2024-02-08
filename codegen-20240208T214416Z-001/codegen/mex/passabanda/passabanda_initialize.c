/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * passabanda_initialize.c
 *
 * Code generation for function 'passabanda_initialize'
 *
 */

/* Include files */
#include "passabanda_initialize.h"
#include "_coder_passabanda_mex.h"
#include "passabanda_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void passabanda_once(void);

/* Function Definitions */
static void passabanda_once(void)
{
  mex_InitInfAndNan();
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\silva\\OneDrive\\Desktop\\ECG_Denoising\\passabanda.m", 0U,
      1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "passabanda", 8, -1, 440);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 232, -1, 435);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void passabanda_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "signal_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    passabanda_once();
  }
}

/* End of code generation (passabanda_initialize.c) */

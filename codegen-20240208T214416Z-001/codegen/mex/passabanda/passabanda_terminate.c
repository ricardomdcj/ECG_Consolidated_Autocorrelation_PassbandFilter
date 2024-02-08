/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * passabanda_terminate.c
 *
 * Code generation for function 'passabanda_terminate'
 *
 */

/* Include files */
#include "passabanda_terminate.h"
#include "_coder_passabanda_mex.h"
#include "passabanda_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void passabanda_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void passabanda_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (passabanda_terminate.c) */

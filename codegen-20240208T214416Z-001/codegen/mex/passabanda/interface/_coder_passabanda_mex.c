/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_passabanda_mex.c
 *
 * Code generation for function '_coder_passabanda_mex'
 *
 */

/* Include files */
#include "_coder_passabanda_mex.h"
#include "_coder_passabanda_api.h"
#include "passabanda_data.h"
#include "passabanda_initialize.h"
#include "passabanda_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&passabanda_atexit);
  /* Module initialization. */
  passabanda_initialize();
  /* Dispatch the entry-point. */
  passabanda_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  passabanda_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

void passabanda_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                            const mxArray *prhs[1])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        10, "passabanda");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "passabanda");
  }
  /* Call the function. */
  passabanda_api(prhs[0], &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/* End of code generation (_coder_passabanda_mex.c) */

/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_passabanda_api.c
 *
 * Code generation for function '_coder_passabanda_api'
 *
 */

/* Include files */
#include "_coder_passabanda_api.h"
#include "passabanda.h"
#include "passabanda_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[5000];

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[5000];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[5000];

static const mxArray *emlrt_marshallOut(const real_T u[5000]);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[5000]
{
  real_T(*y)[5000];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[5000]
{
  static const int32_T dims = 5000;
  real_T(*ret)[5000];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[5000])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[5000]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[5000];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[5000])
{
  static const int32_T i = 0;
  static const int32_T i1 = 5000;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

void passabanda_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*LPassDataFile)[5000];
  real_T(*OrigECG)[5000];
  st.tls = emlrtRootTLSGlobal;
  LPassDataFile = (real_T(*)[5000])mxMalloc(sizeof(real_T[5000]));
  /* Marshall function inputs */
  OrigECG = emlrt_marshallIn(&st, emlrtAlias(prhs), "OrigECG");
  /* Invoke the target function */
  passabanda(&st, *OrigECG, *LPassDataFile);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(*LPassDataFile);
}

/* End of code generation (_coder_passabanda_api.c) */

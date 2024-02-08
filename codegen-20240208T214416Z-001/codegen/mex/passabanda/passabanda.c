/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * passabanda.c
 *
 * Code generation for function 'passabanda'
 *
 */

/* Include files */
#include "passabanda.h"
#include "filter.h"
#include "introsort.h"
#include "passabanda_data.h"
#include "passabanda_emxutil.h"
#include "passabanda_types.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "cs.h"
#include "makeCXSparseMatrix.h"
#include "mwmathutil.h"
#include "solve_from_lu.h"
#include "solve_from_qr.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    15,           /* lineNo */
    "passabanda", /* fcnName */
    "C:\\Users\\silva\\OneDrive\\Desktop\\ECG_Denoising\\passabanda.m" /* pathName
                                                                        */
};

static emlrtRSInfo
    b_emlrtRSI =
        {
            111,        /* lineNo */
            "filtfilt", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    c_emlrtRSI =
        {
            123,         /* lineNo */
            "efiltfilt", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    d_emlrtRSI =
        {
            142,         /* lineNo */
            "efiltfilt", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    e_emlrtRSI =
        {
            152,         /* lineNo */
            "efiltfilt", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo f_emlrtRSI = {
    93,                   /* lineNo */
    "validateattributes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes"
    ".m" /* pathName */
};

static emlrtRSInfo
    g_emlrtRSI =
        {
            298,                             /* lineNo */
            "getCoeffsAndInitialConditions", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo h_emlrtRSI = {
    13,       /* lineNo */
    "sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" /* pathName
                                                                           */
};

static emlrtRSInfo i_emlrtRSI = {
    1450,              /* lineNo */
    "sparse/mldivide", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI =
    {
        160,                         /* lineNo */
        "CXSparseAPI/iteratedSolve", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI =
    {
        312,                      /* lineNo */
        "CXSparseAPI/iteratedLU", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo
    p_emlrtRSI =
        {
            322,            /* lineNo */
            "ffOneChanCat", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    q_emlrtRSI =
        {
            324,            /* lineNo */
            "ffOneChanCat", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRTEInfo emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatefinite", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatefinite.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    13,       /* lineNo */
    1,        /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" /* pName
                                                                           */
};

static emlrtRTEInfo
    d_emlrtRTEI =
        {
            298,        /* lineNo */
            22,         /* colNo */
            "filtfilt", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2023b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

/* Function Definitions */
void passabanda(const emlrtStack *sp, const real_T OrigECG[5000],
                real_T LPassDataFile[5000])
{
  static const int32_T cidxInt[7] = {1, 1, 1, 2, 3, 2, 3};
  static const int32_T ridxInt[7] = {1, 2, 3, 2, 3, 1, 2};
  static const int32_T offsets[4] = {0, 1, 2, 3};
  __m128d r;
  __m128d r1;
  __m128i r2;
  cs_din *N;
  cs_dis *S;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  emxArray_int32_T *y_colidx;
  emxArray_int32_T *y_rowidx;
  emxArray_real_T *y_d;
  real_T b_ytemp[5018];
  real_T ytemp[5018];
  real_T vals[7];
  real_T a2_data[4];
  real_T b2_data[4];
  real_T b_a2_data[4];
  real_T b_b2_data[4];
  real_T outBuff[3];
  real_T outBuff_data[3];
  real_T d;
  real_T val;
  real_T *y_d_data;
  int32_T sortedIndices[7];
  int32_T c;
  int32_T cptr;
  int32_T i;
  int32_T *y_colidx_data;
  int32_T *y_rowidx_data;
  int8_T b_cidxInt[7];
  int8_T b_ridxInt[7];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  /*  */
  /*  Fs=500;         */
  /*  fp=50;fs=60;                     */
  /*  rp=1;rs=2.5;                    */
  /*  wp=fp/(Fs/2);ws=fs/(Fs/2); */
  /*  [n,wn]=buttord(wp,ws,rp,rs);      */
  /*  [bz,az] = butter(n,wn); */
  st.site = &emlrtRSI;
  b_st.site = &b_emlrtRSI;
  c_st.site = &c_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  p = true;
  cptr = 0;
  exitg1 = false;
  while ((!exitg1) && (cptr < 5000)) {
    if ((!muDoubleScalarIsInf(OrigECG[cptr])) &&
        (!muDoubleScalarIsNaN(OrigECG[cptr]))) {
      cptr++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:filtfilt:expectedFinite", 3, 4, 5, "input");
  }
  c_st.site = &d_emlrtRSI;
  b2_data[0] = 0.031451948112026;
  a2_data[0] = 1.0;
  b2_data[1] = 0.094355844336077;
  a2_data[1] = -1.463561442496923;
  b2_data[2] = 0.094355844336077;
  a2_data[2] = 0.914051209844413;
  b2_data[3] = 0.031451948112026;
  a2_data[3] = -0.198874182451286;
  vals[0] = a2_data[1] + 1.0;
  vals[1] = a2_data[2];
  vals[3] = 1.0;
  vals[5] = -1.0;
  vals[2] = a2_data[3];
  vals[4] = 1.0;
  vals[6] = -1.0;
  val = b2_data[0];
  r = _mm_loadu_pd(&a2_data[1]);
  r1 = _mm_loadu_pd(&b2_data[1]);
  _mm_storeu_pd(&outBuff[0], _mm_sub_pd(r1, _mm_mul_pd(_mm_set1_pd(val), r)));
  outBuff[2] = b2_data[3] - val * a2_data[3];
  d_st.site = &g_emlrtRSI;
  e_st.site = &h_emlrtRSI;
  emxInit_real_T(&e_st, &y_d, &d_emlrtRTEI);
  emxInit_int32_T(&e_st, &y_colidx, &d_emlrtRTEI);
  emxInit_int32_T(&e_st, &y_rowidx, &d_emlrtRTEI);
  r2 = _mm_add_epi32(
      _mm_add_epi32(_mm_set1_epi32(0),
                    _mm_loadu_si128((const __m128i *)&offsets[0])),
      _mm_set1_epi32(1));
  _mm_storeu_si128((__m128i *)&sortedIndices[0], r2);
  sortedIndices[4] = 5;
  sortedIndices[5] = 6;
  sortedIndices[6] = 7;
  introsort(sortedIndices, cidxInt, ridxInt);
  i = y_d->size[0];
  y_d->size[0] = 7;
  emxEnsureCapacity_real_T(&e_st, y_d, i, &c_emlrtRTEI);
  y_d_data = y_d->data;
  for (cptr = 0; cptr < 7; cptr++) {
    i = sortedIndices[cptr];
    b_cidxInt[cptr] = (int8_T)cidxInt[i - 1];
    b_ridxInt[cptr] = (int8_T)ridxInt[i - 1];
    y_d_data[cptr] = 0.0;
  }
  i = y_colidx->size[0];
  y_colidx->size[0] = 4;
  emxEnsureCapacity_int32_T(&e_st, y_colidx, i, &c_emlrtRTEI);
  y_colidx_data = y_colidx->data;
  y_colidx_data[1] = 0;
  y_colidx_data[2] = 0;
  y_colidx_data[3] = 0;
  y_colidx_data[0] = 1;
  i = y_rowidx->size[0];
  y_rowidx->size[0] = 7;
  emxEnsureCapacity_int32_T(&e_st, y_rowidx, i, &c_emlrtRTEI);
  y_rowidx_data = y_rowidx->data;
  for (i = 0; i < 7; i++) {
    y_rowidx_data[i] = 0;
  }
  cptr = 0;
  for (c = 0; c < 3; c++) {
    while ((cptr + 1 <= 7) && (b_cidxInt[cptr] == c + 1)) {
      y_rowidx_data[cptr] = b_ridxInt[cptr];
      cptr++;
    }
    y_colidx_data[c + 1] = cptr + 1;
  }
  for (cptr = 0; cptr < 7; cptr++) {
    y_d_data[cptr] = vals[sortedIndices[cptr] - 1];
  }
  cptr = 1;
  for (c = 0; c < 3; c++) {
    int32_T ridx;
    ridx = y_colidx_data[c];
    y_colidx_data[c] = cptr;
    int32_T exitg2;
    do {
      exitg2 = 0;
      i = y_colidx_data[c + 1];
      if (ridx < i) {
        int32_T currRowIdx;
        val = 0.0;
        currRowIdx = y_rowidx_data[ridx - 1];
        while ((ridx < i) && (y_rowidx_data[ridx - 1] == currRowIdx)) {
          val += y_d_data[ridx - 1];
          ridx++;
        }
        if (val != 0.0) {
          y_d_data[cptr - 1] = val;
          y_rowidx_data[cptr - 1] = currRowIdx;
          cptr++;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
  cs_di *cxA;
  y_colidx_data[3] = cptr;
  d_st.site = &g_emlrtRSI;
  e_st.site = &i_emlrtRSI;
  f_st.site = &j_emlrtRSI;
  cxA = makeCXSparseMatrix(y_colidx_data[3] - 1, 3, 3, &y_colidx_data[0],
                           &y_rowidx_data[0], &y_d_data[0]);
  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == NULL) {
    cs_di *b_cxA;
    cs_din *b_N;
    cs_dis *b_S;
    g_st.site = &l_emlrtRSI;
    warning(&g_st);
    cs_di_sfree(S);
    cs_di_nfree(N);
    b_cxA = makeCXSparseMatrix(y_colidx_data[3] - 1, 3, 3, &y_colidx_data[0],
                               &y_rowidx_data[0], &y_d_data[0]);
    b_S = cs_di_sqr(2, b_cxA, 1);
    b_N = cs_di_qr(b_cxA, b_S);
    cs_di_spfree(b_cxA);
    qr_rank_di(b_N, &val);
    solve_from_qr_di(b_N, b_S, (double *)&outBuff[0], 3, 3);
    cs_di_sfree(b_S);
    cs_di_nfree(b_N);
  } else {
    solve_from_lu_di(N, S, (double *)&outBuff[0], 3);
    cs_di_sfree(S);
    cs_di_nfree(N);
  }
  emxFree_int32_T(&f_st, &y_rowidx);
  emxFree_int32_T(&f_st, &y_colidx);
  emxFree_real_T(&f_st, &y_d);
  c_st.site = &e_emlrtRSI;
  val = 2.0 * OrigECG[0];
  d = 2.0 * OrigECG[4999];
  for (i = 0; i < 9; i++) {
    ytemp[i] = val - OrigECG[9 - i];
  }
  memcpy(&ytemp[9], &OrigECG[0], 5000U * sizeof(real_T));
  for (i = 0; i < 9; i++) {
    ytemp[i + 5009] = d - OrigECG[4998 - i];
  }
  b_b2_data[0] = b2_data[0];
  b_a2_data[0] = a2_data[0];
  b_b2_data[1] = b2_data[1];
  b_a2_data[1] = a2_data[1];
  b_b2_data[2] = b2_data[2];
  b_a2_data[2] = a2_data[2];
  b_b2_data[3] = b2_data[3];
  b_a2_data[3] = a2_data[3];
  r = _mm_loadu_pd(&outBuff[0]);
  _mm_storeu_pd(&outBuff_data[0], _mm_mul_pd(r, _mm_set1_pd(ytemp[0])));
  outBuff_data[2] = ytemp[0] * outBuff[2];
  memcpy(&b_ytemp[0], &ytemp[0], 5018U * sizeof(real_T));
  d_st.site = &p_emlrtRSI;
  filter(&d_st, b_b2_data, b_a2_data, b_ytemp, outBuff_data, ytemp);
  for (i = 0; i < 5018; i++) {
    b_ytemp[i] = ytemp[5017 - i];
  }
  memcpy(&ytemp[0], &b_ytemp[0], 5018U * sizeof(real_T));
  r = _mm_loadu_pd(&outBuff[0]);
  _mm_storeu_pd(&outBuff_data[0], _mm_mul_pd(r, _mm_set1_pd(ytemp[0])));
  outBuff_data[2] = ytemp[0] * outBuff[2];
  for (i = 0; i < 4; i++) {
    b_b2_data[i] = b2_data[i];
    b_a2_data[i] = a2_data[i];
  }
  memcpy(&b_ytemp[0], &ytemp[0], 5018U * sizeof(real_T));
  d_st.site = &q_emlrtRSI;
  filter(&d_st, b_b2_data, b_a2_data, b_ytemp, outBuff_data, ytemp);
  for (i = 0; i < 5000; i++) {
    LPassDataFile[i] = ytemp[5008 - i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (passabanda.c) */

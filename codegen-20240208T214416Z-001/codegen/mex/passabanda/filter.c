/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * filter.c
 *
 * Code generation for function 'filter'
 *
 */

/* Include files */
#include "filter.h"
#include "passabanda_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = {
    146,      /* lineNo */
    5,        /* colNo */
    "filter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pName
                                                                           */
};

/* Function Definitions */
void filter(const emlrtStack *sp, real_T b_data[], real_T a_data[],
            const real_T x[5018], const real_T zi_data[], real_T y[5018])
{
  __m128d r;
  __m128d r1;
  real_T a1;
  int32_T j;
  int32_T k;
  a1 = a_data[0];
  if (a_data[0] == 0.0) {
    emlrtErrorWithMessageIdR2018a(
        sp, &b_emlrtRTEI,
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero",
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero", 0);
  } else if (a_data[0] != 1.0) {
    r = _mm_loadu_pd(&b_data[0]);
    r1 = _mm_set1_pd(a1);
    _mm_storeu_pd(&b_data[0], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&b_data[2]);
    _mm_storeu_pd(&b_data[2], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&a_data[1]);
    _mm_storeu_pd(&a_data[1], _mm_div_pd(r, r1));
    a_data[3] /= a1;
    a_data[0] = 1.0;
  }
  y[0] = zi_data[0];
  y[1] = zi_data[1];
  y[2] = zi_data[2];
  memset(&y[3], 0, 5015U * sizeof(real_T));
  for (k = 0; k < 5018; k++) {
    int32_T i;
    int32_T naxpy;
    int32_T scalarLB;
    int32_T vectorUB;
    if (5018 - k < 4) {
      naxpy = 5017 - k;
    } else {
      naxpy = 3;
    }
    scalarLB = ((naxpy + 1) / 2) << 1;
    vectorUB = scalarLB - 2;
    for (j = 0; j <= vectorUB; j += 2) {
      r = _mm_loadu_pd(&b_data[j]);
      i = k + j;
      r1 = _mm_loadu_pd(&y[i]);
      _mm_storeu_pd(&y[i], _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(x[k]), r)));
    }
    for (j = scalarLB; j <= naxpy; j++) {
      vectorUB = k + j;
      y[vectorUB] += x[k] * b_data[j];
    }
    if (5017 - k < 3) {
      naxpy = 5016 - k;
    } else {
      naxpy = 2;
    }
    a1 = -y[k];
    scalarLB = ((naxpy + 1) / 2) << 1;
    vectorUB = scalarLB - 2;
    for (j = 0; j <= vectorUB; j += 2) {
      r = _mm_loadu_pd(&a_data[j + 1]);
      i = (k + j) + 1;
      r1 = _mm_loadu_pd(&y[i]);
      _mm_storeu_pd(&y[i], _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(a1), r)));
    }
    for (j = scalarLB; j <= naxpy; j++) {
      vectorUB = (k + j) + 1;
      y[vectorUB] += a1 * a_data[j + 1];
    }
  }
}

/* End of code generation (filter.c) */

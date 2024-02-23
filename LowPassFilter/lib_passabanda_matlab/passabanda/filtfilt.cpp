//
// File: filtfilt.cpp
//
// MATLAB Coder version            : 4.2
// C/C++ source code generated on  : 12-Feb-2024 00:16:24
//

// Include Files
#include <string.h>
#include "passabanda.h"
#include "filtfilt.h"
#include "filter.h"
#include "passabanda_emxutil.h"
#include "introsort.h"
#include "solve_from_lu.h"
#include "makeCXSparseMatrix.h"
#include "solve_from_qr.h"

// Type Definitions
#include "cs.h"

// Function Definitions

//
// Arguments    : const double b_data[]
//                const double a_data[]
//                const double y[5000]
//                const double zi_data[]
//                double yout_data[]
//                int yout_size[1]
// Return Type  : void
//
void ffOneChanCat(const double b_data[], const double a_data[], const double y
                  [5000], const double zi_data[], double yout_data[], int
                  yout_size[1])
{
  double d0;
  double d1;
  int i0;
  double ytemp_data[5018];
  double b_b_data[4];
  double b_a_data[4];
  double b_ytemp_data[5018];
  double b_zi_data[3];
  int ytemp_size[1];
  memcpy(&yout_data[0], &y[0], 5000U * sizeof(double));
  yout_size[0] = 5000;
  d0 = 2.0 * yout_data[0];
  d1 = 2.0 * yout_data[4999];
  for (i0 = 0; i0 < 9; i0++) {
    ytemp_data[i0] = d0 - yout_data[9 - i0];
  }

  memcpy(&ytemp_data[9], &yout_data[0], 5000U * sizeof(double));
  for (i0 = 0; i0 < 9; i0++) {
    ytemp_data[i0 + 5009] = d1 - yout_data[4998 - i0];
  }

  b_b_data[0] = b_data[0];
  b_a_data[0] = a_data[0];
  b_b_data[1] = b_data[1];
  b_a_data[1] = a_data[1];
  b_b_data[2] = b_data[2];
  b_a_data[2] = a_data[2];
  b_b_data[3] = b_data[3];
  b_a_data[3] = a_data[3];
  memcpy(&b_ytemp_data[0], &ytemp_data[0], 5018U * sizeof(double));
  b_zi_data[0] = zi_data[0] * ytemp_data[0];
  b_zi_data[1] = zi_data[1] * ytemp_data[0];
  b_zi_data[2] = zi_data[2] * ytemp_data[0];
  filter(b_b_data, b_a_data, b_ytemp_data, b_zi_data, ytemp_data, ytemp_size);
  for (i0 = 0; i0 < 5018; i0++) {
    b_ytemp_data[i0] = ytemp_data[5017 - i0];
  }

  memcpy(&ytemp_data[0], &b_ytemp_data[0], 5018U * sizeof(double));
  b_b_data[0] = b_data[0];
  b_a_data[0] = a_data[0];
  b_b_data[1] = b_data[1];
  b_a_data[1] = a_data[1];
  b_b_data[2] = b_data[2];
  b_a_data[2] = a_data[2];
  b_b_data[3] = b_data[3];
  b_a_data[3] = a_data[3];
  memcpy(&b_ytemp_data[0], &ytemp_data[0], 5018U * sizeof(double));
  b_zi_data[0] = zi_data[0] * ytemp_data[0];
  b_zi_data[1] = zi_data[1] * ytemp_data[0];
  b_zi_data[2] = zi_data[2] * ytemp_data[0];
  filter(b_b_data, b_a_data, b_ytemp_data, b_zi_data, ytemp_data, ytemp_size);
  for (i0 = 0; i0 < 5000; i0++) {
    yout_data[i0] = ytemp_data[5008 - i0];
  }
}

//
// Arguments    : double b1_data[]
//                int b1_size[1]
//                double a1_data[]
//                int a1_size[1]
//                double zi_data[]
//                int zi_size[1]
//                double *L
// Return Type  : void
//
void getCoeffsAndInitialConditions(double b1_data[], int b1_size[1], double
  a1_data[], int a1_size[1], double zi_data[], int zi_size[1], double *L)
{
  double vals[7];
  double outBuff[3];
  emxArray_real_T *y_d;
  emxArray_int32_T *y_colidx;
  emxArray_int32_T *y_rowidx;
  int cptr;
  int sortedIndices[7];
  cell_wrap_5 this_tunableEnvironment[2];
  static const signed char a[7] = { 1, 1, 1, 2, 3, 2, 3 };

  static const signed char b[7] = { 1, 2, 3, 2, 3, 1, 2 };

  signed char cidxInt[7];
  signed char ridxInt[7];
  int ridx;
  double tol;
  int currRowIdx;
  cs_di* cxA;
  cs_dis * S;
  cs_din * N;
  *L = 1.0;
  b1_size[0] = 4;
  a1_size[0] = 4;
  b1_data[0] = 0.031451948112026;
  a1_data[0] = 1.0;
  b1_data[1] = 0.094355844336077;
  a1_data[1] = -1.463561442496923;
  b1_data[2] = 0.094355844336077;
  a1_data[2] = 0.914051209844413;
  b1_data[3] = 0.031451948112026;
  a1_data[3] = -0.198874182451286;
  vals[0] = -0.463561442496923;
  vals[1] = 0.914051209844413;
  vals[3] = 1.0;
  vals[5] = -1.0;
  vals[2] = -0.198874182451286;
  vals[4] = 1.0;
  vals[6] = -1.0;
  outBuff[0] = 0.14038770288425215;
  outBuff[1] = 0.065607153112315922;
  outBuff[2] = 0.037706928579305438;
  emxInit_real_T(&y_d, 1);
  emxInit_int32_T(&y_colidx, 1);
  emxInit_int32_T(&y_rowidx, 1);
  for (cptr = 0; cptr < 7; cptr++) {
    sortedIndices[cptr] = cptr + 1;
    this_tunableEnvironment[0].f1[cptr] = a[cptr];
    this_tunableEnvironment[1].f1[cptr] = b[cptr];
  }

  introsort(sortedIndices, this_tunableEnvironment);
  for (cptr = 0; cptr < 7; cptr++) {
    cidxInt[cptr] = a[sortedIndices[cptr] - 1];
    ridxInt[cptr] = b[sortedIndices[cptr] - 1];
  }

  cptr = y_d->size[0];
  y_d->size[0] = 7;
  emxEnsureCapacity_real_T(y_d, cptr);
  for (cptr = 0; cptr < 7; cptr++) {
    y_d->data[cptr] = 0.0;
  }

  cptr = y_colidx->size[0];
  y_colidx->size[0] = 4;
  emxEnsureCapacity_int32_T(y_colidx, cptr);
  y_colidx->data[0] = 1;
  cptr = y_rowidx->size[0];
  y_rowidx->size[0] = 7;
  emxEnsureCapacity_int32_T(y_rowidx, cptr);
  for (cptr = 0; cptr < 7; cptr++) {
    y_rowidx->data[cptr] = 0;
  }

  cptr = 0;
  while ((cptr + 1 <= 7) && (cidxInt[cptr] == 1)) {
    y_rowidx->data[cptr] = ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[1] = cptr + 1;
  while ((cptr + 1 <= 7) && (cidxInt[cptr] == 2)) {
    y_rowidx->data[cptr] = ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[2] = cptr + 1;
  while ((cptr + 1 <= 7) && (cidxInt[cptr] == 3)) {
    y_rowidx->data[cptr] = ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[3] = cptr + 1;
  for (cptr = 0; cptr < 7; cptr++) {
    y_d->data[cptr] = vals[sortedIndices[cptr] - 1];
  }

  cptr = 1;
  ridx = y_colidx->data[0];
  y_colidx->data[0] = 1;
  while (ridx < y_colidx->data[1]) {
    tol = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[1]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      tol += y_d->data[ridx - 1];
      ridx++;
    }

    if (tol != 0.0) {
      y_d->data[cptr - 1] = tol;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  ridx = y_colidx->data[1];
  y_colidx->data[1] = cptr;
  while (ridx < y_colidx->data[2]) {
    tol = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[2]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      tol += y_d->data[ridx - 1];
      ridx++;
    }

    if (tol != 0.0) {
      y_d->data[cptr - 1] = tol;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  ridx = y_colidx->data[2];
  y_colidx->data[2] = cptr;
  while (ridx < y_colidx->data[3]) {
    tol = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[3]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      tol += y_d->data[ridx - 1];
      ridx++;
    }

    if (tol != 0.0) {
      y_d->data[cptr - 1] = tol;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  y_colidx->data[3] = cptr;
  cxA = makeCXSparseMatrix(y_colidx->data[3] - 1, 3, 3, &y_colidx->data[0],
    &y_rowidx->data[0], &y_d->data[0]);
  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == NULL) {
    cs_di_sfree(S);
    cs_di_nfree(N);
    cxA = makeCXSparseMatrix(y_colidx->data[3] - 1, 3, 3, &y_colidx->data[0],
      &y_rowidx->data[0], &y_d->data[0]);
    S = cs_di_sqr(2, cxA, 1);
    N = cs_di_qr(cxA, S);
    cs_di_spfree(cxA);
    qr_rank_di(N, &tol);
    solve_from_qr_di(N, S, (double *)&outBuff[0], 3, 3);
    cs_di_sfree(S);
    cs_di_nfree(N);
  } else {
    solve_from_lu_di(N, S, (double *)&outBuff[0], 3);
    cs_di_sfree(S);
    cs_di_nfree(N);
  }

  emxFree_int32_T(&y_rowidx);
  emxFree_int32_T(&y_colidx);
  emxFree_real_T(&y_d);
  zi_size[0] = 3;
  zi_data[0] = outBuff[0];
  zi_data[1] = outBuff[1];
  zi_data[2] = outBuff[2];
}

//
// File trailer for filtfilt.cpp
//
// [EOF]
//

//
// Student License - for use by students to meet course requirements and
// perform academic research at degree granting institutions only.  Not
// for government, commercial, or other organizational use.
//
// passabanda.cpp
//
// Code generation for function 'passabanda'
//

// Include files
#include "passabanda.h"
#include "anonymous_function.h"
#include "filter.h"
#include "introsort.h"
#include "passabanda_internal_types.h"
#include "sparse.h"
#include "coder_array.h"
//#include "cs.h"
#include "makeCXSparseMatrix.h"
#include "solve_from_lu.h"
#include "solve_from_qr.h"
#include <algorithm>

// Function Definitions
void passabanda(const double OrigECG[5000], double LPassDataFile[5000])
{
  static const signed char b_cidxInt[7]{1, 1, 1, 2, 3, 2, 3};
  static const signed char b_ridxInt[7]{1, 2, 3, 2, 3, 1, 2};
  cs_din *N;
  cs_dis *S;
  coder::anonymous_function b_this;
  coder::sparse y;
  double b_ytemp[5018];
  double ytemp[5018];
  double vals[7];
  double a2_data[4];
  double b2_data[4];
  double outBuff[3];
  double outBuff_data[3];
  double d;
  double val;
  int sortedIndices[7];
  int cptr;
  int i;
  signed char cidxInt[7];
  signed char ridxInt[7];
  //
  //  Fs=500;
  //  fp=50;fs=60;
  //  rp=1;rs=2.5;
  //  wp=fp/(Fs/2);ws=fs/(Fs/2);
  //  [n,wn]=buttord(wp,ws,rp,rs);
  //  [bz,az] = butter(n,wn);
  b2_data[0] = 0.031451948112026;
  a2_data[0] = 1.0;
  b2_data[1] = 0.094355844336077;
  a2_data[1] = -1.463561442496923;
  b2_data[2] = 0.094355844336077;
  a2_data[2] = 0.914051209844413;
  b2_data[3] = 0.031451948112026;
  a2_data[3] = -0.198874182451286;
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
  for (cptr = 0; cptr < 7; cptr++) {
    sortedIndices[cptr] = cptr + 1;
    b_this.workspace.a[cptr] = b_cidxInt[cptr];
    b_this.workspace.b[cptr] = b_ridxInt[cptr];
  }
  coder::internal::introsort(sortedIndices, b_this);
  y.d.set_size(7);
  y.colidx.set_size(4);
  y.colidx[1] = 0;
  y.colidx[2] = 0;
  y.colidx[3] = 0;
  y.colidx[0] = 1;
  y.rowidx.set_size(7);
  for (cptr = 0; cptr < 7; cptr++) {
    i = sortedIndices[cptr];
    cidxInt[cptr] = b_cidxInt[i - 1];
    ridxInt[cptr] = b_ridxInt[i - 1];
    y.d[cptr] = 0.0;
    y.rowidx[cptr] = 0;
  }
  cptr = 0;
  for (int c{0}; c < 3; c++) {
    while ((cptr + 1 <= 7) && (cidxInt[cptr] == c + 1)) {
      y.rowidx[cptr] = ridxInt[cptr];
      cptr++;
    }
    y.colidx[c + 1] = cptr + 1;
  }
  for (cptr = 0; cptr < 7; cptr++) {
    y.d[cptr] = vals[sortedIndices[cptr] - 1];
  }
  cptr = 1;
  for (int c{0}; c < 3; c++) {
    int ridx;
    ridx = y.colidx[c];
    y.colidx[c] = cptr;
    int exitg1;
    do {
      exitg1 = 0;
      i = y.colidx[c + 1];
      if (ridx < i) {
        int currRowIdx;
        val = 0.0;
        currRowIdx = y.rowidx[ridx - 1];
        while ((ridx < i) && (y.rowidx[ridx - 1] == currRowIdx)) {
          val += y.d[ridx - 1];
          ridx++;
        }
        if (val != 0.0) {
          y.d[cptr - 1] = val;
          y.rowidx[cptr - 1] = currRowIdx;
          cptr++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  cs_di *cxA;
  y.colidx[3] = cptr;
  cxA = makeCXSparseMatrix(y.colidx[3] - 1, 3, 3, &(y.colidx.data())[0],
                           &(y.rowidx.data())[0], &(y.d.data())[0]);
  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == nullptr) {
    cs_di *b_cxA;
    cs_din *b_N;
    cs_dis *b_S;
    cs_di_sfree(S);
    cs_di_nfree(N);
    b_cxA = makeCXSparseMatrix(y.colidx[3] - 1, 3, 3, &(y.colidx.data())[0],
                               &(y.rowidx.data())[0], &(y.d.data())[0]);
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
  val = 2.0 * OrigECG[0];
  d = 2.0 * OrigECG[4999];
  for (i = 0; i < 9; i++) {
    ytemp[i] = val - OrigECG[9 - i];
  }
  std::copy(&OrigECG[0], &OrigECG[5000], &ytemp[9]);
  for (i = 0; i < 9; i++) {
    ytemp[i + 5009] = d - OrigECG[4998 - i];
  }
  double b_a2_data[4];
  double b_b2_data[4];
  b_b2_data[0] = 0.031451948112026;
  b_a2_data[0] = 1.0;
  b_b2_data[1] = 0.094355844336077;
  b_a2_data[1] = -1.463561442496923;
  b_b2_data[2] = 0.094355844336077;
  b_a2_data[2] = 0.914051209844413;
  b_b2_data[3] = 0.031451948112026;
  b_a2_data[3] = -0.198874182451286;
  outBuff_data[0] = outBuff[0] * ytemp[0];
  outBuff_data[1] = ytemp[0] * outBuff[1];
  outBuff_data[2] = ytemp[0] * outBuff[2];
  std::copy(&ytemp[0], &ytemp[5018], &b_ytemp[0]);
  coder::filter(b_b2_data, b_a2_data, b_ytemp, outBuff_data, ytemp);
  for (i = 0; i < 5018; i++) {
    b_ytemp[i] = ytemp[5017 - i];
  }
  std::copy(&b_ytemp[0], &b_ytemp[5018], &ytemp[0]);
  outBuff_data[0] = outBuff[0] * ytemp[0];
  outBuff_data[1] = ytemp[0] * outBuff[1];
  outBuff_data[2] = ytemp[0] * outBuff[2];
  std::copy(&ytemp[0], &ytemp[5018], &b_ytemp[0]);
  coder::filter(b2_data, a2_data, b_ytemp, outBuff_data, ytemp);
  for (i = 0; i < 5000; i++) {
    LPassDataFile[i] = ytemp[5008 - i];
  }
}

// End of code generation (passabanda.cpp)

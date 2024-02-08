/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * insertionsort.c
 *
 * Code generation for function 'insertionsort'
 *
 */

/* Include files */
#include "insertionsort.h"
#include "passabanda_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void insertionsort(int32_T x[7], const int32_T cmp_workspace_a[7],
                   const int32_T cmp_workspace_b[7])
{
  int32_T k;
  for (k = 0; k < 6; k++) {
    int32_T idx;
    int32_T xc;
    boolean_T exitg1;
    xc = x[k + 1] - 1;
    idx = k;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= 1)) {
      int32_T i;
      boolean_T varargout_1;
      i = cmp_workspace_a[x[idx] - 1];
      if (cmp_workspace_a[xc] < i) {
        varargout_1 = true;
      } else if (cmp_workspace_a[xc] == i) {
        varargout_1 = (cmp_workspace_b[xc] < cmp_workspace_b[x[idx] - 1]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        x[idx + 1] = x[idx];
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x[idx + 1] = xc + 1;
  }
}

/* End of code generation (insertionsort.c) */

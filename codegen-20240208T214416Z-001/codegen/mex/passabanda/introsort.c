/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * introsort.c
 *
 * Code generation for function 'introsort'
 *
 */

/* Include files */
#include "introsort.h"
#include "insertionsort.h"
#include "passabanda_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void introsort(int32_T x[7], const int32_T cmp_workspace_a[7],
               const int32_T cmp_workspace_b[7])
{
  insertionsort(x, cmp_workspace_a, cmp_workspace_b);
}

/* End of code generation (introsort.c) */

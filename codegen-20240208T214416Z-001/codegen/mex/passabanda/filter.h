/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * filter.h
 *
 * Code generation for function 'filter'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void filter(const emlrtStack *sp, real_T b_data[], real_T a_data[],
            const real_T x[5018], const real_T zi_data[], real_T y[5018]);

/* End of code generation (filter.h) */

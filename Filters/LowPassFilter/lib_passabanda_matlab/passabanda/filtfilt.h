//
// File: filtfilt.h
//
// MATLAB Coder version            : 4.2
// C/C++ source code generated on  : 12-Feb-2024 00:16:24
//
#ifndef FILTFILT_H
#define FILTFILT_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "passabanda_types.h"

// Type Definitions
#include "cs.h"

// Function Declarations
extern void ffOneChanCat(const double b_data[], const double a_data[], const
  double y[5000], const double zi_data[], double yout_data[], int yout_size[1]);
extern void getCoeffsAndInitialConditions(double b1_data[], int b1_size[1],
  double a1_data[], int a1_size[1], double zi_data[], int zi_size[1], double *L);

#endif

//
// File trailer for filtfilt.h
//
// [EOF]
//

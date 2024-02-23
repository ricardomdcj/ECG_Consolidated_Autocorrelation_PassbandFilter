//
// File: filter.h
//
// MATLAB Coder version            : 4.2
// C/C++ source code generated on  : 12-Feb-2024 00:16:24
//
#ifndef FILTER_H
#define FILTER_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "passabanda_types.h"

// Function Declarations
extern void filter(double b_data[], double a_data[], const double x_data[],
                   const double zi_data[], double y_data[], int y_size[1]);

#endif

//
// File trailer for filter.h
//
// [EOF]
//

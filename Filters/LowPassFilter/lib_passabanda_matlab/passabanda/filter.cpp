//
// File: filter.cpp
//
// MATLAB Coder version            : 4.2
// C/C++ source code generated on  : 12-Feb-2024 00:16:24
//

// Include Files
#include <string.h>
#include "passabanda.h"
#include "filter.h"

// Function Definitions

//
// Arguments    : double b_data[]
//                double a_data[]
//                const double x_data[]
//                const double zi_data[]
//                double y_data[]
//                int y_size[1]
// Return Type  : void
//
void filter(double b_data[], double a_data[], const double x_data[], const
            double zi_data[], double y_data[], int y_size[1])
{
  int k;
  int naxpy;
  int j;
  int y_data_tmp;
  double as;
  if ((!(a_data[0] == 0.0)) && (a_data[0] != 1.0)) {
    b_data[0] /= a_data[0];
    b_data[1] /= a_data[0];
    b_data[2] /= a_data[0];
    b_data[3] /= a_data[0];
    a_data[1] /= a_data[0];
    a_data[2] /= a_data[0];
    a_data[3] /= a_data[0];
    a_data[0] = 1.0;
  }

  y_size[0] = 5018;
  y_data[0] = zi_data[0];
  y_data[1] = zi_data[1];
  y_data[2] = zi_data[2];
  memset(&y_data[3], 0, 5015U * sizeof(double));
  for (k = 0; k < 5018; k++) {
    if (5018 - k < 4) {
      naxpy = 5017 - k;
    } else {
      naxpy = 3;
    }

    for (j = 0; j <= naxpy; j++) {
      y_data_tmp = k + j;
      y_data[y_data_tmp] += x_data[k] * b_data[j];
    }

    if (5017 - k < 3) {
      naxpy = 5016 - k;
    } else {
      naxpy = 2;
    }

    as = -y_data[k];
    for (j = 0; j <= naxpy; j++) {
      y_data_tmp = (k + j) + 1;
      y_data[y_data_tmp] += as * a_data[1 + j];
    }
  }
}

//
// File trailer for filter.cpp
//
// [EOF]
//

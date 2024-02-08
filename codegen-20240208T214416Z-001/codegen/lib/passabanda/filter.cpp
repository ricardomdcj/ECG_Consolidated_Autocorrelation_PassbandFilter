//
// Student License - for use by students to meet course requirements and
// perform academic research at degree granting institutions only.  Not
// for government, commercial, or other organizational use.
//
// filter.cpp
//
// Code generation for function 'filter'
//

// Include files
#include "filter.h"
#include <cstring>

// Function Definitions
namespace coder {
void filter(double b_data[], double a_data[], const double x[5018],
            const double zi_data[], double y[5018])
{
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
  y[0] = zi_data[0];
  y[1] = zi_data[1];
  y[2] = zi_data[2];
  std::memset(&y[3], 0, 5015U * sizeof(double));
  for (int k{0}; k < 5018; k++) {
    double as;
    int i;
    int y_tmp;
    if (5018 - k < 4) {
      i = 5017 - k;
    } else {
      i = 3;
    }
    for (int j{0}; j <= i; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * b_data[j];
    }
    if (5017 - k < 3) {
      i = 5016 - k;
    } else {
      i = 2;
    }
    as = -y[k];
    for (int j{0}; j <= i; j++) {
      y_tmp = (k + j) + 1;
      y[y_tmp] += as * a_data[j + 1];
    }
  }
}

} // namespace coder

// End of code generation (filter.cpp)

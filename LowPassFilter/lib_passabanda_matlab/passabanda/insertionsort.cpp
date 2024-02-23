//
// File: insertionsort.cpp
//
// MATLAB Coder version            : 4.2
// C/C++ source code generated on  : 12-Feb-2024 00:16:24
//

// Include Files
#include "passabanda.h"
#include "insertionsort.h"

// Function Definitions

//
// Arguments    : int x[7]
//                const cell_wrap_5 cmp_tunableEnvironment[2]
// Return Type  : void
//
void insertionsort(int x[7], const cell_wrap_5 cmp_tunableEnvironment[2])
{
  int k;
  int xc;
  int idx;
  boolean_T exitg1;
  int i1;
  for (k = 0; k < 6; k++) {
    xc = x[k + 1] - 1;
    idx = k;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= 1)) {
      i1 = cmp_tunableEnvironment[0].f1[x[idx] - 1];
      if ((cmp_tunableEnvironment[0].f1[xc] < i1) || ((cmp_tunableEnvironment[0]
            .f1[xc] == i1) && (cmp_tunableEnvironment[1].f1[xc] <
            cmp_tunableEnvironment[1].f1[x[idx] - 1]))) {
        x[idx + 1] = x[idx];
        idx--;
      } else {
        exitg1 = true;
      }
    }

    x[idx + 1] = xc + 1;
  }
}

//
// File trailer for insertionsort.cpp
//
// [EOF]
//

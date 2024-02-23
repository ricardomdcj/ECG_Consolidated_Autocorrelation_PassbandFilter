//
// File: introsort.cpp
//
// MATLAB Coder version            : 4.2
// C/C++ source code generated on  : 12-Feb-2024 00:16:24
//

// Include Files
#include "passabanda.h"
#include "introsort.h"
#include "insertionsort.h"

// Function Definitions

//
// Arguments    : int x[7]
//                const cell_wrap_5 cmp_tunableEnvironment[2]
// Return Type  : void
//
void introsort(int x[7], const cell_wrap_5 cmp_tunableEnvironment[2])
{
  insertionsort(x, cmp_tunableEnvironment);
}

//
// File trailer for introsort.cpp
//
// [EOF]
//

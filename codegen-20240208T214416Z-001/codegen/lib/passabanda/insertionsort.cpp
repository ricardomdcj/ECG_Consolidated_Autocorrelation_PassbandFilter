//
// Student License - for use by students to meet course requirements and
// perform academic research at degree granting institutions only.  Not
// for government, commercial, or other organizational use.
//
// insertionsort.cpp
//
// Code generation for function 'insertionsort'
//

// Include files
#include "insertionsort.h"
#include "anonymous_function.h"
#include "passabanda_internal_types.h"

// Function Definitions
namespace coder {
namespace internal {
void insertionsort(int x[7], const anonymous_function cmp)
{
  for (int k{0}; k < 6; k++) {
    int idx;
    int xc;
    boolean_T exitg1;
    xc = x[k + 1] - 1;
    idx = k;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= 1)) {
      int i;
      boolean_T varargout_1;
      i = cmp.workspace.a[x[idx] - 1];
      if (cmp.workspace.a[xc] < i) {
        varargout_1 = true;
      } else if (cmp.workspace.a[xc] == i) {
        varargout_1 = (cmp.workspace.b[xc] < cmp.workspace.b[x[idx] - 1]);
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

} // namespace internal
} // namespace coder

// End of code generation (insertionsort.cpp)

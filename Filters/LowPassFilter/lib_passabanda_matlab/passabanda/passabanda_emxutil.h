//
// File: passabanda_emxutil.h
//
// MATLAB Coder version            : 4.2
// C/C++ source code generated on  : 12-Feb-2024 00:16:24
//
#ifndef PASSABANDA_EMXUTIL_H
#define PASSABANDA_EMXUTIL_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "passabanda_types.h"

// Function Declarations
extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for passabanda_emxutil.h
//
// [EOF]
//

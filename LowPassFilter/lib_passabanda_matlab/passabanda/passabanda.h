//
// File: passabanda.h
//
// MATLAB Coder version            : 4.2
// C/C++ source code generated on  : 12-Feb-2024 00:16:24
//
#ifndef PASSABANDA_H
#define PASSABANDA_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "passabanda_types.h"

// Function Declarations
class libPassabanda
{
public:
  libPassabanda(const double* OrigECG, double* LPassDataFile_data, int* LPassDataFile_size);

  void passabanda();

private:
    const double* OrigECG;
    double* LPassDataFile_data;
    int* LPassDataFile_size;
};
#endif

//
// File trailer for passabanda.h
//
// [EOF]
//

//
// File: passabanda.cpp
//
// MATLAB Coder version            : 4.2
// C/C++ source code generated on  : 12-Feb-2024 00:16:24
//

// Include Files
#include "passabanda.h"
#include "filtfilt.h"

// Function Definitions

//
// Fs=500;
//  fp=50;fs=60;
//  rp=1;rs=2.5;
//  wp=fp/(Fs/2);ws=fs/(Fs/2);
//  [n,wn]=buttord(wp,ws,rp,rs);
//  [bz,az] = butter(n,wn);
// Arguments    : const double OrigECG[5000]
//                double LPassDataFile_data[]
//                int LPassDataFile_size[1]
// Return Type  : void
//

libPassabanda::libPassabanda(const double* OrigECG, double* LPassDataFile_data, int* LPassDataFile_size) : OrigECG(OrigECG), LPassDataFile_data(LPassDataFile_data), LPassDataFile_size(LPassDataFile_size) {}

void libPassabanda::passabanda()
{
  double b2_data[4];
  int b2_size[1];
  double a2_data[4];
  int a2_size[1];
  double zi_data[3];
  int zi_size[1];
  double L;

  //int LPassDataFile_size[1] = {5000};
  //
  //
  //
  //
  getCoeffsAndInitialConditions(b2_data, b2_size, a2_data, a2_size, zi_data,
    zi_size, &L);
  ffOneChanCat(b2_data, a2_data, OrigECG, zi_data, LPassDataFile_data,
               LPassDataFile_size);
}

//
// File trailer for passabanda.cpp
//
// [EOF]
//

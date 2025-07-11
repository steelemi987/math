#include <stdio.h>

#include "../s21_math.h"

long double s21_fabs(double x) {
  long double result;

  if (x >= 0)
    result = x;
  else
    result = -x;

  return result;
}
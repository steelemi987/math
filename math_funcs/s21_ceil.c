#include <stdio.h>

#include "../s21_math.h"

long double s21_ceil(double x) {
  long double result;
  int integer = x;

  if (x == integer || x < 0)
    result = integer;
  else if (x > 0)
    result = integer + 1;

  return result;
}
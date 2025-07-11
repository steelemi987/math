#include <stdio.h>

#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double result;

  if (y != 0) {
    double tmp = x / y;
    double i = 0;
    if (tmp > 0) {
      i = s21_floor(tmp);
    } else {
      i = s21_ceil(tmp);
    }

    result = x - (i * y);
  } else
    result = s21_nan();

  return result;
}
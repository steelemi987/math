#include <stdio.h>

#include "../s21_math.h"

long double s21_sqrt(double x) {
  double result = 1.0, current;
  if (x < 0) {
    result = s21_nan();
  } else if (x == 0) {
    result = 0;
  } else {
    double precision = 1e-9;
    do {
      current = result;
      result = (current + x / current) / 2;
    } while (s21_fabs(result - current) > precision);
  }

  return result;
}
#include <stdio.h>

#include "../s21_math.h"

long double s21_log(double x) {
  long double result;
  if (x < 0) {
    result = s21_nan();
  } else if (x == 0) {
    result = -1 / x;
  } else {
    long double sum = 0.0;
    while (x >= 2.0) {
      x /= 2.0;
      sum += 0.69314718056;
    }

    double term = x - 1;
    double n = 1.0;

    while (s21_fabs(term) > 1e-10) {
      sum += term / n;
      n += 1.0;
      term *= -1.0 * (x - 1);
    }

    result = sum;
  }

  return result;
}
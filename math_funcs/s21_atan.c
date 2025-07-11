#include <stdio.h>

#include "../s21_math.h"

long double s21_atan(double x) {
  long double sum = 0.0;
  if (x < 0.0)
    sum = -s21_atan(-x);
  else if (x > 1.0)
    sum = s21_PI / 2 - s21_atan(1 / x);
  else if (x == 1.0)
    sum = s21_PI / 4;
  else {
    double term;
    int i;

    for (i = 0; i < 10000; i++) {
      term = s21_pow(-1, i) * s21_pow(x, 2 * i + 1) / (2 * i + 1);
      sum += term;
    }
  }

  return sum;
}
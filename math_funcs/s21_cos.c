#include <stdio.h>

#include "../s21_math.h"

long double s21_cos(double x) {
  double sum = 1.0;
  double term = 1.0;
  int sign = -1;

  for (int i = 2; i <= 50; i += 2) {
    term *= x * x / (i * (i - 1));
    sum += sign * term;
    sign *= -1;
  }

  return sum;
}
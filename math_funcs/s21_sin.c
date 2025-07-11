#include <stdio.h>

#include "../s21_math.h"

long double s21_sin(double x) {
  double sum = x;
  double term = x;
  int sign = -1;

  for (int i = 2; i <= 50; i += 2) {
    term *= x * x / (i * (i + 1));
    sum += sign * term;
    sign *= -1;
  }

  return sum;
}
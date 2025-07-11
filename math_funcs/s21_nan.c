#include <stdio.h>

#include "../s21_math.h"

long double s21_nan() {
  double b = 0.0, c;
  c = 0 / b;
  return c;
}
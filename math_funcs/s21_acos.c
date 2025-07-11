#include <stdio.h>

#include "../s21_math.h"

long double s21_acos(double x) {
  long double res;
  if (x >= -1 && x <= 1) {
    if (x == -1)
      res = s21_PI;
    else if (x < -0.5 || x > 0.5) {
      res = 2.0 * s21_atan(s21_sqrt((1.0 - x) / (1.0 + x)));
    } else {
      res = s21_PI / 2 -
            (x + (1.0 / 6.0) * s21_pow(x, 3) + (3.0 / 40.0) * s21_pow(x, 5) +
             (5.0 / 112.0) * s21_pow(x, 7) + (35.0 / 1152.0) * s21_pow(x, 9) +
             (63.0 / 2816.0) * s21_pow(x, 11) +
             (231.0 / 13312.0) * s21_pow(x, 13));
    }
  } else
    res = s21_nan();
  return res;
}
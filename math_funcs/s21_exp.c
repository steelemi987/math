#include <stdio.h>

#include "../s21_math.h"

long double s21_exp(double x) {
  long double sum = 1.0;
  if (x < 0) {
    sum = 1.0 / s21_exp(-x);
  } else {
    long double term = 1.0;
    long double i = 1.0;
    if (x == s21_INF) {
      sum = s21_INF;
    } else if (x == -s21_INF) {
      sum = 0;
    } else {
      while (1e-100 < s21_fabs(term)) {
        term *= x / i;
        sum += term;
        i++;
        if (sum > __DBL_MAX__) {
          sum = s21_INF;
          term = 0;
        }
      }
    }
  }
  return sum;
}
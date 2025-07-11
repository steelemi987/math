#include <stdio.h>

#include "../s21_math.h"

long double s21_pow(double base, double deg) {
  int flag = 0;
  long double rez;
  if ((base < 0)) {
    if ((int)deg == deg) {
      base *= -1;
    }
    if ((((int)deg % 2) == 1) || (((int)deg % 2) == -1)) {
      flag += 1;
    }
  }
  if (base == 0) {
    if (deg > 0)
      rez = 0;
    else if (deg == 0)
      rez = 1;
    else {
      rez = 1 / base;
    };
  } else if ((base < 0) && (int)deg != deg) {
    rez = s21_nan();
  } else {
    double tmp_log = s21_log(base);
    double tmp_exp_rez = deg * tmp_log;
    rez = s21_exp(tmp_exp_rez);
    if (flag == 1) {
      rez *= -1;
    }
  }
  return rez;
}
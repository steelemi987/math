#include <stdio.h>

#include "../s21_math.h"

int s21_abs(int x) {
  int result;

  if (x >= 0)
    result = x;
  else
    result = -x;

  return result;
}
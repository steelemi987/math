#include <stdio.h>

#include "../s21_math.h"

long double s21_floor(double x) {
  long double result;
  int integer = x;
  if (x == integer)
    result = integer;
  else {
    if (x >= 0)
      result = integer;
    else
      result = integer - 1;
  }
  return result;
}
#ifndef S21_MATH_H
#define S21_MATH_H
#include <limits.h>

#define s21_PI 3.14159265358979323846264338327950288
#define s21_E 2.71828182845904523536028747135266250
#define s21_PI_2 1.57079632679489661923132169163975144
#define s21_INF 1.0 / 0.0

int s21_abs(int x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_log(double x);
long double s21_pow(double base, double deg);
long double s21_ceil(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_nan();

#endif
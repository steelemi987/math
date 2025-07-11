#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

static const double values1[7] = {4, 0.123, -3, 5.76, 0, 1, 1e+40};
START_TEST(test_sqrt) {
  printf("TEST_SQRT | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n",
         values1[_i], sqrt(values1[_i]), s21_sqrt(values1[_i]));
  if (isnan(sqrt(values1[_i])) != 0)
    ck_assert_ldouble_nan(s21_sqrt(values1[_i]));
  else
    ck_assert_ldouble_eq_tol(sqrt(values1[_i]), s21_sqrt(values1[_i]), 1e-6);
}
END_TEST

static const int values2[3] = {4, -76, 0};
START_TEST(test_abs) {
  printf("TEST_ABS | INPUT: %d | math.h: %d | s21_math.h: %d\n", values2[_i],
         abs(values2[_i]), s21_abs(values2[_i]));
  ck_assert_int_eq(abs(values2[_i]), s21_abs(values2[_i]));
}
END_TEST

static const double values3[8] = {4, -4, -3.543, 6.12, M_PI, -(M_PI / 2), 0, 1};
START_TEST(test_cos) {
  printf("TEST_COS | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n", values3[_i],
         cos(values3[_i]), s21_cos(values3[_i]));
  ck_assert_ldouble_eq_tol(cos(values3[_i]), s21_cos(values3[_i]), 1e-6);
}
END_TEST

static const double values4[8] = {4.11, -4, -3.54, 6, M_PI, -(M_PI / 3), 0, 1};
START_TEST(test_sin) {
  printf("TEST_SIN | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n", values4[_i],
         sin(values4[_i]), s21_sin(values4[_i]));
  ck_assert_ldouble_eq_tol(sin(values4[_i]), s21_sin(values4[_i]), 1e-6);
}
END_TEST

static const double values5[8] = {1.4, -1, -0.543, 0.27, M_PI, -(M_PI * 2 / 3),
                                  0,   1};
START_TEST(test_tan) {
  printf("TEST_TAN | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n", values5[_i],
         tan(values5[_i]), s21_tan(values5[_i]));
  ck_assert_ldouble_eq_tol(tan(values5[_i]), s21_tan(values5[_i]), 1e-6);
}
END_TEST

static const double values6[14] = {4,           -4,   -3.543, 6.12, M_PI,
                                   -(M_PI / 2), 0,    1,      -1,   0.5,
                                   0.7,         -0.7, -0.234, 0.324};
START_TEST(test_acos) {
  printf("TEST_ACOS | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n",
         values6[_i], acos(values6[_i]), s21_acos(values6[_i]));
  if (isnan(acos(values6[_i])) != 0)
    ck_assert_ldouble_nan(s21_acos(values6[_i]));
  else
    ck_assert_ldouble_eq_tol(acos(values6[_i]), s21_acos(values6[_i]), 1e-6);
}
END_TEST

static const double values7[8] = {1.4, -1, -0.543, 0.5, M_PI, -(M_PI * 2 / 3),
                                  0,   1};
START_TEST(test_asin) {
  printf("TEST_ASIN | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n",
         values7[_i], asin(values7[_i]), s21_asin(values7[_i]));
  if (isnan(asin(values7[_i])) != 0)
    ck_assert_ldouble_nan(s21_asin(values7[_i]));
  else
    ck_assert_ldouble_eq_tol(asin(values7[_i]), s21_asin(values7[_i]), 1e-6);
}
END_TEST

static const double values8[8] = {4.11, -4, -3.54, 6, M_PI, -(M_PI / 3), 0, 1};
START_TEST(test_atan) {
  printf("TEST_ATAN | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n",
         values8[_i], atan(values8[_i]), s21_atan(values8[_i]));
  if (isnan(atan(values8[_i])) != 0)
    ck_assert_ldouble_nan(s21_atan(values8[_i]));
  else
    ck_assert_ldouble_eq_tol(atan(values8[_i]), s21_atan(values8[_i]), 1e-6);
}
END_TEST

static const double values9[7] = {0.123, 5, -3, 5.76, 0, 1, M_E};
START_TEST(test_log) {
  printf("TEST_LOG | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n", values9[_i],
         log(values9[_i]), s21_log(values9[_i]));
  if (isnan(log(values9[_i])) != 0)
    ck_assert_ldouble_nan(s21_log(values9[_i]));
  else if (isinf(log(values9[_i])) != 0)
    ck_assert_ldouble_infinite(s21_log(values9[_i]));
  else
    ck_assert_ldouble_eq_tol(log(values9[_i]), s21_log(values9[_i]), 1e-6);
}
END_TEST
static const double values10[5] = {4.0, 0.5, -3, -5.76, 0};
START_TEST(test_pow) {
  double values[5] = {4.0, 0.5, -3, -5.76, 0};
  for (int j = 0; j < 5; j++) {
    printf(
        "TEST_POW | INPUT: base = %lf, deg = %lf | math.h: %lf | s21_math.h: "
        "%Lf\n",
        values10[_i], values[j], pow(values10[_i], values[j]),
        s21_pow(values10[_i], values[j]));
    if (isnan(pow(values10[_i], values[j])))
      ck_assert_ldouble_nan(s21_pow(values10[_i], values[j]));
    else if (isinf(pow(values10[_i], values[j])) != 0)
      ck_assert_ldouble_infinite(s21_pow(values10[_i], values[j]));
    else
      ck_assert_ldouble_eq_tol(pow(values10[_i], values[j]),
                               s21_pow(values10[_i], values[j]), 1e-6);
  }
}
END_TEST

static const double values11[8] = {4.11, -4, -3.54, 6, 0, 1};
START_TEST(test_ceil) {
  printf("TEST_CEIL | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n",
         values11[_i], ceil(values11[_i]), s21_ceil(values11[_i]));
  ck_assert_ldouble_eq_tol(ceil(values11[_i]), s21_ceil(values11[_i]), 1e-6);
}
END_TEST

static const double values12[11] = {5.345, 0.987, -4,       -3.54,    6,
                                    0,     1,     INFINITY, -INFINITY};
START_TEST(test_exp) {
  printf("TEST_EXP | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n",
         values12[_i], exp(values12[_i]), s21_exp(values12[_i]));
  if (isinf(exp(values12[_i])) != 0)
    ck_assert_ldouble_infinite(s21_exp(values12[_i]));
  else
    ck_assert_ldouble_eq_tol(exp(values12[_i]), s21_exp(values12[_i]), 1e-6);
}
END_TEST

static const double values13[4] = {4.7654, -76.999, 0.1111, 0};
START_TEST(test_fabs) {
  printf("TEST_FABS | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n",
         values13[_i], fabs(values13[_i]), s21_fabs(values13[_i]));
  ck_assert_ldouble_eq_tol(fabs(values13[_i]), s21_fabs(values13[_i]), 1e-6);
}
END_TEST

static const double values14[8] = {4.11, -4, -3.54, 6, 0, 1};
START_TEST(test_floor) {
  printf("TEST_FLOOR | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n",
         values14[_i], floor(values14[_i]), s21_floor(values14[_i]));
  ck_assert_ldouble_eq_tol(floor(values14[_i]), s21_floor(values14[_i]), 1e-6);
}
END_TEST

static const double values15[6] = {4, 0.123, -3, 5.76, 0, 999};
START_TEST(test_fmod) {
  double values[5] = {4, 0.123, -3, 5.76, 0};
  for (int j = 0; j < 5; j++) {
    printf("TEST_FMOD | INPUT: %lf | math.h: %lf | s21_math.h: %Lf\n",
           values15[_i], fmod(values15[_i], values15[j]),
           s21_fmod(values15[_i], values15[j]));
    if (isnan(fmod(values15[_i], values[j])) != 0)
      ck_assert_ldouble_nan(s21_fmod(values15[_i], values[j]));
    else
      ck_assert_ldouble_eq_tol(fmod(values15[_i], values15[j]),
                               s21_fmod(values15[_i], values15[j]), 1e-6);
  }
}
END_TEST

Suite* math_suite_create(void) {
  Suite* suite = suite_create("Math");

  TCase* tcase_sqrt = tcase_create("Test sqrt()");
  TCase* tcase_abs = tcase_create("Test abs()");
  TCase* tcase_cos = tcase_create("Test cos()");
  TCase* tcase_sin = tcase_create("Test sin()");
  TCase* tcase_tan = tcase_create("Test tan()");
  TCase* tcase_acos = tcase_create("Test acos()");
  TCase* tcase_asin = tcase_create("Test asin()");
  TCase* tcase_atan = tcase_create("Test atan()");
  TCase* tcase_log = tcase_create("Test log()");
  TCase* tcase_pow = tcase_create("Test pow()");
  TCase* tcase_ceil = tcase_create("Test ceil()");
  TCase* tcase_exp = tcase_create("Test exp()");
  TCase* tcase_fabs = tcase_create("Test fabs()");
  TCase* tcase_floor = tcase_create("Test floor()");
  TCase* tcase_fmod = tcase_create("Test fmod()");

  tcase_add_loop_test(tcase_sqrt, test_sqrt, 0, 7);
  tcase_add_loop_test(tcase_abs, test_abs, 0, 3);
  tcase_add_loop_test(tcase_cos, test_cos, 0, 8);
  tcase_add_loop_test(tcase_sin, test_sin, 0, 8);
  tcase_add_loop_test(tcase_tan, test_tan, 0, 8);
  tcase_add_loop_test(tcase_acos, test_acos, 0, 14);
  tcase_add_loop_test(tcase_asin, test_asin, 0, 8);
  tcase_add_loop_test(tcase_atan, test_atan, 0, 8);
  tcase_add_loop_test(tcase_log, test_log, 0, 7);
  tcase_add_loop_test(tcase_pow, test_pow, 0, 5);
  tcase_add_loop_test(tcase_ceil, test_ceil, 0, 8);
  tcase_add_loop_test(tcase_exp, test_exp, 0, 11);
  tcase_add_loop_test(tcase_fabs, test_fabs, 0, 4);
  tcase_add_loop_test(tcase_floor, test_floor, 0, 8);
  tcase_add_loop_test(tcase_fmod, test_fmod, 0, 6);

  suite_add_tcase(suite, tcase_sqrt);
  suite_add_tcase(suite, tcase_abs);
  suite_add_tcase(suite, tcase_cos);
  suite_add_tcase(suite, tcase_sin);
  suite_add_tcase(suite, tcase_tan);
  suite_add_tcase(suite, tcase_acos);
  suite_add_tcase(suite, tcase_asin);
  suite_add_tcase(suite, tcase_atan);
  suite_add_tcase(suite, tcase_log);
  suite_add_tcase(suite, tcase_pow);
  suite_add_tcase(suite, tcase_ceil);
  suite_add_tcase(suite, tcase_exp);
  suite_add_tcase(suite, tcase_fabs);
  suite_add_tcase(suite, tcase_floor);
  suite_add_tcase(suite, tcase_fmod);

  return suite;
}

int main(void) {
  Suite* suite = math_suite_create();
  SRunner* suite_runner = srunner_create(suite);
  srunner_set_log(suite_runner, "test.log");
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  srunner_free(suite_runner);
  return 0;
}
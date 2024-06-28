#include "s21_tests.h"

START_TEST(simple_char) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus_char) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus2_char) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+2c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus2_char) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-2c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(test2_char) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %2c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(space_char) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World % c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision_char) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision2_char) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.2c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(zero_char) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %0c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(zero_precision_char) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.0c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(h_char) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %hc";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(l_char) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %lc";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

Suite *suiteSprintf_char(void) {
  Suite *s = suite_create("suite_sprintf_char");
  TCase *tc = tcase_create("tc_sprintf_char");

  tcase_add_test(tc, simple_char);
  tcase_add_test(tc, plus_char);
  tcase_add_test(tc, plus2_char);
  tcase_add_test(tc, minus2_char);
  tcase_add_test(tc, test2_char);
  tcase_add_test(tc, space_char);
  tcase_add_test(tc, precision_char);
  tcase_add_test(tc, precision2_char);
  tcase_add_test(tc, zero_char);
  tcase_add_test(tc, zero_precision_char);
  tcase_add_test(tc, h_char);
  tcase_add_test(tc, l_char);

  suite_add_tcase(s, tc);
  return s;
}
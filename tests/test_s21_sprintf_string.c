#include "s21_tests.h"

START_TEST(simple_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %s";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_int_eq(expectedInt, actualInt);
  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(plus_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+s";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_int_eq(expectedInt, actualInt);
  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(minus_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-s";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_int_eq(expectedInt, actualInt);
  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(plus2_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+2s";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus2_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-2s";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(test2_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %2s";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(space_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World % s";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_int_eq(expectedInt, actualInt);
  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(precision_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.s";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_int_eq(expectedInt, actualInt);
  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(precision2_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.2s";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_int_eq(expectedInt, actualInt);
  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(zero_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %0s";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_int_eq(expectedInt, actualInt);
  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(zero_precision_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.0s";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_int_eq(expectedInt, actualInt);
  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(h_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %hs";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(l_string) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %ls";
  char dataOutput[] = "s";

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

Suite *suiteSprintf_string(void) {
  Suite *s = suite_create("suite_sprintf_string");
  TCase *tc = tcase_create("tc_sprintf_string");

  tcase_add_test(tc, simple_string);
  tcase_add_test(tc, plus_string);
  tcase_add_test(tc, minus_string);
  tcase_add_test(tc, plus2_string);
  tcase_add_test(tc, minus2_string);
  tcase_add_test(tc, test2_string);
  tcase_add_test(tc, space_string);
  tcase_add_test(tc, precision_string);
  tcase_add_test(tc, precision2_string);
  tcase_add_test(tc, zero_string);
  tcase_add_test(tc, zero_precision_string);
  tcase_add_test(tc, h_string);
  tcase_add_test(tc, l_string);

  suite_add_tcase(s, tc);
  return s;
}
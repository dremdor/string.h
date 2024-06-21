#include "s21_tests.h"

START_TEST(empty) {
  s21_size_t nByte = 0;
  char dataSrc[] = "";
  char actual[] = "";
  char expected[] = "";

  strncpy(expected, dataSrc, nByte);
  s21_strncpy(actual, dataSrc, nByte);

  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(zero_byte) {
  s21_size_t nByte = 0;
  char dataSrc[] = "Hello";
  char actual[] = "Hello";
  char expected[] = "Hello";

  strncpy(expected, dataSrc, nByte);
  s21_strncpy(actual, dataSrc, nByte);

  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(one_byte) {
  s21_size_t nByte = 1;
  char dataSrc[] = "Hello";
  char actual[] = "Hello";
  char expected[] = "Hello";

  strncpy(expected, dataSrc, nByte);
  s21_strncpy(actual, dataSrc, nByte);

  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(positive_test) {
  s21_size_t nByte = 5;
  char dataSrc[] = "World";
  char actual[] = "Hello";
  char expected[] = "Hello";

  strncpy(expected, dataSrc, nByte);
  s21_strncpy(actual, dataSrc, nByte);

  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(more_byte_test) {
  s21_size_t nByte = 5 + 1;
  char dataSrc[] = "World";
  char actual[] = "Hello";
  char expected[] = "Hello";

  strncpy(expected, dataSrc, nByte);
  s21_strncpy(actual, dataSrc, nByte);

  ck_assert_str_eq(expected, actual);
}
END_TEST

Suite *suiteStrncpy(void) {
  Suite *s = suite_create("suite_strncpy");
  TCase *tc = tcase_create("tc_strncpy");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, zero_byte);
  tcase_add_test(tc, one_byte);
  tcase_add_test(tc, positive_test);
  tcase_add_test(tc, more_byte_test);

  suite_add_tcase(s, tc);
  return s;
}
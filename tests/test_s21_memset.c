#include "s21_tests.h"

START_TEST(positive_test) {
  s21_size_t nByte = 5;
  char expected[] = "Hello";
  char actual[] = "Hello";
  char replace = '*';

  s21_memset(actual, replace, nByte);
  memset(expected, replace, nByte);

  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(zero_byte) {
  s21_size_t nByte = 0;
  char expected[] = "Hello";
  char actual[] = "Hello";
  char replace = '*';

  s21_memset(actual, replace, nByte);
  memset(expected, replace, nByte);

  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(empty) {
  s21_size_t nByte = 0;
  char expected[] = "";
  char actual[] = "";
  char replace = '\0';

  s21_memset(actual, replace, nByte);
  memset(expected, replace, nByte);

  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(long_string) {
  s21_size_t nByte = 5;
  char expected[] = "asdasd asdsad233r2fsdf dfsdgdfgdf 24][sdfpc&*$^#@";
  char actual[] = "asdasd asdsad233r2fsdf dfsdgdfgdf 24][sdfpc&*$^#@";
  char replace = '3';

  s21_memset(actual, replace, nByte);
  memset(expected, replace, nByte);

  ck_assert_str_eq(actual, expected);
}
END_TEST

Suite *suiteMemset(void) {
  Suite *s = suite_create("suite_memset");
  TCase *tc = tcase_create("tc_memset");

  tcase_add_test(tc, positive_test);
  tcase_add_test(tc, zero_byte);
  tcase_add_test(tc, empty);
  tcase_add_test(tc, long_string);

  suite_add_tcase(s, tc);
  return s;
}
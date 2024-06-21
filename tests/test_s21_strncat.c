#include "s21_tests.h"

START_TEST(all_empty) {
  s21_size_t nByte = 0;
  char dataSrc[] = "";

  char expected[] = "";
  char actual[] = "";

  strncat(expected, dataSrc, nByte);
  s21_strncat(actual, dataSrc, nByte);

  ck_assert_mem_ge(expected, actual, nByte);
  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(zero_byte) {
  s21_size_t nByte = 0;
  char dataSrc[] = "Hello";

  char expected[] = "";
  char actual[] = "";

  strncat(expected, dataSrc, nByte);
  s21_strncat(actual, dataSrc, nByte);

  ck_assert_mem_ge(expected, actual, nByte);
  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(empty_src) {
  s21_size_t nByte = 2;
  char dataSrc[] = "";

  char expected[] = "Hello";
  char actual[] = "Hello";

  strncat(expected, dataSrc, nByte);
  s21_strncat(actual, dataSrc, nByte);

  ck_assert_mem_ge(expected, actual, nByte);
  ck_assert_str_eq(expected, actual);
}
END_TEST

START_TEST(positive_test) {
  s21_size_t nByte = 6;
  char dataSrc[] = " World";

  char expected[12] = "Hello";
  char actual[12] = "Hello";

  strncat(expected, dataSrc, nByte);
  s21_strncat(actual, dataSrc, nByte);

  ck_assert_mem_ge(expected, actual, nByte);
  ck_assert_str_eq(expected, actual);
}
END_TEST

Suite *suiteStrncat(void) {
  Suite *s = suite_create("suite_strncat");
  TCase *tc = tcase_create("tc_strncat");

  tcase_add_test(tc, all_empty);
  tcase_add_test(tc, zero_byte);
  tcase_add_test(tc, empty_src);
  tcase_add_test(tc, positive_test);

  suite_add_tcase(s, tc);
  return s;
}
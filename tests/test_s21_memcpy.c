#include "s21_tests.h"

START_TEST(empty_str) {
  s21_size_t nByte = 0;
  char dataSrc[] = "";

  char expected[nByte];
  char actual[nByte];

  memcpy(expected, dataSrc, nByte);
  s21_memcpy(actual, dataSrc, nByte);

  ck_assert_mem_eq(expected, actual, nByte);
}
END_TEST

START_TEST(symbols) {
  s21_size_t nByte = 11;
  char dataSrc[] = "Hello World";

  char expected[nByte];
  char actual[nByte];

  memcpy(expected, dataSrc, nByte);
  s21_memcpy(actual, dataSrc, nByte);

  ck_assert_mem_eq(expected, actual, nByte);
}
END_TEST

START_TEST(numbers) {
  s21_size_t nByte = 9;
  char dataSrc[] = "123456789";

  char expected[nByte];
  char actual[nByte];

  memcpy(expected, dataSrc, nByte);
  s21_memcpy(actual, dataSrc, nByte);

  ck_assert_mem_eq(expected, actual, nByte);
}
END_TEST

Suite *suiteMemcpy(void) {
  Suite *s = suite_create("suite_memcpy");
  TCase *tc = tcase_create("tc_memcpy");

  tcase_add_test(tc, empty_str);
  tcase_add_test(tc, symbols);
  tcase_add_test(tc, numbers);

  suite_add_tcase(s, tc);
  return s;
}
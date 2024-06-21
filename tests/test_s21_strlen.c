#include "s21_tests.h"

START_TEST(empty_str) {
  char testDate[] = "";

  size_t expected = strlen(testDate);
  s21_size_t actual = s21_strlen(testDate);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(numbers) {
  char testDate[] = "987623456124678";

  size_t expected = strlen(testDate);
  s21_size_t actual = s21_strlen(testDate);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(symbols) {
  char testDate[] = "ABCDabcd";

  size_t expected = strlen(testDate);
  s21_size_t actual = s21_strlen(testDate);

  ck_assert_int_eq(expected, actual);
}
END_TEST

Suite *suiteStrlen(void) {
  Suite *s = suite_create("suite_strlen");
  TCase *tc = tcase_create("tc_strlen");

  tcase_add_test(tc, empty_str);
  tcase_add_test(tc, numbers);
  tcase_add_test(tc, symbols);

  suite_add_tcase(s, tc);
  return s;
}
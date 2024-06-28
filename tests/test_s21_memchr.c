#include "s21_tests.h"

START_TEST(empty_str) {
  s21_size_t nByte = 0;
  char testStr[10] = "";
  int findByte = '\0';

  void *expected = memchr(testStr, findByte, nByte);
  void *actual = s21_memchr(testStr, findByte, nByte);

  ck_assert_ptr_eq(expected, actual);
}
END_TEST

START_TEST(find_zero_in_string) {
  s21_size_t nByte = 5;
  char testStr[5] = "Hello";
  int findByte = '\0';

  void *expected = memchr(testStr, findByte, nByte);
  void *actual = s21_memchr(testStr, findByte, nByte);

  ck_assert_ptr_eq(expected, actual);
}
END_TEST

START_TEST(find_simbol_in_string_in_start) {
  s21_size_t nByte = 5;
  char testStr[5] = "World";
  int findByte = 'W';

  void *expected = memchr(testStr, findByte, nByte);
  void *actual = s21_memchr(testStr, findByte, nByte);

  ck_assert_ptr_eq(expected, actual);
}
END_TEST

START_TEST(find_simbol_in_string_in_end) {
  s21_size_t nByte = 6;
  char testStr[11] = "Hello World";
  int findByte = 'd';

  void *expected = memchr(testStr, findByte, nByte);
  void *actual = s21_memchr(testStr, findByte, nByte);

  ck_assert_ptr_eq(expected, actual);
}
END_TEST

START_TEST(test_memchr_not_found) {
  s21_size_t nByte = 5;
  char testStr[5] = "Hello";
  int findByte = 'x';

  void *expected = memchr(testStr, findByte, nByte);
  void *actual = s21_memchr(testStr, findByte, nByte);

  ck_assert_ptr_eq(expected, actual);
}
END_TEST

Suite *suiteMemchr(void) {
  Suite *s = suite_create("suite_memchr");
  TCase *tc = tcase_create("tc_memchr");

  tcase_add_test(tc, empty_str);
  tcase_add_test(tc, find_zero_in_string);
  tcase_add_test(tc, find_simbol_in_string_in_start);
  tcase_add_test(tc, find_simbol_in_string_in_end);
  tcase_add_test(tc, test_memchr_not_found);

  suite_add_tcase(s, tc);
  return s;
}
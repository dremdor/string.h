#include "s21_tests.h"

START_TEST(zero_byte) {
  s21_size_t nByte = 0;
  char dataStr1[] = "Hello";
  char dataStr2[] = "Hello";

  int expected = memcmp(dataStr1, dataStr2, nByte);
  int actual = s21_memcmp(dataStr1, dataStr2, nByte);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(positive_test) {
  s21_size_t nByte = 5;
  char dataStr1[] = "Hello";
  char dataStr2[] = "Hello";

  int expected = memcmp(dataStr1, dataStr2, nByte);
  int actual = s21_memcmp(dataStr1, dataStr2, nByte);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(first_more_test) {
  s21_size_t nByte = 5;
  char dataStr1[] = "Gekko";
  char dataStr2[] = "Hello";

  int expected = memcmp(dataStr1, dataStr2, nByte);
  int actual = s21_memcmp(dataStr1, dataStr2, nByte);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(second_more_test) {
  s21_size_t nByte = 5;
  char dataStr1[] = "Hello";
  char dataStr2[] = "Gekko";

  int expected = memcmp(dataStr1, dataStr2, nByte);
  int actual = s21_memcmp(dataStr1, dataStr2, nByte);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(zero_byte_in_num) {
  s21_size_t nByte = 0;
  char dataStr1[] = "1234";
  char dataStr2[] = "1234";

  int expected = memcmp(dataStr1, dataStr2, nByte);
  int actual = s21_memcmp(dataStr1, dataStr2, nByte);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(eq_long_string) {
  s21_size_t nByte = 42;
  char dataStr1[] = "wugjdklfjgutyjdfghcgg 935923594 ($)%@)#)$";
  char dataStr2[] = "wugjdklfjgutyjdfghcgg 935923594 ($)%@)#)$";

  int expected = memcmp(dataStr1, dataStr2, nByte);
  int actual = s21_memcmp(dataStr1, dataStr2, nByte);

  ck_assert_int_eq(expected, actual);
}
END_TEST

Suite *suiteMemcmp(void) {
  Suite *s = suite_create("suite_strncmp");
  TCase *tc = tcase_create("tc_strncmp");

  tcase_add_test(tc, zero_byte);
  tcase_add_test(tc, positive_test);
  tcase_add_test(tc, first_more_test);
  tcase_add_test(tc, second_more_test);
  tcase_add_test(tc, zero_byte_in_num);
  tcase_add_test(tc, eq_long_string);

  suite_add_tcase(s, tc);
  return s;
}
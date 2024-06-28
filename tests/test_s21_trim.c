#include "s21_tests.h"

START_TEST(positive_test) {
  char dataStr[] = "+!!++He+llo++00";
  char trim_chars[] = "+!0-";

  char expected[] = "He+llo";
  char *actual = (char *)s21_trim(dataStr, trim_chars);

  ck_assert_str_eq(actual, expected);
  if (actual) free(actual);
}
END_TEST

START_TEST(positive_test_2) {
  char dataStr[] = "He000llo0";
  char trim_chars[] = "003";

  char expected[] = "He000llo";
  char *actual = (char *)s21_trim(dataStr, trim_chars);

  ck_assert_str_eq(actual, expected);
  if (actual) free(actual);
}
END_TEST

START_TEST(positive_test_3) {
  char dataStr[] = "Hello World!";
  char trim_chars[] = "World";

  char expected[] = "Hello World!";
  char *actual = (char *)s21_trim(dataStr, trim_chars);

  ck_assert_str_eq(actual, expected);
  if (actual) free(actual);
}
END_TEST

START_TEST(positive_test_4) {
  char dataStr[] = "&* !!Hello * **";
  char trim_chars[] = "&!* ";

  char expected[] = "Hello";
  char *actual = (char *)s21_trim(dataStr, trim_chars);

  ck_assert_str_eq(actual, expected);
  if (actual) free(actual);
}
END_TEST

START_TEST(positive_test_5) {
  char dataStr[] = " Hello World!  ";
  char trim_chars[] = " ";

  char expected[] = "Hello World!";
  char *actual = (char *)s21_trim(dataStr, trim_chars);

  ck_assert_str_eq(actual, expected);
  if (actual) free(actual);
}
END_TEST

START_TEST(empty_space_test) {
  char dataStr[] = "        Hello         ";
  char trim_chars[] = "";

  char expected[] = "Hello";
  char *actual = (char *)s21_trim(dataStr, trim_chars);

  ck_assert_str_eq(actual, expected);
  if (actual) free(actual);
}
END_TEST

START_TEST(null_trim_chars_test) {
  char dataStr[] = "        Hello         ";
  char *trim_chars = S21_NULL;

  char expected[] = "Hello";
  char *actual = (char *)s21_trim(dataStr, trim_chars);

  ck_assert_str_eq(actual, expected);
  if (actual) free(actual);
}
END_TEST

START_TEST(null_data_str_test) {
  char *dataStr = S21_NULL;
  char trim_chars[] = "";

  char *expected = S21_NULL;
  char *actual = (char *)s21_trim(dataStr, trim_chars);

  ck_assert_ptr_eq(actual, expected);
  if (actual) free(actual);
}
END_TEST

START_TEST(empty_test) {
  char dataStr[] = "";
  char trim_chars[] = "";

  char expected[] = "";
  char *actual = (char *)s21_trim(dataStr, trim_chars);

  ck_assert_str_eq(actual, expected);
  if (actual) free(actual);
}
END_TEST

START_TEST(data_str_empty_test) {
  char dataStr[] = "";
  char trim_chars[] = "!@#$%^&*()_+";

  char expected[] = "";
  char *actual = (char *)s21_trim(dataStr, trim_chars);

  ck_assert_str_eq(actual, expected);
  if (actual) free(actual);
}
END_TEST

START_TEST(trim_chars_empty_test) {
  char dataStr[] = "!@#$%^&*()_+";
  char trim_chars[] = "";

  char expected[] = "!@#$%^&*()_+";
  char *actual = (char *)s21_trim(dataStr, trim_chars);

  ck_assert_str_eq(actual, expected);
  if (actual) free(actual);
}
END_TEST

START_TEST(trim_chars_and_data_str_eq) {
  char dataStr[] = "!@#$%^&*()_+";
  char trim_chars[] = "!@#$%^&*()_+";

  char expected[] = "";
  char *actual = (char *)s21_trim(dataStr, trim_chars);

  ck_assert_str_eq(actual, expected);
  if (actual) free(actual);
}
END_TEST

Suite *suiteTrim(void) {
  Suite *s = suite_create("suite_trim");
  TCase *tc = tcase_create("tc_trim");

  tcase_add_test(tc, positive_test);
  tcase_add_test(tc, positive_test_2);
  tcase_add_test(tc, positive_test_3);
  tcase_add_test(tc, positive_test_4);
  tcase_add_test(tc, positive_test_5);
  tcase_add_test(tc, empty_space_test);
  tcase_add_test(tc, null_trim_chars_test);
  tcase_add_test(tc, null_data_str_test);
  tcase_add_test(tc, empty_test);
  tcase_add_test(tc, data_str_empty_test);
  tcase_add_test(tc, trim_chars_empty_test);
  tcase_add_test(tc, trim_chars_and_data_str_eq);

  suite_add_tcase(s, tc);
  return s;
}
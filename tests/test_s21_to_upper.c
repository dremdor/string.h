#include "s21_tests.h"

START_TEST(positive_test) {
  char dataStr[] = "HeLlO wOrLd!";

  char expected[] = "HELLO WORLD!";
  char *actual = s21_to_upper(dataStr);

  ck_assert_str_eq(expected, actual);
  if (actual) free(actual);
}
END_TEST

START_TEST(positive_test_with_numbers) {
  char dataStr[] = "0987654321r1234567890";

  char expected[] = "0987654321R1234567890";
  char *actual = s21_to_upper(dataStr);

  ck_assert_str_eq(expected, actual);
  if (actual) free(actual);
}
END_TEST

START_TEST(positive_test_with_symbols) {
  char dataStr[] = "+_)(*&^%$#@!r!@#$%^&*()_+";

  char expected[] = "+_)(*&^%$#@!R!@#$%^&*()_+";
  char *actual = s21_to_upper(dataStr);

  ck_assert_str_eq(expected, actual);
  if (actual) free(actual);
}
END_TEST

START_TEST(empty_test) {
  char dataStr[] = "";

  char expected[] = "";
  char *actual = s21_to_upper(dataStr);

  ck_assert_str_eq(expected, actual);
  if (actual) free(actual);
}
END_TEST

START_TEST(space_test) {
  char dataStr[] = " ";

  char expected[] = " ";
  char *actual = s21_to_upper(dataStr);

  ck_assert_str_eq(expected, actual);
  if (actual) free(actual);
}
END_TEST

Suite *suiteToUpper(void) {
  Suite *s = suite_create("suite_to_upper");
  TCase *tc = tcase_create("tc_to_upper");

  tcase_add_test(tc, positive_test);
  tcase_add_test(tc, positive_test_with_numbers);
  tcase_add_test(tc, positive_test_with_symbols);
  tcase_add_test(tc, empty_test);
  tcase_add_test(tc, space_test);

  suite_add_tcase(s, tc);
  return s;
}
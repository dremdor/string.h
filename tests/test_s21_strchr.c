#include "s21_tests.h"

START_TEST(empty) {
  char dataStr[] = "";
  char findChar = '\0';

  char *expected = strrchr(dataStr, findChar);
  char *actual = s21_strrchr(dataStr, findChar);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(find_end) {
  char dataStr[] = "Hello";
  char findChar = '\0';

  char *expected = strrchr(dataStr, findChar);
  char *actual = s21_strrchr(dataStr, findChar);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(positive_test) {
  char dataStr[] = "Hello";
  char findChar = 'H';

  char *expected = strrchr(dataStr, findChar);
  char *actual = s21_strrchr(dataStr, findChar);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(number) {
  char dataStr[] = "123456789";
  char findChar = '9';

  char *expected = strrchr(dataStr, findChar);
  char *actual = s21_strrchr(dataStr, findChar);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(not_to_be_found_zero) {
  char dataStr[] = "123456789";
  char findChar = '9';

  char *expected = strrchr(dataStr, findChar);
  char *actual = s21_strrchr(dataStr, findChar);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

Suite *suiteStrchr(void) {
  Suite *s = suite_create("suite_strchr");
  TCase *tc = tcase_create("tc_strchr");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, find_end);
  tcase_add_test(tc, positive_test);
  tcase_add_test(tc, number);
  tcase_add_test(tc, not_to_be_found_zero);

  suite_add_tcase(s, tc);
  return s;
}
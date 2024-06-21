#include "s21_tests.h"

START_TEST(empty) {
  char dataStr[] = "";
  char findChar = '\0';

  char *expected = strrchr(dataStr, findChar);
  char *actual = s21_strrchr(dataStr, findChar);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(positive_test) {
  char dataStr[] = "Hello";
  char findChar = 'l';

  char *expected = strrchr(dataStr, findChar);
  char *actual = s21_strrchr(dataStr, findChar);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(find_zero) {
  char dataStr[] = "Hello";
  char findChar = '\0';

  char *expected = strrchr(dataStr, findChar);
  char *actual = s21_strrchr(dataStr, findChar);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(find_first_symbol) {
  char dataStr[] = "World";
  char findChar = 'W';

  char *expected = strrchr(dataStr, findChar);
  char *actual = s21_strrchr(dataStr, findChar);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(find_last_symbol) {
  char dataStr[] = "World";
  char findChar = 'd';

  char *expected = strrchr(dataStr, findChar);
  char *actual = s21_strrchr(dataStr, findChar);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(find_number) {
  char dataStr[] = "1234567890";
  char findChar = '5';

  char *expected = strrchr(dataStr, findChar);
  char *actual = s21_strrchr(dataStr, findChar);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(negative_find_test) {
  char dataStr[] = "Hello";
  char findChar = 'W';

  char *expected = strrchr(dataStr, findChar);
  char *actual = s21_strrchr(dataStr, findChar);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

Suite *suiteStrrchr(void) {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("tc_strrchr");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, positive_test);
  tcase_add_test(tc, find_zero);
  tcase_add_test(tc, find_first_symbol);
  tcase_add_test(tc, find_last_symbol);
  tcase_add_test(tc, find_number);
  tcase_add_test(tc, negative_find_test);

  suite_add_tcase(s, tc);
  return s;
}
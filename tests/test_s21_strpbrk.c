#include "s21_tests.h"

START_TEST(empty) {
  char dataStr[] = "";
  char findKeys[] = "";

  char *expected = strpbrk(dataStr, findKeys);
  char *actual = s21_strpbrk(dataStr, findKeys);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(positive_test) {
  char dataStr[] = "Hello";
  char findKeys[] = "l";

  char *expected = strpbrk(dataStr, findKeys);
  char *actual = s21_strpbrk(dataStr, findKeys);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(number) {
  char dataStr[] = "1234567890";
  char findKeys[] = "345";

  char *expected = strpbrk(dataStr, findKeys);
  char *actual = s21_strpbrk(dataStr, findKeys);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(find_first_char) {
  char dataStr[] = "World";
  char findKeys[] = "W";

  char *expected = strpbrk(dataStr, findKeys);
  char *actual = s21_strpbrk(dataStr, findKeys);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(last_first_char) {
  char dataStr[] = "World";
  char findKeys[] = "d";

  char *expected = strpbrk(dataStr, findKeys);
  char *actual = s21_strpbrk(dataStr, findKeys);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(find_zero) {
  char dataStr[] = "Hello";
  char findKeys[] = "\0";

  char *expected = strpbrk(dataStr, findKeys);
  char *actual = s21_strpbrk(dataStr, findKeys);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

START_TEST(negative_find_test) {
  char dataStr[] = "Hello";
  char findKeys[] = "World";

  char *expected = strpbrk(dataStr, findKeys);
  char *actual = s21_strpbrk(dataStr, findKeys);

  ck_assert_pstr_eq(expected, actual);
}
END_TEST

Suite *suiteStrpbrk(void) {
  Suite *s = suite_create("suite_strpbrk");
  TCase *tc = tcase_create("tc_strpbrk");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, positive_test);
  tcase_add_test(tc, number);
  tcase_add_test(tc, find_first_char);
  tcase_add_test(tc, last_first_char);
  tcase_add_test(tc, find_zero);
  tcase_add_test(tc, negative_find_test);

  suite_add_tcase(s, tc);
  return s;
}
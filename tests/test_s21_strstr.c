#include "s21_tests.h"

START_TEST(empty) {
  char haystack[] = "";
  char needle[] = "";

  char *expeted = strstr(haystack, needle);
  char *actual = s21_strstr(haystack, needle);

  ck_assert_pstr_eq(expeted, actual);
}
END_TEST
START_TEST(empty_haystack) {
  char haystack[] = "";
  char needle[] = "Hello";

  char *expeted = strstr(haystack, needle);
  char *actual = s21_strstr(haystack, needle);

  ck_assert_pstr_eq(expeted, actual);
}
END_TEST

START_TEST(empty_needle) {
  char haystack[] = "Hello";
  char needle[] = "";

  char *expeted = strstr(haystack, needle);
  char *actual = s21_strstr(haystack, needle);

  ck_assert_pstr_eq(expeted, actual);
}
END_TEST

START_TEST(positive_test) {
  char haystack[] = "Hello";
  char needle[] = "Hello";

  char *expeted = strstr(haystack, needle);
  char *actual = s21_strstr(haystack, needle);

  ck_assert_pstr_eq(expeted, actual);
}
END_TEST

START_TEST(number) {
  char haystack[] = "1234567890";
  char needle[] = "456789";

  char *expeted = strstr(haystack, needle);
  char *actual = s21_strstr(haystack, needle);

  ck_assert_pstr_eq(expeted, actual);
}
END_TEST

START_TEST(find_first_string) {
  char haystack[] = "Hello World";
  char needle[] = "Hello";

  char *expeted = strstr(haystack, needle);
  char *actual = s21_strstr(haystack, needle);

  ck_assert_pstr_eq(expeted, actual);
}
END_TEST

START_TEST(find_last_string) {
  char haystack[] = "Hello World";
  char needle[] = " World";

  char *expeted = strstr(haystack, needle);
  char *actual = s21_strstr(haystack, needle);

  ck_assert_pstr_eq(expeted, actual);
}
END_TEST

START_TEST(find_zero) {
  char haystack[] = "Hello World";
  char needle[] = "\0";

  char *expeted = strstr(haystack, needle);
  char *actual = s21_strstr(haystack, needle);

  ck_assert_pstr_eq(expeted, actual);
}
END_TEST

START_TEST(negative_find_test) {
  char haystack[] = "Hello";
  char needle[] = "World";

  char *expeted = strstr(haystack, needle);
  char *actual = s21_strstr(haystack, needle);

  ck_assert_pstr_eq(expeted, actual);
}
END_TEST

Suite *suiteStrstr(void) {
  Suite *s = suite_create("suite_strstr");
  TCase *tc = tcase_create("tc_strstr");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, empty_haystack);
  tcase_add_test(tc, empty_needle);
  tcase_add_test(tc, positive_test);
  tcase_add_test(tc, number);
  tcase_add_test(tc, find_first_string);
  tcase_add_test(tc, find_last_string);
  tcase_add_test(tc, find_zero);
  tcase_add_test(tc, negative_find_test);
  suite_add_tcase(s, tc);
  return s;
}
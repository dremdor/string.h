#include "s21_tests.h"

START_TEST(empty) {
  char dataStr[] = "";
  char findKeys[] = "";

  s21_size_t expected = strcspn(findKeys, dataStr);
  s21_size_t actual = s21_strcspn(findKeys, dataStr);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(positive_test) {
  char dataStr[] = "Hello";
  char findKeys[] = "Hello";

  s21_size_t expected = strcspn(findKeys, dataStr);
  s21_size_t actual = s21_strcspn(findKeys, dataStr);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(number) {
  char dataStr[] = "1234";
  char findKeys[] = "1234";

  s21_size_t expected = strcspn(findKeys, dataStr);
  s21_size_t actual = s21_strcspn(findKeys, dataStr);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(not_uniq_sim) {
  char dataStr[] = "111111111";
  char findKeys[] = "222222222";

  s21_size_t expected = strcspn(findKeys, dataStr);
  s21_size_t actual = s21_strcspn(findKeys, dataStr);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(str_more_test) {
  char dataStr[] = "12345";
  char findKeys[] = "1234";

  s21_size_t expected = strcspn(findKeys, dataStr);
  s21_size_t actual = s21_strcspn(findKeys, dataStr);

  ck_assert_int_eq(expected, actual);
}
END_TEST

START_TEST(keys_more_test) {
  char dataStr[] = "1234";
  char findKeys[] = "12345";

  s21_size_t expected = strcspn(findKeys, dataStr);
  s21_size_t actual = s21_strcspn(findKeys, dataStr);

  ck_assert_int_eq(expected, actual);
}
END_TEST

Suite *suiteStrcspn(void) {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("tc_strcspn");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, positive_test);
  tcase_add_test(tc, number);
  tcase_add_test(tc, not_uniq_sim);
  tcase_add_test(tc, str_more_test);
  tcase_add_test(tc, keys_more_test);

  suite_add_tcase(s, tc);
  return s;
}
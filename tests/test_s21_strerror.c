#include "s21_tests.h"

#if defined(__APPLE__) || defined(__MACH__)
#define S21_ERRLIST_SIZE 107

#elif defined(__linux__)
#define S21_ERRLIST_SIZE 134

#endif

START_TEST(all_std_errors_positive_test) {
  for (int i = 0; i < S21_ERRLIST_SIZE; i++) {
    char *expected = strerror(i);
    char *actual = s21_strerror(i);
    ck_assert_str_eq(expected, actual);
  }
}
END_TEST

START_TEST(negative_less_err_code_test) {
  for (int i = -1000; i < 0; i++) {
    char *expected = strerror(i);
    char *actual = s21_strerror(i);
    ck_assert_str_eq(expected, actual);
  }
}
END_TEST

START_TEST(negative_more_err_code_test) {
  for (int i = S21_ERRLIST_SIZE; i < 1000; i++) {
    char *expected = strerror(i);
    char *actual = s21_strerror(i);
    ck_assert_str_eq(expected, actual);
  }
}
END_TEST

Suite *suiteStrerror(void) {
  Suite *s = suite_create("suite_strerror");
  TCase *tc = tcase_create("tc_strerror");

  tcase_add_test(tc, all_std_errors_positive_test);
  tcase_add_test(tc, negative_less_err_code_test);
  tcase_add_test(tc, negative_more_err_code_test);

  suite_add_tcase(s, tc);
  return s;
}
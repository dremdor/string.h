#include "s21_tests.h"

START_TEST(positive_test) {
  char dataInsert[] = " World";
  char dataStr[] = "Hello!";
  s21_size_t index = 5;

  char expected[] = "Hello World!";
  char *actual = (char *)s21_insert(dataStr, dataInsert, index);

  ck_assert_str_eq(expected, actual);
  if (actual) free(actual);
}
END_TEST

START_TEST(positive_test_2) {
  char dataInsert[] = "Hello";
  char dataStr[] = " World!";
  s21_size_t index = 0;

  char expected[] = "Hello World!";
  char *actual = (char *)s21_insert(dataStr, dataInsert, index);

  ck_assert_str_eq(expected, actual);
  if (actual) free(actual);
}
END_TEST

START_TEST(more_index_test) {
  char dataInsert[] = "";
  char dataStr[] = "";
  s21_size_t index = 500;

  char expected[] = "";
  char *actual = (char *)s21_insert(dataStr, dataInsert, index);

  ck_assert_str_eq(expected, actual);
  if (actual) free(actual);
}
END_TEST

START_TEST(empty_test) {
  char dataInsert[] = "";
  char dataStr[] = "";
  s21_size_t index = 0;

  char expected[] = "";
  char *actual = (char *)s21_insert(dataStr, dataInsert, index);

  ck_assert_str_eq(expected, actual);
  if (actual) free(actual);
}
END_TEST

// START_TEST(null_test) {
//   char *dataInsert = S21_NULL;
//   char *dataStr = S21_NULL;
//   s21_size_t index = 500;
//
//   char expected[] = "";
//   char *actual = (char *)s21_insert(dataStr, dataInsert, index);
//
//   ck_assert_str_eq(expected, actual);
//   if (actual) free(actual);
// }
// END_TEST

// START_TEST(null_test_2) {
//   char *dataInsert = S21_NULL;
//   char dataStr[] = "Hello ";
//   s21_size_t index = 0;
//
//   char expected[] = "Hello ";
//   char *actual = (char *)s21_insert(dataStr, dataInsert, index);
//
//   ck_assert_str_eq(expected, actual);
//   if (actual) free(actual);
// }
// END_TEST

Suite *suiteInsert(void) {
  Suite *s = suite_create("suite_insert");
  TCase *tc = tcase_create("tc_insert");

  tcase_add_test(tc, positive_test);
  tcase_add_test(tc, positive_test_2);
  tcase_add_test(tc, more_index_test);
  tcase_add_test(tc, empty_test);
  //  tcase_add_test(tc, null_test);
  //  tcase_add_test(tc, null_test_2);

  suite_add_tcase(s, tc);
  return s;
}
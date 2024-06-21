#include <stdio.h>

#include "s21_tests.h"

START_TEST(correct_token_string) {
  char dataStr1[] = "Hello++World_! Privet====!Mir";
  char dataStr2[] = "Hello++World_! Privet====!Mir";
  const char delims[] = "+_! =";

  char *expected = strtok(dataStr1, delims);
  char *actual = s21_strtok(dataStr2, delims);

  s21_size_t expectedLen = s21_strlen(expected);
  s21_size_t actualLen = s21_strlen(actual);

  printf("%lu string_func; %lu our_func", expectedLen, actualLen);
  printf("%s string_func; %s our_func", expected, actual);

  ck_assert_uint_eq(expectedLen, actualLen);
  ck_assert_str_eq(expected, actual);
  /*
    while (expected && actual) {
      actual = s21_strtok(NULL, delims);
      expected = strtok(NULL, delims);
      ck_assert_uint_eq(s21_strlen(actual), s21_strlen(expected));

      if (expected || actual) {
        ck_assert_str_eq(expected, actual);
      } else {
        ck_assert_ptr_null(expected);
        ck_assert_ptr_null(actual);
      }
    }
    */
}
END_TEST
/*
START_TEST(hard_token_string) {
  char dataStr1[] = "++Hello++World_! Privet===!Mir+++ H +";
  char dataStr2[] = "++Hello++World_! Privet===!Mir+++ H +";
  const char delims[] = "+_! =";

  char *expected = strtok(dataStr1, delims);
  char *actual = s21_strtok(dataStr2, delims);

  s21_size_t expectedLen = s21_strlen(expected);
  s21_size_t actualLen = s21_strlen(actual);

  ck_assert_uint_eq(expectedLen, actualLen);
  ck_assert_str_eq(expected, actual);

  while (expected && actual) {
    actual = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(actual), s21_strlen(expected));

    if (expected || actual) {
      ck_assert_str_eq(expected, actual);
    } else {
      ck_assert_ptr_null(expected);
      ck_assert_ptr_null(actual);
    }
  }
}
END_TEST

START_TEST(unary_delimiters) {
  char dataStr1[] = "Hello+World_Privet!Mir_Test";
  char dataStr2[] = "Hello+World_Privet!Mir_Test";
  const char delims[] = "+_! =";

  char *expected = strtok(dataStr1, delims);
  char *actual = s21_strtok(dataStr2, delims);

  s21_size_t expectedLen = s21_strlen(expected);
  s21_size_t actualLen = s21_strlen(actual);

  ck_assert_uint_eq(expectedLen, actualLen);
  ck_assert_str_eq(expected, actual);

  while (expected && actual) {
    actual = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(actual), s21_strlen(expected));

    if (expected || actual) {
      ck_assert_str_eq(expected, actual);
    } else {
      ck_assert_ptr_null(expected);
      ck_assert_ptr_null(actual);
    }
  }
}
END_TEST

START_TEST(no_delims) {
  char dataStr1[] = "HelloWorldPrivetMir";
  char dataStr2[] = "HelloWorldPrivetMir";
  const char delims[] = "+_! =";

  char *expected = strtok(dataStr1, delims);
  char *actual = s21_strtok(dataStr2, delims);

  s21_size_t expectedLen = s21_strlen(expected);
  s21_size_t actualLen = s21_strlen(actual);

  ck_assert_uint_eq(expectedLen, actualLen);
  ck_assert_str_eq(expected, actual);

  while (expected && actual) {
    actual = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(actual), s21_strlen(expected));

    if (expected || actual) {
      ck_assert_str_eq(expected, actual);
    } else {
      ck_assert_ptr_null(expected);
      ck_assert_ptr_null(actual);
    }
  }
}
END_TEST

START_TEST(only_delims) {
  char dataStr1[] = "++++++++";
  char dataStr2[] = "++++++++";
  const char delims[] = "+_! =";

  char *expected = strtok(dataStr1, delims);
  char *actual = s21_strtok(dataStr2, delims);

  ck_assert_ptr_null(expected);
  ck_assert_ptr_null(actual);
}
END_TEST

START_TEST(two_delims) {
  char dataStr1[] = "Hello++++World++H++++W__M";
  char dataStr2[] = "Hello++++World++H++++W__M";
  const char delims[] = "+_! =";

  char *expected = strtok(dataStr1, delims);
  char *actual = s21_strtok(dataStr2, delims);

  s21_size_t expectedLen = s21_strlen(expected);
  s21_size_t actualLen = s21_strlen(actual);

  ck_assert_uint_eq(expectedLen, actualLen);
  ck_assert_str_eq(expected, actual);

  while (expected && actual) {
    actual = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(actual), s21_strlen(expected));

    if (expected || actual) {
      ck_assert_str_eq(expected, actual);
    } else {
      ck_assert_ptr_null(expected);
      ck_assert_ptr_null(actual);
    }
  }
}
END_TEST

START_TEST(space_after_delims) {
  char dataStr1[] = "Hello__+World_  Mir";
  char dataStr2[] = "Hello__+World_  Mir";
  const char delims[] = "+_! =";

  char *expected = strtok(dataStr1, delims);
  char *actual = s21_strtok(dataStr2, delims);

  s21_size_t expectedLen = s21_strlen(expected);
  s21_size_t actualLen = s21_strlen(actual);

  ck_assert_uint_eq(expectedLen, actualLen);
  ck_assert_str_eq(expected, actual);

  while (expected && actual) {
    actual = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(actual), s21_strlen(expected));

    if (expected || actual) {
      ck_assert_str_eq(expected, actual);
    } else {
      ck_assert_ptr_null(expected);
      ck_assert_ptr_null(actual);
    }
  }
}
END_TEST

START_TEST(mixed_n_of_delims) {
  char dataStr1[] = "Hello__World_+++Privet_Mir";
  char dataStr2[] = "Hello__World_+++Privet_Mir";
  const char delims[] = "+_! =";

  char *expected = strtok(dataStr1, delims);
  char *actual = s21_strtok(dataStr2, delims);

  s21_size_t expectedLen = s21_strlen(expected);
  s21_size_t actualLen = s21_strlen(actual);

  ck_assert_uint_eq(expectedLen, actualLen);
  ck_assert_str_eq(expected, actual);

  while (expected && actual) {
    actual = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(actual), s21_strlen(expected));

    if (expected || actual) {
      ck_assert_str_eq(expected, actual);
    } else {
      ck_assert_ptr_null(expected);
      ck_assert_ptr_null(actual);
    }
  }
}
END_TEST

START_TEST(hard_mixed) {
  char dataStr1[] = "     Hello__+ Wor!ld_   Mir+";
  char dataStr2[] = "     Hello__+ Wor!ld_   Mir+";
  const char delims[] = "+_! =";

  char *expected = strtok(dataStr1, delims);
  char *actual = s21_strtok(dataStr2, delims);

  s21_size_t expectedLen = s21_strlen(expected);
  s21_size_t actualLen = s21_strlen(actual);

  ck_assert_uint_eq(expectedLen, actualLen);
  ck_assert_str_eq(expected, actual);

  while (expected && actual) {
    actual = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(actual), s21_strlen(expected));

    if (expected || actual) {
      ck_assert_str_eq(expected, actual);
    } else {
      ck_assert_ptr_null(expected);
      ck_assert_ptr_null(actual);
    }
  }
}
END_TEST

START_TEST(mixed_hard_incorrect) {
  char dataStr1[] = "!Hello__ !M!ish a____World+Mir!!!Privet";
  char dataStr2[] = "!Hello__ !M!ish a____World+Mir!!!Privet";
  const char delims[] = "+_! =";

  char *expected = strtok(dataStr1, delims);
  char *actual = s21_strtok(dataStr2, delims);

  s21_size_t expectedLen = s21_strlen(expected);
  s21_size_t actualLen = s21_strlen(actual);

  ck_assert_uint_eq(expectedLen, actualLen);
  ck_assert_str_eq(expected, actual);

  while (expected && actual) {
    actual = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(actual), s21_strlen(expected));

    if (expected || actual) {
      ck_assert_str_eq(expected, actual);
    } else {
      ck_assert_ptr_null(expected);
      ck_assert_ptr_null(actual);
    }
  }
}
END_TEST

START_TEST(very_hard_mixed) {
  char dataStr1[] = "!       H!E!L!L!O!!W!!ORL!D";
  char dataStr2[] = "!       H!E!L!L!O!!W!!ORL!D";
  const char delims[] = "+_! =";

  char *expected = strtok(dataStr1, delims);
  char *actual = s21_strtok(dataStr2, delims);

  s21_size_t expectedLen = s21_strlen(expected);
  s21_size_t actualLen = s21_strlen(actual);

  ck_assert_uint_eq(expectedLen, actualLen);
  ck_assert_str_eq(expected, actual);

  while (expected && actual) {
    actual = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(actual), s21_strlen(expected));

    if (expected || actual) {
      ck_assert_str_eq(expected, actual);
    } else {
      ck_assert_ptr_null(expected);
      ck_assert_ptr_null(actual);
    }
  }
}
END_TEST
*/
Suite *suiteStrtok(void) {
  Suite *s = suite_create("suite_strtok");
  TCase *tc = tcase_create("tc_strtok");

  tcase_add_test(tc, correct_token_string);
  /*
  tcase_add_test(tc, hard_token_string);
  tcase_add_test(tc, unary_delimiters);
  tcase_add_test(tc, no_delims);
  tcase_add_test(tc, only_delims);
  tcase_add_test(tc, even_n_of_delims);
  tcase_add_test(tc, odd_n_of_delims);
  tcase_add_test(tc, mixed_n_of_delims);
  tcase_add_test(tc, hard_mixed);
  tcase_add_test(tc, mixed_hard_incorrect);
  tcase_add_test(tc, very_hard_mixed);
*/
  suite_add_tcase(s, tc);
  return s;
}
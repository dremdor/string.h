#include "s21_tests.h"

int main(void) {
  runTests();

  return 0;
}

void runTestcase(Suite *testcase) {
  static int counterTestcase = 1;

  if (counterTestcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counterTestcase, "\n");
  counterTestcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

void runTests(void) {
  Suite *listCases[] = {suiteMemchr(),
                        suiteMemcmp(),
                        suiteMemcpy(),
                        suiteMemset(),
                        suiteStrchr(),
                        suiteStrcspn(),
                        suiteStrerror(),
                        suiteStrlen(),
                        suiteStrncat(),
                        suiteStrncmp(),
                        suiteStrncpy(),
                        suiteStrpbrk(),
                        suiteStrrchr(),
                        suiteStrstr(),
                        suiteStrtok(),
                        suiteSprintf_int(),
                        suiteSprintf_int_u(),
                        suiteSprintf_char(),
                        suiteSprintf_float(),
                        suiteSprintf_string(),
                        suiteInsert(),
                        suiteToLower(),
                        suiteToUpper(),
                        suiteTrim(),
                        NULL};

  for (Suite **currentTestcase = listCases; *currentTestcase != NULL;
       currentTestcase++) {
    runTestcase(*currentTestcase);
  }
}
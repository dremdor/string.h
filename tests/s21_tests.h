#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../string_functions/s21_string.h"

Suite *suiteMemchr(void);
Suite *suiteMemcmp(void);
Suite *suiteMemcpy(void);
Suite *suiteMemset(void);
Suite *suiteStrchr(void);
Suite *suiteStrcspn(void);
Suite *suiteStrerror(void);
Suite *suiteStrlen(void);
Suite *suiteStrncat(void);
Suite *suiteStrncmp(void);
Suite *suiteStrncpy(void);
Suite *suiteStrpbrk(void);
Suite *suiteStrrchr(void);
Suite *suiteStrstr(void);
Suite *suiteStrtok(void);
Suite *suiteSprintf_int(void);
Suite *suiteSprintf_char(void);
Suite *suiteSprintf_float(void);
Suite *suiteSprintf_string(void);

void runTests(void);
void runTestcase(Suite *testcase);

#endif
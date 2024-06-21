#include <stdio.h>
#include <string.h>

#include "string_functions/s21_string.h"

int main(void) {
  char expected[1024];
  char actual[1024];

  char *format = "Hello World %c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

    printf("expected = %s\n", expected);
    printf("actual = %s", actual);
    return 0;
}
#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *pointer = str;

  int status = 0;
  s21_size_t i = 0;

  while (pointer[i] != '\0' && status == 0) {
    if (pointer[i] == c) status = 1;
    i++;
  }

  i--;

  return status ? (void *)(pointer + i) : S21_NULL;
}
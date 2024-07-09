#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  const char *p = str;

  s21_size_t len = 0;

  while (*p != '\0') {
    ++len;
    ++p;
  }

  return len;
}
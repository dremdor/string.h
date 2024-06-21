#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *pointer = (const char *)str;
  int status = 0;
  s21_size_t i = 0;
  for (; i < n && status == 0; ++i) {
    if (*pointer == c)
      status = 1;
    else
      ++pointer;
  }
  return status ? (void *)(pointer) : S21_NULL;
}
#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  const char *pointer = src;
  char *pointer2 = dest;

  for (s21_size_t i = 0; i < n; i++) {
    pointer2[i] = pointer[i];
  }

  return (void *)dest;
}
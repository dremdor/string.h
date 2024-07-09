#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *pointer = str1;
  const char *pointer2 = str2;

  int sum = 0;

  for (s21_size_t i = 0; i < n; i++) {
    sum += pointer[i] - pointer2[i];
  }

  if (sum > 0)
    sum = 1;
  else if (sum < 0)
    sum = -1;
  else
    sum = 0;

  return sum;
}
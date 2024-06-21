#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *a = str1;
  char *ret = S21_NULL;

  int flag = 1;
  while (*a != '\0' && flag) {
    const char *b = str2;
    while (*b != '\0' && flag) {
      if (*b == *a) {
        ret = (char *)a;
        flag = 0;
      }
      b++;
    }
    a++;
  }

  return ret;
}
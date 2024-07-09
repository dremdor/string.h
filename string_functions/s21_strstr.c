#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *ret = S21_NULL;
  if (s21_strlen(haystack) >= s21_strlen(needle)) {
    for (s21_size_t i = 0, br = 1;
         i <= s21_strlen(haystack) - s21_strlen(needle) && br; i++) {
      int found = 1;
      for (s21_size_t j = i, k = 0; needle[k]; k++, j++)
        if (haystack[j] != needle[k]) {
          found = 0;
        }
      if (found == 1) {
        ret = (char *)(haystack + i);
        br = 0;
      }
    }
  }
  return ret;
}
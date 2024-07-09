#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  char *ret = str;
  static char *last = S21_NULL;

  if (str) {
    last = str;
  } else if (!last)
    ret = S21_NULL;

  if (last) {
    while (*last && s21_strchr(delim, *last)) {
      ++last;
    }

    if (*last == '\0') {
      ret = S21_NULL;
    } else {
      char *start = last;

      while (*last && !s21_strchr(delim, *last)) {
        ++last;
      }

      if (*last) {
        *last = '\0';
        ++last;
      } else {
        last = S21_NULL;
      }
      ret = start;
    }
  }

  return ret;
}

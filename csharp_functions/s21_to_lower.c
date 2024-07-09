#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  s21_size_t str_len = s21_strlen(str);

  char *res = malloc(sizeof(char) * (str_len + 1));
  if (res) {
    for (s21_size_t i = 0; i < str_len; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        res[i] = str[i] + 32;
      } else {
        res[i] = str[i];
      }
    }
    res[str_len] = '\0';
  } else
    res = S21_NULL;

  return res;
}
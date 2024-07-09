#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if ((!src) || (!str)) {
    return S21_NULL;
  }

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  char *new = S21_NULL;

  if ((start_index <= src_len) && (src_len != 0)) {
    new = malloc((src_len + str_len + 1) * sizeof(char));
    if (!new) {
      new = S21_NULL;
    } else {
      s21_strncpy(new, src, start_index);
      s21_strncpy(new + start_index, str, str_len);
      s21_strncpy(new + start_index + str_len, src + start_index,
                  src_len - start_index);
      new[src_len + str_len] = '\0';
    }
  }

  return (void *)new;
}
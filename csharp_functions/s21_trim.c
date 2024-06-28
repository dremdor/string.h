#include "../string_functions/s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (!src) {
    return S21_NULL;
  }

  if (!trim_chars || *trim_chars == '\0') {
    trim_chars = " ";
  }

  int len = s21_strlen(src);
  int start = 0, end = len;

  while (start < len && s21_strchr(trim_chars, src[start])) {
    start++;
  }

  while (end > start && s21_strchr(trim_chars, src[end - 1])) {
    end--;
  }

  int trimmed_len = end - start;

  char *trimmed = malloc(trimmed_len + 1);
  if (!trimmed) {
    trimmed = S21_NULL;
  } else {
    s21_strncpy(trimmed, src + start, trimmed_len);
    trimmed[trimmed_len] = '\0';
  }
  return trimmed;
}
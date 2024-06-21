#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *pointer = str1;
  const char *pointer2 = str2;

  s21_size_t length = 0;
  int status = 0;

  for (s21_size_t i = 0; pointer[i] != '\0' && status == 0; i++) {
    for (s21_size_t j = 0; pointer2[j] != '\0' && status == 0; j++) {
      if (pointer[i] == pointer2[j]) status = 1;
    }
    if (status == 0) length++;
  }

  return length;
}
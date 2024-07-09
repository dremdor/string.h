#include "s21_strerror.h"

#include "../s21_string.h"

char *s21_strcpy(char *dest, const char *src);

char *s21_strerror(int errnum) {
  static char res[S21_BUFF_SIZE] = {'\0'};

  if (errnum < 0 || errnum >= S21_ERRLIST_SIZE) {
    s21_sprintf(res, ERROR " %d", errnum);
  } else {
    s21_strcpy(res, s21_sys_errlist[errnum]);
  }

  return res;
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;

  while (src[i]) {
    dest[i] = src[i];
    i++;
  }

  dest[s21_strlen(src)] = '\0';
  return dest;
}
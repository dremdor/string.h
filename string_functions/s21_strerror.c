#include "s21_strerror.h"

#include <stdio.h>
#include <string.h>

#include "s21_string.h"

char *s21_strerror(int errnum) {
  static char res[S21_BUFF_SIZE] = {'\0'};

  if (errnum < 0 || errnum >= S21_ERRLIST_SIZE) {
    sprintf(res, ERROR " %d", errnum);
  } else {
    strcpy(res, s21_sys_errlist[errnum]);
  }

  return res;
}
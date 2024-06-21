#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  char *ret = str;

  static char *last = S21_NULL;
  if (str) {
    last = str;
  }

  if ((last == 0) || (*last == 0)) {
    ret = S21_NULL;
  }

  char *c = last;  // поиск следующей позиции токена
  while (*c && s21_strchr(delim, *c)) {
    ++c;
  }
  if (*c == 0) {  // если достигнут конец строки возвращаем 0
    ret = S21_NULL;
  }

  char *start = c;  // начало найденного токена
  while (*c && s21_strchr(delim, *c) == 0) {  //поиск конца токена
    ++c;
  }
  if (*c == 0 && ret) {  // если снова достигнут конец строки возвращаем токен
    last = c;
    ret = start;
  }
  *c = 0;  // заменяем разделитель символом конца строки, чтобы отделить токены
  last = c + 1;  // перемещаем указатель ласт на следующий токен

  return (ret ? start : ret);
}
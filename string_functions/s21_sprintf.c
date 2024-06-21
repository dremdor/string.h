#include <stdarg.h>
#include <stdio.h>
#include "s21_string.h"

typedef struct {
  int spec_on;
  int plus;
  int minus;
  int space;
  int width;
  int precision;
} Specs;

void parse_int(char *buffer, int number, Specs specs);
void parse_double(char *buffer, double number, Specs specs);
int get_width(const char *format, s21_size_t *index);
void str_from_int(char *buffer, int *buffer_index, int number);
void str_from_double(char *buffer, int *buffer_index, double number);

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  Specs specs = {0, 0, 0, 0, 0, 0};
  va_start(args, format);
  int print_index = 0;
  for (s21_size_t i = 0; format[i] != '\0'; ++i) {
    char buffer[256] = "";
    if (format[i] == '%' && specs.spec_on == 0) {
      specs.spec_on = 1;
    }
    else if(format[i] == '+' && specs.spec_on == 1) {
        specs.plus = 1;
      } 
    else if (format[i] == '-' && specs.spec_on == 1) {
        specs.minus = 1;
      } 
    else if (format[i] == ' ' && specs.spec_on == 1) {
        specs.space = 1;
      } 
    else if (format[i] >= '0' && format[i] <= '9' && specs.spec_on == 1) {
        specs.width = get_width(format, &i);
      } 
    else if (format[i] == '.' && specs.spec_on == 1) {
        ++i;
        specs.precision = get_width(format, &i);
      } 
    else if (format[i] == 'c' && specs.spec_on == 1) {
        str[print_index] = va_arg(args, int);
        ++print_index;
        specs.spec_on = 0;
      } 
    else if ((format[i] == 'd' || format[i] == 'u') && specs.spec_on == 1) {
        parse_int(buffer, va_arg(args, int), specs);
        s21_strncpy(str + print_index, buffer, s21_strlen(buffer));
        print_index += s21_strlen(buffer);
        specs.spec_on = 0;
      } 
    else if (format[i] == 'f' && specs.spec_on == 1) {
        //parse_double(buffer, va_arg(args, double), specs);
        //s21_strncpy(str + print_index, buffer, s21_strlen(buffer));
        //print_index += s21_strlen(buffer);
      } 
    else if (format[i] == 's' && specs.spec_on == 1) {
        s21_strncpy(buffer, va_arg(args, char *), 1024);
        s21_strncpy(str + print_index, buffer, s21_strlen(buffer));
        print_index += s21_strlen(buffer);
        specs.spec_on = 0;
      } 
    else if (format[i] == '%' && specs.spec_on == 1) {
        str[print_index] = '%';
        ++print_index;
        specs.spec_on = 0;
      }
    else {
      str[print_index] = format[i];
      ++print_index;
    }
}
  str[print_index] = '\0';
  va_end(args);
  return s21_strlen(str);
}

int get_width(const char *format, s21_size_t *i) {
  int shift = 0;
  char number[10];
  while (format[*i] >= '0' && format[*i] <= '9') {
    number[shift] = format[*i];
    ++shift;
    ++(*i);
  }
  --(*i);
  number[shift] = '\0';
  int degree = 1;
  int width = 0;
  for (int j = s21_strlen(number) - 1; j > 0; --j, degree *= 10) {
    width += number[j] * degree;
  }
  return width;
}

void parse_int(char *buffer, int number, Specs specs) {
  int buffer_index = 0;
  if (specs.space == 1 && number >= 0) {
    buffer[buffer_index] = ' ';
    ++buffer_index;
  }
  str_from_int(buffer, &buffer_index, number);
}

void str_from_int(char *buffer, int *buffer_index, int number) {
  if (number == 0) {
    buffer[*buffer_index] = '0';
    ++(*buffer_index);
    buffer[*buffer_index] = '\0';
  } else {
    if (number < 0) {
      number = -number;
      buffer[*buffer_index] = '-';
      ++(*buffer_index);
    }
    char p[50] = "";
    int index = 0;
    while (number != 0) {
      p[index] = (number % 10) + '0';
      number /= 10;
      ++index;
    }
    for (int i = index - 1; i >= 0; --i) {
      buffer[*buffer_index] = p[i];
      ++(*buffer_index);
    }
    buffer[*buffer_index] = '\0';
  }
}
//
//void str_from_double(char *buffer, int *buffer_index, double number) {
//  int unit = (int)number;
//  double div = number - unit;
//  str_from_int(buffer, buffer_index, unit);
//}
//void parse_double(char *buffer, double number, Specs specs) {
//  int buffer_index = 0;
//  if (specs.space == 1 && number >= 0) {
//    buffer[buffer_index] = ' ';
//    ++buffer_index;
//  }
//  str_from_double(buffer, &buffer_index, number);
//}

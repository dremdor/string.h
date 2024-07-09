#include "../s21_string.h"

typedef struct {
  int spec_on;
  int plus;
  int minus;
  int space;
  int width;
  int h_length;
  int l_length;
  int precision;
} Specs;

void parse_int(char *buffer, int number, Specs specs);
void parse_double(char *buffer, double number, Specs specs);
void parse_char(char *buffer, char ch, Specs specs);
void parse_string(char *buffer, const char *string, Specs specs);
int get_width(const char *format, s21_size_t *index);
void str_from_int(char *buffer, int *buffer_index, int number);
void str_from_double(char *buffer, int *buffer_index, double number,
                     Specs specs);
void add_spaces_to_int(char *buffer, Specs specs);
void str_from_unsigned_int(char *buffer, int *buffer_index,
                           unsigned int number);
void parse_unsigned_int(char *buffer, unsigned int number, Specs specs);

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  Specs specs = {0, 0, 0, 0, 0, 0, 0, -1};
  va_start(args, format);
  int print_index = 0;
  for (s21_size_t i = 0; format[i] != '\0'; ++i) {
    char buffer[SIZE] = "";
    if (format[i] == '%' && specs.spec_on == 0) {
      specs.spec_on = 1;
    } else if (format[i] == '+' && specs.spec_on == 1) {
      specs.plus = 1;
    } else if (format[i] == '-' && specs.spec_on == 1) {
      specs.minus = 1;
    } else if (format[i] == ' ' && specs.spec_on == 1) {
      specs.space = 1;
    } else if (format[i] >= '0' && format[i] <= '9' && specs.spec_on == 1) {
      specs.width = get_width(format, &i);
    } else if (format[i] == '.' && specs.spec_on == 1) {
      ++i;
      specs.precision = get_width(format, &i);
    } else if (format[i] == 'c' && specs.spec_on == 1) {
      parse_char(buffer, va_arg(args, int), specs);
      s21_strncpy(str + print_index, buffer, s21_strlen(buffer));
      print_index += s21_strlen(buffer);
      specs.spec_on = 0;
    } else if (format[i] == 'd' && specs.spec_on == 1) {
      parse_int(buffer, va_arg(args, int), specs);
      s21_strncpy(str + print_index, buffer, s21_strlen(buffer));
      print_index += s21_strlen(buffer);
      specs.spec_on = 0;
    } else if (format[i] == 'u' && specs.spec_on == 1) {
      parse_unsigned_int(buffer, va_arg(args, unsigned int), specs);
      s21_strncpy(str + print_index, buffer, s21_strlen(buffer));
      print_index += s21_strlen(buffer);
      specs.spec_on = 0;
    } else if (format[i] == 'f' && specs.spec_on == 1) {
      parse_double(buffer, va_arg(args, double), specs);
      s21_strncpy(str + print_index, buffer, s21_strlen(buffer));
      print_index += s21_strlen(buffer);
      specs.spec_on = 0;
    } else if (format[i] == 's' && specs.spec_on == 1) {
      parse_string(buffer, va_arg(args, char *), specs);
      s21_strncpy(str + print_index, buffer, s21_strlen(buffer));
      print_index += s21_strlen(buffer);
      specs.spec_on = 0;
    } else if (format[i] == '%' && specs.spec_on == 1) {
      str[print_index] = '%';
      ++print_index;
      specs.spec_on = 0;
    } else if (format[i] == 'h' && specs.spec_on == 1) {
      specs.h_length = 1;
    } else if (format[i] == 'l' && specs.spec_on == 1) {
      specs.l_length = 1;
    } else {
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
  char number[10] = "";
  while (format[*i] >= '0' && format[*i] <= '9') {
    number[shift] = format[*i];
    ++shift;
    ++(*i);
  }
  --(*i);
  number[shift] = '\0';
  int degree = 1;
  int width = 0;
  for (int j = s21_strlen(number) - 1; j >= 0; --j, degree *= 10) {
    width += (number[j] - '0') * degree;
  }
  return width;
}

void parse_int(char *buffer, int number, Specs specs) {
  int buffer_index = 0;
  if (specs.space == 1 && number >= 0) {
    buffer[buffer_index] = ' ';
    ++buffer_index;
  } else if (specs.plus == 1 && number >= 0) {
    buffer[buffer_index] = '+';
    ++buffer_index;
  }
  str_from_int(buffer, &buffer_index, number);
  if (specs.width > (int)s21_strlen(buffer) && specs.minus == 1) {
    for (int i = s21_strlen(buffer); i < specs.width; ++i) {
      buffer[buffer_index] = ' ';
      ++buffer_index;
    }
  }
  buffer[buffer_index] = '\0';
  add_spaces_to_int(buffer, specs);
}

void parse_unsigned_int(char *buffer, unsigned int number, Specs specs) {
  int buffer_index = 0;
  str_from_unsigned_int(buffer, &buffer_index, number);
  if (specs.width > (int)s21_strlen(buffer) && specs.minus == 1) {
    for (int i = s21_strlen(buffer); i < specs.width; ++i) {
      buffer[buffer_index] = ' ';
      ++buffer_index;
    }
  }
  buffer[buffer_index] = '\0';
  add_spaces_to_int(buffer, specs);
}

void add_spaces_to_int(char *buffer, Specs specs) {
  char temp[SIZE] = "";
  int place_index = 0;
  int len = (int)s21_strlen(buffer);
  s21_strncpy(temp, buffer, len);
  if (specs.width > len) {
    for (int i = 0; i < specs.width - len; ++i) {
      buffer[place_index] = ' ';
      ++place_index;
    }
  } else if (specs.precision > 0) {
    for (int i = 0; i < specs.precision - len; ++i) {
      buffer[place_index] = '0';
      ++place_index;
    }
  }
  s21_strncpy(buffer + place_index, temp, len);
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

void str_from_unsigned_int(char *buffer, int *buffer_index,
                           unsigned int number) {
  if (number == 0) {
    buffer[*buffer_index] = '0';
    ++(*buffer_index);
    buffer[*buffer_index] = '\0';
  } else {
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

void str_from_double(char *buffer, int *buffer_index, double number,
                     Specs specs) {
  if (number < 0) {
    number = -number;
    buffer[*buffer_index] = '-';
    ++(*buffer_index);
  }
  int unit = (int)number;
  double div = number - unit;
  str_from_int(buffer, buffer_index, unit);
  if (specs.precision != 0) {
    buffer[*buffer_index] = '.';
    ++(*buffer_index);
  }
  int precision = 6;
  if (specs.precision != -1) precision = specs.precision;
  for (int i = 0; i < precision; ++i) {
    div *= 10;
    int digit = (int)div;
    buffer[*buffer_index] = '0' + digit;
    ++(*buffer_index);
    div -= digit;
  }
  if ((int)(div * 10) >= 5) {
    int i = *buffer_index - 1;
    while (i >= 0 && buffer[i] == '9') {
      buffer[i] = '0';
      --i;
    }
    if (i >= 0) {
      buffer[i] += 1;
    } else {
      for (int j = *buffer_index; j > 0; --j) {
        buffer[j] = buffer[j - 1];
      }
      buffer[0] = '1';
      ++(*buffer_index);
    }
  }

  buffer[*buffer_index] = '\0';
}

void parse_double(char *buffer, double number, Specs specs) {
  int buffer_index = 0;
  if (specs.space == 1 && number >= 0) {
    buffer[buffer_index] = ' ';
    ++buffer_index;
  } else if (specs.plus == 1 && number >= 0) {
    buffer[buffer_index] = '+';
    ++buffer_index;
  }
  str_from_double(buffer, &buffer_index, number, specs);
  if (specs.width > (int)s21_strlen(buffer) && specs.minus == 1) {
    for (int i = s21_strlen(buffer); i < specs.width; ++i) {
      buffer[buffer_index] = ' ';
      ++buffer_index;
    }
  }
  buffer[buffer_index] = '\0';
  add_spaces_to_int(buffer, specs);
}

void parse_char(char *buffer, char ch, Specs specs) {
  int buffer_index = 0;
  if (specs.width > 1 && specs.minus == 0) {
    for (int i = specs.width - 1; i > 0; --i) {
      buffer[buffer_index] = ' ';
      ++buffer_index;
    }
  }
  buffer[buffer_index] = ch;
  ++buffer_index;
  if (specs.width > 1 && specs.minus == 1) {
    for (int i = 1; i < specs.width; ++i) {
      buffer[buffer_index] = ' ';
      ++buffer_index;
    }
  }
  buffer[buffer_index] = '\0';
}

void parse_string(char *buffer, const char *string, Specs specs) {
  int buffer_index = 0;
  if (specs.width > (int)s21_strlen(string) && specs.minus == 0) {
    for (int i = specs.width - (int)s21_strlen(string); i > 0; --i) {
      buffer[buffer_index] = ' ';
      ++buffer_index;
    }
  }
  int precision = s21_strlen(string);
  if (specs.precision != -1) precision = specs.precision;
  s21_strncpy(buffer + buffer_index, string, precision);
  buffer_index += (int)s21_strlen(string);
  if (specs.width > (int)s21_strlen(string) && specs.minus == 1) {
    for (int i = (int)s21_strlen(string); i < specs.width; ++i) {
      buffer[buffer_index] = ' ';
      ++buffer_index;
    }
  }
  buffer[buffer_index] = '\0';
}
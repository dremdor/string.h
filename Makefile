LIBRARY 	= s21_string.a
FUNC_FILES 	= string_functions/s21_*.c
OBJ			= s21_*.o
FUNC_TEST	= tests/test_s21_*.c
OBJ_TEST	= test_s21_*.o
OUT_TEST	= string_test
REPORT_FILE = report/index.html

UNAME_S := $(shell uname -s)

CC			= gcc
CFLAGS		= -c -std=c11 -Wall -Werror -Wextra
L_FLAGS		= -std=c11 -Wall -Werror -Wextra
COVER_FLAG  = --coverage
LIB_FLAGS 	= ar rcs
CHECK_FILES = ./tests/*.check

ifeq ($(UNAME_S), Linux)
	OS_SPECIFIC_FLAGS 				= -lcheck -lsubunit -lm
	OS_SPECIFIC_GCOV_REPORT 		= lcov_branch_coverage=1
	OS_SPECIFIC_GCOV_REPORT_HTML 	= genhtml_branch_coverage=1
else ifeq ($(UNAME_S), Darwin)
	OS_SPECIFIC_FLAGS 				= -lcheck
    OS_SPECIFIC_GCOV_REPORT 		= branch_coverage=1
    OS_SPECIFIC_GCOV_REPORT_HTML 	= branch_coverage=1
endif

all: s21_string.a

s21_string.a: build.o
	$(LIB_FLAGS) $(LIBRARY) $(OBJ)
	rm -fr $(OBJ)

test: test_file
	./$(OUT_TEST)
	$(MAKE) gcov_report
	-rm -rf *.gc* *.info $(OUT_TEST) $(OBJ_TEST) $(OBJ) $(LIBRARY)
#	open $(REPORT_FILE)

    # Делаешь .check файл, сверху имя #suite имя_сюита, каждый тест пишешь как #test имя_тест, далее команда чекмк собирает тест.c файл самостоятельно\
	 , главное чтобы первым файлом .check был файл со всеми зависимостями, у меня он назван _main.check, соотв он всегда будет первый)как то по аскии
new_check: s21_string.a                       
	checkmk clean_mode=1 $(CHECK_FILES) > test.c
	$(CC) $(COVER_FLAG) test.c -L. $(LIBRARY) $(OS_SPECIFIC_FLAGS) -o $(OUT_TEST)


test_file: s21_string.a_for_test build_test.o
	$(CC) $(L_FLAGS) $(COVER_FLAG) $(OBJ_TEST) tests/main.c -L. $(LIBRARY) $(OS_SPECIFIC_FLAGS) -o $(OUT_TEST)

s21_string.a_for_test: build_object_for_test.o
	$(LIB_FLAGS) $(LIBRARY) $(OBJ)
	rm -fr $(OBJ)

build.o:
	$(CC) $(CFLAGS) $(FUNC_FILES)

build_object_for_test.o:
	$(CC) $(CFLAGS) $(COVER_FLAG) $(FUNC_FILES)

build_test.o:
	$(CC) $(CFLAGS) $(FUNC_TEST)

gcov_report:
	lcov -t "test" -o string.info -c -d . --rc $(OS_SPECIFIC_GCOV_REPORT)
	genhtml -o report string.info --rc $(OS_SPECIFIC_GCOV_REPORT_HTML)

build_o: $(FUNC_FILES)
	$(CC) $(CFLAGS) $(FUNC_FILES)

rebuild: clean all

clean:
	rm -rf $(OBJ) $(OUT_TEST) $(OBJ_TEST) $(LIBRARY) $(OUT_TEST) *.gc* report/ *.info

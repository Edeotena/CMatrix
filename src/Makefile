CC = gcc

FLAGS = -Wall -Wextra -Werror -std=c11 -fanalyzer -pedantic

ADDITIONAL_FLAGS = -lcheck
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ADDITIONAL_FLAGS += -lsubunit -lm
endif
#ifeq ($(UNAME_S),Darwin)
#	something for MACOS
#endif

SRC_C_FILES = lib/*.c

TEST_C_FILES = tests/*.c

TEST_TARGET  = s21_test

LIB = s21_matrix.a

REPORT_DIR = report

all: clean test gcov_report $(LIB)

apply_clang: 
	cp ../materials/linters/.clang-format .
	clang-format -i *.[ch]
	clang-format -i */*.[ch]
	rm -f .clang-format

test: apply_clang $(SRC_C_FILES)
	$(CC) $(FLAGS) $(SRC_C_FILES) $(TEST_C_FILES) -o $(TEST_TARGET) $(ADDITIONAL_FLAGS)
	./$(TEST_TARGET)

build: apply_clang $(SRC_C_FILES)
	$(CC) $(FLAGS) $(SRC_C_FILES) main.c -o s21_main $(ADDITIONAL_FLAGS)
	./s21_main

gcov_report: apply_clang
	$(CC) --coverage $(FLAGS) $(SRC_C_FILES) $(TEST_C_FILES) -o $(TEST_TARGET) $(ADDITIONAL_FLAGS)
	./$(TEST_TARGET)
	lcov -t "$(TEST_TARGET)" -o $(TEST_TARGET).info -c -d .
	genhtml -o report $(TEST_TARGET).info
	rm *.gcda *.gcno *.info
	open report/index.html

$(LIB): apply_clang
	$(CC) -c $(SRC_C_FILES) $(ADDITIONAL_FLAGS)
	ar rcv $(LIB) *.o
	ranlib $(LIB)
	rm *.o

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem .

clean_test:
	rm -f $(TEST_TARGET)

clean_report:
	rm -rf $(REPORT_DIR)

clean_lib:
	rm -f $(LIB)

clean_obj:
	rm -f *.o

clean_gcov:
	rm -f *.gc*

clean: clean_test clean_report clean_lib clean_obj clean_gcov
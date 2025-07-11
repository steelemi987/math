CC=gcc
CFLAGS = -Wall -Werror -Wextra -c -std=c11

all: s21_math.a
s21_math.a: 
	$(CC) $(CFLAGS) math_funcs/*.c
	ar rcs s21_math.a *.o
test: s21_math.a
	$(CC) $(CFLAGS) math_test.c
	$(CC) -L. -I. -o math_test math_test.c s21_math.a `pkg-config --cflags --libs check`
gcov_report:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage math_funcs/*.c
	ar rcs s21_math_gcov.a *.o
	ranlib s21_math_gcov.a
	$(CC) $(CFLAGS) math_test.c
	$(CC) -L. -I. -o math_test math_test.o s21_math_gcov.a -lgcov `pkg-config --cflags --libs check`
	./math_test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
clean:
	rm math_test test.log s21_math.a *.o *.gcno *gcov.a *.gcda *.info
	rm -rf report

rebuild:
	make clean
	make test

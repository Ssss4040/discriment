CC = gcc -std=c11 -Wall -Wextra -Werror -g
OS = $(shell uname)
GCOVFLAGS = -L. --coverage

ifeq ($(OS), Linux)
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	FLAGS = -lcheck -lm
endif

all: clean clang test
	
test: 
	$(CC) -o test_runner test_for_quadratic_equation.c quadratic_equation.c $(FLAGS)
	./test_runner


s21_quadratic_equation.a:
	ar -rc s21_quadratic_equation.a
	ranlib s21_quadratic_equation.a
	rm -f *.o


s21_quadratic_equation.o:
	$(CC) -c s21_quadratic_equation.c

clang:
	clang-format -style=google -i *.c
	clang-format -style=google -i *.h

git: clean
	git add . && git commit -m "add" && git push

clean:
	rm -rf *.o *.a test_runner

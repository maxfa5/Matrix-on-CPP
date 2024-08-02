CC = g++
CFLAGS =-std=c++17 -Wall -Wextra -Werror -lm  
SRC = s21*.cpp
TEST_SRC = tests/*test*.cpp
LIBSFLAGS = -lgtest  -pthread -lgcov
GCOV_FLAGS = -fprofile-arcs -ftest-coverage  --coverage 
LIB = s21_matrix_oop.a
GCOVR_PATH = gcovr
# ~/.local/bin/gcovr 
# gcovr
REPORT = report/index.html

all : $(LIB)

$(LIB):
	rm -rf $(LIB)
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(LIB) *.o
	ranlib $(LIB)
	rm -rf *.o

test: clean $(LIB)
	$(CC) $(CFLAGS) -L. -l:$(LIB) $(GCOV_FLAGS) $(SRC) ${TEST_SRC} -o test_result $(LIBSFLAGS) -g 
	./test_result
	
val: 
	valgrind --tool=memcheck --leak-check=yes -s  --leak-check=full --show-leak-kinds=all --track-origins=yes  ./test_result

gcov_report: test
	mkdir report
	${GCOVR_PATH} -r . --html --exclude-throw-branches  --exclude-unreachable-branches --html-details  -o $(REPORT)  -e tests/test.cpp  -e tests/test_accesors_mutators.cpp -e tests/test_sum_sub.cpp -e tests/test_construct.cpp -e tests/test_deter.cpp -e 	tests/test_eq.cpp -e tests/test_inverse_compl.cpp -e tests/test_mul.cpp -e tests/test_transpose.cpp
	xdg-open $(REPORT)

clean:
	rm -rf test_result
	rm -rf report
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.a
	rm -rf result

rebuild: clean all

check:
	clang-format -n $(SRC) $(TEST_SRC) tests/test.h *.h
	
fix:
	clang-format -i $(SRC) $(TEST_SRC) tests/test.h *.h

cppcheck:
	cppcheck --enable=all --force --suppress=missingIncludeSystem --language=c++ $(SRC) *.h

manual_test: $(LIB)
	$(CC) $(SRC) ./tests/main.cpp $(CFLAGS) -o  result -g
	./result

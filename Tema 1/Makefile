CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: algo1_test.o algo2_test.o 

run-best:
	./test1

run-p1:
	./test1

run-p2:
	./test2

algo1.o: algo1.cpp
	g++ algo1.cpp -c $(CFLAGS)

algo1_test.o: algo1_test.cpp algo1.o
	g++ algo1.o algo1_test.cpp -o test1 $(CFLAGS)

algo2.o: algo2.cpp
	g++ algo2.cpp -c $(CFLAGS)

algo2_test.o: algo2_test.cpp algo2.o
	g++ algo2.o algo2_test.cpp -o test2 $(CFLAGS)


.PHONY: clean

clean:
	rm -rf *.o test1 test2 test.in test.out


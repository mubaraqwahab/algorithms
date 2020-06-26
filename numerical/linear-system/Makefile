jacobi: norm.o
	g++ -Wall jacobi.cpp norm.o -o jacobi.out

gaussseidel: norm.o
	g++ -Wall gaussseidel.cpp norm.o -o gaussseidel.out

norm.o:
	g++ -Wall -c norm.cpp

.PHONY: clean
clean:
	rm -fv *.o *.out
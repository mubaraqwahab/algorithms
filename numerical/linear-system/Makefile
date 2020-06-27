jacobi: norm.o
	g++ -Wall jacobi.cpp norm.o -o jacobi

gaussseidel: norm.o
	g++ -Wall gaussseidel.cpp norm.o -o gaussseidel

norm.o:
	g++ -Wall -c norm.cpp

.PHONY: clean
clean:
	rm -fv *.o jacobi gaussseidel
executables = jacobi gaussseidel

$(executables): % : %.cpp norm.o
	g++ -Wall $^ -o $@

norm.o:
	g++ -Wall -c norm.cpp

.PHONY: clean
clean:
	rm -fv *.o $(executables)

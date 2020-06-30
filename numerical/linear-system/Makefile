executables = jacobi gaussseidel
flags = -Wall -Wno-sign-compare

$(executables): % : %.cpp norm.o
	g++ $(flags) $^ -o $@

norm.o:
	g++ $(flags) -c norm.cpp

.PHONY: clean
clean:
	rm -fv *.o $(executables)

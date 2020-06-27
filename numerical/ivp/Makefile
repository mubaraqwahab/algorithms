executables = euler heun rungekutta4

$(executables): % : %.cpp
	g++ -Wall $^ -o $@

.PHONY: clean
clean:
	rm -fv *.o $(executables)

executables = polygonarea simplex

$(executables): % : %.cpp
	g++ -Wall $^ -o $@

.PHONY: clean
clean:
	rm -fv *.o $(executables)

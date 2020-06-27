polygonarea: % : %.cpp
	g++ -Wall $^ -o $@

simplex: % : %.cpp %-helpers.cpp
	g++ -Wall $^ -o $@

.PHONY: clean
clean:
	rm -fv *.o polygonarea simplex

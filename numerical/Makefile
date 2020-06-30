# -Wno-sign-compare flag is to disable the -Wsign-compare warning:
# "comparison between signed and unsigned integer expressions"

polygonarea: % : %.cpp
	g++ -Wall -Wno-sign-compare $^ -o $@

.PHONY: clean
clean:
	rm -fv *.o polygonarea

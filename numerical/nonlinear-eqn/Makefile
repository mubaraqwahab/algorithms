executables = fixedpoint newtonraphson secant bisection falseposition

# For % and %.cpp in the following, see https://www.gnu.org/software/make/manual/make.html#Static-Pattern
# What they do here (simply): if 'abc' is a target, then 'abc.cpp' should be its prerequisite

# $^ = all prerequisites
# $@ = filename of target
# See https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables

$(executables): % : %.cpp
	g++ -Wall $^ -o $@

.PHONY: clean
clean:
	rm -fv *.o $(executables)
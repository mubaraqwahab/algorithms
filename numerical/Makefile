# (Use -I to specify include path)

# Directory for ivp algorithms
ivpdir = ivp
# Directory for nonlinear equations algorithms
nledir = nonlinear-eqn

# IVP

fixedpoint:
	g++ -Wall $(nledir)/fixedpoint.cpp -o $(nledir)/fixedpoint.out

newtonraphson:
	g++ -Wall $(nledir)/newtonraphson.cpp -o $(nledir)/newtonraphson.out

secant:
	g++ -Wall $(nledir)/secant.cpp -o $(nledir)/secant.out

# NLE

euler:
	g++ -Wall $(ivpdir)/euler.cpp -o $(ivpdir)/euler.out

.PHONY: clean
clean:
	rm -fv *.o *.out
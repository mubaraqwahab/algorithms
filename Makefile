selectionsort:
	g++ selectionsort.cpp -o selectionsort.out

bubblesort:
	g++ bubblesort.cpp -o bubblesort.out

.PHONY: clean
clean:
	rm -fv *.o *.out
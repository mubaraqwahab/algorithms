selectionsort:
	g++ selectionsort.cpp -o selectionsort.out

bubblesort:
	g++ bubblesort.cpp -o bubblesort.out

sequentialsearch:
	g++ sequentialsearch.cpp -o sequentialsearch.out

.PHONY: clean
clean:
	rm -fv *.o *.out
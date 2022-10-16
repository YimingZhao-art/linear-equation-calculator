

determinant.o : determinant.cpp
	g++ -c determinant.cpp -o determinant.o

linear_equations.o : linear_equations.cpp
	g++ -c linear_equations.cpp -o linear_equations.o

main : linear_equations.o determinant.o
	g++ -o main linear_equations.o determinant.o -pedantic-errors -std=c++11

clean:
	rm *.o

.PHONY: clean 

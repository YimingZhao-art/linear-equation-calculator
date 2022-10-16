#include <iostream>
#include <cmath>
#include "determinant.h"
using namespace std;


double ** Substitute(double ** D, double * S, int n, int i){
	double ** N ;
	N = new double * [n];
	for ( int j = 0; j < n; j++ ){
		N[j] = new double [n];
	}
	
	for ( int j = 0; j < n; j++ ){
		N[j][i] = S[j];
	}
	
	for ( int p = 0; p < n; p++ ){
		for ( int q = 0; q < n; q++ ){
			if ( q == i )
				continue;
			else {
				N[p][q] = D[p][q];
			}
		}
	}
	return N;
}

void Solve(double ** D, int n, double * S){
	double answer = 0;
	double under = Cal(D,n);
	double on;
	for ( int i = 0; i < n; i++ ){
		double ** N = Substitute(D, S, n, i);
		on = Cal(N,n);
		answer = on / under;
		cout << "x" << i << ": " << answer << endl;
	}
}

int main() {
	int size;
	cout << "Choose the size: ";
	cin >> size;
	
	cout << "input the coefficent in order: \n";
	double ** D = SetDeterminant(size);
	
	double * S;
	S = new double [size];
	cout << "Input the right part: \n";
	for ( int i = 0; i < size; i++ )
		cin >> S[i];
	
	if ( Cal(D, size) == 0 ){
		cout << "No solution!n";
		return 0;
	}
	
	Solve(D,size,S);
}
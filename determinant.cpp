#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void ** printD(int ** D, int n){
	for ( int i = 0; i < n; i++ ){
		for ( int j = 0; j < n; j++ ){
			cout << setw(3) << fixed << D[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}


double ** sub( double ** D, int x, int y, int n ){
	double ** Sub;
	Sub = new double * [n-1];
	for ( int i = 0; i < n-1; i++ ){
		Sub[i] = new double [n-1];
	}
	int row = 0;
	for ( int i = 0; i < n; i++ ){
		if ( i == x )
			continue;
		int col = 0;
		for ( int j = 0; j < n; j++ ){
			if ( j == y )
				continue;
			Sub[row][col] = D[i][j];
			col++;
		}
		row++;
	}
	return Sub;
}

double Cal(double ** D, int n){
	double answer = 0;
	if ( n == 1 )
		answer = D[0][0];
	else if ( n == 2 )
		answer = D[0][0]*D[1][1] - D[1][0]*D[0][1];
	else {
		for ( int i = 0; i < n; i++ ){
			
			answer += Cal( sub(D,0,i,n), n-1 ) * pow(-1,i) * D[0][i];
		}
	}
	return answer;
}



double ** SetDeterminant(int n) {
	
	double ** D;
	D = new double * [n];
	
	for ( int i = 0; i < n; i++ ){
		D[i] = new double [n];
	}
	
	for ( int i = 0; i < n; i++ ){
		for ( int j = 0; j < n; j++ ){
			cin >> D[i][j];
		}
	}
	
	/*print(D,n);
	print(sub(D, 1, 1, n),n-1); */

	return D;
}
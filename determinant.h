#ifndef DETERMINANT_H
#define DETERMINANT_H

void ** printD(double ** D, int n);
double ** sub( double ** D, int x, int y, int n );
double Cal(double ** D, int n);
double ** SetDeterminant(int n);

#endif
/*---------------------------------------------*
 * Header file for poly.c		       *
 * contains function and structure definitions *
 *					       *
 * authors: Oisín O'Halloran, Peter Roe,       *
 * 	    T.J. Kenneally, Petru Zelenitchi,  *
 * 	    George Raju			       *
 *					       *
 * date: 29/11/18			       *
 *---------------------------------------------*/

#ifndef POLY_H
#define POLY_H

//include standard library functions
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//data structure for single polynomial
//int coeff[] --> variable length array of coefficients
//int size --> size of the coeff array
//
//structure must be initialised with make_poly() in order
//to allocate memory
typedef struct{
	int size;
	double coeff[];
}poly;

//------------functions------------

//poly createion and deletion functions --Oisín
poly* make_poly(int size);
poly* create_poly(int size, double coefficients[]);
void delete_poly(poly* in);

//poly add and subtract funtions --Peter
poly* poly_add(poly* a, poly* b);
poly* poly_sub(poly* a, poly* b);

//poly print and order functions --TJ
void print_poly(poly* a);
poly* poly_order(poly* a);

//poly division and normalisation --Petru
poly* poly_division (poly* a, double x);
poly* poly_normalise (poly* a);

//extra functions
int poly_equal(poly* a,poly *b);

#endif

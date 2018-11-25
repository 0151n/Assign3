/*---------------------------------------------*
 * Header file for poly.c		       *
 * contains function and structure definitions *
 *
 * authors: Oisín O'Halloran --add other people*
 * date 23/11/18			       *
 *---------------------------------------------*/

#ifndef POLY_H
#define POLY_H

//include standard library functions
#include<stdio.h>
#include<stdlib.h>

//data structure for single polynomial
//int coeff[] --> variable length array of coefficients
//int size --> size of the coeff array
//
//structure must be initialised with make_poly() in order
//to allocate memory
typedef struct{
	double coeff[];
	int size;
}poly;

//------------functions------------

poly* make_poly(int size);

#endif

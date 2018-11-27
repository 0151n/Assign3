/*---------------------------------------------*
 * file containing all functions regarding the *
 * manipulation of polynomials                 *
 *                                             *
 * authors: Oisín O'Halloran --add others      *
 * date: 23/11/18                              *
 * --------------------------------------------*/

#include"poly.h"

// poly* make_poly(int size)
// function to create a "poly" structure in memory given its size
// parameters:
// 	size --> size fo the polynomial (e.g. number of coefficients)
// return:
// 	poly* --> pointer to the newly allocated poly structure in memory
poly* make_poly(int size){
	int i; //counter integer for for loop
	//allocate memory for struct
	poly* out = malloc(sizeof(poly) + size*sizeof(double));
	//if memory allocation fails
	if(out == NULL){
		printf("MEMORY ALLOCATION FAILED\n");
		return NULL;
	}
	//set size variable in newly allocated poly struct
	out->size = size;
	//set all values in coeff to zero
	for(i = 0;i < size;i++)out->coeff[i] = 0;
	//return pointer to new poly structure
	return out;
}

// poly* create_poly(int size,double coefficients)
// function to create a polynimial and then fill it with user defined values
// parameters:
// 	size --> size of the polynimial as an int
// 	coefficients --> array of coefficients as doubles
// returns:
// 	poly* --> pointer to newly allocated and assigned poly structure
poly* create_poly(int size,double coefficients[]){
	int i;//counter variable
	//create new polynomial
	poly* newpoly = make_poly(size);
    
    for(i = 0;i < size;i++)newpoly->coeff[i] = coefficients[i];         
	return newpoly;
}
//poly* delete_poly(poly* in)
//function to delete a polynomial from memory
//parameters:
//  in --> pointer to poly structure to be deleted
//returns:
// void
void delete_poly(poly* in){
   //free memory pointed to by in 
   free(in);
}

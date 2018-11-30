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


// polyAdd
// Parameters: 
// poly* a: Memory address for poly a
// poly* b: Memory address for poly b
// Return: Poly with value of a + b
poly* polyAdd(poly* a, poly* b)
{
  // Find sizes of polys relative to eachother
  int aBig = 0;
  int small = a->size;
  int big = b->size;
  if(a->size > b->size){
    small = b->size;
    big = a->size;
    aBig = 1;
  }
  poly* sum = make_poly(big);
  // Add respective overlapping coefficients
  for(int i = 0; i < small;i++)
    sum->coeff[i] = a->coeff[i] + b->coeff[i];
  // Add non-overlapping coefficients to answer
  for(int i = small; i < big; i++)
    if(aBig)
	sum->coeff[i] = a->coeff[i];
    else
	sum->coeff[i] = b->coeff[i];
  // Return answer poly
  return sum;
}

// polySub
// Parameters: 
// poly* a: Memory address for poly a
// poly* b: Memory address for poly b
// Return: Poly with value of a - b
poly* polySub(poly* a, poly* b)
{
  // Find sizes of polys relative to eachother
  int aBig = 0;
  int small = a->size;
  int big = b->size;
  if(a->size > b->size){
    small = b->size;
    big = a->size;
    aBig = 1;
  }
  poly* sub = make_poly(big);
  // Add respective overlapping coefficients
  for(int i = 0; i < small;i++)
    sub->coeff[i] = a->coeff[i] - b->coeff[i];
  // Add non-overlapping coefficients to answer
  for(int i = small; i < big; i++)
    if(aBig)
	sub->coeff[i] = a->coeff[i];
    else
	sub->coeff[i] = -(b->coeff[i]);
  // Return answer poly
  return sub;
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

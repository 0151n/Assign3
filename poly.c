/*---------------------------------------------*
 * file containing all functions regarding the *
 * manipulation of polynomials                 *
 *                                             *
 * authors: Oisín O'Halloran --add others       *
 * date: 23/11/18                              *
 * --------------------------------------------*/

#include"poly.h"

//poly* make_poly(int size)
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
  int size = a->size;
  if(a->size < b->size)
    size = b->size;
  poly* sum = make_poly(size);
  for(int i = 0; i < size;i++){
    sum->coeff[i] = a->coeff[i] + b->coeff[i];
  }
  return sum;
}

// polySub
// Parameters: 
// poly* a: Memory address for poly a
// poly* b: Memory address for poly b
// Return: Poly with value of a - b
poly* polySub(poly* a, poly* b)
{
  int size = a->size;
  if(a->size < b->size)
    size = b->size;
  poly* sub = make_poly(size);
  for(int i = 0; i < size;i++){
    sub->coeff[i] = a->coeff[i] - b->coeff[i];
  }
  return sub;
}

/*---------------------------------------------*
 * file containing all functions regarding the *
 * manipulation of polynomials                 *
 *					       *
 * authors: Oisín O'Halloran, Peter Roe,       *
 * 	    T.J. Kenneally, Petru Zelenitchi,  *
 * 	    George Raju			       *
 *					       *	
 * date: 29/11/18                              *
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


// poly* poly_add(poly* a, poly* b)
// Parameters: 
// poly* a: Memory address for poly a
// poly* b: Memory address for poly b
// Return: Poly with value of a + b
poly* poly_add(poly* a, poly* b)
{
  // Find sizes of polys relative to eachother
  int i; //counter varialbes
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
  for(i = 0; i < small;i++)
    sum->coeff[i] = a->coeff[i] + b->coeff[i];
  // Add non-overlapping coefficients to answer
  for(i = small; i < big; i++)
    if(aBig)
	sum->coeff[i] = a->coeff[i];
    else
	sum->coeff[i] = b->coeff[i];
  // Return answer poly
  return sum;
}

// poly* poly_sub(poly* a, poly* b)
// Parameters: 
// poly* a: Memory address for poly a
// poly* b: Memory address for poly b
// Return: Poly with value of a - b
poly* poly_sub(poly* a, poly* b)
{
  // Find sizes of polys relative to eachother
  int i; // counter variable
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
  for(i = 0; i < small;i++)
    sub->coeff[i] = a->coeff[i] - b->coeff[i];
  // Add non-overlapping coefficients to answer
  for(i = small; i < big; i++)
    if(aBig)
	sub->coeff[i] = a->coeff[i];
    else
	sub->coeff[i] = -(b->coeff[i]);
  // Return answer poly
  return sub;
}

// void print_poly(poly*a)
// function to print a polynomial including exponents
// parameters:
// 	poly* a = a previously created poly
// returns:
// 	void
void print_poly(poly* a){
    int i; //For loop index
    int size = a->size; //int size = to the size stored in memory for a
    
//    printf("\nPolynomial contains: \n");//Print a heading for print_poly output
    for (i = 0; i <= size - 1; i++){
		if(a->coeff[i] > 0 && i != 0)printf(" + ");//if positive print with +
		else if(a->coeff[i] < 0)printf(" ");
        printf("%lfx^%d",a->coeff[i],i);//print each element from the array in with exponent   
	}
    printf("\n");//Move next output to new line
}

// poly* order_poly(poly* a)
// function to return order a polynomial from highest coefficient downwards
// parameters:
// 	poly* order = the polynomial that is to be reordered
// returns:
// 	return a poly with orders descending from highest coefficient

int poly_order(poly* order){
	int i; //counter variables for use in function

	//loop through coeff array of order polynomial from the last element to the first 
	for(i = order->size - 1;i > 0;i--){
			if(order->coeff[i] != 0)return i;
	}
	return 0;//Return newly order polynomial
}

// poly* poly_division (poly* a,double x) 
// Function to divide all coefficients in a polynomial by a double
// Parameters:   
// poly* a: Memory address for poly a 
// double x : Double to be divided by
// Return: Poly with value of a/x  
poly* poly_division (poly* a,double x) 
{
    int i; // counter variable
    int size = a->size; 
    poly* division = make_poly(size); //make new poly the same size as the input
    for(i = 0; i < size;i++){ //loop through each coefficient of inputted poly
        division->coeff[i] = a->coeff[i] / x; //divide each coefficient by double x and set as coefficient of new poly
    } 
    return division; //return new poly
} 

// poly* poly_normalise (poly* a,double c) 
// function to normalise a polynomial
// Parameters:   
// poly* a: Memory address for poly a 
// Return: Normalised poly

poly* poly_normalise (poly* a) 
{ 
    int size = a->size;
    double c = a->coeff[size - 1]; //get value of coeffiecient with highest term
    int i; //counter variable
    poly* normalise = make_poly(size); //make new poly of the same size as input
    for(i = 0; i < size;i++){ //loop through each coefficient
        normalise->coeff[i] = a->coeff[i] / c; //divide each coefficient by value of coefficient of largest term
    } 
    return normalise; 
}
// int poly_equal(poly* a, poly* b)
// function to check if two polynomials are equal
// Parameters:
// poly* a: memory address of poly a
// poly* b: memory address of poly b
// return:
//  int: 1 if equal, 0 if not equal
int poly_equal(poly* a, poly* b){
	int i; //counter variable
	//make sure both polys are same size
	if(a->size != b->size)return 0; //return 0 if sizes are not the same
	for(i = 0;i < a->size;i++){ //loop through each element of coefficient array
		if(a->coeff[i] != b->coeff[i])return 0;//return 0 if coefficients are not the same
	}
	return 1; //if coefficients are the same
}

//poly* poly_multiply (poly* a, double x)
//Parameters:
//  poly* a: Memory address for poly a
//  double x: Double to be multiplied by
//Return: Answer of Poly with value of a multiplied by x
poly* poly_multiply(poly* a, double x) {
  
  int i;  //Variable for counter
  int size = a->size;

  poly* multiply = make_poly(size);//Make the new poly the same size as the input
  for(i=0;i<size;i++){ //Loop through each coefficient of inputted poly
    multiply->coeff[i] = a->coeff[i] * x;//multiply each coefficient by double x and set as coefficient of new poly
  }

  return multiply; //Return new poly
}

// poly* poly_input(char name)
// function to input a polynomial from the user
// parameters:
// 	char name --> name of the poly
// return:
// 	pointer to inputed poly in memory
poly* poly_input(char name)
{
  int i;
  int power;
  printf("Highest power of poly %c:",name);
  scanf("%d",&power);
  double values[power+1];
  for(i = 0; i < power+1; i ++){
    printf("Enter coefficient for x^%d: ",i);
    scanf("%lf",&values[i]);
  }
  return create_poly(power+1,values);
}





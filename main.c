/*---------------------------------------------*
 * File containing main function for project3  *
 *					       *
 * authors: Oisín O'Halloran, Peter Roe,       *
 * 	    T.J. Kenneally, Petru Zelenitchi,  *
 * 	    George Raju			       *
 *					       *	
 * date: 29/11/18                              *
 * --------------------------------------------*/
#include"poly.h"

// int run_testcases()
// function to run test cases on all funtions in project
// parameters:
// 	none
// return
// 	int: 1 if test successful, 0 if unsuccessful
int run_testcases(){
	//test cases for addition
	//two polys of same size
	//create data structures
	double add1[] = {1,2,3};
	double add2[] = {3,2,1};
	double res1[] = {4,4,4};
	
	poly* addcase1 = create_poly(3,add1);
	poly* addcase2 = create_poly(3,add2);
	poly* expected_result1 = create_poly(3,res1);
	poly* result1 = poly_add(addcase1,addcase2);
	
	printf("TEST CASE 1: ADD TWO POLYNOMIALS OF THE SAME SIZE\n");
	printf("-------------------------------------------------\n");
	printf("ADD:\n");
	print_poly(addcase1);
	printf("AND:\n");
	print_poly(addcase2);
	printf("\nEXPECTED RESULT = ");
	print_poly(expected_result1);
	printf("ACTUAL RESULT     = ");
	print_poly(result1);
	if(poly_equal(expected_result1,result1))printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- ");		
	printf("-------------------------------------------------\n");

	//two polys of different size
	double add3[] = {1,1,2,3};
	double res2[] = {1,4,4,4};

	poly* addcase3 = create_poly(4,add3);
	poly* expected_result2 = create_poly(3,res2);
	poly* result2 = poly_add(addcase1,addcase3);
	
	printf("TEST CASE 2: ADD TWO POLYNOMIALS OF THE SAME SIZE\n");
	printf("-------------------------------------------------\n");
	printf("ADD:\n");
	print_poly(addcase1);
	printf("AND:\n");
	print_poly(addcase3);
	printf("\nEXPECTED RESULT = ");
	print_poly(expected_result2);
	printf("ACTUAL RESULT     = ");
	print_poly(result2);
	if(poly_equal(expected_result2,result2))printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- \n");		
	printf("-------------------------------------------------\n");


}

int main(){
	run_testcases();
}

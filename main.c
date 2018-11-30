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
//	void
void run_testcases(){
	//test cases for addition
	//two polys of same size
	
	//create arrays of coefficients for creating polynomials
	double add1[] = {1,2,3};
	double add2[] = {3,2,1};
	double res1[] = {4,4,4};
	
	//create polynomials
	poly* addcase1 = create_poly(3,add1);
	poly* addcase2 = create_poly(3,add2);
	poly* expected_result1 = create_poly(3,res1);
	//perform addition operation
	poly* result1 = poly_add(addcase1,addcase2);

	//run test case	
	printf("TEST CASE 1: ADD TWO POLYNOMIALS OF THE SAME SIZE\n");
	printf("-------------------------------------------------\n");
	printf("ADD:\n");
	print_poly(addcase1);
	printf("AND:\n");
	print_poly(addcase2);
	printf("\nEXPECTED RESULT = ");
	print_poly(expected_result1);
	printf("ACTUAL RESULT   = ");
	print_poly(result1);
	if(poly_equal(expected_result1,result1))printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- ");		
	printf("-------------------------------------------------\n");

	//two polys of different size
	//create arrays of coefficients for creating polynomials
	double add3[] = {3,2,1,1};
	double res2[] = {4,4,4,1};
	//create polynomials
	poly* addcase3 = create_poly(4,add3);
	poly* expected_result2 = create_poly(4,res2);
	//perform addition operation
	poly* result2 = poly_add(addcase1,addcase3);
	
	//run test case
	printf("TEST CASE 2: ADD TWO POLYNOMIALS OF DIFFERENT SIZE\n");
	printf("-------------------------------------------------\n");
	printf("ADD:\n");
	print_poly(addcase1);
	printf("AND:\n");
	print_poly(addcase3);
	printf("\nEXPECTED RESULT = ");
	print_poly(expected_result2);
	printf("ACTUAL RESULT   = ");
	print_poly(result2);
	if(poly_equal(expected_result2,result2))printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- \n");		
	printf("-------------------------------------------------\n");

	//test cases for subtraction
	//two polys of same size
	
	//create arrays of coefficients for creating polynomials
	double sub1[] = {1,2,3};
	double sub2[] = {1,2,3};
	double res3[] = {0,0,0};
	
	//create polynomials
	poly* subcase1 = create_poly(3,sub1);
	poly* subcase2 = create_poly(3,sub2);
	poly* expected_result3 = create_poly(3,res3);
	//perform subtraction operation
	poly* result3 = poly_sub(subcase1,subcase2);

	//run test case	
	printf("TEST CASE 3: SUBTRACT TWO POLYNOMIALS OF THE SAME SIZE\n");
	printf("-------------------------------------------------\n");
	printf("SUBTRACT:\n");
	print_poly(subcase1);
	printf("AND:\n");
	print_poly(subcase2);
	printf("\nEXPECTED RESULT = ");
	print_poly(expected_result3);
	printf("ACTUAL RESULT   = ");
	print_poly(result3);
	if(poly_equal(expected_result3,result3))printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- ");		
	printf("-------------------------------------------------\n");

	//two polys of different size
	//create arrays of coefficients for creating polynomials
	double sub3[] = {3,2,1,1};
	double res4[] = {-2,0,2,-1};
	//create polynomials
	poly* subcase3 = create_poly(4,sub3);
	poly* expected_result4 = create_poly(4,res4);
	//perform subtraction operation
	poly* result4 = poly_sub(subcase1,subcase3);
	
	//run test case
	printf("TEST CASE 4: SUBTRACT TWO POLYNOMIALS OF DIFFERENT SIZE\n");
	printf("-------------------------------------------------\n");
	printf("SUBTRACT:\n");
	print_poly(subcase1);
	printf("AND:\n");
	print_poly(subcase3);
	printf("\nEXPECTED RESULT = ");
	print_poly(expected_result4);
	printf("ACTUAL RESULT   = ");
	print_poly(result4);
	if(poly_equal(expected_result4,result4))printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- \n");		
	printf("-------------------------------------------------\n");

	//test cases for division
	//create arrays of coefficients for creating polynomials
	double div1[] = {1,2,3};
	double res5[] = {0.5f,1,1.5f};
	double divisor1 = 2;
	
	//create polynomials
	poly* divcase1 = create_poly(3,div1);
	poly* expected_result5 = create_poly(3,res5);
	//perform divtraction operation
	poly* result5 = poly_division(divcase1,divisor1);

	//run test case	
	printf("TEST CASE 5: DIVIDE A POLYNOMIAL OF SIZE 3 BY DOUBLE\n");
	printf("-------------------------------------------------\n");
	printf("DIVIDE:\n");
	print_poly(divcase1);
	printf("BY:\n");
	printf("%lf\n",divisor1);
	printf("\nEXPECTED RESULT = ");
	print_poly(expected_result5);
	printf("ACTUAL RESULT   = ");
	print_poly(result5);
	if(poly_equal(expected_result5,result5))printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- ");		
	printf("-------------------------------------------------\n");

	//poly of length 4
	//create arrays of coefficients for creating polynomials
	double div2[] = {10,2.5,5,15};
	double res6[] = {4,1,2,6};
	double divisor2 = 2.5;
	
	//create polynomials
	poly* divcase2 = create_poly(4,div2);
	poly* expected_result6 = create_poly(4,res6);
	//perform division operation
	poly* result6 = poly_division(divcase2,divisor2);

	//run test case	
	printf("TEST CASE 6: DIVIDE A POLYNOMIAL OF SIZE 4 BY DOUBLE\n");
	printf("-------------------------------------------------\n");
	printf("DIVIDE:\n");
	print_poly(divcase2);
	printf("BY:\n");
	printf("%lf\n",divisor2);
	printf("\nEXPECTED RESULT = ");
	print_poly(expected_result6);
	printf("ACTUAL RESULT   = ");
	print_poly(result6);
	if(poly_equal(expected_result6,result6))printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- ");		
	printf("-------------------------------------------------\n");

	//test cases for multiplication
	//create arrays of coefficients for creating polynomials
	double mul1[] = {1,2,3};
	double res7[] = {10,20,30};
	double multiplier1 = 10;
	
	//create polynomials
	poly* mulcase1 = create_poly(3,mul1);
	poly* expected_result7 = create_poly(3,res7);
	//perform divtraction operation
	poly* result7 = poly_multiply(mulcase1,multiplier1);

	//run test case	
	printf("TEST CASE 7: MULTIPLY A POLYNOMIAL OF SIZE 3 BY DOUBLE\n");
	printf("-------------------------------------------------\n");
	printf("MULTIPLY:\n");
	print_poly(mulcase1);
	printf("BY:\n");
	printf("%lf\n",multiplier1);
	printf("\nEXPECTED RESULT = ");
	print_poly(expected_result7);
	printf("ACTUAL RESULT   = ");
	print_poly(result7);
	if(poly_equal(expected_result7,result7))printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- \n");		
	printf("-------------------------------------------------\n");

	//poly of length 4
	//create arrays of coefficients for creating polynomials
	double mul2[] = {1.5,3,6,4};
	double res8[] = {3,6,12,8};
	double multiplier2 = 2;
	
	//create polynomials
	poly* mulcase2 = create_poly(4,mul2);
	poly* expected_result8 = create_poly(4,res8);
	//perform multiplication operation
	poly* result8 = poly_multiply(mulcase2,multiplier2);

	//run test case	
	printf("TEST CASE 8: MULTIPLY A POLYNOMIAL OF SIZE 4 BY DOUBLE\n");
	printf("-------------------------------------------------\n");
	printf("MULTIPLY:\n");
	print_poly(mulcase2);
	printf("BY:\n");
	printf("%lf\n",multiplier2);
	printf("\nEXPECTED RESULT = ");
	print_poly(expected_result8);
	printf("ACTUAL RESULT   = ");
	print_poly(result8);
	if(poly_equal(expected_result8,result8))printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- \n");		
	printf("-------------------------------------------------\n");

	//test cases for order
	//create arrays of coefficients for creating polynomials
	double order1[] = {1,2,3};
	
	//create polynomial
	poly* ordercase1 = create_poly(3,order1);
	//define expected result	
	int expected_result9 = 2;
	//perform divtraction operation
	int result9 = poly_order(ordercase1);

	//run test case	
	printf("TEST CASE 9: GET ORDER OF A POLYNOMIAL OF SIZE 3\n");
	printf("-------------------------------------------------\n");
	printf("FIND ORDER OF:\n");
	print_poly(ordercase1);
	printf("\nEXPECTED RESULT = ");
	printf("%d\n",expected_result9);
	printf("ACTUAL RESULT   = ");
	printf("%d\n",result9);
	if(expected_result9 == result9)printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- \n");		
	printf("-------------------------------------------------\n");

//create arrays of coefficients for creating polynomials
	double order2[] = {1,3,0,4,0,1,0};
	
	//create polynomial
	poly* ordercase2 = create_poly(7,order2);
	//define expected result	
	int expected_result10 = 5;
	//perform divtraction operation
	int result10 = poly_order(ordercase2);

	//run test case	
	printf("TEST CASE 10: GET ORDER OF A POLYNOMIAL OF SIZE 7 \n");
	printf("-------------------------------------------------\n");
	printf("FIND ORDER OF:\n");
	print_poly(ordercase2);
	printf("\nEXPECTED RESULT = ");
	printf("%d\n",expected_result10);
	printf("ACTUAL RESULT   = ");
	printf("%d\n",result10);
	if(expected_result10 == result10)printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- \n");		
	printf("-------------------------------------------------\n");

	//test cases for normalise
	//create arrays of coefficients for creating polynomials
	double norm1[] = {1,2,3};
	double res11[] = {(double)1/3,(double)2/3,1};
	
	//create polynomial
	poly* normcase1 = create_poly(3,norm1);
	//define expected result	
	poly* expected_result11 = create_poly(3,res11);
	//perform normalise operation
	poly* result11 = poly_normalise(normcase1);

	//run test case	
	printf("TEST CASE 11: NORMALISE A POLYNOMIAL OF SIZE 3\n");
	printf("-------------------------------------------------\n");
	printf("FIND ORDER OF:\n");
	print_poly(normcase1);
	printf("\nEXPECTED RESULT = ");
	print_poly(expected_result11);
	printf("ACTUAL RESULT   = ");
	print_poly(result11);
	if(poly_equal(expected_result11,result11))printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- \n");		
	printf("-------------------------------------------------\n");

	//create arrays of coefficients for creating polynomials
	double norm2[] = {5,3,1,7,1,3,10};
	double res12[] = {(double)5/10,(double)3/10,(double)1/10,(double)7/10,(double)1/10,(double)3/10,1};
	
	//create polynomial
	poly* normcase2 = create_poly(7,norm2);
	//define expected result	
	poly* expected_result12 = create_poly(7,res12);
	//perform divtraction operation
	poly* result12 = poly_normalise(normcase2);

	//run test case	
	printf("TEST CASE 12: NORMALISE A POLYNOMIAL OF SIZE 7\n");
	printf("-------------------------------------------------\n");
	printf("FIND ORDER OF:\n");
	print_poly(normcase2);
	printf("\nEXPECTED RESULT = ");
	print_poly(expected_result12);
	printf("ACTUAL RESULT   = ");
	print_poly(result12);
	if(poly_equal(expected_result12,result12))printf("\n              --- TEST CASE PASSED --- \n");
	else printf("\n              --- TEST CASE FAILED --- \n");		
	printf("-------------------------------------------------\n");

}

int main(){
	run_testcases();
}

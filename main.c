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
	//two polys of same size
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
	printf("TEST CASE 3: DIVIDE A POLYNOMIALS OF SIZE 3 BY DOUBLE\n");
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
	printf("TEST CASE 3: DIVIDE A POLYNOMIALS OF SIZE 4 BY DOUBLE\n");
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

	



}

int main(){
  // Title
  printf("====================\nAssignment 3: Poly Cal\n====================\n");
  int input;
  double value;

  // Menu
  while(1){
    printf("Operations available:\n0) Test cases\n1) Add two polynomials\n2) Subract two polnomials\n3) Multiply polynomial by double\n4) Divide polynomial by double\n5) Normalise polynomial\n6) Return order of polynomial\n7) Print polynomial\n8) Exit\nChoice: ");
    scanf("%d",&input);

    if(input == 0){
      //Test
      run_testcases();
    }
    else if(input == 1){
      //Add
      poly* a = poly_input('a');
      poly* b = poly_input('b');
      printf("Answer = ");
      print_poly(poly_add(a,b));
    }
    else if(input ==2){
      //Sub
      poly* a = poly_input('a');
      poly* b = poly_input('b');
      printf("Answer = ");
      print_poly(poly_sub(a,b));
    }
    else if(input == 3){
      //Multiply
      poly* a = poly_input('a');
      printf("Double value to multiply by: ");
      scanf("%lf",&value);
      printf("Answer = ");
      print_poly(poly_multiply(a,value));
    }
    else if(input == 4){
      //Divide
      poly* a = poly_input('a');
      printf("Double value to divide by: ");
      scanf("%lf",&value);
      printf("Answer = ");
      print_poly(poly_division(a,value));
    }
    else if(input == 5){
      //Normalise
      poly* a = poly_input('a');
      printf("Answer = ");
      print_poly(poly_normalise(a));
    }
    else if(input == 6){
      //Order
      poly* a = poly_input('a');
      printf("Answer = %lf\n",poly_order(a));
    }
    else if(input == 7){
      //Print
      poly* a = poly_input('a');
      printf("Answer = ");
      print_poly(a);
    }
    else if(input == 8){
      //Exit
      break;
    }
    else{
      //Invalid Input
      printf("Invalid input\n");
      char bin[100];
      scanf("%s",bin);
    }
  }// Menu
  return EXIT_SUCCESS;
}

poly* poly_input(char name)
{
  int length;
  printf("Length of poly %c:",name);
  scanf("%d",&length);
  double values[length];
  for(int i = 0; i < length; i ++){
    printf("Enter coefficient for x^%d: ",i);
    scanf("%lf",&values[i]);
  }
  return create_poly(length,values);
}

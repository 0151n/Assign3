/*--------------------------------------------*
 * File containing main function for project3 *
 *					      *
 * author: Oisín O'Halloran --add others      *
 *                                            *
 *					      *
 *--------------------------------------------*/
#include"poly.h"


int main(){
    int i = 0;
    double poly1[] = {1,2,3};

	poly* test = create_poly(3,poly1);	
	poly* out = poly_multiply(test,2);
	print_poly(test);
	print_poly(out);
}

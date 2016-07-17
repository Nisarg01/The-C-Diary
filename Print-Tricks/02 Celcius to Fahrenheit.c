/* Tempreture Conversion by Nisarg

This is the program where we will use our own mathematical expression

*/


#include <stdio.h>


/* "void" in the argument of main strictly prohobits compiler to 
compile main with any arguments which means it will strictly take no arguments at all

main() indicates that it can have none or any number of arguments whereas
main(void) indicates no arguments at all
*/

int main(void) 
{
	
// float datatype allows us to have decimal values
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	//following print lines will give a tabular feel while printing

	printf("   F |  C\n");
	printf("------------\n");

	// this loop statement will save us from the pain of writing multiple iterations
	while (fahr <= upper) 
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		
		printf(" %3.0f %6.1f\n", fahr, celsius);

		//increment by 20, but looks more logical this way
		fahr += step;
	}
	return 0;
}

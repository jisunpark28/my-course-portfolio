/********************************************************************* 
Printing the Expression

We would want to print:
42 + 3 + 6
**********************************************************************/


//plus sign comes after every number except the las
void printExpression(const int numbers[], int used, int total)
{
	int i;
	//print the first number
	printf("%d", numbers[0]);
	//start with the second number and print everything else in array
	for (i = 1; i < used; i++){
		printf(" + %d", numbers[i]);
	}
	printf(" = %d\n", total);
}
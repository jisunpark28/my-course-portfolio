/********************************************************************* 
Printing the Expression

We would want to print:
42 + 3 + 6
**********************************************************************/


//Putting it all together

#include <stdio.h>
//our spec stated that we expect 20 numbers
#define CAPACITY 20

//this function reads from the user a set of numbers and stores it into an array.  Reading stops
//after CAPACITY values are read or after user enters a 0.  Function returns number of values read
int readNumbers(int numbers[]);

//this function sums the numbers in the numbers array
//used is the number of values stored in the numbers array
int sumArray(const int numbers[], int used);

//this function prints the sum expression with the total
void printExpression(const int numbers[], int used, int total);

int main(void)
{
	//declare an array with CAPACITY elements
    int numbers[CAPACITY]={0};
    int used = readNumbers(numbers);
    int total;
    if(used != 0){
    	total = sumArray(numbers, used);
    	printExpression(numbers, used, total);
    }
    else{
    	printf("no values entered");
    }
    return 0;
}

int readNumbers(int numbers[])
{
    int used = 0;
    int input;

    printf("Please enter a number (0 to exit): ");
    scanf("%d", &input);

    //continue reading while we have space in array and user hasn't entered 0
    while(used < CAPACITY && input != 0) {
        numbers[used] = input;  //store the number in array
        used++;                 //increment count of stored numbers

        printf("Please enter a number (0 to exit): ");
        scanf("%d", &input);
    }

    return used;
}
//this function sums the numbers in the numbers array
//used is the number of values stored in the numbers array
int sumArray(const int numbers[], int used)
{
	int total = 0;
	int i;
	//note this pattern for a for loop that will iterate through every element of the array
	//this is why we count from 0!
	for(i = 0; i < used; i++){
		total += numbers[i];
	}
	return total;
}
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
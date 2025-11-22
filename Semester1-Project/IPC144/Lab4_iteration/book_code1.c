/*
Iteration(=Loops) is the process of repeating the instructions of our program.

A while loop
	while (<check to keep going with loop>){
		//things we do each time go here.  make sure
		//there is something in here that will update
		//the values used in the check or you will get
		//stuck!
	}

sample run
Please enter a number (0 to exit): 15
Please enter a number (0 to exit): 5
Please enter a number (0 to exit): -2
Please enter a number (0 to exit): 0
Total of all values entered was: 18
*/

#include <stdio.h>
//declare what functions we will have:
int getNumber();
int main(void)
{
	int total=0;
	int number = getNumber();
	//while the number entered isn't 0
	while (number != 0){
		total += number; 		//update total
		number = getNumber();	//prompt and read
	}

	//once the loop is done, print total:
	printf("Total of all values entered was: %d\n",total);
	return 0;
}
int getNumber()
{
	int number;
	printf("Please enter a number (0 to exit): ");
	scanf("%d", &number);
	return number;
}
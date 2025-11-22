/*
Iteration(=Loops), Line Drawing with while

A for loop
    for (<initialization>; <check statement>; <update>){}


*/


#include <stdio.h>
//declare what functions we will have:
int getNumStars();
void drawLine(int numStars);
int main(void)
{
	int numStars = getNumStars();
	drawLine(numStars);
	return 0;
}
int getNumStars()
{
	int numStars;
	printf("Please enter number of stars on the line: ");
	scanf("%d", &numStars);
	return numStars;
}
void drawLine(int numStars)
{
	int i=0;  //initialize the counter before the loop

	//while loop has condition that is same as the middle part of
	//the for loop
	while(i < numStars){
		printf("*");
		// just before the end of the while loop
		// update the counter
		i++;
	}
	printf("\n");
}
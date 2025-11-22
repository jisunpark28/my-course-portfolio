/*
Iteration(=Loops), Line Drawing - with data validation

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
	//prompt and read
	printf("Please enter number of stars on the line: ");
	scanf("%d", &numStars);
	//while the data is wrong:
	while(numStars < 0 || numStars > 50){
		//print error message
		printf("Error: Number of stars must be between 0 and 50 inclusive.");
		//prompt and read
		printf("Please enter number of stars on the line: ");
		scanf("%d", &numStars);

	}
	return numStars;
}
void drawLine(int numStars){
	int i;
	for (i = 0; i < numStars; i++){
		printf("*");
	}
	printf("\n");
}
/*
Iteration(=Loops), Line Drawing with for

A for loop
    for (<initialization>; <check statement>; <update>){}

절대 하지 말아야 할 Extremely bad practice!
    note! 조건을 결정하는 변수 i가 for문 안에 있는것 
          makes the code harder to read, makes the code more error prone.
        int i;
        for (i = 0; i < n; i++){
	        i += 2;
        }

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

void drawLine(int numStars){
	int i; //declare our loop counter
	//putting together our loop with its 3 parts
	// * initialization
	// * check
	// * increment
	for (i = 0; i < numStars; i++){
		//each time we do the for loop, we print one star
		printf("*");
	}
	//after we print all the stars put in a newline
	printf("\n");
}
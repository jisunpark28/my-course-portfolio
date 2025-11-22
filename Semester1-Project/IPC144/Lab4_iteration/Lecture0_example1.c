/******************************************
[do-while + if]

Create a loop using do-while to obtain a mark for a subject as folloing
As long as you enter an invalid mark (<0 or >100), keep on asking from it
the user again and again for a valid marks. 
When valid mark is entered, display mark and exit the program. 
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int mark;

	//do-whilel loop
	do {

		//instructions
		printf("Enter Mark: ");
		scanf("%d", &mark);

        if (mark < 0 || mark >100){
            printf("Invalid mark, Enter Again...");
        }

	} while (mark < 0 || mark >100);


	return 0;
}
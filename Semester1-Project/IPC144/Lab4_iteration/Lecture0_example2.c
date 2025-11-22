/******************************************
[do-while + if] 

print 5 to 1 using a do-while loop
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int count = 5;

	//do-whilel loop
	do {

		//instructions
		printf("Count %d\n", count);
        count--;
	} while (count>0);


	return 0;
}
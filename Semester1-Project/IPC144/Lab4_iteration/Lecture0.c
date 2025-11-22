/******************************************
Iteration

1. do-while loop: post-check loop
while(condition) : condition = true --> instrructions keep working


[example]
count = 1
count = 2
count = 3
count = 4
count = 5
******************************************/
//[case1]
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>

// int main(void) {

// 	int count = 1;

// 	//do-whilel loop
// 	do {

// 		//instructions
// 		printf("count = %d\n", count);
// 		count++;
// 	} while (count <= 5);


// 	return 0;
// }


//[case2]
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>

// int main(void) {

// 	int count = 0;

// 	//do-whilel loop
// 	do {

// 		//instructions
// 		printf("count = %d\n", count+1);
// 		count++;
// 	} while (count <= 5);


// 	return 0;
// }

//[case3]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int count = 0;

	//do-whilel loop
	do {

		//instructions
		count++;
		printf("count = %d\n", count);

	} while (count < 5);


	return 0;
}
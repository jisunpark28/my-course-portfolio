/******************************************
Walkthrough 1: What is the output of the following program?

+=: 계산 후 값 변경!!!!

whole thing: -4
x = -4, y = -4
x++ = 2
++y = 3
x = 3
y = 3

******************************************/

#include <stdio.h>
int main(void){
	int x=1;
	int y=1;
	printf("whole thing: %d\n", x = y += 3 / 4 + 5 * 2 % 3 - 6);
	printf("x = %d, y = %d\n", x , y);
	x = 2;
	y = 2;
	printf("x++ = %d\n", x++);
	printf("++y = %d\n", ++y);
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	return 0;
}
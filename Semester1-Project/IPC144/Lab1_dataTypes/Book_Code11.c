/******************************************
Walkthrough 2: What is the output of the following program?

float : 소수점 6자리까지 표현됨, 자동 반올림됨

whole thing: 2
x = 2, y = 2.666667

******************************************/

#include <stdio.h>
int main(void){
	int x=1;
	float y=1;
	printf("whole thing: %d\n", x = y = (9 * 2.0 - 2 % 3 * 5) / 3);
	printf("x = %d, y = %f\n", x , y);
	return 0;
}

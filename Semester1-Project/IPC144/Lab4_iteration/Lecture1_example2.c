/******************************************
Iteration

2. while loop: pre-check loop
while(condition) : condition = true --> instrructions keep working

Note! count = 0 (atarting 0 is best option!)

Q2. Obtain age and make sure age is inbetween and including 0 and 120.
Prompt to ask for age again and again if invalid age is entered

do-while or while
    : 첫 변수값을 받고 시작해야할 때(count를 따르지 않을 때)는 do-while이 좋음
    : count값에 따라 진행할 때는 while이 좋음

******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int age;
    printf("Enter age: ");
    scanf("%d", &age);

	//whilel loop
    while (age<0 || age>120){

        //instructions
        printf("Invalid age, Enter Again...\n");
        printf("Enter age: ");
        scanf("%d", &age);
    }


	return 0;
}
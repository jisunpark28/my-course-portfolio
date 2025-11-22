/******************************************
Palleral Array + String


[^\n] before enter
[^H] befor H
******************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {

    //int x[]={ 3,4,5 };
    //char name[31] = {'D','A','V','I','D','\0'};  //char array, \0 null terminator
    char name[31] = "DAVID PETS";
    printf("My name is %s\n", name);

    char brand[41]; //runtime error: 40까지만 허용. 그 이상 넘어가면 memory error 발생, scanf에서 --> %40s로 제한
    printf("Enter the car brand: ");
    scanf("%40s", brand); //string에서는 &절대 사용하지 않음


    char brand[31]; 
    printf("Enter the car brand: "); // if input = range rover 
    scanf("%30s", brand); //

    printf("You entered %s\n", brand); // only show range (because it stops before blank" " ) --> %30[^\n] instead of %30s


	return 0;

}
/******************************************
1. 5 + 2 * 6 - 17 / 3 % 4
2. 15 + 29 / 4 / 2.0 - 3 * 2
3. a++
4. x = b += 19 / 3 % 4 * 3 / 5
5. y = c += 7 - d++ * 6 / 4 % 3

+= : 오른쪽 계산 완료 후 진행.


What are constants?

    Constants are names for values that naver change in your program. 

Why do we want to use constants?

    constants minimize updates to one location and provide clear documentation of the value.

Declare a constant named TAU using preprocessor statements to 5 decimal places. This value is 6.28318

    #define TAU 6.28318 
    A constant named TAU with the value 6.28318 can be declared using a preprocessor statement as follows: #define TAU 6.28318

What is the difference between prefix increment and postfix increment


    prefix increment adds 1 to the variable before using its value.
    postfix increment adds 1 to the variable after using its value.

******************************************/

#include <stdio.h>
int main(void)
{
    int a = 5;
    int b = 10;
    int c = 11;
    int d = 3;
    int x;
    int y;

    int answer1; 
    float answer2;
    int answer3; 
    int answer4;
    int answer5;


        answer1 = 5 + 2 * 6 - 17 / 3 % 4;
        answer2 = 15 + 29 / 4 / 2.0 - 3 * 2;
        answer3 = a++;
        answer4 = x = b += 19 / 3 % 4 * 3 / 5;
        answer5 = y = c += 7 - d++ * 6 / 4 % 3;

    printf("%d\n", answer1);
    printf("%.2f\n", answer2);
    printf("%d\n", answer3);
    printf("%d\n", answer4);
    printf("%d\n", answer5);
    return 0;
}
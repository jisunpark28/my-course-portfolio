#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main() {

    char ch1='A';
    char ch2='B';

    // checking the type
    int res = isalpha(ch1);
    printf("Result: %d (is it alphabet? %c)\n", res, ch1);
    res = isalpha(ch2);
    printf("Result: %d (is it alphabet? %c)\n", res, ch2); 

    //isspace()
    //isdigit()


char ch3 = tolower(ch1);
putchar(ch3); //display format setting X
char ch4 = toupper(ch3);
putchar(ch4); //display format setting X

    return 0;
}
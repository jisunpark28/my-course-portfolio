/******************************************

1. How can we turn a character from lower case to upper case and vice versa?
    We can convert lower case to upper case by subtracting ('a'-'A') from a character.
    We can convert upper case to lower case by submitting ('a'-'A') from a character.

******************************************/


#include <stdio.h>

int main(void)
{
    char digit = '6';
    char lower = 't';
    char upper = 'Q';

    printf("digit as a char %c\n", digit);
    printf("digit as an int %d\n", digit);

    digit = digit -'0';
    printf("new digit as an int %d\n",digit);

    printf("%c\n", lower);
    printf("%c\n", lower - ('a'-'A'));

    printf("%c\n", upper);
    printf("%c\n", upper + ('a'-'A'));

    return 0;
}

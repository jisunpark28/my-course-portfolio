#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);
    printf("%d", number * 2);

    return 0;
}
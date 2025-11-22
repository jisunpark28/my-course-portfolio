#define SCR_SECURE_NO_WARNING
#include <stdio.h>

int main(void)
{
    int inchVal;
    double cmVal;

    printf("Enter the number of inches: ");
    scanf("%d", &inchVal);

    cmVal = 2.54 * inchVal;

    printf("%d\" is %.1lf cm", inchVal, cmVal);

    return 0;
}
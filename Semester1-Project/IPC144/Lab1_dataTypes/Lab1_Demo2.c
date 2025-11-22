#include <stdio.h>

int main(void)
{
    int a =5;
    int b =10;
    int c = a + b;

    printf("a =%d, b = %d, c = %d\n", a, b, c);

    a = (a + 8) % 3;
    b += (a + a + a);
    c = b * 2 /7;

    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
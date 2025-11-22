/******************************************
1. Can you observe a pattern with the behaviour of the modulus operator?
    The modulus operator repeats 0, 1, 2 when dividing by 3.
2. What is the difference between postfix ++ (var++) and prefix ++ (++var) operators?
    postfix adds 1 to the variable after using its value.
    prefix adds 1 to the variable befor using its value.

*******************************************/

#include <stdio.h>
int main(void)
{
    int intResult = 8/3;
    float floatResult = 8.0/3;
    int apple = 6;
    int banana = 0;
    int carrot = 6;
    int daikon = 0;
    int n = 0;
    int mod =0;

    printf("%d\n", intResult);
    printf("%f\n", floatResult);

    apple = 6;
    banana = apple++;
    printf("apple = %d, banana=%d\n", apple, banana);
    banana = apple++;
    printf("apple = %d, banana=%d\n", apple, banana);

    carrot = 6;
    daikon = ++carrot;
    printf("carrot = %d, daikon=%d\n", carrot, daikon);
    daikon = ++carrot;
    printf("carrot = %d, daikon=%d\n", carrot, daikon);

    mod = n % 3;
    printf("%d %% 3 is %d\n", n++, mod);
    mod = n % 3;
    printf("%d %% 3 is %d\n", n++, mod);
    mod = n % 3;
    printf("%d %% 3 is %d\n", n++, mod);
    mod = n % 3;
    printf("%d %% 3 is %d\n", n++, mod);
    mod = n % 3;
    printf("%d %% 3 is %d\n", n++, mod);
    mod = n % 3;
    printf("%d %% 3 is %d\n", n++, mod);
    mod = n % 3;
    printf("%d %% 3 is %d\n", n++, mod);

    return 0;
}


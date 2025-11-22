#include <stdio.h>

struct Daisy
{
    int petals;
    int stem;
    char leaf;
};

int main(void)
{
    struct Daisy flower1 = {10, 5, 'A'};
    struct Daisy flower2 = {3, 7, 'B'};

    printf("%c: %d x %d\n", flower2.leaf, flower2.stem,
           flower2.petals);
    printf("%c: %d x %d\n", flower1.leaf, flower1.petals,
           flower1.stem);

    return 0;
}

//B: 7 x 3
//A: 10 x 5
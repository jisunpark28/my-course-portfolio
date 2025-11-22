#include <stdio.h>
int rose(int petals);
int daisy(int petals);
int lily(int petals);

int main(void)
{
        int total = rose(0);

        printf("total: %d\n", total);

        total = daisy(total);
        printf("total: %d\n", total);

        total =lily(total);
        printf("total: %d\n", total);

        return 0;

}

int rose(int petals)
{
    printf("rose\n");

    return petals +1;
}

int daisy(int petals)
{
    printf("daisy\n");
    
    return rose(petals) +2;
}

int lily(int petals)
{
    printf("lily\n");

    return daisy(petals) +3;
}


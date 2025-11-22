#include <stdio.h>
#define MAX 8
#define STRINGMAX 10

struct Smoothie
{
    char name[STRINGMAX + 1];
    int fruits[MAX];
    int numFruits;
};

void blend(struct Smoothie* drink);
void shake(int* a, int* b);
void printSmoothie(struct Smoothie* drink);

int main(void)
{
    struct Smoothie berry = {"berry", {3,1,6,1,4}, 5 };
    printSmoothie(&berry);
    blend(&berry);
    printSmoothie(&berry);
}
void blend(struct Smoothie* drink)
{
    int i;
    int end = drink->numFruits-1;
    for (i = 0; i < drink->numFruits/2; i++){
        shake(&(drink->fruits[i]), &(drink->fruits[end-i]));
    }
}
void shake(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void printSmoothie(struct Smoothie* drink)
{
    int i;

    //print the name data member of the Smoothie struct pointed to by drink
    printf("%s\n", drink->name);

    //this loop prints every value in the fruits array
    //separated by a space on one line
    for(i = 0; i < drink->numFruits; i++){
        printf("%d ", drink->fruits[i]);
    }
    printf("\n");
}
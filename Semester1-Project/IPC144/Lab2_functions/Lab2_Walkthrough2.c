#include <stdio.h>
void apple(void);
void cabbage(void);
void eggplant(void);
void ginger(void);
void lettuce(void);
void orange(void);
void onion(void);
void radish(void);

int main(void)
{
    lettuce();
    printf(" at the ");
    radish();
    printf(" ");
    ginger();
    printf("\n");
    return 0;
}
void apple(void)
{
    printf("a");
    cabbage();
    printf("a");
}
void cabbage(void)
{
    printf("c");
    eggplant();
    printf("c");
}
void eggplant(void)
{
    printf("e");
}
void ginger(void)
{
    printf("g");
    orange();
}
void lettuce(void)
{
    printf("L");
    onion();
}
void orange(void)
{
    printf("o!");
}
void radish(void)
{
    printf("r");
    apple();
    printf("r");
}
void onion(void)
{
    printf("ook");
}
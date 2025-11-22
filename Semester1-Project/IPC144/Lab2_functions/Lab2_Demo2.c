/******************************************
walkthrough table : 250917_IPC144LAB_lab2.docx
******************************************/
#include <stdio.h>

int strawberry(int leaves);
int pies(int crusts);

int main(void)
{
    int apple = 3;
    int orange = 12;
    apple += strawberry(orange);
    printf("apple: %d\n", apple);
    apple += pies(7);
    printf("apple: %d\n", apple);
    return 0;
}
int strawberry(int leaves)
{
    int rc = leaves*2;
    rc += 5;
    printf("strawberry rc = %d\n", rc);
    return rc;
}

int pies(int crusts)
{
    int rc = crusts;
    rc += strawberry(crusts % 5 + 2);
    printf("pies rc = %d\n", rc);
    return rc;
}

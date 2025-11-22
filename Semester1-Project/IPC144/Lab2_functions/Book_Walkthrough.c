/***************************************************************** 
[Self Check]

1. What is the difference between cohesion and coupling?
Cohesion describes the relationship of the code within a function
Coupling describes the relationship between functions.

2. Why is high cohesion desirable in a function?
A function that is highly cohesive is dedicated to a clear single objective. Every line of code is working towards the completion of that objective. It makes the function precise and understandable.

3. What is meant by the term loose coupling?
A function is loosely coupled if they are not dependent on each other. That is, each function can work on their own without needing to be paired to another function.


***************************************************************/


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

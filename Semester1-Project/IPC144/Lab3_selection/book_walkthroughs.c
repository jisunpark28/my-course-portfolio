#include <stdio.h>

int decision(int data)
{
    int rc = 0;
    if(data > 0){
        rc = 1;
    }
    return rc;
}

int main(void)
{
    int apple = 0;
    int orange = apple++;
    if(decision(apple) == 0){
        printf("Today");
    }
    else{
        printf("Yesterday");
    }
    if(decision(orange) == 0){
        printf(" was sunny\n");
    }
    else{
        printf(" was cloudy\n");
    }
}
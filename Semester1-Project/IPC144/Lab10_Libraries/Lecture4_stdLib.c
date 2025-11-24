#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char num[] ="3.4567";

    // String to number conversion
    int num1 = atoi(num);
    long num2 = atol(num);
    double num3 = atof(num);

    printf("The type: %d(int), %ld(long int), %.2lf(double)\n", num1, num2, num3);

    //random numbers
        //int ranNum = rand();
    int i;
    double min =0, max=100;

    for (i=0; i<5; i++){
        printf("Random Num-%d is %d\n", i+1, rand());

    }

    //Change seed value for random numbers
    srand(766666); // if the seed value is fixed, the random value is not going to be changed 
    for (i=0; i<5; i++){
        printf("Random Num-%d is %d\n", i+1, rand());

    }

    //Change seed value for random numbers
    srand(time(NULL)); // time(NULL) depends on computer time
    for (i=0; i<5; i++){
        printf("Random Num-%d is %d\n", i+1, rand());
    }

    //rand() generates random num between 0 and RAND_MAX
    for (i=0; i<5; i++){
        printf("Random Num-%d is %d\n", i+1, rand()); 
    }
    printf("RAND MAX in this computer is %d\n", RAND_MAX);

    //rand() generates random num between 0 and 1
    for (i=0; i<5; i++){
        printf("Random Num-%d(0-1) is %.2f\n", i+1, (double)rand()/RAND_MAX); 
    }

    //rand() generates random num between min and max
    for (i=0; i<5; i++){
        printf("Random Num-%d(min-max) is %.2f\n", i+1, ((double)rand()/RAND_MAX) *(max-min)); 
    }

    //rand() generates random num between min and max (+ range)
    min =-200, max=50;
    for (i=0; i<5; i++){
        printf("Random Num-%d(min-max) is %.2f\n", i+1,min+ ((double)rand()/RAND_MAX) *(max-min)); 
    }

    return 0;
}
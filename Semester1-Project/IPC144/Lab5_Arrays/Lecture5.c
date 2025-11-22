/******************************************
Array Practice 3
Modify the above program to add another function called getPrices
  i. Declare the array for prices in main
  ii. Use the getprices to populate the arrray
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5 
float calcuate(float [], int, int);
void getPrices(float [], int);

float calcuate(float pr[], int first, int last){ 
    int i;
    float sum = 0;
    for(i=first-1;i<last;i++){
        sum += pr[i];
    }

    return sum;
}

void getPrices(float prs[], int sz){ 
        int i;
        for(i=0;i<SIZE;i++){
        printf("Enter Price %d: ", i+1);
        scanf("%f", &prs[i]);
    }
}

int main(){

    float prices[SIZE] = {0,0,0,0,0}; //Initialization is not required for the problem. Although I do it
    int i, first, last;
    float sum;


    getPrices(prices, SIZE);    

    //Display the prices you got from getPrices
    for(i=0; i<SIZE; i++){
        printf("Prices %d: %.2g\n", i+1, prices[i]);
    }

    printf("Enter first Product Num: ");
    scanf("%d", &first);
    printf("Enter last Product Num: ");
    scanf("%d", &last);

    sum = calcuate(prices, first, last);
    printf("Summation is %.2f\n", sum);
    
    return 0;
}
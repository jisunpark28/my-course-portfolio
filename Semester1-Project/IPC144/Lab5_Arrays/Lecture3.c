/******************************************
Array Practice 1 

Create a program to obtain
product prices of X products.
X can be defined as a Macro with starting value 5

- Obtain prices for 5 products and store in a array.
- Obtain two numbers, 
   first number representing starting product. e.g: 2
   second number representing ending product. e.g: 4
- Find the summation of prices from first product to last product
  inclusive of both.
- e.g first=2, last=4
  Add 2,3,4 and give the summation

******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5 

int main(){

    float prices[SIZE] = {0,0,0,0,0}; //Initialization is not required for the problem.
    int i, first, last;
    float sum=0;

    for(i=0;i<SIZE;i++){
        printf("Enter Price %d: ", i+1);
        scanf("%f", &prices[i]);
    }

        //if we need iteration, we use 'do-while'
        printf("Enter first Product Num: ");
        scanf("%d", &first);
        printf("Enter last Product Num: ");
        scanf("%d", &last);

        //first = 2, prices[1] last = 4, prices[3]
        for(i=first-1;i<last;i++){
            sum += prices[i];
        }

        printf("Summation over the range is %.2f\n", sum);

    // double price[SIZE];
    // int i;
    // double sum=0;

    // for (i=0; i<SIZE; i++){
    //     printf("Enter price of product %d: ", i+2);
    //     scanf("%lf", &price[i]);
    //     i++;
    // }

    // for (i=0; i<SIZE; i++){
    //     sum += price[i+2];
    //     printf("Product%d price: %.2lf\n", i+2, price[i+2]);
    //     i++;
    // }


    return 0;
}

/******************************************
Array Practice 2

The logic in 1 above should be altered 
i. Obtain the two numbers (first and last ) in main
ii. Send over the two numbers and the price array to another 
  function called calculate. Perform the same logic to get summation
 of prices between and including the two numbers and return the result
ii.. main function should display the result.
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5 
float calcuate(float [], int, int);

// 일변 변수의 경우 데이터값을 전달, array의 경우 데이터를 복사 중복시키는게 아니고 주소와 필요한 정보만 전달.
float calcuate(float pr[], int first, int last){
    int i;
    float sum = 0;
    for(i=first-1;i<last;i++){
        sum += pr[i];
    }

    return sum;
}

int main(){

    float prices[SIZE] = {0,0,0,0,0}; //Initialization is not required for the problem. Although I do it
    int i, first, last;
    float sum;

    for(i=0;i<SIZE;i++){
        printf("Enter Price %d: ", i+1);
        scanf("%f", &prices[i]);
    }

        //if we need iteration, we use 'do-while'
        printf("Enter first Product Num: ");
        scanf("%d", &first);
        printf("Enter last Product Num: ");
        scanf("%d", &last);

        sum = calcuate(prices, first, last);  //함수로 가져올때는 array []부분 생략! 
        printf("Summation is %.2f\n", sum);

    return 0;
}
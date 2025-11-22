#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Lab4.h"

int power(int base, int exponent){
    int ret=1, i;
    for(i=0; i<exponent; i++){
    ret=ret*base;
    }
    return ret;
}

int readIntInRange(int min, int max){
    int num;
    do{
        printf("Please enter an integer between %d and %d inclusive: ", min, max);
        scanf("%d", &num);
        if(num<min || num>max){
        printf("The input was not between %d and %d\n", min, max);
        }
    }while(num<min || num>max);
    return num;
}

int fibonacci(int n){
    int nth=0, i;
    int prev=0, current=1;
    if (n<=1){
        return n;
    }
    for(i=2; i<=n; i++){
        nth = prev + current;
        prev = current;
        current = nth;
        
    }
    return nth;
}

int sum(int start, int stop){
    int ret=0, i;
    int between = stop-start;
    for(i=0;i<=between;i++){
        ret += start;
        start++;
    }
    return ret;
}

int fizzBuzzScore(int endPoint){
    int i, score=0;

    for(i=1;i<=endPoint;i++){
        if(i%15==0){
            score +=5;
        }else if(i%3==0){
            score +=1;
        }else if(i%5==0){
            score +=2;
        }
    }
    return score;
}

int sumDigits(int number){
    int sum=0;
    while(number!=0){
        sum += number%10;
        number = number/10;
    }
    return sum;
}

int isLower(char letter){
    int ret;
    if (letter>='a' && letter <='z'){
        ret=1;
    }else{
        ret=0;
    }
    return ret;
}

char toUpper(char letter){
    if (letter>='a' && letter <='z'){
        letter += 'A'-'a';
    }
    return letter;
}

int biggest(int first, int second, int third){
    int ret;
    if(first>=second && first>=third){
        ret=first;
    }else if(second>=first &&second>=third){
        ret=second;
    }else{
        ret=third;
    }
    return ret;
}

double ticketPrice(int age, int hasCoupon, int dayOfWeek){
    double price;
    if (dayOfWeek==1){
        price=5;
    }else if(dayOfWeek>=2 &&dayOfWeek<=4){
        if(age>=65){
            price=9;
        }else if(age>12){
            price=12;
        }else{
            price=7;
        }
    }else{
        if(age>=65){
            price=10;
        }else if(age>12){
            price=15;
        }else{
            price=8;
        }
    }
    if(dayOfWeek!=1&&hasCoupon==1){
        price=price*0.8;
    }
    return price;
}
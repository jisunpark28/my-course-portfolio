#include <stdio.h>
#include "Lab3_Demo.h"

int isLower(char letter){
    if (letter >= 'a' && letter <= 'z'){
        return 1;
    }
    else{
        return 0;
    } 
}

char toUpper(char letter){
    char result;

    if (letter >= 97 && letter <= 122){
        result = letter - ('a'-'A');
        return result;
    }
    else {
        result = letter;
        return result;
    }

}


int biggest(int first, int second, int third){
    int result;
    if (first >= second && first >= third){
        result = first;
    }
    else if (second >= first && second >= third){
        result = second;
    }
    else {
        result = third;
    }
    return result;
}


double ticketPrice(int age, int hasCoupon,int dayOfWeek){
    double ticketPrice;

    if (dayOfWeek == 1){
        ticketPrice = 5;
    }
    else if (dayOfWeek == 0 || dayOfWeek == 5 || dayOfWeek == 6){
        if (age <=12){
            ticketPrice = 8;
        }
        else if (age < 65){
            ticketPrice = 15;
        }
        else {
            ticketPrice = 10;
        }
    }

    else {
        if (age <=12){
            ticketPrice = 7;
        }
        else if (age < 65){
            ticketPrice = 12;
        }
        else {
            ticketPrice = 9;
        }       
    }


    if (dayOfWeek != 1 && hasCoupon == 1){
        ticketPrice *= 0.8;
        return ticketPrice;
    }
    else {
        return ticketPrice;
    }
}


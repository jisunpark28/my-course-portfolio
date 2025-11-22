#define _CRT_SECURE_NO_WARNINGS
#include "lab3practice.h"

/*
This function is passed a number that can be positive or negative.  
If the number is positive, function returns the number.
If the number is negative, function returns the positive version of that number
*/
int absoluteValue(int number){
    if(number >= 0){
        return number;
    }
    else{
        return -number;    //number*(-1)보다 더 간결함
    }
}
/*
This function is passed two numbers representing what each player "threw" in a game 
of rock-paper-scissors. This function returns 1 if player won the game, 0 if they 
either tied or lost the game
*/
int rockPaperScissors(int player, int opponent){
    if (player == 0 && opponent == 2) return 1;
    if (player == 1 && opponent == 0) return 1;
    if (player == 2 && opponent == 1) return 1;
    return 0;  
}

/*
This function returns the day of the week represented as follows:
0 - Sunday
1 - Monday
2 - Tuesday
...
6 - Saturday

January 1 2025 occurred on a Wednesday.  Given a number representing the day 
of the month in January, function returns the day of the week.  If day is invalid, 
function returns -1:
*/
int dayOfWeekJan2025(int day){
if (day < 1 || day > 31) return -1;

return ((day + 2) % 7);
}

//if문 - else문 구조   return 없어도 O.
//if문 구조가 else문 없이 끝난다면 꼭 return 있어야함.
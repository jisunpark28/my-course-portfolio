#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "lab3practice.h"

//int absoluteValue(int number);
//int rockPaperScissors(int player, int opponent);
//int dayOfWeekJan2025(int day);

int main(void)
{

    //Function1
    int number = 3;
    printf("absoluteValue(%d) returens %d\n\n", number, absoluteValue(number));


    //Function2
    int player = 1; // 0=rock, 1=paper, 2=scissos
    int opponent = 2;

    printf("rockPaperScissors(%d, %d) - returns %d, ", player, opponent, rockPaperScissors(player, opponent));

    if (rockPaperScissors(player, opponent) == 1){
        printf("player win\n");    
    } else {
        if (player == opponent){
        printf("tie game\n");  
        } else{
            printf("player lost\n");
        }  
       }



    //Function3
    int day = 26;
    char *dayNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    printf("dayOfWeekJan2025(%d) - ", day);

    if(dayOfWeekJan2025(day)==-1){
        printf("returns %d because Jan. %d doesn't exist", dayOfWeekJan2025(day), day);
    }  else if(dayOfWeekJan2025(day)>=0 && dayOfWeekJan2025(day) <= 6){
        printf("returns %d because Jan. %d is on %s\n", dayOfWeekJan2025(day), day,  dayNames[dayOfWeekJan2025(day)]);
    }  else{
        printf ("Error: Invalid return code %d\n", dayOfWeekJan2025(day));
    }
}

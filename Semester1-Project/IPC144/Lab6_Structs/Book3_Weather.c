/******************************************
Define a struct named Weather that stores:

Day of the week (string, maximum 10 characters)
High temperature (whole number)
Low temperature (whole number)
Probability of Precipitation (whole number)
Write a program that will

Declare and initialize three instances of Weather structs for three different days:
day 1 - use the information for today
day 2 - use the information for tomorrow
day 3 - use the information for the day after tomorrow
for pop use the highest probabilty for the entire day
Calculates and displays the average high temperature across the three days
Displays which day had the highest probability of precipitation



Key Note! 배열변수는 위치를 표현하고, 그냥 변수는 값을 표현
day1.day ==> 위치 (day1.day +1 : 위치 변경 M --> o // day1.day = 값 대입 불가능)
day1.highTemp ==> 값 표현 (day1.highTemp + 1 : 6+1 // day1.highTemp = value : 값 대입 가능)
******************************************/
#include <stdio.h>

struct Weather
{
    char day[10];
    int highTemp;
    int lowTemp;
    int pop;
};

int main(void)
{
    struct Weather day1 = {"Monday", 6, 9, 20};
    struct Weather day2 = {"Tuesday", 4, 11, 40 };
    struct Weather day3 = {"Wednesday", 4,10,70 };

    float avgHigh = (day1.highTemp + day2.highTemp +
                     day3.highTemp) / 3.0;

    int maxPop = day1.pop;
    int whichDay = 1;
    printf("Average High Temperature: %.1f\n", avgHigh);

    if (day2.pop > maxPop) {
        maxPop = day2.pop;
        whichDay = 2;
    }
    if (day3.pop > maxPop) {
        maxPop = day3.pop;
        whichDay = 3;
    }

    if(whichDay == 1){
        printf("Day with highest pop: %s ", day1.day);
    }
    else if(whichDay == 2){
        printf("Day with highest pop: %s ", day2.day);
    }
    else{
        printf("Day with highest pop: %s ", day3.day);
    }
    //%% prints a single % in the output
    printf("(%d %%)\n", maxPop);

    return 0;
}
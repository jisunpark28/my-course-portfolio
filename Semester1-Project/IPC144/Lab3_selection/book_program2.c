#include <stdio.h>

float TOURate(int dayOfWeek, int hour, int min){
    float rates;
    int time = hour*60 + min;
    if (dayOfWeek==6 || dayOfWeek==0){
        rates = 7.6;
    }else {
        if(time >= 19 * 60 || time < 7 * 60){
            rates = 7.6;
        }else if((time >= 7 * 60 && time < 11 * 60) || (time >= 17 * 60 && time < 19 * 60)){
            rates = 12.2;
        }else {
            rates=15.8;
        }
    }
    return rates;
}
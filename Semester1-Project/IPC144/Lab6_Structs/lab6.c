#include <stdio.h>
#include "lab6.h"

void makeChange(int cents, int* quarters, int* dimes, int* nickels){
    //Firtst Logic - Rounding
    int endingCents = cents % 5;
    if (endingCents==1 || endingCents==2){
        cents -= endingCents;
    }else{
        cents += (5 - endingCents);
    }

    //Second Logic - Calculation
    *quarters = cents / 25;
    cents %= 25;
    *dimes = cents / 10;
    cents %=10;
    *nickels = cents / 5;
}

void setDate(const char dateString[], struct DateTime* dt){
    // string --> int (ASCII CODE사용해야함)
    // 숫자 48 사용보다 문자 '0' 사용이 더 좋은 표현 임. 
    //  값 --> dt.hour
    // 주소 --> dt -> hour
    (*dt).day = (dateString[0]-'0')*10 + (dateString[1]-'0');
    (*dt).month = (dateString[3]-'0')*10 + (dateString[4]-'0');
    (*dt).year = (dateString[6]-'0')*1000 + 
                 (dateString[7]-'0')*100 + 
                 (dateString[8]-'0')*10 + 
                 (dateString[9]-'0');
}

void printDateTime(const struct DateTime* dt){
    const char* monthNames[] = {"", "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"};
    const char* ampm;
    int displayHour, i;

    
    if((*dt).hour==0){
        ampm= "am";
        displayHour = 12;
    }else if((*dt).hour<12){
        ampm= "am";
    }else if((*dt).hour==12){
        ampm= "pm";
    }else{
        ampm= "pm";
        displayHour = (*dt).hour -12;
    }

    for (i=0; i<12; i++){
        if((*dt).month == i){
            printf("%s %d, %d %d:%d %s\n", monthNames[i], (*dt).day, (*dt).year, displayHour, (*dt).minute, ampm);
        }
    }
    
}

void setTime(const char timeString[], struct DateTime* dt){
    (*dt).hour = (timeString[0]-'0')*10 + (timeString[1]-'0');
    (*dt).minute = (timeString[3]-'0')*10 + (timeString[4]-'0');
}

//초기화변수(카운트)
//반복 until string 끝까지((alpha if(대문자,소문자) numif)) 
//변수주소에 값넣기
void countCharacters(const char str[], int* numAlpha, int* numDigits){
    int i, countAlpha=0, countDigit=0;
    for(i=0;str[i]!='\0';i++){
        if(((str[i]>='A')&&(str[i]<='Z')) || ((str[i]>='a')&&(str[i]<='z'))){
            countAlpha++;
        }
        if((str[i]-'0')>=0 && (str[i]-'0')<=9){
            countDigit++;
        }
    }
    *numAlpha = countAlpha;
    *numDigits = countDigit;
}

//변수 설정
//크기비교 -> min
//크기비교 -> max
//평균
void minMaxAverage(int array[],int size, int* minIdx, int* maxIdx, double* average){
    int i;
    double sum=0;
    *minIdx=0;
    *maxIdx=0;
    for (i=0;i<size;i++){
        if(array[i] < array[*minIdx]){
            *minIdx = i;
        }else if(array[i] > array[*maxIdx]){
            *maxIdx = i;
        }
        sum +=array[i];
    }
    *average= sum/size;
}
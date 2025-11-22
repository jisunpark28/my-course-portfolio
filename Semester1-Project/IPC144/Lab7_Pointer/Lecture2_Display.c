/******************************************

******************************************/

#define _CRT_SECURE_NO_WARNING
#include <stdio.h>


void display1(int, double);
void display2(int *, double *);

//Pass by value method
void display1(int first, double sec){
    printf("Values are %d : %.2lf\n", first, sec);

}

//Pass by address (or known as pass by reference) method
void display2(int* pt1, double* pt2){
    printf("Values are %d : %.2lf\n", *pt1, *pt2);

}

int main(){
    int x= 67;
    double y = 7.89;
    display1(x, y); 
    display2(&x, &y);
//값만 보여줄때는 pass by value, pass by address 모두 가능

    return 0;
}
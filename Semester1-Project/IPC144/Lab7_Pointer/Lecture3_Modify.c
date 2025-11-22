/******************************************
Activity1

Create a new function called 
modify to receive addresses for
a integer and double, 
add the two values and return the result 

Using main call modify and show the result received
******************************************/


#define _CRT_SECURE_NO_WARNING
#include <stdio.h>


void display1(int, double);
void display2(int *, double *);
double modify1(int*, double*);
double modify2(int, double);

//Pass by value method
void display1(int first, double sec){
    printf("Values are %d : %.2lf\n", first, sec);

}

//Pass by address (or known as pass by reference) method
void display2(int* pt1, double* pt2){
    printf("Values are %d : %.2lf\n", *pt1, *pt2);

}

double modify1(int* val1, double* val2){
    return (*val1) + (*val2);

}

double modify2(int val1, double val2){
    return (val1) * (val2);

}


int main(){
    int x= 67;
    double y = 7.89;
    display1(x, y);
    display2(&x, &y);
    printf("Modify returns : %.2lf\n", modify1(&x,&y));
    printf("Modify returns : %.2lf\n", modify2(x,y));
//값을 계산에 이용할때는 pass by value, pass by address 모두 가능
    return 0;
}
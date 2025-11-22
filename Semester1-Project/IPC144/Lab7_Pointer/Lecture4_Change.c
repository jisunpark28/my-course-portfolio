/******************************************
 Activity2

Think of another function where we 
need to update the x and y values of main
from user input. How are we going to 
achieve that.... 
******************************************/

#define _CRT_SECURE_NO_WARNING
#include <stdio.h>


void display1(int, double);
void display2(int *, double *);
double modify(int*, double*);
void change(int*, double*);

//Pass by value method
void display1(int first, double sec){
    printf("Values are %d : %.2lf\n", first, sec);

}

//Pass by address (or known as pass by reference) method
void display2(int* pt1, double* pt2){
    printf("Values are %d : %.2lf\n", *pt1, *pt2);

}

double modify(int* val1, double* val2){
    return (*val1) + (*val2);

}


void change(int* first, double* sec){
    //*first = 99;
    //*sec = 45.555;
    printf("Enter New Value for Main-X: ");
    scanf("%d", &(*first));   //Quiz : scanf("%d", ____); , &(*first) means first (address of x)
    printf("Enter New Value for Main-Y: ");
    scanf("%lf", &(*sec)); //&(*sec) means sec (address of y)
}
//원본 값 변경을 위해서는 꼭 pass by address

int main(){
    int x= 67;
    double y = 7.89;
    display1(x, y);
    display2(&x, &y);
    printf("Modify returns : %.2lf\n", modify(&x,&y));
    change(&x, &y);
    printf("New Values of X and Y are: %d, %.2lf\n", x, y);
    return 0;
}
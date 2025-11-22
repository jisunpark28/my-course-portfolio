/******************************************
Structs Example

2. Create a new program with two files casr.h, car.c

in car.h
Declare a struct called Vehicle to store vehicle 
information (brand, model, price, year)

in car.c
Create a fuction called getCarInfor
to obtain car information, store to a struct and return that back

Create a main function to obtain car information using getCarinfo and display
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Lecture3_Car.h"

int main(){

    struct Vehicle car = getCarInfor();
    printf("Brand: %s\tModel: %s\tPrice: %.2lf\tYear: %d\n", car.brand, car.model, car.price, car.year);
    return 0;
}

struct Vehicle getCarInfor(){
    struct Vehicle veh;

    printf("\nEnter Brand:");
    scanf("%20[^\n]%*c", veh.brand); //It's a string, so no &

    printf("Enter Model:");
    scanf("%20[^\n]%*c", veh.model); //100[^\n]는 scanf에서만 쓸 수 있음, printf는 %s

    printf("Enter Price:");
    scanf("%lf%*c", &veh.price);

    printf("Enter Year:");
    scanf("%d%*c", &veh.year);

    return veh;  //return을 꼭 해줘야함!!
}
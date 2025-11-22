/******************************************
Struct with Arrrays
- Initialization:  = {{0}}
******************************************/
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include "Lecture1_Car.h"
#define GSize 4
#define PSize 4

int main(){
    struct Car cr ={"Toyota","Tacoma","Green",12000.50,{30, 31, 29, 34},{40, -1, -1, -1} };
    int position=1, i;
    
    //Enter 4 gas values 45, 67, 34, 56, 78 but on at a time
    for(i=0; i<5; i++){
        addGas(cr.gasAmounts, &position);
    }

    changeProperties(&cr);

    //Display Car Properties
    mainDisplay(&cr, GSize, PSize);
    return 0;
}

//mainDisplay fn that receives an address to a car struct and sizes of gasAmount and pressure array sizes
void mainDisplay(struct Car* cr, int gSize, int pSize){
    int i;
    printf("Brand:%s\nModel:%s\nColor:%s\nPrice:%.2f\n", (*cr).brand, (*cr).model, (*cr).color, (*cr).price); //(*cr).price == cr->price
    displayPresssures((*cr).tirePressure, pSize);    //array이므로 그냥 이름사용. (&사용하지 않음!)
    for (i=0; i<gSize; i++){
        if((*cr).gasAmounts[i] != -1){
            displayGasAmount(&(*cr).gasAmounts[i]);
        }
    }
}

void displayPresssures(double press[], int sz){
    char dirs[4][3] = {"LF","RF","LR","RR"}; //string 저장 array
    // printf("%s\n",dirs[0]); //String 1 which is LF
    // printf("%s\n",dirs[0][1]); //Refers the second character of string 1 which is F
    int i;
    printf("==Tire Pressures==\n");
    for(i=0; i<sz; i++){
        printf("\t%s = %.2lf\n",dirs[i], press[i]);
    }
}

void displayGasAmount(double* amt){
    printf("GAS : %.2lf Liters\n", *amt);
}

void addGas(double gas[], int* pos){
    printf("Enter New Gas: ");
    scanf("%lf",&gas[*pos]);
    //Update the position using *pos
    *pos = (*pos+1)%4;
}

void changeProperties(struct Car* crs){
    printf("Enter Brand: ");
    scanf("%s[^\n]%*c", (*crs).brand);
    printf("Enter Model: ");
    scanf("%s[^\n]%*c", (*crs).model);
    printf("Enter Color: ");
    scanf("%s[^\n]%*c", (*crs).color);
    printf("Enter Price: ");
    scanf("%f%*c", &(*crs).price);
}
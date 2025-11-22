/******************************************
Struct with Arrrays
- Initialization:  = {{0}}
******************************************/
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include "Lecture2_Modify.h"
#define GSize 4
#define PSize 4

int main(){
    struct Car cr[2] ={{"Toyota","Tacoma","Green",12000.50,{30, 31, 29, 34},{40, -1, -1, -1}},
                     {"Toyota","Tundra","Black",32000.70,{31, 32, 23, 31},{42, 34, 56, 32}} };
    int position[2]={1,3};
    int i;
    
    //Enter 4 gas values 45, 67, 34, 56, 78 but on eat a time
    for(i=0; i<5; i++){
        addGas(cr[1].gasAmounts, &position[1]);
    }

    changeProperties(&cr[0]);

    //Display Car Properties
    mainDisplay(cr, 2, GSize, PSize);
    return 0;
}

//mainDisplay fn that receives an address to a car struct and sizes of gasAmount and pressure array sizes
void mainDisplay(struct Car cr[], int sz, int gSize, int pSize){
    int i,j;
    for(i=0;i<sz;i++){
        printf("Brand:%s\nModel:%s\nColor:%s\nPrice:%.2f\n", cr[i].brand, cr[i].model, cr[i].color, cr[i].price); 
        displayPresssures(cr[i].tirePressure, pSize);   
        for (j=0; j<gSize; j++){
            if(cr[i].gasAmounts[i] != -1){
                displayGasAmount(&cr[i].gasAmounts[j]);
            }
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
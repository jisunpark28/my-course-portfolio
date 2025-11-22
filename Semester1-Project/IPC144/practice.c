#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "practice.h"
#define gSIZE 4
#define pSIZE 4

int main(){
    struct Car car1[2] ={{"Toyota", "Tacoma", "Green", 12000.50, {30,31,29,34}, {40,-1,-1,-1}},
                         {"Honda", "CRV", "Gray", 50000.50, {30,31,29,34}, {40,-1,-1,-1}}};
    int position[2] = {1,1}, i;
    for (i=0;i<3;i++){
        addGas(car1[1].gasAmounts, &position[1]);
    }
    changeProperties(&car1[0]);
    mainDisplay(car1, 2, pSIZE, gSIZE);
    return 0;
}

void mainDisplay(struct Car cr[], int sz, int pSize, int gSize){
    int i, j;
    for(i=0;i<sz;i++){
        printf("Car Information\n");
        printf("Brand:%s\nModel:%s\nColor:%s\nPrice:%.2lf\n",
                (cr[i]).brand,(cr[i]).model,(cr[i]).color,(cr[i]).price);
        displayPressure((cr[i]).pressure, pSize);
        for(j=0;j<gSize;j++){
            if((cr[i]).pressure[j] != -1){
                displayGasAmount(&(cr[i]).gasAmounts[j]);
            }
        } 
    }   
}

void displayPressure(double press[], int sz){
    int i;
    char direction[4][3] = {"LF","RF","LR","RR"};
    printf("==Tire Pressure==\n");
    for(i=0;i<sz;i++){
        printf("\t%s:%.2lf\n", direction[i],press[i]);
    }
}
void displayGasAmount(double* amt){
    printf("Gas Amount: %.2lf Liters\n", *amt);
}

void addGas(double amt[], int* pos){
    printf("Enter new gas Amount: ");
    scanf("%lf", &amt[*pos]);
    *pos=(*pos+1)%4;
}

void changeProperties(struct Car* cr){
    printf("Enter Car Brand: ");
    scanf("%s%*c", (*cr).brand);
    printf("Enter Car Model: ");
    scanf("%s%*c", (*cr).model);
    printf("Enter Car Color: ");
    scanf("%s%*c", (*cr).color);
    printf("Enter Car Price: ");
    scanf("%lf%*c", &(*cr).price);
}
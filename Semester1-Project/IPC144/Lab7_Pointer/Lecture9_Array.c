/*
문법적 표현	                            실제 메모리 동작
int arr[] (함수 정의 시)	            **int *arr**과 100% 동일하게 취급됨
arr (배열 이름)	                        &arr[0] (첫 요소의 주소)와 동일함
arr[i] (배열 접근)	                    *(arr + i) (포인터 연산)과 동일함
*/

//Original Code-------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(int[], int);
int summate(int[], int);

void display(int mks[], int sz){
    int i;
    for(i=0; i<sz; i++){
        printf("Marks %d is : %d\n", i+1, mks[i]);
    }
}

int main(){
    int marks[] = {21, 45, 67};
    display(marks, 3);

    //char name[51] = "";
    return 0;
}


//First Commented Block(주소 전달) &marks[0] VS marks-------------------------------------------------------------------------------

// void display(int mks[], int sz){
//     int i;
//     for(i=0; i<sz; i++){
//         printf("Marks %d is : %d\n", i+1, mks[i]);
//     }
// }

// int main(){
//     int marks[] = {21, 45, 67};
//     display(&marks[0], 3);

//     //char name[51] = "";
//     return 0;
// }

//Second Commented Block(포인터 문법) int *mks VS int mks[]-------------------------------------------------------------------------------

// void display(int *mks, int sz){
//     int i;
//     for(i=0; i<sz; i++){
//         printf("Marks %d is : %d\n", i+1, mks[i]);
//     }
// }

// int main(){
//     int marks[] = {21, 45, 67};
//     display(&marks[0], 3);

//     //char name[51] = "";
//     return 0;
// }

//Third Commented Block(포인터 연산 문법) *mks, *(mks+1), *(mks+2)-------------------------------------------------------------------------------
// void display(int *mks, int sz){

//     //first value
//     printf("Marks 1: %d\n", *mks); //mks[0]
//     //second value
//     printf("Marks 1: %d\n", *(mks+1)); //mks[1]
//     //third value
//     printf("Marks 1: %d\n", *(mks+2)); //mks[2]

//     /*
//     int i;
//     for(i=0; i<sz; i++){
//         printf("Marks %d is : %d\n", i+1, mks[i]);
//     }
//     */
// }

// int main(){
//     int marks[] = {21, 45, 67};
//     display(&marks[0], 3);

//     //char name[51] = "";
//     return 0;
// }
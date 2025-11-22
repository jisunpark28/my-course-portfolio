/******************************************
Structs Example

4. Create a new program as following
There are 2 students in the class
Each student can take 2 subjects 

Create a program to 
1. define a student with following attributes 
  student name, age and subject and the marks the student got for that subject
2. Create two students in main.
3. Using a function called getStudentInfo, get all student infor
4. Using another function , display all student info

!struct type function
    함수 내에서 Struct 상자를 만들어서 상자 자체를 전달!!(returnO) (inputX, output-struct)
!일반 function
    함수가 struct 열쇠로 캐비넷을 열고 정보 수정 (returnX) (input-struct, outputX)    
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Lecture5_StudentArray.h"
#define SSIZE 2
#define CSIZE 2

int main(){

    struct Student sts[SSIZE];

    getstudentInfor(sts, SSIZE, CSIZE);
    displayStudents(sts, SSIZE, CSIZE);

    return 0;
}

void getstudentInfor(struct Student sts[], int numSt, int numCs){
    int i, j;

    for(i=0; i<numSt; i++){
        printf("Enter student %d name: ", i+1);
        scanf("%30s[^\n]%*c", sts[i].name);
        printf("Enter student %d age: ", i+1);
        scanf("%d%*c", &sts[i].age);

        for(j=0; j<numCs; j++){
            printf("\tEnter subject %d name: ", j+1);
            scanf("%20[^\n]%*c", sts[i].cs[j].cName);
            printf("\tEnter subject %d mark: ", j+1);
            scanf("%lf%*c", &sts[i].cs[j].mark);
        }
    }
}

void displayStudents(struct Student sts[], int sSize, int cSize){
    int i, j;
    for(i=0; i<sSize; i++){
        printf("Student %d: %s, Age: %d\n", i+1, sts[i].name, sts[i].age);
        for(j=0; j<cSize; j++){
            printf("\tSubject %d: %s, Mark: %.2lf\n", j+1, sts[i].cs[j].cName, sts[i].cs[j].mark);
        }
    }
}
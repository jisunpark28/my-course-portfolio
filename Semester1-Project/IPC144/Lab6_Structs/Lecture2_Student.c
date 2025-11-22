/******************************************
Structs Example 1

Modify the program(student.c) to create a 3rd student (sts3)
Obtain user inputs for student 3 and display them

Student - name, age, mark
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//Define a new Composite Data tipe
struct Student{
    //Attributes of a Student
    char name[30];
    int age;
    double mark;
};

int main(){
    //Declare a Student variable
    struct Student sts1;
    struct Student sts2 = {"Mark Henry", 27, 99.9};
    struct Student sts3;

    //How to access sts2 attributes
    printf("Name is : %s\n", sts2.name);
    printf("Age is : %d\n", sts2.age);
    printf("Mark is : %.2lf\n", sts2.mark);

    printf("Enter Name:");
    scanf(" %30[^\n]%*c", sts3.name); //%*c: read character but no store it.
    printf("Enter Age:");
    scanf("%d%*c", &sts3.age);
    printf("Enter Mark:");
    scanf("%lf%*c", &sts3.mark);

    //Display sts3 attributes
    printf("Name is : %s\tAge is : %d\tMark is : %.2lf\n", sts3.name, sts3.age, sts3.mark);

    return 0;
}
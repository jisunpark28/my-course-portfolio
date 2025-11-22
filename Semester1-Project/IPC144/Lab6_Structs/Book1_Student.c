#include <stdio.h>

struct Student
{
    char firstName[101];
    char lastName[101];
    int studentNumber;
    char program[5];
    float gpa;
};

int main(){
    struct Student student1 = {"Amy", "Lee", 123456789, "CPA", 3.7};

    printf("%s %s\n", student1.firstName, student1.lastName);
    printf("Student #: %d\n", student1.studentNumber);
    printf("Program: %s\n", student1.program);
    printf("GPA: %.2f\n", student1.gpa);
    return 0;
}
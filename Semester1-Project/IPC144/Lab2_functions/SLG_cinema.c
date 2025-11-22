#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SLG_cinema.h"


int getAdultTickets(void){
    int adults;
    printf("Enter number of adult tickets: ");
    scanf("%d", &adults);
    return adults;
}
int getStudentTickets(void){
    int student;
    printf("Enter number of student tickets: ");
    scanf("%d", &student);
    return student;
}
int getChildTickets(void){
    int child;
    printf("Enter number of child tickets: ");
    scanf("%d", &child);
    return child;
}
int calculateCost(int adults, int students, int children){
    int total;
    total = adults*12 + students*9 + children*6;
    return total;
}
void printSummary(int adults, int students, int children, int total){
    printf("\n--- Ticket Summary ---\n");
    printf("Adults: %d X $12\n", adults);
    printf("student: %d X $9\n", students);
    printf("child: %d X $6\n", children);
    printf("total: $%d", total);
}
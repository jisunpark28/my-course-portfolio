/******************************************
Implement the next program based on these function prototypes. 
We are required to program a simple movie ticket that allows 
our client to bill and calculate prices correctly. 
We have 3 categories: adult, student and child. 
$12, $9 and $6 respectively. 

Expected output:
Enter number of adult tickets: ..
Enter number of student tickets: ..
Enter number of child tickets: ..

--- Ticket Summary ---
Adults: .. X $12
student: .. X $9 
child: .. X $6 
Total: $...
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SLG_cinema.h"

int main(void){
    int adults, students, children, total;

    adults = getAdultTickets();
    students = getStudentTickets();
    children = getChildTickets();
    total = calculateCost(adults,students,children);
    printSummary(adults,students,children,total);


    return 0;
}
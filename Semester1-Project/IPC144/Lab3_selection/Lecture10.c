/******************************************
Loan type
	1 - Car Loan
	2 - Home Loan

The interest rate for a loan is dependent on type of loan and duration of loan(years) as following.
term(yrs)        1           2
loan type 1		1.99		3.99
loan type 2     4.99		5.99

Create a program to output the correct interest rate based on type of loan and term of loan inputs
Also make sure if invalid types or terms entered show an error

******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int type, term;
	printf("Enter your Loan Type as a number (1 for Car, 2 for House): ");
	scanf("%d", &type);
	printf("Enter Term(Years) of Loan: ");
	scanf("%d", &term);

	if (!(type == 1 || type == 2) || (term !=1 && term !=2)) { //!(type ==1 || type ==2), (type != 1 && type != 2)
		printf("Invalid Type or Term\n");
	}
	else if (type == 1 && term == 1){
		printf("1.99%%\n");
	}
	else if(type ==1 && term == 2){
		printf("3.99%%\n");
	}
	else if (type == 2 && term == 1){
		printf("4.99%%\n");
	}
	else {
		printf("5.99%%\n");
	}
	return 0;
}
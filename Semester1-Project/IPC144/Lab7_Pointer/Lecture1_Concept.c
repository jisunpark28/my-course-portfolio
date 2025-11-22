/******************************************
 * 
!! &ptr / *ptr / ptr

******************************************/

#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

int main(){

    int x = 78;
    int* ptr = &x;
    //int *ptr = &x;

    printf("Value   of x : %d\n", x);
    printf("Address of x : %x\n", &x);

    printf("Address of ptr: %x\n", &ptr);
    printf("Value of ptr : %x\n", ptr);   // %x : unsigned int
    printf("Value of X using ptr: %d\n", *ptr);

    *ptr = 100;
    printf("New Value of x : %d\n", x);


    return 0;
}



/*

pointer is a variable of a data type(any int,
double, struct Student....) whos purpose
is to REPRESENT another variable of the same data
type using the latter's address.


int x = 78;

int *ptr =&x;      //agentpointer is a variable of a data type(any int, 
double, struct Student....) whos purpose 
is to REPRESENT another variable of the same data 
type using the latter's address.


int x = 78;

int *ptr =&x;      //agent 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	int x = 78;
	int* ptr = &x;

	printf("Value   of x : %d\n", x);
	printf("Address of x : %x\n", &x);

	printf("Addres of ptr: %x\n", &ptr);
	printf("Value of ptr : %x\n", ptr);
	printf("Value of X using ptr: %d\n", *ptr);

	*ptr = 100;
	printf("New Value   of x : %d\n", x);








	return 0;
}
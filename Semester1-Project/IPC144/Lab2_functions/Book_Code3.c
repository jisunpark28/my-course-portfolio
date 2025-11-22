/***************************************************************** 
[Runtime Stack]
Runtime Stack: The runtime stack is a structure used to organize local variables and function calls
Stack Frames: Each stack frame tracks a single function call. It tracks every the value of every variable and parameter for that particular function call

note!! when a function is completed, so at this point, the frame is removed and a value is returned to the calling funtion.
***************************************************************/

#include <stdio.h>

int abacus(int);
int calculator(int);
int computer(int);

int main(void) //We start with a stack frame for the main() function
{

	int result = abacus(0);  
	printf("result = %d\n", result);
	return 0;
}
int abacus(int info) 
{
	int rc = 1;		

	printf("abacus one\n"); 
	rc += computer(info); 
	printf("abacus two, rc = %d\n", rc);
	return rc;
}
int calculator(int data)  
{
	printf("calculator\n"); 
	return data + 1;       
}
int computer(int data) 
{
	int rc;                    
	printf("computer one\n");  
	rc = calculator(data + 1); 
	printf("computer two\n");  
	return rc;
}


/***************************************************************** 
[Runtime Stack]
 
    calculator(1) data 1 --> return 2
    computer(0) rec = 2 calculator(data + 1), data = 0 --> return 2
    abacus(0) = (rc=1) rc += computer(0), info =0 --> return 3
    main(void) result = abacus(0)
***************************************************************/
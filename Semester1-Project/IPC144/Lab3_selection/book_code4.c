/*
Would you like a Large(L) or Small(S) drink? S
Would you like to add tapioca (Y or N)? Y
Would you like to add jelly (Y or N)? N
Price is: $6.25

Selection - Alternative
    1. Explicit Branching
        if-else (참이면 A, 거짓이면 B)
    2. Default & Override
        if (일단 Default value 세팅, 만약 조건이 참이면 값을 덮어 씀 )
    3. mutually exclusive condiitons
        if-else if-else if-else if-else
    4. Multiple path way(not mutually exclusive conditions)
        if-if-if
    
*/

#include <stdio.h>
#include "book_code.h"

char getSize()
{
	char size;
	printf("Would you like a Large(L) or Small(S) drink? ");
	//notice the space in front of the %c in this scanf().
	//when you read a number, the compiler knows to ignore whitespace characters
	//such as space, tab and newlines.  However, when you read a character,
	//space, tab and newlines may actually be the data you are trying to read.
	//thus, the space in front of the %c means remove all leading whitepaces.
	//this is especially important on the second and third scanfs that involve
	//characters because when the user will type L then hit the return key (a newline)
	//the newline must be "read" in order to get to the next piece of real information
	scanf(" %c", &size);
	return size;
}
char getTapioca()
{
	char tapioca;
	printf("Would you like to add tapioca (Y or N)? ");
	scanf(" %c", &tapioca);
	return tapioca;
}
char getJelly()
{
	char jelly;
	printf("Would you like to add jelly (Y or N)? ");
	scanf(" %c", &jelly);
	return jelly;
}
double calculateTea(char size, char addTapioca, char addJelly)
{
	//default to small size price
	double totalPrice = 4.00;
	if(size == 'L'){
		//change initial price if it is large
		totalPrice = 5.50;
	}
	if(addTapioca=='Y'){
		totalPrice += 0.75;
	}
	if(addJelly == 'N'){
		totalPrice += 0.5;
	}
	return totalPrice;
}

void printResult2(double price)
{
	printf("Price is: $%.2lf\n",price);
}
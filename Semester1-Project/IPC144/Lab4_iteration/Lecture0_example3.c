/******************************************
[do-while + if] 

Obtain a vowel. As long as user enters non-vowel characters, keep on asking for a new input for a vowel 
When vowel in entered display and exit

note! when ommit '%*c' --> 1loop skip
	%d%*c
	%c%*c

[condition] 조건 여러개일 경우,
a or e --> && 써야 함. (true && fals --> fals)

******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	char vowel;

	//do-whilel loop
	do {

		//instructions
		printf("Enter vowel: ");
        scanf(" %c", &vowel);
        
        if(vowel != 'a' && vowel !='e' && vowel !='i' && vowel !='o' && vowel !='u'){
            printf("Not a vowel, Enter Again..\n");
        }

	} while (vowel != 'a' && vowel !='e' && vowel !='i' && vowel !='o' && vowel !='u');


	return 0;
}
/********************************************************************* 
All Caps

Enter a word: r2d2
r2d2 in all caps: R2D2

Steps:
Prompt user for a word
Read the word into a string
Go through each character in the string
Check if the character is a lowercase letter
If it is lowercase, convert it to uppercase
If it's not lowercase, leave it unchanged
Print the result
**********************************************************************/

#include <stdio.h>

void getWord(char word[]);
void allCaps(char word[]);

int main(void)
{
    char word[100];

    getWord(word);
    printf("%s in all caps: ", word);
    allCaps(word);
    printf("%s\n", word);
    return 0;
}

void getWord(char word[])
{
    printf("Enter a word: ");
    scanf("%s", word);
}
void allCaps(char word[])
{
	//calculate the distance between lower case to upper case.
	//As lower case sequence is same as upper case
	//sequence.. that is a -> b ->c ... A->B->C...
	//Thus the distance between the the corresponding letters are the same;
	int distance = 'a' - 'A';
	int i;
	//loop through and check for null char  to get to the end
	for (i = 0 ; word[i] != '\0'; i ++){
		//if lower case
		if(word[i] >='a' && word[i] <= 'z'){
			//convert
			word[i] = word[i] - distance;
		}

	}
}
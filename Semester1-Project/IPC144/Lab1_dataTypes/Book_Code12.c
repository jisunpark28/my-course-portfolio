/******************************************
Programming:
A recipe for sweet and sour ribs makes the sauce out of 4 ingredients in different proportions. The recipe uses: 1 part soy sauce, 2 parts vinegar, 3 parts sugar and 4 parts water. Thus, if someone uses 100ml of soy sauce, they would need 200 ml of vinegar, 300ml of sugar and 400ml of water to make up the recipe.

Sample Run:

Enter the number of ml of soy sauce are you using: 100

Your recipe will use:

100 ml of soy sauce
200 ml of vinegar
300 ml of sugar
400 ml of water
******************************************/
#define CRT_CECURE_NO_WARNING
#include <stdio.h>
int main(void)
{
    int soyAmount;

    printf("Enter the numbr of ml of soy sauce are you using: ");
    scanf("%d", &soyAmount);

    printf("\nYour recipe will use:\n\n");
    printf("%d ml of soy sauce\n", soyAmount);
    printf("%d ml of vinegar\n", soyAmount*2);
    printf("%d ml of sugar\n", soyAmount*3);  
    printf("%d ml of water", soyAmount*4);         

 return 0;
}
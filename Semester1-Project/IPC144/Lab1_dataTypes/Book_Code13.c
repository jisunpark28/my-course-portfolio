/******************************************
Programming:
Write a program that will ask the user for the total amount of sauce they want. The program will then figure out how much of each ingredient is needed. Output the result to the nearest ml. For simplicity you may assume that all ingredients contribute their full amount to the total sauce volume (this is not true in practice)

Sample Run:

Please enter how much sauce you want to make in ml: 200

Your recipe will use:
20 ml of soy sauce
40 ml of vinegar
60 ml of sugar
80 ml of water


Note: double로 계산하되, %.0lf을 이용해서 정수로 표현!!!
******************************************/
// #define CRT_CECURE_NO_WARNING
// #include <stdio.h>
// int main(void)
// {
//     int sauceTotal;

//     printf("lease enter how much sauce you want to make in ml: ");
//     scanf("%d", &sauceTotal);

//     printf("\nYour recipe will use:\n");
//     printf("%d ml of soy sauce\n", sauceTotal * 1 / 10);
//     printf("%d ml of vinegar\n", sauceTotal * 2 / 10);
//     printf("%d ml of sugar\n", sauceTotal * 3 / 10);  
//     printf("%d ml of water", sauceTotal * 4 / 10);         

//  return 0;
// }



#include <stdio.h>
int main(void)
{
	int total;
	double part;

	printf("Please enter how much sauce you want to make in ml: ");
	scanf("%d",&total);
	part = total/10.0;	//note that 10.0 and 10 are not the same.  total/10 is an int
						//it would be a truncated result.

	printf("\nYour recipe will use:\n\n");
	printf("%.0lf ml of soy sauce\n", part);
	printf("%.0lf ml of vinegar\n", part*2);
	printf("%.0lf ml of sugar\n", part*3);
	printf("%.0lf ml of water\n", part*4);
	return 0;
}


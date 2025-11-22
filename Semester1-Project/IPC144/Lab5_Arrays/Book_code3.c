//readNumbers() function



#include <stdio.h>
//our spec stated that we expect 20 numbers
#define CAPACITY 20

//this function reads from the user a set of numbers and stores it into an array.  Reading stops
//after CAPACITY values are read or after user enters a 0.  Function returns number of values read
int readNumbers(int numbers[]);

int main(void)
{
	//declare an array with CAPACITY elements
    int numbers[CAPACITY]={0};
    int used = readNumbers(numbers);

    return 0;
}

int readNumbers(int numbers[])
{
    int used = 0;
    int input;

    printf("Please enter a number (0 to exit): ");
    scanf("%d", &input);

    //continue reading while we have space in array and user hasn't entered 0
    while(used < CAPACITY && input != 0) {
        numbers[used] = input;  //store the number in array
        used++;                 //increment count of stored numbers

        printf("Please enter a number (0 to exit): ");
        scanf("%d", &input);
    }

    return used;
}


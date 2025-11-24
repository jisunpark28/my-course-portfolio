#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void clearButter();

void clearBuffer() {
    while(getchar()!='\n');
}


int main(){


    //To get the size of any array
    char name[21]="aa ss";
    printf("%ld\n", sizeof(name));

    char ch;
    int num;
/*
    printf("Enter a number: ");
    //scanf("%d%*c", &num);
        //scanf("%d%*[^\n]", &num);

    printf("Enter a letter: ");
    scanf("%c%*c", &ch);

    printf("NUM=%d CHAR=%c\n", num, ch);
*/

/* 좀 더 살펴볼것, 이 케이스
    printf("Enter a number: ");
    scanf("%d%*[^\n]", &num);

    printf("Enter a letter: ");
    scanf("%c%*c", &ch);

    printf("NUM=%d CHAR=%c\n", num, ch);
*/

/*
    printf("Enter a number: ");
    scanf("%d", &num);
    clearBuffer();

    printf("Enter a numbletter: ");
    scanf("%c", &ch);
    clearBuffer();

    printf("Press Enter to continue the program ...\n");
    clearBuffer();


    printf("NUM=%d CHAR=%c\n", num, ch);
*/


char testNum;
int val;

do{
    printf("Enter a number: ");
    val = scanf("%d%c",&num,&testNum);

    if(val != 2 || testNum != '\n'){
        printf("Not a Number, Enter Again...\n");
        clearBuffer();
    }
} while(val != 2 || testNum != '\n');

printf("Enter a letter: ");
scanf("%c", &ch);
clearBuffer();

printf("Press Enter to continue the program....");
clearBuffer();

printf("NUM=%d  CHAR=%c\n", num, ch);
    return 0;
}
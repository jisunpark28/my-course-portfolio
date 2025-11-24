#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

    char name1[] ="Seneca College";
    char name2[31];
    char name3[31];
    char name4[31]="The ";
    char name5[31]="Seneca CA";
    char name6[31]="Seneca CB";

    // length of string
    int len = strlen(name1);
    printf("Length of string: %d\n", len);


    // copy string
    strcpy(name2, name1);
    puts(name2); // = printf("%s", name2);, it has null terminater 

    //string copy for n number of chars
    strncpy(name2, name1, 5);
    puts(name2); // \0 null, it doesn't have null terminater, it displays all string, because 

    //string copy for n number of chars
    strncpy(name3, name1, 5);
    puts(name3); // it could be show garbage data after 5 letters

    //string copy for n number of chars
    strncpy(name3, name1, 5);
    name3[5] = '\0';
    puts(name3); // it could be show garbage data after 5 letters

    //String concatenation
    strcat(name3, name2);
    puts(name3);

    //String concat with  n chars
    strncat(name4, name3, 3);
    puts(name4);

    //string compare
    int ret = strcmp(name5, name6);
    printf("Result: %d (Compare %s and %s)\n", ret, name5, name6);


    //string compare n chars
    int retN = strncmp(name5, name6, 4);
    printf("Result: %d (Compare %s and %s)\n", retN, name5, name6);


    return 0;
}
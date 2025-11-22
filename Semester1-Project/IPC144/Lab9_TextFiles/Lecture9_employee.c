#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(){

    FILE* fp = NULL;
    fp = fopen("readwrite.txt","w+");
    char line[41];

    if(fp != NULL){
        fprintf(fp, "First Line Written\n"); //pointer starts the second line
        rewind(fp); //pointer back to the 
        fscanf(fp,"%40[^\n]%*c", line);
        printf("You wrote and read : %s\n", line);
        fclose(fp);
    }
    else{
        printf("Error!!\n");
    }
    return 0;
}



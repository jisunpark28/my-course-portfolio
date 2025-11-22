#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Lecture8_employee.h"
#define SIZE 10

int main(){

    struct Employee employee[SIZE] = {{0}};
    int records = loadData("data3.txt", employee, SIZE);
    
    int i;
    for(i=0; i<records-1;i++){
            display(&employee[i]);
    }
    return 0;
}

int loadData(const char fname[], struct Employee emps[], int sz){
    FILE* fp = NULL;
    int i=0, retVal;
    fp = fopen(fname,"r");

    if (fp != NULL){

        do{
            retVal = fscanf(fp,"%d,%30[^,],%lf,%12[^\n]%*c", &emps[i].id, emps[i].name, &emps[i].salary, emps[i].phoneNo);
            if(retVal==3){
                emps[i].phoneNo[0]='\0';
            }
            i++;
        } while(i<sz && retVal >=3);

        fclose(fp);
    }
    else{
        printf("File Open Error !!!\n");
    }
    return i;
}

void display(const struct Employee* emp){
    if((*emp).phoneNo[0] != '\0'){          //when there is a phone number
        printf("%4d%25s%12.2lf%15s\n",(*emp).id,(*emp).name, emp->salary, emp->phoneNo);
    }
    else{
        printf("%4d%25s%12.2lf\n",emp->id,emp->name, emp->salary);
    }
}


/*

Output Formatting (%4d, %25s): Align columns (e.g., reserve 4 spaces for ID, 25 for name). 
Data Validation ((*emp).phoneNo[0] != '\0'): Check if the first character of the string is not the null terminator to confirm data exists. 
Loop Selection: Use a do-while loop instead of a while loop when processing records with a varying number of returned items (e.g., 4 or 3). 
Array Safety: Use the condition i < size to prevent exceeding array boundaries. 
Function Return: Return the i value (the count of records read) from the function. 
File Pointer Reset: Use rewind(FILE *fp) to move the file pointer back to the beginning of the file. 
Pointer Access: Access structure members via pointer using either (*employee).id or employee->id.

*/
#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include "Lab5.h"

int main(){

    //Function1: Sum of array
    int array1[4] = {1, 5, 4, 3};
    int sum = findSum(array1,4);
    printf("Sum of array: %d\n", sum);


    //Function2: Reverse array
    int i;
    int array2[6] = {2,1,3,4,7,6};
    reverse(array2, 6);
    printf("{");
    for(i=0;i<6;i++){
        printf("%d", array2[i]);
        if(i!=5){
            printf(",");
        }
    }
    printf("}\n");    


    //Function3: Count character occurrences
    char mystring[100]={"the quick brown Fox jumped\tOver r2d2 but c 3po was\n Too tall"};
    int numTs = countChar('t',mystring);
    printf("The counts of the letter T: %d\n", numTs);    
    

    //Function4: Count character occurrences (case insensitive)
    int numTsAll = countAllCase('o',mystring);
    printf("The counts of the letter o: %d\n", numTsAll);

    //Function5:
    double average = findAverage(array2, 6);
    printf("The Average of the values of Array: %.2lf\n", average);

    //Function6:
    int array6[6] = {2,1,3,1,7,6};   
    int keyFound = linearSearch(1, array6, 6);
    printf("Searching the Key Value:%d\n", keyFound);

    //Function7:
    char mystringLowcase[100]={"the quick brown Fox jumped\tover r2d2 but c 3po was\n too tall"};
    capitalize(mystringLowcase);
    printf("%s\n", mystringLowcase);

    //Function8:
    char mystringTrailling[50] = "hello  \t world \n\t\n"; 
    removeTrailingWhitespace(mystringTrailling);
    printf("%s\n", mystringTrailling);

    return 0;
}

int findSum(const int array[], int size){
    int i; int sum=0;
    for(i=0; i<size; i++){
        sum += array[i];
    }
    return sum;
}

//값을 Swap할때는 하나의 임시 변수만 사용해야함.
void reverse(int array[], int size){
    int temp, i;
    for (i=0; i<size/2; i++){
        temp = array[i];
        array[i] = array[size-1-i];
        array[size-1-i] = temp;
    }
}

//for 루프로 array를 검토할때는 \0문자 고려할것!
int countChar(char ch,const char str[]){
    int count=0, i;
    for (i=0; str[i]!='\n'; i++){
        if (ch==str[i]){
            count++;
        }
    }
    return count;
}

//This function returns the number of times ch shows up. 
//If ch is an alphabetic character, 
//count both the upper and lower case versions of this character.
//1)같을 경우 2)대소문자 차이 있을경우(소문자가 대문자랑 같을경우/대문자가 소문자랑 같은경우)
int countAllCase(char ch,const char str[]){
    int i, count=0; 
    for(i=0;str[i]!='\0';i++){
        if(ch==str[i]){
                count++;
        }else{
            if((ch>'a' && ch <'z')&&(ch==(str[i]+32))){
                count++;
            }else if((ch>'A' && ch <'Z')&&(ch==(str[i]-32))){
                count++;
            }
       }       
    }
    return count; 
}

int findSmallest(int array[], int size){
    int result=0, i=0;
    result = array[0];
    for(i=0;i<size;i++){
        if(result>array[i]){
            result = array[i];
        }
    }
    return result;
}

double findAverage(int array[],int size){
    double result=0, sum=0;
    int i;
    for(i=0; i<size; i++){
        sum += array[i];
    }  
    result = sum/size;
    return result;
}


int linearSearch(int key, const int array[], int size){
    int result=-1, i, flag=0;
    for(i=0;i<size||flag==0;i++){
        if(key==array[i]){
            result=array[i];
            flag=1;
        }
    } 
    return result;
}



void capitalize(char str[]){
    int i=0;
    while (str[i]!= '\0'){
        if (i == 0 || str[i-1]==' ' || str[i-1]=='\t' || str[i-1]=='\n' ){
            if (str[i]>='a' && str[i]<='z'){
                str[i] = str[i]-32;
            }
        }
        i++;
    }
}



void removeTrailingWhitespace(char str[]){
    int i=49, flag=0, num;
    while(flag==0){
        if (str[i]>='A' && str[i]<='z'){
            flag=1;
            num=i;
        }
        i--;
    }
    for(i=num+1; i<50;i++){
        str[i]=0;
    }
}

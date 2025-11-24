#include <stdio.h>
#include <string.h>

int main(){

    char destination[10] ="hello";
    printf("Array: %s\n", destination);

    char destinationStr[10];
    strcpy(destinationStr, "hello");
    printf("Strcpy: %s\n", destinationStr);

    char s1[10] = "apple";
    char s2[10] = "banana";
    int compare = strcmp(s1,s2);
    printf("Compare two words: %d\n", compare);
        // 0 : s1 = s2
        // negative : s1 < s2 (lexically)
        // positive : s1 > s2 (lexically)

    char ch = "a";
    int count = countVersionA(ch, s1);
    printf("%d", count);
    return 0;
}

    int countVersionA(char ch, char str[]) {
        int count=0;
        int i;
        int length = strlen(str);
        for (i=0; i<length; i++){
            if(str[i]==ch){
                count++;
            }
        }
        return count;
    }
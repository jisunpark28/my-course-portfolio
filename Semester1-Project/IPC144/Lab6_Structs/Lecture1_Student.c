/******************************************
Student - name, age, mark
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//Define a new Composite Data type
struct Student{
    //Attributes of a Student
    char name[30];
    int age;
    double mark;
};

int main(){
    //Declare a Student variable
    struct Student sts1;
    struct Student sts2 = {"Mark Henry", 27, 99.9};

    //How to access sts2 attributes
    printf("Name is : %s\n", sts2.name);        //배열공간이 많이 남았어도 %s 하니까 null앞까지만 표기하네. 
    printf("Age is : %d\n", sts2.age);
    printf("Mark is : %.2lf\n", sts2.mark);
    return 0;
}


/******************************************
[Review]
Strings: Defined as a character array with a null terminator
Null Terminator: indicates the end of a string ('\0')

Arrays (Contrast with Structs): are limited to a single data type and related by index
Parallel arrays: multiple arrays to represent composite data

[Arrays VS Structs]
Data Type
    Arrays: single data type
    Structs: multiple data types    
Access Method
    Arrays: index-based
    Structs: attribute-based (using dot operator)
Logical Relationship
    Arrays: no inherent relationship between elements
    Structs: attributes are logically related 
Use Case
    Arrays: store collections of similar items
    Structs: store composite data items 

[Structs]
attributes: are called data members. refer to the variables inside the struct
Accessing Attributes: using the dot (.) operator
Struct Definition Syntax: defined using the struct keyword
struct: keyword used to define a new composite data type
data member: variable inside a struct
data type: the type of data a variable can hold (e.g., int, char, double)

[scanf]
input buffer/read buffer: A specific memory location or region used to store intermediate inputs (like typed characters or numbers) when the user presses Enter
%*c: A format specifier used in scanf statements when reading characters after reading numbers. The asterisk (*) means read the character, but do not store it into a variable. This is done to clear the leftover newline character (\n) from the input buffer so that the next scanf correctly waits for user input instead of skipping immediately

[각각 '끝'을 어떻게 정의하는지]
Strings: null terminator ('\0')
Arrays: fixed size defined at declaration
Structs: defined by the struct definition, padding may be added for alignment


******************************************/
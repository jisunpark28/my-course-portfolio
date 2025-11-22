/******************************************
Sphere

note: int/int = int  ==> float/int = float

[Terminalogy]
An expression is a sequence of operator(s) and operand(s) that evaluates to a single result.

Operators are symbols used to indicate the operation to be performed. For example, the + symbol is the addition operator, which specifies that the operands should be added together.

Operands are the data that is being used by the operator. For example the two values on either side of the + would be the operands for that operation

Precedence refers to the order of operations of the operators. Each operator has a precedence which dictate the order of evaluation within an expression with multiple operators. Precedence can be modified based using round brackets ().
constant: 
Syntax errors : A syntax error is an error that breaks the language rules of your programming language. For example, C requires each statment to be terminated with a semi-colon (;). If you forget to add this, you are breaking the syntax rules and it will result in a syntax error
Logic errors (=symantic errors) :  A logical error is an error where the logic of the program is not correct... this could be a miscalculation, a wrong sequencing of statements, a misplaced logical structure and more
******************************************/
#include <stdio.h>
int main(void)
{
    double const pi = 3.14159;
    double volume ;
    double radius ;

    printf("Please enter the radius of the sphere: ");
    scanf("%lf", &radius);
    volume = 4.0/3 * pi * radius * radius * radius;
    printf("The volume of the Sphere is %.2lf", volume);

    return 0;
}
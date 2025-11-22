/******************************************
Debugging:
The following is a program that should print out the numbers 1 to 5 one per line. If it was working, this would be the output:

1
2
3
4
5


However, there are bugs in the program (both syntactic and logical).

#include <stdio.h>
int main(void)}
    integer x=0;
    printf("%d\n",x++);
    printf("%d\n",x++);
    printf("%d\n",x++);
    printf("%d\n",x++);
    printf("%d\n",x++);
    return 0
}

1. What are the syntax error generated when you compile the program as is?
2. What is the cause of the syntax error(s) and how would you fix it?

    a. '}' instead of '{' on the 'int main(void)}' line
    b. 'integer' instead of 'int' on the 'integer x=0;' line
    c. missing ';' on the 'return 0' line


3. What logical error exist in above program?

    x is initially 0, the first line of output outputs x++. 
    since x++ results in the original value of x, the first ouput would be 0. 

4. How do you fix it?

    To fix it, we can do one of two things. Either we initialize x with 1 (int x = 1)
    or we put prefix increment instead of profix on each line.

******************************************/

#include <stdio.h>
int main(void)}
    integer x=0;
    printf("%d\n",x++);
    printf("%d\n",x++);
    printf("%d\n",x++);
    printf("%d\n",x++);
    printf("%d\n",x++);
    return 0
}
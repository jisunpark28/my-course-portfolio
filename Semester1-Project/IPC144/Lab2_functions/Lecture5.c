/******************************************
1. Create new project
2. create header file(.h)
    put function prototypes
3. create source file(.c)
    put #define _CRT_SECURE_NO_WARNINGS
        #include <stdio.h>
        #include "calculate.h"
        functions 
4. creat another source file(.c)
    put head name of functions 
            #include <stdio.h>
            #include "calculate.h"
        main fuction
******************************************/

#include <stdio.h>
#include "calculate.h"

int main() {

	double fVal = getInput();
	double sVal = getInput();

	double retVal = add(fVal, sVal);
	display(retVal);

	return 0;
}
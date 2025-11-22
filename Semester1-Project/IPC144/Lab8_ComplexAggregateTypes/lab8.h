/***************************************************************** 

    File: lab8.h

    Author: [Your Name]
    Seneca email: [Your Seneca email address]

	The function prototypes for every function you write go
	into the header file.  You do not need to modify this file
        
***************************************************************/

/*this struct is used by all functions in lab 8.  We typically declare structs in 
.h files so that it can be included in all files that need to use the struct*/

struct DateTime
{
	int day;
	int month;
	int year;
	int hour;
	int minute;
};

/* Add the function prototypes for the lab8 problems to this file.  
 below this comment  You can copy these from the lab specifications. */

int readNumericDataFile(const char*, struct DateTime [], int);
int readStringDataFile(const char*, struct DateTime [], int);
void printToFile(const char*, struct DateTime [], int);

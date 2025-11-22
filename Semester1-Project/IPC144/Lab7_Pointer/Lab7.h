/***************************************************************** 

    File: lab7.h

    Author: Jisun Park
    Seneca email: jpark295@myseneca.ca

	The function prototypes for every function you write go
	into the header file.  You do not need to modify this file
        
***************************************************************/

/*this struct is used by all functions in lab 7.  We typically declare structs in 
.h files so that it can be included in all files that need to use the struct*/

struct Date
{
    int day;
    int month;
    int year;
};

int findDate(int, int, int, struct Date [],int);
int numInYear(int, struct Date [], int);
int cmpDates(int, int, struct Date []);
void printDates(struct Date [], int);
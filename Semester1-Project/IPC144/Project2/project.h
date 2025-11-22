/***************************************************************** 

    File: project.h

    Author: Jisun Park
    Seneca email: jpark295@myseneca.ca

    To compile program in codespaces, in terminal pane type:
        gcc -Wall project.c projectmain.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//function prototypes go into this file as does any constants

#define SIZE 95000

struct BabyName
{
    int year;
    char name[31];
    int frequency;
};
void nameOrganize(char[]);
int displayMenu(void);
int loadData(const char*, const char*, struct BabyName[], struct BabyName[], int*, int*);
void findNameCount(struct BabyName[], struct BabyName[], int, int);
void insertionSort(struct BabyName [], struct BabyName);
void getTopNames(struct BabyName [], struct BabyName [], int, int);
void nameHistogram(struct BabyName [], struct BabyName [], int, int);
int countPerYear(char [], int, struct BabyName[], struct BabyName[], int, int);
void saveCombinedData(struct BabyName [], struct BabyName [], int, int);
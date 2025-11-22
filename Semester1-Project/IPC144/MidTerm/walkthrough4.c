#include <stdio.h>
#define CAPACITY 4
int rose(int blossom[]);
void printArray(int array[], int size);

int main(void)
{
	int orchid[CAPACITY] = {2, 1, 3, 5};
	int total;
	printArray(orchid,CAPACITY);
	total = rose(orchid);
	printArray(orchid,CAPACITY);
	printf("total: %d\n",total);
	return 0;
}

int rose(int blossom[])
{
	int rc=0;
	int i, j;
	for(i=0, j=CAPACITY-1;i<CAPACITY;i++, j--){
		blossom[i] += blossom[j];
		rc += blossom[i];
	}
	return rc;
}
//prints an array with space separating
//each value of array
void printArray(int array[], int size)
{
	int i;
	for(i = 0 ;i < size;i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
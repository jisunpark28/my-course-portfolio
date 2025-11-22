#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	//file start point & end point

	FILE* fp = NULL; //files are represented using pointers Since the size of the file is variable 구조체 정의
					 //When declaring a pointer without immediately assigning an address, it is customary to initialize it with the NULL value. 
					 //NULL signifies that the pointer is not associated with an address.
	fp = fopen("data.txt", "w"); //2 parameters: file name/directory, file mode(6 types) 구조체 위치 정의
								 //The fopen function is utilized to load a file located on the hard drive into memory (RAM). 
								 //This function returns the starting address of the file.
	int v1 = 9;
	if (fp != NULL) {
		fprintf(fp,"This is first line %d\n", v1);
		fprintf(fp, "This is second line %d\n", v1+8);

		fclose(fp); //Explicitely save changes permanantly
	}
	else {
		printf("File Open Error !!!\n");
	}

	return 0;
}
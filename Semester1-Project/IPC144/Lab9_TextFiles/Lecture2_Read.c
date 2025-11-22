#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	FILE* fp = NULL;
	fp = fopen("data.txt", "r"); 
	char buffer[51];

	if (fp != NULL) { //작업이 성공하면, fp는 더 이상 NULL이 아니며 파일의 시작 주소를 가지게 됩니다
		
		fgets(buffer, 50, fp); //read 1st line, after read 1st line cursor moves to next line, so if after writing somthing, we have to move the cursor to the point to read. 
		printf("%s", buffer);


		fgets(buffer, 50, fp); //read 2nd line(automatically moves to next line), because cursor is already at next line
		printf("%s", buffer);


		fclose(fp);
	}
	else {
		printf("File Open Error !!!\n");
	}

	return 0;
}
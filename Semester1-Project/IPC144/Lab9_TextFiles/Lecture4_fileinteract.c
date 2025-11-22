/*
record means txt file, fild means content in the file
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Student {
	int id;
	int age;
	char name[31];
	double mark;
};

int main() {

	FILE* fp = NULL;
	struct Student st;
	fp = fopen("data2.txt", "r");

	if (fp != NULL) {

		fscanf(fp, "%d,%d,%20[^;];%lf%*c", &st.id, &st.age, st.name, &st.mark); //don't put space
		printf("ID=%d\t Age=%d\t Name=%s \t Mark=%.2lf\n", st.id, st.age, st.name, st.mark);

		fscanf(fp, "%d,%d,%20[^;];%lf%*c", &st.id, &st.age, st.name, &st.mark); //don't put space
		printf("ID=%d\t Age=%d\t Name=%s \t Mark=%.2lf\n", st.id, st.age, st.name, st.mark);

		fclose(fp);
	}
	else {
		printf("File Open Error !!!\n");
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Lecture9.h"

int main(void) {
	double mks = getMark();
	char let = obtainLetter(mks);
	display(let);
	return 0;
}
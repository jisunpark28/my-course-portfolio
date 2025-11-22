 /******************************************
Iteration

3. for loop: initialize(최초한번), condition, count(카운트먼저하고 조건확인)

Note! 몇번 진행할지 정해졌을때만 for loop


Q1. Obtain marks of 5 students and find the average
Q2. Modify Q1 to make sure the marks you enter are valid (if not ask again and again)
Q3. Find the minimum and maximum marks

왜 잘못된 값 들어오면 완전히 끝나지? for 루프 다시 들어가야하는거 아냐?

******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int count;
    double mark, total=0, min=100, max=0;

for (count=0;count<5;count++) {
    do {
        printf("Enter Mark for Student %d: \n", count+1);
        scanf("%lf", &mark);

        if (mark<0 ||mark>100){
            printf("INvalid Mark, Enter Again...");
        } 

        
    }while (mark < 0 || mark > 100);
    if (mark>max) max = mark;
    if (mark<min) min = mark;
    total = total + mark;
}
    printf("Average is: %.2lf\n", total / count);
    printf("Mimimum mark is: %.2lf\n", min);
    printf("Maximum mark is: %.2lf\n", max);

	return 0;
}
 

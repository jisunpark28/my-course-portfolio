/*****************************************************************************

*****************************************************************************/

#include <stdio.h>
// #define SIZE 10

// int main(){
    // printf("%10dTEST\n", 34); // 10spaces before the value
    // printf("%-10dTEST\n", 34); // 10spaces after the value
    // printf("%10d%12.2lf%20s%6c\n", 34,56.7888,"David Lucas", 'Y'); // 
    // printf("%-10d%12.2lf%20s%%6c\n", 56.7888,"David Lucas", 'Y'); //
    // printf("%010d%12.2lf%20s%6c\n", 34,56.7888,"David Lucas", 'Y'); // 

//     double mark[SIZE], sum=0;
//     int i;

//     do{
//         for (i=0;i<SIZE;i++){
//             printf("Please enter mark for student %d: ", i+1);
//             scanf("%lf", &mark[i]);
//             sum +=mark[i];
//         }
//     }while(mark[i]>=0 && mark[i]<=100);

//     printf("The sum of the marks: %.2lf", sum);

//     return 0;
// }

int main(){
    int i, flag =1;
    double mark, sum=0;

    for(i=0;i<10 && flag ==1;i++){
        printf("Please enter mark for student %d: ", i+1);
        scanf("%lf", &mark);

        if(mark >= 0 && mark <=100){
            sum+=mark;
        }else{
            flag =0;
        }
}

printf("The average is %.2lf", sum);

return 0;
}

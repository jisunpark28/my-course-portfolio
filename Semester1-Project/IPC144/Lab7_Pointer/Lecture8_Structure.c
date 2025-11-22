
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include "Lecture8_Structure.h"

void getData(struct Student* st){
    printf("Enter Student ID: ");
    scanf("%d%*c", &((*st).id)); // (*st).id instead of *st.id // &((*st).id)이게 익숙해지면 &st->id 이렇게 사용가능. 같은표현
    printf("Enter Student Name: ");
    scanf("%30[^\n]%*c", (*st).name);
    printf("Enter Student Age: ");
    scanf("%d%*c", &((*st).age));
    printf("Enter Student Mark: ");
    scanf("%lf%*c", &((*st).mark));

}
void modifyData(int* idx, double* mks){
    printf("Enter New Student ID: ");
    scanf("%d%*c", &(*idx));
    printf("Enter New Student Mark: ");
    scanf("%lf%*c", &(*mks));
}
void display(struct Student sts){
    printf("ID: %d\tName: %s\tAge: %d\tMark: %.2lf\n", sts.id, sts.name, sts.age,sts.mark);  
}
int main(){
    struct Student newSt;
    getData(&newSt);
    display(newSt); //Display Initial Student Values
    modifyData(&newSt.id, &newSt.mark);
    display(newSt); //Display after Modification
    return 0;
}


// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include "studentstruct.h"

// void getData(struct Student* st) {
// 	printf("Enter ID: ");
// 	scanf("%d%*c", ______);
// 	printf("Enter Name: ");
// 	scanf("%20[^\n]%*c", ______);
// 	printf("Enter Age: ");
// 	scanf("%d%*c", ______);
// 	printf("Enter Mark: ");
// 	scanf("%lf%*c", ______);
// }
// void modifyData(int* idx, double* mks) {
// 	printf("Enter New ID: ");
// 	scanf("%d%*c", ______);
// 	printf("Enter New Mark: ");
// 	scanf("%lf%*c", ______);
// }
// void display(struct Student sts) {

// 	printf("ID: %d\tName:%s\tAge: %d\tMark:%.2lf\n", ____, ____, ____, ____);
// }

// int main() {
// 	struct Student newSt;
// 	getData(______);
// 	display(_______);//Display Initial Student values
// 	modifyData(____, , _____);
// 	display(_____)//Display after Modification


// 	return 0;
// }
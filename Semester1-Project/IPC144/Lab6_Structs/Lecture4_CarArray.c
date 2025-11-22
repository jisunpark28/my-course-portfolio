/******************************************
Structs Example

3. Modify the above program as following:

in main function
-Create and array of Cars to store 3 cars
-populate the array one car at a time using getCarInfo

Create another function called display, send the car array to dispaly 
and display all cars
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Lecture4_CarArray.h"
#define SIZE 3

int main(){

    struct Vehicle car[SIZE];
    int i;

    for(i=0; i<SIZE; i++){
        car[i] = getCarInfor();
    }

    display(car, SIZE);

    return 0;
}

void display(struct Vehicle cars[], int sz){
    int i;
    for(i = 0; i < sz; i++){
        printf("\nBrand: %s\tModel: %s\tPrice: %.2lf\tYear: %d\n", cars[i].brand, cars[i].model, cars[i].price, cars[i].year); //배열위치!!실수없길!
    }
}

struct Vehicle getCarInfor(){
    struct Vehicle veh;

    printf("\nEnter Brand:");
    scanf("%20[^\n]%*c", veh.brand); //It's a string, so no &

    printf("Enter Model:");
    scanf("%20[^\n]%*c", veh.model); //It's a string, so no &

    printf("Enter Price:");
    scanf("%lf%*c", &veh.price);

    printf("Enter Year:");
    scanf("%d%*c", &veh.year);

    return veh;
}

    

/***************************************
Struct Type Function (구조체 반환 함수)
    (장점)새로운 구조체 객체를 생성하거나 준비하여 돌려주는 것
    (장점)직관적으로 결과를 받을 수 있어 코드가 깔끔
    (단점)성능 문제, 구조체의 크기가 매우 클 경우, 구조체 전체를 복사하여 반환하는 과정에서 성능 오버헤드가 발생
    (단점)다중 반환 불가, 단 하나의 구조체만 반환할 수 있습니다. (여러 개의 데이터를 한 번에 처리하기 어려움)
ex) struct Vehicle getCarInfor()
ex) 단일 객체 처리 & 크기가 작을 때

Function with Struct Pointer (포인터를 통한 전달 함수)
    (장점)고성능/고효율: 함수에 구조체의 **주소(포인터)**만 전달하기 때문에, 구조체 크기가 아무리 커도 복사 비용이 **포인터 크기(4 또는 8바이트)**만큼만 발생하여 매우 효율적
    (장점)다중 입력/출력 가능: 여러 개의 배열 요소(cars[])나 여러 개의 포인터를 인수로 받아, 함수가 여러 변수의 값을 한 번에 수정하거나 채울 수 있음.
    (장점)배열 처리의 표준: 배열(문자열 포함)을 다룰 때는 이 포인터 전달 방식(cars[] 또는 char *)이 유일한 표준 방식
    (단점) 안전성 저하: 함수가 포인터를 통해 원본 메모리에 직접 접근하기 때문에, 함수 내부에서 실수를 하거나 버그가 발생하면 호출자의 데이터(원본)가 손상될 위험
    (단점)복잡한 호출: 호출 시 반드시 주소 연산자(&)를 사용해야 함
ex) void display(struct Vehicle cars[], int sz)
ex) 다중 객체 처리 (배열)
ex) 객체 크기가 클 때
ex) 함수 내에서 객체의 값을 수정해야 할 때
 ************************************************* */
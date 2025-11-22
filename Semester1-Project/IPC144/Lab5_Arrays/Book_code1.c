/******************************************
Array
: provides a way to store multiple instances of the same type of data
  allowing for access based around an index.
  *instance: object or process

[사용법]
: datatype arrayName[capacity];
  arrayName[index]=value;
  datatype is some data type such as int, char, double etc. This specifies what is held in each element of the array.
  arrayName is the variable name for the array.
  capacity is the number of elements reserved for the array.

index
: refers to the element.


C-string


null-terminated character string: \0
--> Buffer Overflow
원인: 문자열의 길이 정보가 데이터 자체에 포함되지 않고, 별도의 종단 문자에 의존하기 때문이다.
결과: 프로그래머가 메모리 관리를 직접 해야 하며, 작은 실수에도 치명적인 보안 문제가 발생한다.
******************************************/

//-Strings _ worst design decision ever _ null-terminated character string


char s[6]="ab";          //this is same as {'a','b','\0'};
char robot[6] = "r2d2";
char anumber[10] = "123";

printf("%s\n",s);
printf("%s\n",robot);
printf("%s\n",anumber);
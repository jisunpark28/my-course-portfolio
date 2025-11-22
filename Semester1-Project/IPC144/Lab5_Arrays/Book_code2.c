/******************************************
Structs

are used to create aggregate data type.
data type made up of multiple pieces of data
an array is an aggregate data
the data in a struct can be different types

******************************************/

struct Student{
	int studentNumber;
	double gpa;
	char name[60+1]
};

int main(void){

	//this next line creates a variable called student1
	//struct Student is the data type(like int)
	struct Student student1 ={12345,3.0,"Austin"};

	printf("Student's Name: %s\n",student1.name)

	printf("%s - %d 's gpa is %.1lf\n", student1.name,
							student1.studentNumber,student1.gpa);

}
struct Student
{
	char firstName[101];
	char lastName[101];
	int studentNumber;
	char program[5];
	float gpa;
};

void printStudent(const char* firstName, const char* lastName, int studentNumber, const char* program, float gpa);

int main(void)
{
	struct Student student1 ={ "Amy", "Lee", 123456789, "CPA", 3.7};
	printStudent(student1.firstName, student1.lastName,student1.studentNumber, student1.program, student1.gpa);
	return 0;
}

void printStudent(const char* firstName, const char* lastName, int studentNumber, const char* program, float gpa){

	printf("%s %s\n", firstName, lastName);
	printf("Student #: %d\n", studentNumber);
	printf("Program: %s\n", program);
	printf("GPA: %f\n", gpa);
}
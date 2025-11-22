struct Course{
    char cName[21];
    double mark;
};

struct Student{
    char name[31];
    int age;
    struct Course cs[31];
};

void getstudentInfor(struct Student[], int, int); 
void displayStudents(struct Student[], int, int); 
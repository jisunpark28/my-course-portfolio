/******************************************
pass by address(in getData function) / pass by value (in display function)
******************************************/
struct Student{
    int id;
    char name[21];
    int age;
    double mark;
};

void getData(struct Student*);
void modifyData(int*, double*);
void display(struct Student);
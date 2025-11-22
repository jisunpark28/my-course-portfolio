struct Employee {
    int id;
    char name[31];
    double salary;
    char phoneNo[13];
};

int loadData(const char[], struct Employee[], int);
void display(const struct Employee*);
struct Car{
    char brand[21];
    char model[21];
    char color[21];
    double price;
    double pressure[4];
    double gasAmounts[4];
};

void mainDisplay(struct Car [],int, int, int);
void displayPressure(double [], int);
void displayGasAmount(double*);
void addGas(double [], int*);
void changeProperties(struct Car*);

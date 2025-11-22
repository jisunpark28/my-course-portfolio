struct Car{
    char brand[21];             //char* barnd(single string)로 하지 않고 char brand[21](multiple character) 사용
    char model[21];
    char color[11];
    float price;
    double tirePressure[4];
    double gasAmounts[4];
};

//값 변경이 필요한 것은 *, []적용.

void mainDisplay(struct Car*, int, int);

void displayPresssures(double [], int); //subfn displayPresssures(---)

void displayGasAmount(double*); //subfn  displayGasAmount(&---)

void addGas(double [], int*);

void changeProperties(struct Car*);
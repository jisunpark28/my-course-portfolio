/******************************************
Structs Example

2. Create a new program with two files casr.h, car.c

in car.h
Declare a struct called Vehicle to store vehicle 
information (brand, model, price, year)

in car.c
Create a fuction called getCarInfor
to obtain car information, store to a struct and return that back

Create a main function to obtain car information using getCarinfo and display
******************************************/


struct Vehicle{
    char brand[21];
    char model[21];
    double price;
    int year;
};

struct Vehicle getCarInfor();
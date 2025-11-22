/******************************************
Problem 1: Movie Struct
Define a struct named Movie that stores the following information:

Title (string, maximum 100 characters)
Director (string, maximum 50 characters)
Year released (integer)
Rating (float, 0.0 to 10.0)

Write a program that:
Declares and initializes two Movie structs with information about your favorite movies
Displays the information for both movies in a formatted manner
******************************************/

#include <stdio.h>

struct Movie{
    char title[101];
    char director[101];
    int year;
    float rating;

};

int main(){
    struct Movie movie1={"Star Trek: First Contact", "Jonathan Frakes", 1996, 5.3};
    struct Movie movie2={"Turning Red", "Domee Shi", 2022, 8.7};

    printf("<%s>\n", movie1.title);
    printf("Director: %s\n", movie1.director);
    printf("Year: %d\n", movie1.year);
    printf("Rating: %.1f\n\n", movie1.rating);

    printf("<%s>\n", movie2.title);
    printf("Director: %s\n", movie2.director);
    printf("Year: %d\n", movie2.year);
    printf("Rating: %.1f\n", movie2.rating);

    return 0;
}
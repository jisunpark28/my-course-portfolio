// #include <stdio.h>
// struct Book{
//     char title[100];
//     char author[50];
//     int pages;
//     float rating
// }
// int main(void)
// {
//     //Terry Practchett wrote Guards! Guards!
//     struct Book = {'Terry Pratchett', "Guards! Guards!", 432, 4.7};
//     printf("Title: %s\n", Book.title);
//     printf("Author: %s\n", Book.author);
//     printf("Pages: %d\n", Book.pages);
//     printf("Rating: %f\n", Book.rating);
//     return 0;
// }

#include <stdio.h>
struct Book
{
    char title[100];
    char author[50];
    int pages;
    float rating;
};
int main(void)
{
    //Terry Practchett wrote Guards! Guards!
    struct Book myBook= { "Guards! Guards!","Terry Pratchett", 432, 4.7};
    printf("Title: %s\n", myBook.title);
    printf("Author: %s\n", myBook.author);
    printf("Pages: %d\n", myBook.pages);
    printf("Rating: %f\n", myBook.rating);
    return 0;
}
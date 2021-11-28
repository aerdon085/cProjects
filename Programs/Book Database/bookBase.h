#include <stdio.h>
#include <stdlib.h>

int br()
{
    // function for section breaking
    system("cls");
    printf("\n\n=====     =====     =====\n");
    return 0;
}

struct library
{
    char title[21];
    char author[21];
    int pages;
    float price;
};
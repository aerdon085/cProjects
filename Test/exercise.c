#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// signature
double calc();

int main()
{
    char firstName;
    char middleName;
    int input1;
    int input2;

    printf("First initial name of customer: ");
    scanf(" %c", &firstName);
    printf("Middle initial of customer: ");
    scanf(" %c", &middleName);
    printf("Desired number of pencils: ");
    scanf("%d", &input1);
    printf("Desired number of notebooks: ");
    scanf("%d", &input2);

    printf("%c.%c. needs %d pencils, %d notebooks, and 1 lunchbox. Total amount is %.2f.", firstName, middleName, input1, input2, calc(input1, input2));

    return 0;
}

double calc(int noPencils, int noNotes)
{
    const double pricePencils = 0.23;
    const double priceNotes = 2.89;
    const double priceLunch = 4.99;

    return (noPencils * pricePencils) + (noNotes * priceNotes) + priceLunch;
}
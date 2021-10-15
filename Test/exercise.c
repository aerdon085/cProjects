#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double num1, num2, result;
    char choice;

    do
    {
        printf("Please enter first number: ");
        scanf(" %lf", &num1);
        printf("Please enter second number: ");
        scanf(" %lf", &num2);
        printf("%f and %f is %.2f.\n", num1, num2, result = num1 + num2);
        printf("Are you done? (Y/N)\n");
        scanf(" %c", &choice);
    } while ((choice != 'Y') && (choice != 'y'));

    return 0;
}
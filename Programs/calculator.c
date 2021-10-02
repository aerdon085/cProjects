#include <stdio.h>
#include <stdlib.h>
#include <math.h>

calculate();

int main()
{
    char grade;

    printf("Enter grade: ");
    scanf(" %c", &grade);

    switch(grade)
    {
    case 'A' :
        printf("Excellent!\n");
        break;
    case 'B' :
        printf("You did great!\n");
        break;
    case 'C' :
        printf("You did alright!\n");
        break;
    default :
        printf("Invalid grade.\n");
    }

    return 0;
}

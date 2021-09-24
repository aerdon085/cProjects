#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char name[] = "Adrian"; // %s
    char grade = 'N';       // %c
    int age = 19;           // %d
    double gpa = 3.7;       // %f

    // \n makes string before it go to new line in output
    printf("%d\n", age);
    printf("%f\n", gpa);
    printf("%s\n", name);
    printf("My name is %s and I am %d\n", "Adrian", 19);

    printf("%f\n", pow(2, 3)); // always %f even if result is non-decimal; dunno why
    printf("%f\n", sqrt(36));
    printf("%f\n", ceil(gpa));
    printf("%f\n", floor(gpa));

    return 0;
}
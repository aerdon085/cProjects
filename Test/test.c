#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // SECTION
    // variables (char"", char'', int, double/float)
    char name[] = "Adrian";      // %s
    char faveLetter = 'S';       // %c
    int age = 19;                // %d
    double /*or float*/ g = 9.8; // %f

    // constant variables (const)
    const /*const mean a variable (in this case an integer) whose value cannot be reassigned*/ int BIRTHYEAR = 2002;
    char birthMonth[] = "March"; // char x[]="strings" are an exception, they inherently cannot be reassigned
    const int BIRTHDAY = 25;     // it is ideal that all constant variables are denoted by capitalized names to avoid confusion

    // \n makes string before it go to new line in output
    faveLetter = 'A';

    printf("My name is %s %s and I am %d years old.\n", name, "Luzon", age);
    printf("My favourite letter is %c.\n", faveLetter);
    printf("My birthdate is %s %d %d.\n", birthMonth, BIRTHDAY, BIRTHYEAR);

    printf("\nGravity is %f.\n", g);
    printf("My age plus year of birth is %d.\nIf result above is divided by day of birth: %f.\n", age + BIRTHYEAR, 2021 / BIRTHDAY);
    printf("%d to the power of %d is %f.\n", 2, 3, pow(2, 3)); // always %f and not %d placeholder for math functions even if result is non-decimal, dunno why
    printf("The square root of my day of birth is %f using percentF as placeholder.\nUsing percentD as placeholder: %d.\n", sqrt(BIRTHDAY), sqrt(BIRTHDAY));
    printf("Rounding up the value of g, the answer is %f. Rounding it down: %f.\n", ceil(g), floor(g));

    // SECTION
    // getting user input (scanf)

    int inputAge;
    printf("\nEnter your age: ");
    scanf("%d", &inputAge);
    printf("You are %d years old", inputAge);

    double inputDec;
    printf("\nEnter desired decimal number: ");
    scanf("%lf", &inputDec);
    printf("The desired decimal number is %f", inputDec);

    char inputOneLet;
    printf("\nPlease enter one-letter password: ");
    scanf("%c", &inputOneLet);
    printf("One letter password entered is %c", inputOneLet);

    char inputPass[20];
    printf("\nPlease enter password: ");
    scanf("%s", inputPass); // scanf, when used for strings, does not read the rest of the string separated by the first space
    printf("Your password is %s", inputPass);

    char inputName[20];
    printf("\nPlease enter password: ");
    fgets(inputName, 20, stdin); // fgets can take input string that has space but has its own set of problems
    printf("Your name is %s", inputName);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Student
{
    char name[50];
    char major[50];
    int age;
    double gpa;
};

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
    scanf(" %c", &inputOneLet);
    printf("One letter password entered is %c", inputOneLet);

    char inputPass[20];
    printf("\nPlease enter password: ");
    scanf("%s", inputPass); // scanf, when used for strings, does not read the rest of the string separated by the first space
    printf("Your password is %s", inputPass);

    char inputName[20];
    printf("\nPlease enter full name: ");
    fgets(inputName, 20, stdin); // fgets can take input string that has space but has its own set of problems
    printf("Your name is %s", inputName);

    // SECTION
    // calculator

    double num1;
    double num2;
    printf("\nThis is a calculator. Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    printf("Sum is %f", num1 + num2);

    // SECTION
    // rewriting string

    char month[] = "March";
    printf("%s\n", month);
    strcpy(month, "April");
    printf("%s\n", month);

    // SECTION
    // arrays

    char faveInitial[] = {'A', 'B', 'C'};
    printf("%c", faveInitial[0]);

    // SECTION
    // structs

    struct Student student1;
    struct Student student2;
    student1.age = 22;
    student1.gpa = 3.2;
    strcpy(student1.name, "James");
    student2.age = 25;
    student2.gpa = 4.0;
    strcpy(student2.name, "Jim");
    printf("%s is %s\'s best friend.", student2.name, student1.name);

    // SECTION
    // while loop - executes code first until false

    int index = 6;
    while (index <= 5)
    {
        printf("%d\n", index);
        index += 1;
    }

    // SECTION
    // do while - executes code first before it checks whether to execute again

    int index1 = 6;
    do
    {
        printf("%d\n", index1);
        index1++;
    } while (index1 <= 5);

    // SECTION
    // while and if...else (if)

    int inputGuess;
    int attempt = 3;
    int secretNumber = 5;

    printf("Please input guess: ");
    scanf("%d", &inputGuess);
    attempt -= 1;
    printf("Number of attempts left: %d\n", attempt);

    while (inputGuess != secretNumber && attempt != 0)
    {
        printf("%d is incorrect!\nPlease input guess: ", inputGuess);
        scanf("%d", &inputGuess);
        attempt -= 1;
        printf("Number of attempts left: %d\n", attempt);
    }

    if (inputGuess != secretNumber && attempt == 0)
    {
        printf("You lose!\n");
    }
    else if (inputGuess == secretNumber)
    {
        printf("You win!\n");
    }

    // SECTION
    // for loop

    return 0;
}
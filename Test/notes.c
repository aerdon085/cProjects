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
    scanf(" %d", &inputAge);
    printf("You are %d years old", inputAge);

    double inputDec;
    printf("\nEnter desired decimal number: ");
    scanf(" %lf", &inputDec);
    printf("The desired decimal number is %f", inputDec);

    char inputOneLet;
    printf("\nPlease enter one-letter password: ");
    scanf(" %c", &inputOneLet);
    printf("One letter password entered is %c", inputOneLet);

    char inputPass[20];
    printf("\nPlease enter password: ");
    scanf(" %s", inputPass); // scanf, when used for strings, does not read the rest of the string separated by the first space
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
    scanf(" %lf", &num1);
    printf("Enter second number: ");
    scanf(" %lf", &num2);
    printf("Sum is %f\n", num1 + num2);

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
    scanf(" %d", &inputGuess);
    attempt -= 1;
    printf("Number of attempts left: %d\n", attempt);

    while (inputGuess != secretNumber && attempt != 0)
    {
        printf("%d is incorrect!\nPlease input guess: ", inputGuess);
        scanf(" %d", &inputGuess);
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

    for (int i = 0; i <= 5; i++)
    {
        printf("%d\n", i);
    }

    // SECTION
    // #include VS #define
    /*
    #include files are lists of functions that have to be typed before main() in order for functions such as "printf()" to be read by the compiler.
    #include<> is for files that are built-in; #include"" is for files that contain functions that the programmer made or regularly uses that is found in built-in header files
    #define is for defining constants (as opposed to variables)
    when making custom header file, it must be saved with .h file extension and must be found in the same folder as the .c source code file*/

    // SECTION
    // 2d arrays and nested loops

    int nums[3][2] /*data[number of arrays inside array][number of items inside inner array]*/ = {{1, 2}, {3, 4}, {5, 6}};
    printf("%d", nums[1][0]); // [index position of array inside the array][index position of item inside inner array]
    int i, j;                 // nested loop
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d", nums[i][j]);
        }
        printf("\n");
    }

    // SECTION
    // 2d string array

    char names[2][4][20] /*[number of arrays inside array][number of strings inside inner array][string length + 1 (null zero)]*/ = {{"Adrian", "Josh", "Tasch", "Jacob"}, {"Dave", "Bob", "Harry"}};
    printf("%s\n", names[1][2]);
    strcpy(names[1][2], "Hermione");
    printf("%s\n", names[1][2]);
    printf("Second array inside of main array names only have 3 names. Please input one more: ");
    scanf(" %s", &names[1][3]);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%s", names[i][j]);
        }
    }

    // SECTION
    // scanf with %d/%d/%d (use of forward slash to gather integer data in one prompt)

    char pizzaTopping[24], ordinalPlaceD[3], ordinalPlaceM[3];
    int pizzaSlices, pizzaMonth, pizzaDay, pizzaYear;
    double pizzaCost;
    printf("How much does pizza cost in your area? Please input your answer (XX.XX): ");
    scanf(" %lf", &pizzaCost);
    printf("Your favourite one-word pizza topping?: ");
    scanf(" %s", &pizzaTopping);
    printf("How many slices of pizza?: ");
    scanf(" %d", &pizzaSlices);
    printf("Delivery date? Please input forward slashes between designated numbers (DD/MM/YYYY): ");
    scanf(" %d/%d/%d", &pizzaDay, &pizzaMonth, &pizzaYear); // forward slash crucial for functionality
    if (pizzaDay == 1)
    {
        strcpy(ordinalPlaceD, "st");
    }
    else if (pizzaDay == 2)
    {
        strcpy(ordinalPlaceD, "nd");
    }
    else if (pizzaDay == 3)
    {
        strcpy(ordinalPlaceD, "rd");
    }
    else
    {
        strcpy(ordinalPlaceD, "th");
    }
    if (pizzaMonth == 1)
    {
        strcpy(ordinalPlaceM, "st");
    }
    else if (pizzaMonth == 2)
    {
        strcpy(ordinalPlaceM, "nd");
    }
    else if (pizzaMonth == 3)
    {
        strcpy(ordinalPlaceM, "rd");
    }
    else
    {
        strcpy(ordinalPlaceM, "th");
    }
    printf("Your pizza, topped with %s and sliced into %d pieces, will arrive at the %d%s of the %d%s month in the year %d for $%.2f.\n", pizzaTopping, pizzaSlices, pizzaDay, ordinalPlaceD, pizzaMonth, ordinalPlaceM, pizzaYear, pizzaCost);

    // SECTION
    // memory address

    int add = 30, add1 = 19;
    printf("The physical memory address of var:add and add1 is at %p and %p respectively.\n", &add, &add1);

    return 0;
}
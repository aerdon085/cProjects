/* DEVELOPER'S NOTES
Program to-dos:
- Put failsafe codes in case user enters inappropriate data during prompts
- Fix string sorter mechanism on func:strMode()
- Add number randomizer for decimal
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

// function declaration
// int strMode(int n, int n0, char order);
int alphaMode(int n, char order);
int numMode(int n, char order, int special);
int decMode(int n, char order);
int arrange0(int n, int dataType, char order, char arr2[n], int arr3[n], float arr4[n]);
int terminate();

// main program
int main()
{
    int special = 0;              // for special section in main()
    char order;                   // order choice
    int typeAns, numAns, numAns0; // var for what data type and how many data respectively
    int tADone = 0;               // flag variable for valid entries of data above respectively

    // prompt if input will be alpha or num
    do
    {
        printf("What data type will your entry be?\n1. String\n2. Alphabet\n3. Integer\n4. Decimal\n5. Surprise me!\n6. Exit\n");
        scanf(" %d", &typeAns);
        if (typeAns > 0 && typeAns < 7)
        {
            if (typeAns == 6)
                terminate();
            tADone = 1;
            break;
        }
        printf("Your entry might have been invalid.\n");
    } while (tADone != 1);

    // prompt for sort order
    printf("In what order do you want the data to be displayed?\nEnter 'A' for ascending and 'D' for descending.\n");
    scanf(" %c", &order);

    // prompt the maximum number of items to be entered
    // afterwards, lead immediately to appropriate function to ask for the data to be manually entered
    printf("What maximum number of data will you enter?\nATTENTION!\nPlease enter only an integer: ");
    scanf(" %d", &numAns);

    if (typeAns == 2)
        alphaMode(numAns, order);
    else if (typeAns == 3)
        numMode(numAns, order, special);
    else if (typeAns == 4)
        decMode(numAns, order);
    else if (typeAns == 1)
    {
        printf("Please enter the maximum characters you will enter per data.\nATTENTION!\nEnter only an integer.\nTo ensure that there will be no data corruption, input your entry only after adding it by one (1).\n");
        scanf(" %d", &numAns0);
        // strMode(numAns, numAns0, order);
    }

    if (typeAns != 5)
        terminate();

    // this section is special, therefore:
    special = 1;
    numMode(numAns, order, special);

    return 0;
}

int terminate()
{
    printf("Terminating...");
    exit(0);
    return 0;
}

// SECTION: prompt modes
// for string data
/*
int strMode(int n, int n0, char order)
{
    char arr[n][n0];
    char temp[n0];

    // prompt for data
    printf("Please input %d data string(s).\n", n);
    for (int i = 0; i < n; i++)
    {
        gets(arr[i]);
    }

    // sort order
    printf("Entries received.\nSorting...\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (toupper(arr[i][0]) < toupper(arr[j][0]))
            {
                // switch
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
} */
// for letter data
int alphaMode(int n, char order)
{
    char arr[n];
    int dataType = 2;       // dataType == 2 to say data is a letter
    int empty[] = {0};      // empty
    float empty4[] = {0.0}; // empty

    // prompt for data
    printf("Please input %d data character(s).\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i]);
    }

    // sorter
    printf("Entries received.\nSorting...\n");
    arrange0(n, dataType, order, arr, empty, empty4);

    for (int i = 0; i < n; i++)
    {
        printf("%c\n", arr[i]);
    }

    return 0;
}
// for number data
int numMode(int n, char order, int special)
{
    int arr[n];
    int dataType = 3;       // dataType == 3 to say data is a number
    char empty[] = {'A'};   // empty
    float empty4[] = {0.0}; // empty

    if (special == 0)
    {
        // prompt for data
        printf("Please input %d data integer(s).\n", n);
        for (int i = 0; i < n; i++)
        {
            scanf(" %d", &arr[i]);
        }
    }
    else if (special == 1)
    {
        time_t t;
        srand(time(&t));
        for (int i = 0; i < n; i++)
        {
            arr[i] = (rand() % n) + 1;
        }
    }

    // sort order
    printf("Entries received.\nSorting...\n");
    arrange0(n, dataType, order, empty, arr, empty4);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
int decMode(int n, char order)
{
    float arr[n];
    int dataType = 4;     // dataType == 4 to say data is a number
    int empty3[] = {0};   // empty
    char empty[] = {'A'}; // empty

    // prompt for data
    printf("Please input %d data decimals(s).\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %f", &arr[i]);
    }

    // sort ascending
    printf("Entries received.\nSorting...\n");
    arrange0(n, dataType, order, empty, empty3, arr);

    for (int i = 0; i < n; i++)
    {
        printf("%.2f\n", arr[i]);
    }

    return 0;
}

// SECTION: bubble sorter
int arrange0(int n, int dataType, char order, char arr2[n], int arr3[n], float arr4[n])
{
    char temp2;
    int temp3;
    float temp4;

    switch (toupper(order))
    {
    case 'A':
        if (dataType == 2)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr2[i] < arr2[j])
                    {
                        // switch
                        temp2 = arr2[i];
                        arr2[i] = arr2[j];
                        arr2[j] = temp2;
                    }
                }
            }
        }
        else if (dataType == 3)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr3[i] < arr3[j])
                    {
                        // switch
                        temp3 = arr3[i];
                        arr3[i] = arr3[j];
                        arr3[j] = temp3;
                    }
                }
            }
        }
        else if (dataType == 4)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr4[i] < arr4[j])
                    {
                        // switch
                        temp4 = arr4[i];
                        arr4[i] = arr4[j];
                        arr4[j] = temp4;
                    }
                }
            }
        }
        break;
    case 'D':
        if (dataType == 2)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr2[i] > arr2[j])
                    {
                        // switch
                        temp2 = arr2[i];
                        arr2[i] = arr2[j];
                        arr2[j] = temp2;
                    }
                }
            }
        }
        else if (dataType == 3)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr3[i] > arr3[j])
                    {
                        // switch
                        temp3 = arr3[i];
                        arr3[i] = arr3[j];
                        arr3[j] = temp3;
                    }
                }
            }
        }
        else if (dataType == 4)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr4[i] > arr4[j])
                    {
                        // switch
                        temp4 = arr4[i];
                        arr4[i] = arr4[j];
                        arr4[j] = temp4;
                    }
                }
            }
        }
        break;
    default:
        terminate();
    }

    return 0;
}
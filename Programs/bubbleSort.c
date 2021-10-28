/* DEVELOPER'S NOTES
Program to-dos:
- Put failsafe codes in case user enters inappropriate data during prompts.
- Add ascending/descending order option for sorting.
- String sorter mechanism on func:strMode()
- Add sorter option for digits with decimals
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int strMode(int n, int n0);
int alphaMode(int n);
int numMode(int n);
int main()
{
    int didSwap = 0; // flag variable if successful
    char arrAns;
    int isAlpha = 0, isNum = 0;
    int typeAns, numAns, numAns0; // var for what data type and how many data respectively

    // prompt if input will be alpha or num
    printf("What data type will your entry be?\n1. Strings\n2. Alphabet\n3. Number\n");
    scanf(" %d", &typeAns);
    if (typeAns > 3 || typeAns < 1)
    {
        printf("Invalid input. Terminating program...\n");
        exit(0);
    }

    // prompt the maximum number of items to be entered
    // afterwards, lead immediately to appropriate function to ask for the data to be manually entered
    printf("What maximum number of data will you enter?\nATTENTION!\nPlease enter only an integer: ");
    scanf(" %d", &numAns);

    if (typeAns == 2)
        alphaMode(numAns);
    else if (typeAns == 3)
        numMode(numAns);
    else if (typeAns == 1)
    {
        printf("Please enter the maximum characters you will enter per data.\nATTENTION!\nEnter only an integer.\nTo ensure that there will be no data corruption, input your entry after adding it by one (1).\n");
        scanf(" %d", &numAns0);
        printf("%d", numAns0);
        strMode(numAns, numAns0);
    }

    return 0;
}

// prompt modes
int strMode(int n, int n0)
{
    printf("Under development UwU");
    return 0;
}
//
int alphaMode(int n)
{
    char arr[n];
    char temp;

    // prompt for data
    printf("Please input %d data character(s).\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i]);
    }

    // sort ascending
    printf("Entries received.\nSorting...\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (toupper(arr[i]) < toupper(arr[j]))
            {
                // switch
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c\n", arr[i]);
    }

    return 0;
}
//
int numMode(int n)
{
    int arr[n];
    int temp;

    // prompt for data
    printf("Please input %d data integer(s).\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &arr[i]);
    }

    // sort ascending
    printf("Entries received.\nSorting...\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                // switch
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int arrAscend(int numArr[10]);
int arrDescend(int numArr[10]);
int main()
{
    int valArr[10];
    int didSwap = 0; // flag variable if successful
    char arrAns;
    time_t t;

    srand(time(&t));

    printf("Generating random elements...\nThe elements are: ");
    // generates 10 random numbers and puts them on an array
    for (int i = 0; i < 10; i++)
    {
        valArr[i] = (rand() % 100) + 1;
        printf("%d ", valArr[i]);
    }
    printf("\b.\n");

    // prompt sorting order (ascending/descending)
    printf("How do you want your list ordered?\nPress 'A' for ascending (low to high), and 'D' for descending (high to low).\n");
    scanf(" %c", &arrAns);
    arrAns = toupper(arrAns);

    // bubble sorting algorithm
    if (arrAns == 'A')
    {
        arrAscend(valArr);
        didSwap = 1;
    }
    else if (arrAns == 'D')
    {
        arrDescend(valArr);
        didSwap = 1;
    }
    else
    {
        printf("Invalid input.\n");
    }

    if (didSwap == 1)
    {
        // prints out new order
        printf("New order: ");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", valArr[i]);
        }
        printf("\b.\n");
    }

    return 0;
}

// bubble sorting modes
int arrAscend(int numArr[10])
{
    int valHol1, valHol2; // value placeholders for switching

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // see if numArr[i], the first value in the array, is less than j
            if (numArr[i] < numArr[j])
            {
                // temporarily hold value of array elements to be swapped
                valHol1 = numArr[i];
                valHol2 = numArr[j];
                // swap values
                numArr[i] = valHol2;
                numArr[j] = valHol1;
                // by this point, numArr[i] is now greater than numArr[j]
                // continue inner loop:
                continue;
            }
        }
    }

    return 0;
}
int arrDescend(int numArr[10])
{
    int valHol1, valHol2;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (numArr[i] > numArr[j])
            {
                valHol1 = numArr[i];
                valHol2 = numArr[j];
                numArr[i] = valHol2;
                numArr[j] = valHol1;
                continue;
            }
        }
    }

    return 0;
}
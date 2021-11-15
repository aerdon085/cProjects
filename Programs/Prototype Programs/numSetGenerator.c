// The program looks for a number of random integers, allocates an array and fills it with numbers between 1 and 500 and then loops through all the numbers and figures out the smallest, the biggest, and the average.It then frees the memory.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int br() // used after a section has been completed in the program
{
    printf("\n\n=== ======== ======= ===\n\n");
    return 0;
}

int main()
{
    // SECTION: prompt for number of sets
    int setQuan; // int variable for number of sets and determines number of elements for all parallel arrays

    br();
    printf("How many sets of number-holders do you want to work with?\n");
    scanf(" %d", &setQuan);

    // SECTION: prompt for number of numbers within [i]th set
    int *setNum[setQuan];  // parallel array holding the actual numbers generated in every array[i]
    int setSize[setQuan];  // parallel array holding the number of elements for array[i]
    int setRange[setQuan]; // parallel array holding the highest possible value of array[i] from 0

    br();
    for (int i = 0; i < setQuan; i++)
    {
        printf("How many numbers do you want generated for this set? (Set %d/%d)\n", i + 1, setQuan);
        scanf(" %d", &setSize[i]);

        // allocate heap memory
        setNum[i] = (int *)malloc(setSize[i] * sizeof(int));
        if (!setNum[i])
        {
            printf("Error. Not enough memory.\n");
            exit(1);
        }
    }

    // SECTION: prompt for largest possible value for [i]th set
    br();
    for (int i = 0; i < setQuan; i++)
    {
        printf("What would be the largest possible number in set %d which will hold %d numbers?\nPlease input only positive integer/s.\n", i + 1, setSize[i]);
        scanf(" %d", &setRange[i]);
    }

    // SECTION: generate random number
    time_t t;
    srand(time(&t)); // for seeding rand()

    br();
    printf("Generating random number...\n");
    for (int i = 0; i < setQuan; i++)
    {
        for (int j = 0; j < setSize[i]; j++)
        {
            setNum[i][j] = (rand() % setRange[i]) + 1;
        }
    }

    // SECTION: prompt what to do with data
    char printRespo; // char variable for whether data sets should be printed
    char orderRespo; // char variable for the order at which data sets will be printed, if opted

    br();
    do
    {
        printf("Number generation finished!\nThe program by default only prints out the (1) highest and (2) lowest value, and (3) average of the data set.\nDo you also want to print the set of numbers? (Y/N): ");
        scanf(" %c", &printRespo);
    } while (!(isalpha(printRespo) && (toupper(printRespo) == 'Y' || toupper(printRespo) == 'N')));

    if (toupper(printRespo) == 'Y')
    {
        br();
        do
        {
            printf("In what order do you want the data numbers printed?\nEnter [A] for ascending and [D] for descending.\n");
            scanf(" %c", &orderRespo);
        } while (!(toupper(orderRespo) == 'A' || toupper(orderRespo) == 'D'));
    }

    // SECTION: if user wants a printed set of the data, order according to entry; otherwise, skip this section
    int tempSwitch;

    if (toupper(printRespo) == 'Y')
    {
        switch (toupper(orderRespo))
        {
        case 'A':
            printf("The order will be ascending.\n");
            for (int i = 0; i < setQuan; i++)
            {
                for (int j = 0; j < setSize[i]; j++)
                {
                    for (int k = 0; k < setSize[i]; k++)
                    {
                        if (setNum[i][j] < setNum[i][k])
                        {
                            tempSwitch = setNum[i][j];
                            setNum[i][j] = setNum[i][k];
                            setNum[i][k] = tempSwitch;
                        }
                    }
                }
            }
            break;
        case 'D':
            printf("The order will be descending.\n");
            for (int i = 0; i < setQuan; i++)
            {
                for (int j = 0; j < setSize[i]; j++)
                {
                    for (int k = 0; k < setSize[i]; k++)
                    {
                        if (setNum[i][j] > setNum[i][k])
                        {
                            tempSwitch = setNum[i][j];
                            setNum[i][j] = setNum[i][k];
                            setNum[i][k] = tempSwitch;
                        }
                    }
                }
            }
            break;
        default:
            printf("Error");
        }
    }

    // SECTION: find highest, lowest, and average of each data set
    int setHighest[setQuan];     // parallel array that holds highest value of array[i]
    int setLowest[setQuan];      // parallel array that holds lowest value of array[i]
    float setAverage[setQuan];   // parallel array that holds average value of array[i]
    int tempHighest, tempLowest; // temporary variables crucial for computation per set
    float total;                 // temporary variable for summation of numbers within set
    int printInOrder;            // 1 for YES and 0 for NO

    br();
    if (toupper(printRespo) == 'Y')
    {
        // for efficiency maintenance reasons, it must be made clear that it is this block of code that executes and not the other (the "other" referring to if the answer to var:printRespo is 'N')
        printf("Determining highest and lowest value...\nCalculating the average value...\n");
        printInOrder = 1;
    }
    else if (toupper(printRespo) == 'N')
    {
        // indicate execution of only this code block
        printf("Going through the data...\nDetermining highest and lowest value...\nCalculating the average value...\n");
        printInOrder = 0;
    }
    else
    {
        exit(1);
    }

    // determine highest, lowest, and average
    for (int i = 0; i < setQuan; i++)
    {
        // reset variables crucial for computation
        tempHighest = 0;
        tempLowest = setRange[i] + 1;
        total = 0.0;

        // IMPORTANT: a unique calculation process exists for when the user opts to print his data set so that the program would not have to meaninglessly iterate through an ordered data set
        if (toupper(printRespo) == 'Y' && printInOrder == 1)
        {
            // at this point, the program assumes that all data sets have been arranged accordingly
            if (toupper(orderRespo) == 'A')
            {
                // to find highest value of array[i], go to index position x where x is the array size of array[i] minus 1
                tempHighest = setNum[i][(setSize[i] - 1)];
                // to find lowest value of array[i], go to index position x where x is array size minus itself to get 0 (which is the first position of an array)
                tempLowest = setNum[i][(setSize[i] - setSize[i])];
            }
            else if (toupper(orderRespo) == 'D')
            {
                // to find highest value of array[i], go to index position x where x is array size minus itself to get 0 (which is the first position of an array)
                tempHighest = setNum[i][(setSize[i] - setSize[i])];
                // to find lowest value of array[i], go to index position x where x is the array size of array[i] minus 1
                tempLowest = setNum[i][(setSize[i] - 1)];
            }
            else
            {
                exit(1);
            }

            // as the if...else code block only applies for the determination of highest and lowest values, a separate for loop will be used for the average
            for (int j = 0; j < setSize[i]; j++)
            {
                total += (float)setNum[i][j];
            }
        }
        else if (toupper(printRespo) == 'N' && printInOrder == 0)
        {
            for (int j = 0; j < setSize[i]; j++)
            {
                if (setNum[i][j] > tempHighest)
                    tempHighest = setNum[i][j];
                if (setNum[i][j] < tempLowest)
                    tempLowest = setNum[i][j];
                total += (float)setNum[i][j];
            }
        }
        else
        {
            exit(1);
        }

        // finalize data values
        setHighest[i] = tempHighest;
        setLowest[i] = tempLowest;
        setAverage[i] = total / (float)setSize[i];
    }

    // SECTION: print
    br();
    printf("Printing results...\n");
    for (int i = 0; i < setQuan; i++)
    {
        br();
        printf("Data details for set %d:\n", i + 1);
        printf("Size: %d\nHighest value: %d\nLowest value: %d\nAverage: %.3f\n", setSize[i], setHighest[i], setLowest[i], setAverage[i]);

        // if user opted to print
        if (toupper(printRespo) == 'Y')
        {
            printf("Printing data for set %d...\n", i + 1);
            for (int j = 0; j < setSize[i]; j++)
            {
                printf("%d\n", setNum[i][j]);
            }
        }
    }

    // SECTION: program termination
    br();
    printf("Thank you for using the program!\n");
    free(setNum); // free heap memory
    printf("Terminating program...\n");

    return 0;
}
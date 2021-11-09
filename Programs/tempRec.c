#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *temps[2]; // an array of pointers that can be used to point to an array of heap memory whose size depends on var:num at the time of the iteration
    int num[2];
    // assuming there are two cities (temps[2]), prompt how much heap memory is required
    for (int i = 0; i < 2; i++)
    {
        printf("How many readings for this city?\n");
        scanf(" %d", &num[i]);
        printf("You will be entering %d data for this city.\n", num[i]);
        // allocate heap values
        temps[i] = (float *)malloc(num[i] * sizeof(float));
        // check for failure of allocation
        if (!temps[0]) /* can also be written if (temps[i] == 0) */
        {
            printf("Memory allocation failure.\n");
            exit(1);
        }
    }
    // at this point, temps[0] have x bytes allocated according to num at that point of the iteration, and temps[1] likewise
    for (int i = 0; i < 2; i++)
    {
        printf("What's the temperature of city %d?\n", i + 1);
        for (int j = 0; j < num[i]; j++)
        {
            printf("Please enter data (%d/%d): ", j + 1, num[i]);
            scanf(" %f", &temps[i][j]);
        }
    }
    for (int i = 0; i < 2; i++)
    {
        printf("These are the temperatures of city %d:\n", i + 1);
        for (int j = 0; j < num[i]; j++)
        {
            printf("%f\n", temps[i][j]);
        }
    }
    // if either temps pointer array is found to have allocated memory
    if (temps[0] != 0 || temps[1] != 0)
    {
        printf("Clearing memory...\n");
        // deallocate heap
        for (int i = 0; i < 2; i++)
        {
            free(temps[i]);
        }
    }

    return 0;
}
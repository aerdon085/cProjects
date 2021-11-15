#include <stdio.h>
#include <string.h>

int main()
{
    char nameMovie[5][21];
    int ratingMovie[5];
    int ansRating, temp;
    char tempChar[21];

    // ask for favourite movies
    printf("Please input your 5 most favourite movies:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("(%d/5) ", i + 1);
        gets(nameMovie[i]);
    }
    // ask for rating
    printf("Please rate the following movies from 1 (lowest) to 10 (highest):\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s: ", nameMovie[i]);
        scanf(" %d", &ratingMovie[i]);
    }
    // sort order
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (ratingMovie[i] > ratingMovie[j])
            {
                temp = ratingMovie[i];
                ratingMovie[i] = ratingMovie[j];
                ratingMovie[j] = temp;
                strcpy(tempChar, nameMovie[i]);
                strcpy(nameMovie[i], nameMovie[j]);
                strcpy(nameMovie[j], tempChar);
            }
        }
    }
    // print from highest to lowest rating
    for (int i = 0; i < 5; i++)
    {
        printf("%d: %s\n", ratingMovie[i], nameMovie[i]);
    }

    return 0;
}
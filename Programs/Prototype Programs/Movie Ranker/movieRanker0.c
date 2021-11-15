/* DEVELOPER'S NOTES/DEVNOTES
How does this work at all? Look at section 20211103.

Chapter 25, Section: Array of Pointers, p215-217. An explanation will be made clear soon.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char *movies[3] = {"Iron Man", "Thor", "Avengers"};
    int rating[3];
    char *movieTemp;
    int temp;

    // rate movies
    printf("Please rank the following movies from 1 (lowest) to 10 (highest):\n");
    for (int i = 0; i < 3; i++)
    {
        printf("(%d/3) %s: ", i + 1, *(movies + i));
        scanf(" %d", &rating[i]);
    }
    // rank
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (rating[i] > rating[j])
            {
                // sort ranking
                temp = rating[i];
                rating[i] = rating[j];
                rating[j] = temp;
                // sort movies since they are parallel
                // 20211103
                movieTemp = movies[i];
                movies[i] = movies[j];
                movies[j] = movieTemp;
            }
        }
    }
    // print
    for (int i = 0; i < 3; i++)
    {
        printf("%d %s.\n", rating[i], *(movies + i));
    }

    return 0;
}
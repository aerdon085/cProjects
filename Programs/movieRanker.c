#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int numMovies, rating, faveRating, notFaveRating;
    char nameMovies[30], faveMovie[30], notFaveMovie[30];
    faveRating = 6;
    notFaveRating = 5;

    do
    {
        printf("How many movies have you seen?: ");
        scanf(" %d", &numMovies);

        if (numMovies > 0)
        {
            for (int i = 1; i <= numMovies; i++)
            {
                printf("What's the title of the movie? One-word titles only! (%d/%d): ", i, numMovies);
                scanf(" %s", &nameMovies);
                printf("How would you rate the movie? ");
                scanf(" %d", &rating);
                if (rating >= 1 && rating <= 5)
                {
                    if (rating < notFaveRating)
                    {
                        strcpy(notFaveMovie, nameMovies);
                        notFaveRating = rating;
                    }
                }
                else if (rating >= 6 && rating <= 10)
                {
                    if (rating > faveRating)
                    {
                        strcpy(faveMovie, nameMovies);
                        faveRating = rating;
                    }
                }
            }
            printf("Your favourite movie is %s with a rating of %d.\n", faveMovie, faveRating);
            printf("Your least favourite movie is %s with a rating of %d.\n", notFaveMovie, notFaveRating);
        }
    } while (!(numMovies > 0));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int dice1, dice2;
    int total1, total2;
    int winLose;
    time_t t;
    char ans;
    char comparison[10];

    // the hells is this for?
    srand(time(&t));

    dice1 = (rand() % 5 + 1);
    dice2 = (rand() % 5 + 1);
    total1 = dice1 + dice2;
    printf("First roll of the dice was %d and %d for a total of %d.\n", dice1, dice2, total1);

    // keep prompting for proper answer while answer is not a letter h, l, and s
    // entering any of the allowed letter will return false that all of it is not the sought-after letter and so will exit the section
    do
    {
        puts("Do you think the next roll will be (H)igher, (L)ower, or (S)ame?");
        scanf(" %c", &ans);
        ans = toupper(ans);
    } while ((ans != 'H') && (ans != 'L') && (ans != 'S'));

    puts("Your answer has been received! And it was a...");

    dice1 = (rand() % 5) + 1;
    dice2 = (rand() % 5) + 1;
    total2 = dice1 + dice2;

    // check for which of the letters entered and check if correct
    switch (ans)
    {
    case 'H':
        if (total1 < total2)
            winLose = 1;
        break;
    case 'L':
        if (total1 > total2)
            winLose = 1;
        break;
    case 'S':
        if (total1 == total2)
            winLose = 1;
        break;
    default:
        winLose = 0;
    }
    // after returning either true or false (1 or 0 respectively), translate for player
    if (winLose == 1)
    {
        printf("Good guess! ");
    }
    else if (winLose == 0)
    {
        printf("Wrong guess, unfortunately! ");
    }
    else
    {
        puts("Looks like something went wrong.");
    }
    // explain to player his win/loss;
    if (total1 > total2)
        strcpy(comparison, "less than");
    if (total1 < total2)
        strcpy(comparison, "more than");
    if (total1 == total2)
        strcpy(comparison, "equal to");
    printf("The dice value was %d and %d which totalled to %d and is %s the first total which was %d.\n", dice1, dice2, total2, comparison, total1);

    return 0;
}
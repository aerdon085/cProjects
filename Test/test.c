#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    char color[20];
    char pluralNoun[20];
    char celebrityFN[20];
    char celebrityLN[20];

    printf("Please enter color: ");
    scanf("%s", &color);
    printf("\nPlease enter a plural noun: ");
    scanf("%s", &pluralNoun);
    printf("\nPlease enter celebrity: ");
    scanf("%s%s", &celebrityFN, &celebrityLN);

    printf("\nRoses are %s", color);
    printf("\n%s are blue", pluralNoun);
    printf("\nI love %s %s", celebrityFN, celebrityLN);
    */

    int luckyNum[] = {2, 2, 2, 2, 3, 1};
    luckyNum[0] = 33;
    printf("%d", luckyNum[0]);

    int ranNum[10];
    ranNum[0] = 1;
    printf("\n%d", ranNum[0]);

    char ranChar[] = {"Nice", "Mmm", "Yes"};
    printf("\n%s", ranChar[0]);

    return 0;
}
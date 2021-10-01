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

    // 5. reactangle
    const int h = 7;
    const int w = 5;
    int rA = h * w;
    int rP = (2 * h) + (2 * w);
    printf("The area (A) of a rectangle with a height (h) of 7 inches and width (w) of 5 inches is %d.\n", rA);
    printf("The perimeter (P) of the same rectangle is %d.\n", rP);

    // 6. circle
    // Formula for area of circle is A=(pi)r^2
    const double pi = 3.14;
    const double cP = 37.68;
    const double cA = 113.040001;
    double rSquared /*r^2=*/ = cA / pi;
    double r = sqrt(rSquared);
    printf("Radius (r) of circle when area (A) is %f\n", r);
    printf("Given that r is %f, check correctness by finding P where its answer is equal to %f\n", r, cP);
    double findP = 2 * (pi * r);
    printf("Answer is %f, and is it equal to %f?\n", findP, cP);

    return 0;
}
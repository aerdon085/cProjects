#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
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
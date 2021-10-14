#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int ctr = 0;

    printf("%d\n", ++ctr);
    printf("%d\n", ++ctr);
    printf("%d\n", ++ctr);
    printf("%d\n", ++ctr);
    printf("%d\n", ++ctr);

    printf("%d\n", --ctr);
    printf("%d\n", --ctr);
    printf("%d\n", --ctr);
    printf("%d\n", --ctr);
    printf("%d\n", --ctr);

    printf("%d\n", ctr++);
    printf("%d\n", ctr++);
    printf("%d\n", ctr++);
    printf("%d\n", ctr++);
    printf("%d\n", ctr++);

    printf("%d\n", ctr--);
    printf("%d\n", ctr--);
    printf("%d\n", ctr--);
    printf("%d\n", ctr--);
    printf("%d\n", ctr--);

    return 0;
}
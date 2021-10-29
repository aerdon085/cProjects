#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    srand(time(&t));

    for (int i = 0; i < 1000; i++)
    {
        printf("%d\n", (rand() % 20) + 1);
    }
}
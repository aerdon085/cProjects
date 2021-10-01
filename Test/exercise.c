#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function signature */
int sayHi();

int main()
{
    printf("%d", sayHi(3));

    return 0;
}

int sayHi(int num)
{
    int result = num * num * num;

    return result;
}

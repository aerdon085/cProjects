#include <stdio.h>
#include <stdlib.h>

int main()
{
    char oneLet;
    printf("Please enter one-letter password: ");
    scanf("%c", &oneLet);
    printf("One letter password entered is %c", oneLet);

    return 0;
}
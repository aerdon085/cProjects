#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function signature */
int sayHi();

int main()
{
    printf("%d", sayHi(3,4));

    return 0;
}

int sayHi(int num1, int num2)
{
    int result;
    if(num1 > num2){
        result = num1;
    } else {
        result = num2;}

    return result;
}

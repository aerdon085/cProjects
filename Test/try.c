#include <stdio.h>
#include <stdlib.h>

int compare();

int main()
{
    const char message[] = "The greatest number is: ";

    printf("%s %d\n", message, compare(5, 9, 1));

    if (compare(1, 1, 1) == 2) {
        printf("It is equal!\n");
    } else if (!(compare(1, 1, 1) != 1)) {
        printf("It is not equal because of the negator!");
    }

    return 0;
}

int compare(int num1, int num2, int num3)
{
    int result;

    if (num1 >= num2 && num1 >= num3) {
        result = num1;
    } else if (num2 >= num1 && num2 >= num3) {
        result = num2;
    } else {
        result = num3;
    }

    return result;
}

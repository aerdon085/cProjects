// this program prints into a new file the letters array and then prints it out backwards

#include <stdio.h>
#include <stdlib.h>
FILE *fptr;

int main()
{
    char letters[5] = {'A', 'B', 'C', 'D', 'E'};

    fptr = fopen("rAF.txt", "w+");
    if (fptr == 0)
    {
        printf("An error has occurred.\n");
        exit(1);
    }
    for (int i = 0; i < 5; i++)
    {
        fputc(letters[i], fptr);
    }

    char letter;
    printf("Reading the letters backward...\n");
    fseek(fptr, -1, SEEK_END);
    for (int i = 5; i > 0; i--)
    {
        letter = fgetc(fptr);
        fseek(fptr, -2, SEEK_CUR);
        printf("%c", letter);
    }
    fclose(fptr);

    return 0;
}
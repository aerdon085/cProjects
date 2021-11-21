#include <stdio.h>
#include <stdlib.h>
FILE *fptr;

int main()
{
    char letters[5] = {'A', 'B', 'C', 'D', 'E'};

    fptr = fopen("rAF2.txt", "w+");
    if (fptr == 0)
    {
        printf("An error has occurred.\n");
        exit(1);
    }
    for (int i = 0; i < 5; i++)
    {
        fprintf(fptr, "%c\n", letters[i]);
    }

    char letter;
    printf("Reading the letters backward...\n");
    fseek(fptr, 0, SEEK_SET);
    for (int i = 0; i < 5; i++)
    {
        letter = fgetc(fptr);
        fseek(fptr, +2, SEEK_CUR);
        printf("%c", letter);
    }
    fclose(fptr);

    return 0;
}
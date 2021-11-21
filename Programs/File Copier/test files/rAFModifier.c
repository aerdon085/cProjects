// this program accesses a rAF.txt file and modifies a leter as indicated for var:pos

#include <stdio.h>
#include <stdlib.h>
FILE *fptr;

int main()
{
    int pos;
    scanf(" %d", &pos);

    fptr = fopen("rAF.txt", "r+");
    if (fptr == 0)
    {
        exit(1);
    }
    fseek(fptr, pos - 1, SEEK_SET);
    fputc('*', fptr);

    char letter;
    fseek(fptr, 0, SEEK_SET);
    for (int i = 0; i < 5; i++)
    {
        letter = fgetc(fptr);
        fseek(fptr, 0, SEEK_CUR);
        printf("%c", letter);
    }
    fclose(fptr);

    return 0;
}
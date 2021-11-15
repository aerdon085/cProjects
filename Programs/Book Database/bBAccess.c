#include <stdio.h>
#include <stdlib.h>
FILE *fptr;

int main()
{
    char fileLine[100];
    fptr = fopen("bookBase.txt", "r");

    // if fopen() did not return an error
    if (fptr != 0)
    {
        // feof() returns a true condition if we have just reached the end of the file
        // while we haven't reached the end of file:
        while (!feof(fptr))
        {
            fgets(fileLine, 100, fptr);
            if (!feof(fptr))
            {
                printf("%s", fileLine);
            }
        }
    }
    else
    {
        printf("Error opening file.\n");
    }
    fclose(fptr);

    return 0;
}
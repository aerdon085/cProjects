#include <stdio.h>
#include <stdlib.h>
FILE *fptr;
FILE *cfile;

void br()
{
    system("cls");
    printf("===== FILE COPIER =====\n\n");
}

int main()
{
    br();
    // prompt for filename that wants to be accessed
    int fileNameLength;
    printf("Please indicate how long the filename you want accessed is per character, including the extension and its symbols.\n(NOTE: For storage and memory efficiency, you are required to increase your value to be entered by at least one. E.g. filename.txt is equal to 12 characters plus 1 will be 13 characters in total.)\n");
    scanf(" %d", &fileNameLength);
    getchar();
    br();
    char fileName[fileNameLength];
    printf("Please input the name of the filename, complete with its extension, you want accessed.\n(NOTE: This program is case-sensitive.)\n");
    gets(fileName);

    // open the indicated file
    char string[100];
    fptr = fopen(fileName, "r");
    if (fptr == 0)
    {
        br();
        printf("An error has occurred.\nTerminating program...\n");
        exit(1);
    }

    br();
    // prompt for new filename of copied file
    int newFileNameLength;
    printf("Please indicate how long your new destination file's filename will be per character, including the extension and symbols.\n(NOTE: For storage and memory efficiency, you are required to increase your value to be entered by at least one. E.g. filename.txt is equal to 12 characters plus 1 will be 13 characters in total.)\n");
    scanf(" %d", &newFileNameLength);
    getchar();
    br();
    char newFileName[newFileNameLength];
    printf("Please input the new name of the destination file, complete with its extension.\n");
    gets(newFileName);

    cfile = fopen(newFileName, "w+");
    while (!feof(fptr))
    {
        fgets(string, 100, fptr);
        fprintf(cfile, "%s", string);
    }
    br();
    printf("File copy successful.\nTerminating program...\n");
    fclose(fptr);
    fclose(cfile);

    return 0;
}
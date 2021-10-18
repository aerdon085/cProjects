#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;

    printf("Welcome!\n1. Add New Contact\n2. Edit Existing Contact\n3. Call Contact\n4. Text Contact\n5. Exit\n");

    do
    {
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printf("You are adding a contact...\n");
        case 2:
            printf("You are editing an existing contact...\n");
        case 3:
            printf("Calling contact...\n");
        case 4:
            printf("Texting contact...\n");
        case 5:
            exit(1);
        default:
            printf("%d is not a valid selection.\n", choice);
        }
    } while ((choice < 1) || (choice > 5));

    return 0;
}
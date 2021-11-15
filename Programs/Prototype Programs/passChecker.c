// make a password strength checker

#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main()
{
    int passCount, hasDigit = 0, hasUpper = 0, hasLower = 0, okayPass;
    char password[25];

    // start the loop asking for input; every iteration is every letter added to its respective index inside the array
    printf("Please enter password: ");
    for (int i = 0; i < 25; i++)
    {
        password[i] = getchar();
        // if password letter in index position i contains \n, break out of loop and proceed to password composition analysis
        if (password[i] == '\n')
        {
            passCount = i;
            break;
        }
    }
    printf("Your password is ");
    for (int i = 0; i < passCount; i++)
    {
        // check if there are enough characters
        putchar(password[i]);
        if (passCount >= 8)
        {
            okayPass = 1;
        }
        if (isdigit(password[i]))
        {
            hasDigit = 1;
            continue;
        }
        else if (isupper(password[i]))
        {
            hasUpper = 1;
            continue;
        }
        else if (islower(password[i]))
        {
            hasLower = 1;
            continue;
        }
    }
    printf(".\n");

    if (okayPass == 1 && hasDigit == 1 && hasUpper == 1 && hasLower == 1)
    {
        printf("Your password is strong enough!\n");
    }
    else
    {
        printf("Error code: %d%d%d%d.\n", okayPass, hasDigit, hasUpper, hasLower);
        if (!okayPass)
            printf("You need at least 8 characters.\n");
        if (!hasDigit)
            printf("Please add at least one digit to your password.\n");
        if (!hasUpper)
            printf("Please add at least one upper-case letter to your password.\n");
        if (!hasLower)
            printf("Please add at least one digit to your password.\n");
    }

    return 0;
}
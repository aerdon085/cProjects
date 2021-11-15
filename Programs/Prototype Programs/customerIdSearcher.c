#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // parallel array
    int custId[10] = {313, 453, 502, 101, 892, 475, 792, 912, 343, 633};
    float custBal[10] = {0.00, 45.43, 71.23, 301.56, 9.08, 192.41, 389.00, 229.67, 18.31, 59.54};
    int tempInt;      // for temporary integer placeholder
    float tempFloat;  // for temp decimal placeholder
    int highId = 0;   // placeholder for highest value in array
    int lowId = 1000; // for lowest value in array
    float avg;        // placeholder for middle value of array

    int entry;            // custId as entered by user
    int entryResult = -1; // number in array when found, default is user not found

    /* sort array in an ordinal manner
    NOTE: After the switch, for some unexpected reason tho working, the datas in the array will be in a descending order with highest value in index position 0 and lowest in index position 9
    */
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (custId[i] > custId[j])
            {
                // switch id
                tempInt = custId[i];
                custId[i] = custId[j];
                custId[j] = tempInt;
                // switch balance
                tempFloat = custBal[i];
                custBal[i] = custBal[j];
                custBal[j] = tempFloat;
                // assign highest and lowest values
                // because, by this section, i will contain the lowest value and contrary for j, assign appropriately
                if (custId[i] < lowId)
                    lowId = custId[i]; // if i is less than lowId...
                if (custId[j] > highId)
                    highId = custId[j]; // if j is greater than highId...
            }
        }
    }

    // determine mean of array
    avg = ((float)highId + (float)lowId) / 2.0;

    // prompt customer id entry
    printf("Please input your ID: ");
    scanf(" %d", &entry);

    // determine which end of the array the entered id is closer to and search from there either ascending or desc appropriately using var:avg
    if ((float)entry > avg)
    {
        // if entry is greater than avg, start from the end of the array that contain the largest value, descending
        for (int i = 0; i < 10; i++)
        {
            if (entry == custId[i])
            {
                entryResult = i;
                break;
            }
            else if (entry > custId[i]) // if compared array data is less than entry, exit
            {
                break;
            }
            printf("Checking data (%d/10)\n", i + 1);
        }
    }
    else if ((float)entry <= avg)
    {
        // if entry is less than or equal to avg, search array in the ascending order from the end of the array that contain the lowest value
        for (int i = 9; i > -1; i--)
        {
            if (entry == custId[i])
            {
                entryResult = i;
                break;
            }
            else if (entry < custId[i]) // if compared array data now becomes larger than entry, exit
            {
                break;
            }
            printf("Checking data (%d/10)\n", i + 1);
        }
    }

    // print result
    if (entryResult >= 0 && entryResult < 10)
        printf("Welcome user %d! Your balance is %.2f.\n", custId[entryResult], custBal[entryResult]);
    else
        printf("User not found.\n");

    return 0;
}
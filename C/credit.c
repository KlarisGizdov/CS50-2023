#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user for card number
    long long ccnumber;
    do
    {
        ccnumber = get_long_long("Enter card number: ");
    }
    while (ccnumber < 0); //Card number has to be > 0

    int sum1 = 0, sum2 = 0, length = 0;
    long long ccnumber_copy = ccnumber; // Create a copy of ccnumber to check the length later
    while (ccnumber > 0)
    {
        //Get last digit
        int digit = ccnumber % 10;

        //Sum every other digit starting from second to last
        if (length % 2 == 1)
        {
            int doubled = digit * 2;
            sum1 += doubled / 10 + doubled % 10;
        }
        //Sum remaining digits
        else
        {
            sum2 += digit;
        }

        //Update variables/repeat
        ccnumber /= 10;
        length++;
    }

    //Find out the card brand
    if ((sum1 + sum2) % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (length == 15 && (ccnumber_copy / 10000000000000 == 34 || ccnumber_copy / 10000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (ccnumber_copy / 100000000000000 >= 51 && ccnumber_copy / 100000000000000 <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && ccnumber_copy / 1000000000000 == 4)
    {
        printf("VISA\n");
    }
    else if (length == 16 && ccnumber_copy / 1000000000000000 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

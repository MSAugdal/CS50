#include <cs50.h>
#include <stdio.h>
#include <math.h>


int getLengthOfInt(long num);
bool checkCard(long cardNum);
int getFirstDigit(long input);

int main(void) 
{
    long input = get_long("Insert number: ");
    int lengthOfInput = getLengthOfInt(input);
    int firstDigit = getFirstDigit(input);

    // American Express
    if (lengthOfInput == 15 && firstDigit == 3)
    {
        if (checkCard(input) == true)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //  Visa
    else if (lengthOfInput == 13 && firstDigit == 4 || lengthOfInput == 16 && firstDigit == 4)
    {
        if (checkCard(input) == true)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // MasterCard
    else if (lengthOfInput == 16 && firstDigit == 5)
    {
        if (checkCard(input) == true)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int getLengthOfInt(long num)
{
    int length = log10(num) + 1;
    return length;
}

int getFirstDigit(long input)
{
    if (input < 10) return input;
    return getFirstDigit(input/10);
}

bool checkCard(long cardNum)
{
    // chop off last digit
    long cardNumCopy = cardNum / 10;
    int product1 = 0;
    int product2 = 0;
    int lengthOfNum = getLengthOfInt(cardNumCopy);
    // checks every other number
    while (lengthOfNum > 2)
    {
        product1 += cardNumCopy % 10 * 2;
        cardNumCopy /= 100;
    }
    while (lengthOfNum > 2)
    {
        product2 += cardNum % 10 * 2;
        cardNum /= 100;
    }

    if ((product1 + product2) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

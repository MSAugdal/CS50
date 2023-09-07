#include <cs50.h>
#include <stdio.h>
#include <math.h>

int getLengthOfLong(long num);
int getFirstTwoDigits(long input);
bool getAndCheckChecksum(long cardNum, int product, int lastDigit);

int main(void) 
{
    long input = get_long("Insert number: ");
    int lengthOfInput = getLengthOfLong(input);
    int firstDigit = getFirstTwoDigits(input);

    // American Express
    if (lengthOfInput == 15 && firstDigit == 34 || lengthOfInput == 15 && firstDigit == 37) //Filters input to check initial validity
    {
        if (getAndCheckChecksum(input / 10, 0, input % 10) == 
            true)  //divides input with 10 to remove last digit, and input % 10 to get last digit
        {
            printf("AMEX\n");
        }
        else
        {
            printf("amex INVALID\n");
        }
    }

    //  Visa
    else if (lengthOfInput == 13 && firstDigit / 10 == 4 || 
             lengthOfInput == 16 && firstDigit / 10 == 4)    //Filters input to check initial validity
    {
        if (getAndCheckChecksum(input / 10, 0, input % 10) == 
            true) //divides input with 10 to remove last digit, and input % 10 to get last digit
        {
            printf("VISA\n");
        }
        else
        {
            printf("visa INVALID\n");
        }
    }

    // MasterCard
    else if (lengthOfInput == 16 && firstDigit >= 51 && firstDigit <= 55)   //Filters input to check initial validity
    {
        if (getAndCheckChecksum(input / 10, 0, input % 10) == true) //input / 10 to remove last digit, input % 10 to get last digit
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("master INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int getLengthOfLong(long num)    //Gets length of inputed long for initial filtering. recursive
{
    int length = floor(log10(num)) + 1;
    return length;
}

int getFirstTwoDigits(long input)   //Gets the first two digits of the cardNum for initial filtering. recusive
{
    if (input < 100) 
    {
        return input;
    }
    return getFirstTwoDigits(input / 10);
}

bool getAndCheckChecksum(long cardNum, int product, int lastDigit)
{
    if (cardNum < 10)                                        //if true, the loop is on the last digit
    {
        if (cardNum % 10 * 2 >= 10)                          //Splits number into 2 if its over 9 and adds the digits to product1
        {
            int chop = cardNum % 10 * 2;
            product += chop % 10;
            chop /= 10;
            product += chop;
            cardNum /= 10;
        }
        else                                                //Adds number as normal if not over 9
        {
            product += cardNum * 2;
        }
        if ((product + lastDigit) % 10 == 0)                //Adds everything together, and checks if the checksum is valid
        {
            return true;
        }
        return false;
    }

    if (cardNum % 10 * 2 >= 10)                             //Splits number into 2 if its over 9 and adds the digits to product1
    {
        int chop = cardNum % 10 * 2;
        product += chop % 10;
        chop /= 10;
        product += chop;
        cardNum /= 10;
    }
    else                                                    //If number is 9 or under, modulo 10, *2 and add to product1
    {
        product += cardNum % 10 * 2;
        cardNum /= 10;
    }
    
    if (cardNum < 10)
    {
        product += cardNum % 10;
        cardNum /= 10;
        return getAndCheckChecksum(cardNum, product, lastDigit);
    }
    else
    {
        product += cardNum % 10;
        cardNum /= 10;
        return getAndCheckChecksum(cardNum, product, lastDigit);
    }
}
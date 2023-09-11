#include <cs50.h>
#include <stdio.h>

int getNumOfRows(void);
void printPyramids(int rows);

int main(void) 
{
    // take input: only allow 1 - 8, including 8
    int numOfRows = getNumOfRows();
    // print the pyramids
    printPyramids(numOfRows);
}

int getNumOfRows(void)
{
    int rows;
    do
    {
        rows = get_int("Enter num of rows: ");
    }
    while (rows < 1 || rows > 9);
    return rows;
}

void printPyramids(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        // prints first pyramid
        int spaces = rows - i;
        int hashes = i;
        for (int j = 1; j <= spaces; j++)
        {
            printf(" ");
        }
        for (int l = 1; l <= hashes; l++)
        {
            printf("#");
        }

        // prints space between pyramids
        printf("  ");

        // prints pyramid 2, same as 1 but reverse
        int hashes2 = rows - i;
        int spaces2 = i;
        for (int j = 1; j <= hashes; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
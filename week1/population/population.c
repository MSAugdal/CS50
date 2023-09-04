#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);
    
    // TODO: Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);
    
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    for (int i = startSize; i < endSize; i = i - (i / 4) + (i / 3))
    {
        years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}

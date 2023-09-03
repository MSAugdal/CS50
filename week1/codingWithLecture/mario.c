#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int get_size(void);
void print_grid(int size);

int main(void)
{
    // Get size of grid
    int bricksPerside = get_size();

    // Print the grid of bricks
    print_grid(bricksPerside);
}

int get_size(void)
{
    int bricksPerSide;
    do
    {
        bricksPerSide = get_int("Bricks per side: ");
    } while (bricksPerSide < 1);
    return bricksPerSide;
}

void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }

    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }

    while (true)
    {
        printf("meow\n");
    }
}
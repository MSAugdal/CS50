#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // asks user for name and says hello to them
    string name = get_string("What is your name: ");
    printf("Hello, %s!\n", name);
}
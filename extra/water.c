#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for input of minutes showering
    int minutes = get_int("minutes: ");

    // Calculate number of bottles and print result
    printf("bottles: %i\n", minutes * 12);
}

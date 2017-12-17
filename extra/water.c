#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for input
    int minutes = get_int("minutes: ");

    // Calculate number of bottles and print result
    printf("bottles: %i\n", minutes * 12);
}

#include <cs50.h>
#include <stdio.h>

int main (void)
{
    // Get input and convert it to cents
    int debt = get_double("O hai! How much change is owed?\n") * 100;

    int coins = 0;

    // Only coins are .25 .1 .05 .01
    while (debt > 0)
    {
        if (debt >= 25)
        {
            // Reduce the debt by that amount
            debt -= 25;
        }
        else if (debt >= 10)
        {
            debt -= 10;
        }
        else if (debt >= 5)
        {
            debt -= 5;
        }
        else if (debt >= 1)
        {
            debt -= 1;
        }
        // Add one coin
        coins++;
    }

    // Print final result
    printf("%i\n", coins);
}

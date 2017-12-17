#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for input
    int apples = get_int("How many apples do you have? ");
    
    // Print output
    printf("Mwahahaha. I ate one of your apples!\nYou now have %i apples!\n", apples - 1);
}

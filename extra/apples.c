#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int apples = get_int("How many apples do you have? ");
    printf("Mwahahaha. I ate one of your apples!\nYou now have %i apples!\n", apples - 1);
}

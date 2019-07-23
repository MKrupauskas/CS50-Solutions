#include <stdio.h>
#include <cs50.h>

int main (void)
{
    char c = get_char();

    printf("%c - original, %c - capitalised\n", c, c - 32);
}

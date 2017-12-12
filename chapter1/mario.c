#include <stdio.h>
#include <cs50.h>

void print_symbols(int count, bool is_hash)
{
    // Print Symbols
    for (int i = 0; i < count; i++)
    {
        is_hash ? printf("#") : printf(" ");
    }
}

int main(void)
{
    int height = 0;

    do
    {
        height = get_int("Height: ");
    } while (height < 0 || height > 23);

    int hashes = 1, spaces = height - 1;

    for (int i = 0; i < height; i++)
    {
        // Left align and draw the first half
        print_symbols(spaces, false);
        print_symbols(hashes, true);

        printf("  ");
        print_symbols(hashes, true);
        printf("\n");

        // Hashes increase going down the pyramid
        hashes++;
        // Spaces decrease going down the pyramid
        spaces--;
    }
}

#include <stdio.h>
#include <cs50.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Incorrect argument count");
        return 1;
    }

    char *key = argv[1];
    char *plaintext = get_string("plaintext: ");

    printf(plaintext);
}

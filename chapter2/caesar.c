#include <stdio.h>
#include <cs50.h>

int string_length(char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++);
    return i;
}

void encrypt(char character, bool is_upper, int key)
{
    // The 97 and 65 are for going to and from the alphabetical enumeration
    printf("%c", (((character + key) - (is_upper ? 97 : 65)) % 26) + (is_upper ? 97 : 65));
}

int main(int argc, char **argv)
{
    // There must be two arguments
    if (argc != 2)
    {
        printf("No key provided");
        return 1;
    }

    // Get the key, turn it into an int
    int key = atoi(argv[1]);
    // Get plaintext
    char *plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, l = string_length(plaintext); i < l; i++)
    {
        // Check if the char is in the alphabet
        if ((plaintext[i] >= 'a' && plaintext[i] <= 'z') || (plaintext[i] >= 'A' && plaintext[i] <= 'Z'))
        {
            encrypt(plaintext[i], (plaintext[i] >= 'a' && plaintext[i] <= 'z'), key);
        }
        // If character is not alphabetic
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

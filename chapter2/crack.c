#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main (int argc, char **argv)
{
    // Verify user input
    if (argc != 2)
    {
        printf("You must provide a hash");
        return 1;
    }

    // Extract salt from given hash
    char salt[3];
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];
    salt[2] = '\0';

    // Store full alphabet of chars for easy iteration
    char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", *hash, password[5];

    // Prepare full string for iteration
    for (int i = 0; i < 4; i++)
    {
        password[i] = '\0';
    }

    // Brute force the hash for every existing combination
    for (int size = 0; size < 4; size++)
    {
        for (long long i = 0; i < pow(52, size + 1); i++)
        {
            password[0] = chars[i % 52];

            if (size >= 1)
            {
                password[1] = chars[(i / 52) % 52];
            }
            if (size >= 2)
            {
                password[2] = chars[(i / (int) pow(52, 2) ) % 52];
            }
            if (size >= 3)
            {
                password[3] = chars[(i / (int) pow(52, 3) ) % 52];
            }

            hash = crypt(password, salt);

            // If hashes match, print password
            if (strcmp(argv[1], hash) == 0)
            {
                printf("%s %s %s\n", password, argv[1], hash);
                return 0;
            }
        }
    }
}

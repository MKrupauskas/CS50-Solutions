#include <stdio.h>
#include <cs50.h>
#define _XOPEN_SOURCE
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("You must provide a hash");
        return 1;
    }

    char salt[3];
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];
    salt[2] = '\0'

        char pass[4];
    char *characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            pass[0] = characters[j];
        }

        if (i >= 1)
        {
            for (int j = 0; j < 52; j++)
            {
                pass[1] = characters[j];
            }
        }

        if (crypt(pass, salt) == hash)
            printf("Your pass is &c", pass);
    }
}

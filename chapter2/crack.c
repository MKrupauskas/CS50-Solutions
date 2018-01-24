#include <stdio.h>
#include <cs50.h>

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
    salt[2] = '\0';

    char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", *hash;
    char password[5];

    //testing for 1 chars words.
    for (int i = 0; i < 52; i++)
    {
        password[0] = chars[i];
        password[1] = '\0';

        hash = crypt(password, salt);
        if (strcmp(argv[1], hash) == 0)
        {
            printf("%s %s %s\n", password, argv[1], hash);
            return 0;
        }
    }

    for (int j = 0; j < 52; j++)
    {
        for (int k = 0; k < 52; k++)
        {
            password[0] = chars[j];
            password[1] = chars[k];
            password[2] = '\0';

            hash = crypt(password, salt);
            if (strcmp(argv[1], hash) == 0)
            {
                printf("%s %s %s\n", password, argv[1], hash);
                return 0;
            }
        }
    }

    for (int o = 0; o < 52; o++)
    {
        for (int p = 0; p < 52; p++)
        {
            for (int q = 0; q < 52; q++)
            {
                password[0] = chars[o];
                password[1] = chars[p];
                password[2] = chars[q];
                password[3] = '\0';

                hash = crypt(password, salt);
                if (strcmp(argv[1], hash) == 0)
                {
                    printf("%s %s %s\n", password, argv[1], hash);
                    return 0;
                }
            }
        }
    }

    for (int o = 0; o < 52; o++)
    {
        for (int p = 0; p < 52; p++)
        {
            for (int q = 0; q < 52; q++)
            {
                for (int r = 0; r < 52; r++)
                {
                    password[0] = chars[o];
                    password[1] = chars[p];
                    password[2] = chars[q];
                    password[3] = chars[r];
                    password[4] = '\0';

                    hash = crypt(password, salt);
                    if (strcmp(argv[1], hash) == 0)
                    {
                        printf("%s %s %s\n", password, argv[1], hash);
                        return 0;
                    }
                }
            }
        }
    }
}

int abc(char *s, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '\0')
        {
            s[i] = 'A';
            break;
        }
        if (s[i] == 'Z')
        {
            s[i] = 'a';
            break;
        }
        if (s[i] == 'z')
        {
            if (i == size - 1)
            {
                return 0;
            }
            s[i] = 'A';
        }
        else
        {
            s[i]++;
            break;
        }
    }
    return 1;
}
char *s = "aa";
printf(abc(s, 1));

for (int i = 0; i < 4; i++)
{
    for ()
        if (i >= 0)
        {
        }
}

for (int i = 0; i < 4; i++)
    password[i] = '\0';

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
            password[2] = chars[(i / (int)pow(52, 2)) % 52];
        }
        if (size >= 3)
        {
            password[3] = chars[(i / (int)pow(52, 3)) % 52];
        }

        hash = crypt(password, salt);
        // printf("%s %s %s\n", password, argv[1], hash);
        if (strcmp(argv[1], hash) == 0)
        // if (true)
        {
            printf("%s %s %s\n", password, argv[1], hash);
            return 0;
        }
    }
}
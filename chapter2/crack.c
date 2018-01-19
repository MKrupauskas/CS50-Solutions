#include <stdio.h>
#include <cs50.h>

int main (int argc, char **argv)
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

    char pass[5];
    pass[0] = '\0';
    pass[1] = '\0';
    pass[2] = '\0';
    pass[3] = '\0';
    pass[4] = '\0';

    char *characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 52; j++)
    //     {
    //         pass[0] = characters[j];
    //         if (i >= 1)
    //         {
    //             for (int k = 0; k < 52; k++)
    //             {
    //                 pass[1] = characters[k];

    //                 if (i >= 2)
    //                 {
    //                     for (int l = 0; l < 52; l++)
    //                     {
    //                         pass[2] = characters[l];
    //                         if (i >= 3)
    //                         {
    //                             for (int p = 0; p < 52; p++)
    //                             {
    //                                 pass[3] = characters[p];
    //                                 printf("%s\n", pass);
    //                             }
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

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
}
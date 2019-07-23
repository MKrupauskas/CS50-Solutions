
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

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
    int len = 1;
    char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char pass[len];

    int i;
    for(i = 0; i <= len; i++) pass[i] = ;

    do {
        for(i = 0; i <= len ; i++) putchar(chars[(int) pass[i]]);
        putchar('\n');
        for(i = 0; i <= len && ++pass[i] == len; i++) pass[i] = 0;
    } while(i < len);

}
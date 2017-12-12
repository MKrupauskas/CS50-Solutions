#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    string name = get_string();

    // Print first character if its not a space
    if (name[0] != ' ')
    {
        printf("%c", toupper(name[0]));
    }

    for (int i = 0; i < strlen(name); i++)
    {
        // Iterate through the whole string and check for spaces
        if (name[i] == ' ' && name[i + 1] != '\0' && name[i + 1] != ' ')
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    // Print new line at the end
    printf("\n");
}

void short_solution (int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Missing arguments");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        printf("%c", toupper(argv[i][0]));
    }
    printf("\n");
}

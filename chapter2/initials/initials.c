#include <stdio.h>
#include <cs50.h>

char toupper(char character)
{
    if (character > 96 && character < 123)
    {
        // Lowercase characters get converted to uppercase
        return character - 32;
    }
    return character;
}

int string_length(char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++)
        ;
    return i;
}

int main(void)
{
    char *name = get_string();

    // Print first character if its not a space
    if (name[0] != ' ')
    {
        printf("%c", toupper(name[0]));
    }

    for (int i = 0; i < string_length(name); i++)
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

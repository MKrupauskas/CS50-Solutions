// Hello World program

#include<stdio.h>
#include<cs50.h>

bool agree(char c)
{
    return (c == 'Y' || c == 'y');
}

int main(void)
{
    printf("Do you agree? (y/n)\n");
    char c = get_char();

    if(agree(c))
    {
        printf("Yeah\n");
    }
    else
    {
        printf("Nope\n");
    }
}

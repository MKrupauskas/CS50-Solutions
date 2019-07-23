bar// Hello World program

#include<stdio.h>
#include<cs50.h>

int main(void)
{
    printf("Whats your name?\n");
    string name = get_string();

    printf("Whats your age?\n");
    int age = get_int();

    printf("Say a number?\n");
    long long number = get_int();

    int count = 1;

    while(number > 0)
    {
        printf("Hello %s! Your are %d\n", name, age);
        printf("%i mississippi\n", count);
        number--;
        count++;
    }

    if(age < 18)
    {
        printf("Get 'outta 'ere young man\n");
    }
    else
    {
        printf("Come in\n");
    }
}

// struct get_user()
// {
//     printf("Whats your name? \n");
//     string name = get_string();
//     printf("Whats your age? \n");
//     int age = get_int();
// }
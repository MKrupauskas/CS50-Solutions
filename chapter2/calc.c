#include <stdio.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    // Define argument range
    if (argc < 2 || argc > 4)
    {
        printf("Incorrectly entered arguments");
        return 1;
    }

    // Get first and second numbers as floats a and b
    float a = atof(argv[1]), b = atof(argv[3]);
    // Get the math operator
    char operation = argv[2][0];

    // Compare and print answer
    switch (operation)
    {
    case '+':
        printf("%f\n", a + b);
        break;
    case '-':
        printf("%f\n", a - b);
        break;
    case 'x':
        printf("%f\n", a * b);
        break;
    case '/':
        printf("%f\n", a / b);
        break;
    case '%':
        printf("%f\n", a - (b * (int)(a / b)));
        break;
    default:
        return 1;
    }
}

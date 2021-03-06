#include <stdio.h>
#include <cs50.h>

bool verify_card (long long number)
{
    int doubled_digits, verification_number = 0;

    while (number > 0)
    {
        // Add every digit to sum that isn't doubled
        verification_number += number % 10;
        number /= 10;
        // Multiply every other digit by two and add digits
        verification_number += ((number % 10) * 2) % 10 + ((number % 10) * 2) / 10;
        number /= 10;
    }

    // verification number must end with 0
    return (verification_number % 10 == 0);
}

void print_card_type (long long number)
{
    // Go down to the first 2 digits
    while (number > 100)
    {
        number /= 10;
    }

    // AMEX start with 34, 37
    if (number == 34 || number == 37)
    {
        printf("AMEX\n");
    }
    // MASTERCARD starts with 51, 52, 53, 54, 55
    else if (number >= 51 && number <= 55)
    {
        printf("MASTERCARD\n");
    }
    // VISA starts with 4
    else if (number / 10 == 4)
    {
        printf("VISA\n");
    }
}

int main (void)
{
    long long number = get_long_long("Number: ");

    verify_card(number) ? print_card_type(number) : printf("INVALID\n");
}


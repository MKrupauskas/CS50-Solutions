#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get isbn number
    long long isbn = get_long_long("ISBN: ");
    int sum = 0;

    // Go from last digit to first digit
    for (int i = 10; i > 0; i--)
    {
        sum += (isbn % 10) * i;
        isbn /= 10;
    }

    // Check if the sum divided with no remainder and print answer
    sum % 11 == 0 ? printf("YES\n") : printf("NO\n");
}

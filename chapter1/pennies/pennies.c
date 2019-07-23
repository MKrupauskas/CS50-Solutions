#include <cs50.h>
#include <stdio.h>

int main(void)
{
    double sum = 0, pennies;
    int daysInMonth;

    // days in month have to be between 28 and 31
    do
    {
        daysInMonth = get_int("Days in month: ");
    }
    while (daysInMonth < 28 || daysInMonth > 31);

    // no less than 1 starting pennie allowed
    do
    {
        pennies = get_double("Pennies on first day: ");
    }
    while (pennies < 1);
    pennies /= 100;

    for (int i = 0; i < daysInMonth; i++)
    {
        sum += pennies;
        pennies *= 2; // double the pennies every day
    }

    printf("$%.2f\n", sum); // set precision to 2 decimal points
}

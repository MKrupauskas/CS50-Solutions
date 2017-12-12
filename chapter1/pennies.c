#include <cs50.h>
#include <stdio.h>

int main(void)
{
    double sum = 0, pennies = 0;
    int daysInMonth = 0;

    // days in the month have to be between 28 and 31
    while (daysInMonth < 28 || daysInMonth > 31)
    {
        daysInMonth = get_int("Days in month: ");
    }

    // no less than 1 starting pennie allowed
    while (pennies < 1)
    {
        pennies = get_double("Pennies on first day: ");
    }
    pennies /= 100;

    for (int i = 0; i < daysInMonth; i++)
    {
        sum += pennies;
        // double the pennies every day
        pennies *= 2; 
    }

    // set precision to 2 digits after the decimal point
    printf("$%.2f\n", sum); 
}

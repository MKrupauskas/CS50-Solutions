#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float C = get_float("C: ");
    // calculate the value of F
    float F = ((C * 9) / 5) + 32; 
    // set precision to 1 digit after the decimal point
    printf("F: %.1f\n", F); 
}

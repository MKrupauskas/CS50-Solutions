/**
 * fahrenheit.c
 *
 * CS50 AP
 * Old Friends
 *
 * Converts degrees C to degrees F
 * by collecting info at command line
 */

#include <cs50.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./fahrenheit <celsius>\n");
        return 1;
    }

    // Calculate celsius
    float celsius = atof(argv[1]);

    // Convert to fahrenheit; no float errors b/c celsius is a float
    float fahrenheit = (celsius * 9) / 5 + 32;
    printf("F: %.1f\n", fahrenheit);
}

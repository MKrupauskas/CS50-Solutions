//Helper functions for the sort race

#include <cs50.h>
#include <string.h>
#include "helpers.h"

//Returns true if str is a valid flag (-a, -b, -r, or -s), false otherwise
bool check_flag(char *str)
{
    return (strcmp(str, "-a") == 0 || strcmp(str, "-b") == 0 || strcmp(str, "-r") == 0
            || strcmp(str, "-s") == 0);
}

//Sorts array of n values using bubble sort.
void bubble(int values[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (values[i] > values[j])
            {
                // Swap elements
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
    return;
}

//Sorts array of n values using selection sort.
void selection(int values[], int n)
{
    int temp, min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            min = values[min] > values[j] ? j : min;
        }
        // Swap elements
        temp = values[i];
        values[i] = values[min];
        values[min] = temp;
    }
    return;
}

//Sorts array of n values using insertion sort.
void insertion(int values[], int n)
{
    int temp, index;
    for (int i = 1; i < n; i++)
    {
        index = i;
        while (index > 0 && values[index] < values[index - 1])
        {
            // Swap elements
            temp = values[index];
            values[index] = values[index - 1];
            values[index - 1] = temp;
            index--;
        }
    }
    return;
}

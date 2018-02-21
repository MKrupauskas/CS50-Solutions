//Helper functions for the sort race

#include <cs50.h>
#include "helpers.h"

//Returns true if str is a valid flag (-a, -b, -r, or -s), false otherwise
bool check_flag(char *str)
{
    return false;
}

//Sorts array of n values using bubble sort.
void bubble(int values[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (values[i] > values[j]) {
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
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (values[i] > values[j]) {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
    return;
}

//Sorts array of n values using insertion sort.
void insertion(int values[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (values[i] > values[j]) {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
    return;
}

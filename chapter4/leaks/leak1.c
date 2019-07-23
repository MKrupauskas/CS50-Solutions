/*******************************
 * leak1.c
 *
 * CS50 AP
 * Problem 5-2
 *******************************/

// defines
#define _XOPEN_SOURCE
#define NUMS 50

// includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// prototypes
void bar(void);
void foo(void);

// global declarations
int* ptrs[NUMS];

int main(int argc, char* argv[])
{
    for (int i = 0; i < NUMS; i++)
    {
        ptrs[i] = malloc(sizeof(int));
    }
    bar();
    foo();
    foo();
    for (int i = 0; i < NUMS; i++)
    {
        free(ptrs[i]);
    }
}

void bar(void)
{
    srand48(time(NULL));
    for (int i = 0; i < NUMS; i ++)
        *(ptrs[i]) = drand48() * 100;
}

void foo(void)
{
    for (int i = 0; i < NUMS; i ++)
    {
        printf("%d\n", *(ptrs[i]));
    }
}

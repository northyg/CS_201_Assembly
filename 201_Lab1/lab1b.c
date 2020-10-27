// Giselle Northy
// CS201 Lab1 Summer 2020
// Part A: Convert C++ to C (5 points)
// File lab1b.c
//Part B: Working with Command Line Arguments (5 points)


#include <stdio.h>

int main (int argc, char **argv)
{
    int i = 0;

    for(i = 0; i < argc; i++)
    {
        printf("arg %d: %s\n", i, argv[i]);
    }

    return 0;
}
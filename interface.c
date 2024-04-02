#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#include "functions.c"

#define MAX_STRING_SIZE 256

int mainMenu(int array1[MAX_ARRAY][MAX_ARRAY], int array2[MAX_ARRAY][MAX_ARRAY], int arrayResult[MAX_ARRAY][MAX_ARRAY], int rowsA, int colsA, int rowsB, int colsB, int resultRows, int resultCols)
{
    int option;
    if (array1[0][0] != 0)
    {
        breakLine();
        writePlus(0, "Active Arrays:");
        dysplayArray(array1, rowsA, colsA, "Array 1:");
    }
    if (array2[0][0] != 0)
    {
        dysplayArray(array2, rowsB, colsB, "Array 2:");
    }
    if (arrayResult[0][0] != 0)
    {
        dysplayArray(arrayResult, resultRows, resultCols, "Result Array :");
    }
    breakLine();
    writePlus(0, "Array Options:");
    writePlus(0, "1 -> Generate Array (not yet implemented)");
    writePlus(0, "2 -> Custom Array");
    writePlus(0, "3 -> Multiply Arrays");
    breakLine();
    writePlus(0, "Program Options:");
    writePlus(0, "8 -> Write to File");
    writePlus(0, "9 -> Read from File");
    writePlus(0, "0 -> Exit");
    breakLine();
    printf("\t\tOption: ");
    scanf("%d", &option);
    fflush(stdin);
    breakLine();
    return option;
}
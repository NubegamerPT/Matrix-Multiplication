#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#include "functions.c"

#define ARRAY_ROWS_A 3
#define ARRAY_COLS_A 3
#define ARRAY_ROWS_B 3
#define ARRAY_COLS_B 3

int main()
{
    // gives sizes for 2 matrixes used for testting porpuses
    // cols ->, rows ↓

    // Define 3D vectors
    int arrayTest1[ARRAY_ROWS_A][ARRAY_COLS_A];
    int arrayTest2[ARRAY_ROWS_B][ARRAY_COLS_B];

    if (checkArray(ARRAY_COLS_A, ARRAY_ROWS_B) == -1)
    {
        writePlus(2, "Cannot multiply! (Check columns and rows)");
    }
    else
    {
        writePlus(3, "Matrices are suitable for multiplication!");
    }

    return 0;
}
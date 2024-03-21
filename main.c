#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define SLEEP_MS(milliseconds) Sleep(milliseconds)
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
#include <unistd.h>
#define SLEEP_MS(milliseconds) usleep(milliseconds * 1000)
#else
#error "Unsupported operating system"
#endif

#include "functions.c"

#define ARRAY_ROWS_A 2
#define ARRAY_COLS_A 2
#define ARRAY_ROWS_B 2
#define ARRAY_COLS_B 3

int main()
{
    int resultSizeCols = 0;
    int resultSizeRows = 0;
    int tempSize = 0;

    // gives sizes for 2 matrixes used for testting porpuses
    // cols ->, rows ↓

    int array1[MAX_ARRAY][MAX_ARRAY];
    int array2[MAX_ARRAY][MAX_ARRAY];
    int tempArray[MAX_ARRAY];


    int arrayResult[MAX_ARRAY][MAX_ARRAY] = {0};
    // We knowm for a fact that matrixes can only be multiplied if the number of
    // columns in the first matrix is equal to the number rows for the other matrix
    if (checkArray(ARRAY_COLS_A, ARRAY_ROWS_B) == -1)
    {
        writePlus(2, "Cannot multiply! (Check columns and rows)");
    }
    else
    {
        resultSizeCols = ARRAY_COLS_A;
        resultSizeRows = ARRAY_ROWS_B;
        tempSize = resultSizeCols * resultSizeRows;
        writePlus(3, "Matrices are suitable for multiplication!");
        requestArray(array1, ARRAY_COLS_A, ARRAY_ROWS_A);
        dysplayArray(array1, ARRAY_COLS_A, ARRAY_ROWS_A,"The array you inserted:");
        requestArray(array2, ARRAY_COLS_B, ARRAY_ROWS_B);
        dysplayArray(array2, ARRAY_COLS_B, ARRAY_ROWS_B,"The array you inserted:");
    }

    for (int i = 0; i < tempSize; i++)
    {
        tempArray[i] = array1[i][i] * array2[i][i] + array1[i][i+1]*array2[i+1][i];
        tempArray[i+1] = array1[i][i]  * array2[i][i+1] + array1[i][i+1] * array2[i][i];
    }

    for (int row = 0; row < resultSizeCols; row++)
    {
        for (int col = 0; col < resultSizeRows; col++)
        {
            arrayResult[col][row] = tempArray[col + (resultSizeCols * row)];
        }   
    }

    
    dysplayArray(arrayResult,resultSizeCols,resultSizeRows,"The resulting array will look like this:");
    

    return 0;
}
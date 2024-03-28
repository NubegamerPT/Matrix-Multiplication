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

int main()
{
    int resultSizeCols = 0;
    int resultSizeRows = 0;

    // gives sizes for 2 matrixes used for testting porpuses
    // cols ->, rows ↓

    int array1[MAX_ARRAY][MAX_ARRAY];
    int array2[MAX_ARRAY][MAX_ARRAY];
    int result[MAX_ARRAY][MAX_ARRAY] = {0}; // Initialize result array with zeros

    int colsA, rowsA, colsB, rowsB;

    // Request user input for matrix sizes
    printf("Enter the number of rows and columns for matrix A: \n");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the number of rows and columns for matrix B: \n");
    scanf("%d %d", &rowsB, &colsB);

    int arrayResult[MAX_ARRAY][MAX_ARRAY] = {0};
    // We knowm for a fact that matrixes can only be multiplied if the number of
    // columns in the first matrix is equal to the number rows for the other matrix
    if (checkArray(colsA, rowsB) == -1)
    {
        writePlus(2, "Cannot multiply! (Check columns and rows)");
    }
    else
    {
        resultSizeCols = colsA;
        resultSizeRows = rowsB;
        writePlus(3, "Matrices are suitable for multiplication!");
        requestArray(array1, colsA, rowsA);
        dysplayArray(array1, colsA, rowsA, "The array you inserted:");
        requestArray(array2, colsB, rowsB);
        dysplayArray(array2, colsB, rowsB, "The array you inserted:");
    }

//  for (int colsA_ = 0; colsA_ < colsA; colsA_++)
//    { 
        for (int rowsA_ = 0; rowsA_ < rowsA; rowsA_++)
        {
            for (int colsB_ = 0; colsB_ < colsB; colsB_++)
            {
                for (int rowsB_ = 0; rowsB_ < rowsB; rowsB_++)
                {
                    arrayResult[rowsA_][colsB_] += array1[rowsA_][rowsB_] * array2[rowsB_][colsB_];
                    printf("Doing: [%d][%d] += [%d][%d]*[%d][%d]   ", rowsA_, colsB_, rowsA_, rowsB_, rowsB_, colsB_);
                    printf("colsA_ = [%d] rowsA_ = [%d] colsB_ = [%d] rowsB_ = [%d]\n", 0, rowsA_, colsB_, rowsB_);
                    SLEEP_MS(1);
                }
            }
        }
//    }

    dysplayArray(arrayResult, resultSizeCols, resultSizeRows, "The resulting array will look like this:");
    SLEEP_MS(1000000);

    return 0;
}
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
        resultSizeCols = colsB;
        resultSizeRows = rowsA;
        writePlus(3, "Matrices are suitable for multiplication!");
        
        requestArray(array1, rowsA, colsA);
        dysplayArray(array1, rowsA, colsA, "The array you inserted:");
        requestArray(array2, rowsB, colsB);
        dysplayArray(array2, rowsB, colsB, "The array you inserted:");

        multyplyArrys(array1, array2, arrayResult, rowsA, colsB, rowsB);

        dysplayArray(arrayResult, resultSizeRows, resultSizeCols, "The resulting array will look like this:");
        SLEEP_MS(5000);
    }
    fflush(stdin);
    writePlus(1, "Press any key to leave the program.");
    getchar();
    writePlus(0, "Exiting the program now...");
    SLEEP_MS(3000);

    return 0;
}
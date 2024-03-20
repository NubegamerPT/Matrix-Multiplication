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
#define ARRAY_COLS_A 3
#define ARRAY_ROWS_B 3
#define ARRAY_COLS_B 3

int main()
{
    // gives sizes for 2 matrixes used for testting porpuses
    // cols ->, rows ↓
    
    int arrayTest1[MAX_ARRAY][MAX_ARRAY];
    int arrayTest2[MAX_ARRAY][MAX_ARRAY];

    if (checkArray(ARRAY_COLS_A, ARRAY_ROWS_B) == -1)
    {
        writePlus(2, "Cannot multiply! (Check columns and rows)");
    }
    else
    {
        writePlus(3, "Matrices are suitable for multiplication!");
        requestArray(arrayTest1,ARRAY_COLS_A,ARRAY_ROWS_A);
        dysplayArray(arrayTest1,ARRAY_COLS_A,ARRAY_ROWS_A);
        requestArray(arrayTest2,ARRAY_COLS_B,ARRAY_ROWS_B);
        dysplayArray(arrayTest2,ARRAY_COLS_B,ARRAY_ROWS_B);
    }
    return 0;
}
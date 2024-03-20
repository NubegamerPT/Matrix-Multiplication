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

#define ARRAY_ROWS_A 3
#define ARRAY_COLS_A 3
#define ARRAY_ROWS_B 3
#define ARRAY_COLS_B 3

int main()
{
    // gives sizes for 2 matrixes used for testting porpuses
    // cols ->, rows ↓

    // Define 3D vectors
    writePlus(0,"TESTE");
    writePlus(1,"TESTE");
    writePlus(2,"TESTE");
    writePlus(3,"TESTE");
    writePlus(4,"TESTE");
    SLEEP_MS(1000);
    int arrayTest1[MAX_ARRAY][MAX_ARRAY];
    int arrayTest2[MAX_ARRAY][MAX_ARRAY];

    if (checkArray(ARRAY_COLS_A, ARRAY_ROWS_B) == -1)
    {
        writePlus(2, "Cannot multiply! (Check columns and rows)");
    }
    else
    {
        writePlus(3, "Matrices are suitable for multiplication!");
        requestArray(arrayTest1,ARRAY_ROWS_A,ARRAY_COLS_A);
        dysplayArray(arrayTest1,ARRAY_ROWS_A,ARRAY_COLS_A);
        requestArray(arrayTest2,ARRAY_ROWS_B,ARRAY_COLS_B);
        dysplayArray(arrayTest2,ARRAY_ROWS_B,ARRAY_COLS_B);
    }
    return 0;
}
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

#include "interface.c"

int main()
{
    int resultSizeCols = 0;
    int resultSizeRows = 0;

    boolean isntRunning = TRUE;
    boolean isCorrect = FALSE;
    boolean canMultiply = FALSE;

    int option = '0';

    // gives sizes for 2 matrixes used for testting porpuses
    // cols ->, rows ↓

    int array1[MAX_ARRAY][MAX_ARRAY] = {0};
    int array2[MAX_ARRAY][MAX_ARRAY] = {0};
    int result[MAX_ARRAY][MAX_ARRAY] = {0}; // Initialize arrays with zeros

    int colsA, rowsA, colsB, rowsB;

    do
    {
        int temp_ = mainMenu();
        switch (temp_)
        {
        case 1:

            break;
        case 2:
            writePlus(0, "Enter the number of rows and columns for matrix A: ");
            scanf("%d %d", &rowsA, &colsA);
            writePlus(0, "Enter the number of rows and columns for matrix B: ");
            scanf("%d %d", &rowsB, &colsB);

            int arrayResult[MAX_ARRAY][MAX_ARRAY] = {0};
            // We knowm for a fact that matrixes can only be multiplied if the number of
            // columns in the first matrix is equal to the number rows for the other matrix

            if (checkArray(colsA, rowsB) == -1)
            {
                writePlus(2, "Cannot multiply! (Check columns and rows)");
                canMultiply = FALSE;
            }
            else
            {
                canMultiply = TRUE;
                resultSizeCols = colsB;
                resultSizeRows = rowsA;
                writePlus(3, "Matrices are suitable for multiplication!");

                do
                {
                    requestArray(array1, rowsA, colsA);
                    dysplayArray(array1, rowsA, colsA, "The array you inserted is correct? Y/n:");
                    breakLine();
                    printf("Option: ");
                    scanf(" %c", &option);
                    fflush(stdin);
                    option = tolower(option);
                    if (option == 'n')
                    {
                        isCorrect = FALSE;
                    }
                    else if (option == 'y')
                    {
                        isCorrect = TRUE;
                    }
                    else
                    {   
                        writePlus(1, "Invalid Option! Assuming to be correct. Resuming...");
                        isCorrect = TRUE;
                    }
                } while (!isCorrect);

                do
                {
                    requestArray(array2, rowsB, colsB);
                    dysplayArray(array2, rowsB, colsB, "The array you inserted is correct? Y/n:");
                    breakLine();
                    printf("Option: ");
                    scanf(" %c", &option);
                    fflush(stdin);
                    option = tolower(option);
                    if (option == 'n')
                    {
                        isCorrect = FALSE;
                    }
                    else if (option == 'y')
                    {
                        isCorrect = TRUE;
                    }
                    else
                    {   
                        writePlus(1, "Invalid Option! Assuming to be correct. Resuming...");
                        isCorrect = TRUE;
                    }
                } while (!isCorrect);
                fflush(stdin);
            }
            break;

        case 3:
            if (rowsA == 0)
            {
                writePlus(2, "Cannot multiply! (No Arrays to multiply)");
                SLEEP_MS(1000);
                isntRunning = TRUE;
            }
            else if (!canMultiply)
            {
                writePlus(2, "Cannot multiply! (Check columns and rows)");
                SLEEP_MS(1000);
                isntRunning = TRUE;
            }
            else
            {
                writePlus(1, "Clearing result array. \n");
                for (int resultSizeCols_ = 0; resultSizeCols_ < resultSizeCols; resultSizeCols_++)
                {
                    for (int resultSizeRows_ = 0; resultSizeRows_ < resultSizeRows; resultSizeRows_++)
                    {
                        result[resultSizeRows_][resultSizeCols_] = 0;
                    }
                }
                
                multyplyArrys(array1, array2, arrayResult, rowsA, colsB, rowsB);
                dysplayArray(arrayResult, resultSizeRows, resultSizeCols, "The resulting array will look like this:");
                breakLine();
                writePlus(1, "Press any key to continue.");
                getchar();
                system("cls");
            }
            break;

        case 0:
            isntRunning = FALSE;
            break;

        default:
            isntRunning = TRUE;
            break;
        }
    } while (isntRunning);
    fflush(stdin);
    writePlus(1, "Exiting the program now...");
    SLEEP_MS(2000);

    return 0;
}
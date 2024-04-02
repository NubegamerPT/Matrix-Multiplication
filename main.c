#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define SLEEP_MS(milliseconds) Sleep(milliseconds)
#define CLS "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
#include <unistd.h>
#define SLEEP_MS(milliseconds) usleep(milliseconds * 1000)
#define CLS "clear"
#else
#error "Unsupported operating system"
#endif

#include "interface.c"

int main()
{
    boolean isntRunning = TRUE;
    boolean isCorrect = FALSE;
    boolean canMultiply = FALSE;

    FILE *userData;

    char option = '0';

    // gives sizes for 2 matrixes used for testting porpuses
    // cols ->, rows ↓

    int array1[MAX_ARRAY][MAX_ARRAY] = {0};
    int array2[MAX_ARRAY][MAX_ARRAY] = {0};
    int result[MAX_ARRAY][MAX_ARRAY] = {0}; // Initialize arrays with zeros

    int colsA = 0;
    int rowsB = 0;
    int rowsA = 0;
    int colsB = 0;

    int resultSizeCols = 0;
    int resultSizeRows = 0;

    do
    {
        int temp_ = mainMenu(array1, array2, result, rowsA, colsA, rowsB, colsB, resultSizeRows, resultSizeCols);
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
                system(CLS);
                breakLine();
                writePlus(2, "Cannot multiply! (Check columns and rows)");
                breakLine();
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
                system(CLS);
                breakLine();
                writePlus(2, "Cannot multiply! (No Arrays to multiply)");
                breakLine();
                SLEEP_MS(1000);
                isntRunning = TRUE;
            }
            else if (!canMultiply)
            {
                system(CLS);
                breakLine();
                writePlus(2, "Cannot multiply! (Check columns and rows)");
                breakLine();
                SLEEP_MS(1000);
                isntRunning = TRUE;
            }
            else
            {
                resultSizeCols = colsB;
                resultSizeRows = rowsA;
                writePlus(1, "Clearing result array. \n");
                for (int resultSizeCols_ = 0; resultSizeCols_ < resultSizeCols; resultSizeCols_++)
                {
                    for (int resultSizeRows_ = 0; resultSizeRows_ < resultSizeRows; resultSizeRows_++)
                    {
                        result[resultSizeRows_][resultSizeCols_] = 0;
                    }
                }

                multiplyArrys(array1, array2, arrayResult, rowsA, colsB, rowsB);
                dysplayArray(arrayResult, resultSizeRows, resultSizeCols, "The resulting array will look like this:");
                breakLine();
                writePlus(1, "Press any key to continue.");
                getchar();
                system(CLS);
            }
            break;

        case 8:
            if (rowsA == 0 && colsB == 0)
            {
                system(CLS);
                breakLine();
                writePlus(2, "Nothing to write!");
                breakLine();
                SLEEP_MS(1000);
                isntRunning = TRUE;
            }
            else
            {
                userData = fopen("arrayList.txt", "w");

                if (userData == NULL)
                {
                    writePlus(2, "Error creating file... \n");
                    breakLine();
                }
                else
                {
                    writePlus(3, "Writing to file... \n");
                    fprintf(userData, "Array 1:\n    ");
                    for (int i = 0; i < colsA; i++)
                    {
                        fprintf(userData, "---%d---", i + 1);
                    }
                    fprintf(userData, "\n");
                    for (int row = 0; row < rowsA; row++)
                    {
                        fprintf(userData, "%3d:", row + 1);
                        for (int col = 0; col < colsA; col++)
                        {
                            fprintf(userData, "[%5d]", array1[row][col]);
                        }
                        fprintf(userData, "\n");
                    }

                    fprintf(userData, "\nArray 2:\n    ");
                    for (int i = 0; i < colsB; i++)
                    {
                        fprintf(userData, "---%d---", i + 1);
                    }
                    fprintf(userData, "\n");
                    for (int row = 0; row < rowsB; row++)
                    {
                        fprintf(userData, "%3d:", row + 1);
                        for (int col = 0; col < colsB; col++)
                        {
                            fprintf(userData, "[%5d]", array2[row][col]);
                        }
                        fprintf(userData, "\n");
                    }

                    if (isCorrect && arrayResult[0][0] != 0)
                    {
                        fprintf(userData, "\nResult Array:\n    ");
                        for (int i = 0; i < resultSizeCols; i++)
                        {
                            fprintf(userData, "---%d---", i + 1);
                        }
                        fprintf(userData, "\n");
                        for (int row = 0; row < resultSizeRows; row++)
                        {
                            fprintf(userData, "%3d:", row + 1);
                            for (int col = 0; col < resultSizeCols; col++)
                            {
                                fprintf(userData, "[%5d]", arrayResult[row][col]);
                            }
                            fprintf(userData, "\n");
                        }
                    }
                }
                fclose(userData);

                userData = fopen("userData.bin", "w");

                if (userData != NULL)
                {
                    int temp_ = 0;
                    fwrite(&rowsA, sizeof(rowsA), 1, userData);
                    fwrite(&colsA, sizeof(colsA), 1, userData);
                    fwrite(&rowsB, sizeof(rowsB), 1, userData);
                    fwrite(&colsB, sizeof(colsB), 1, userData);
                    fwrite(&isCorrect, sizeof(isCorrect), 1, userData);
                    fwrite(&canMultiply, sizeof(isCorrect), 1, userData);
                    for (int rowsA_ = 0; rowsA_ < rowsA; rowsA_++)
                    {
                        for (int colsA_ = 0; colsA_ < colsA; colsA_++)
                        {
                            temp_ = array1[rowsA_][colsA_];
                            fwrite(&temp_, sizeof(temp_), 1, userData);
                        }
                    }
                    temp_ = 0;
                    for (int rowsA_ = 0; rowsA_ < rowsA; rowsA_++)
                    {
                        for (int colsA_ = 0; colsA_ < colsA; colsA_++)
                        {
                            temp_ = array2[rowsA_][colsA_];
                            fwrite(&temp_, sizeof(temp_), 1, userData);
                        }
                    }
                }
                fclose(userData);
                SLEEP_MS(1000);
                system(CLS);
            }
            break;

        case 9:
            userData = fopen("userData.bin", "r");

            if (userData != NULL)
            {
                writePlus(3, "Reading from local file... \n");
                int temp_ = 0;
                fread(&rowsA, sizeof(rowsA), 1, userData);
                fread(&colsA, sizeof(colsA), 1, userData);
                fread(&rowsB, sizeof(rowsB), 1, userData);
                fread(&colsB, sizeof(colsB), 1, userData);
                fread(&isCorrect, sizeof(isCorrect), 1, userData);
                fread(&canMultiply, sizeof(isCorrect), 1, userData);
                for (int rowsA_ = 0; rowsA_ < rowsA; rowsA_++)
                {
                    for (int colsA_ = 0; colsA_ < colsA; colsA_++)
                    {
                        fread(&temp_, sizeof(temp_), 1, userData);
                        array1[rowsA_][colsA_] = temp_;
                    }
                }
                temp_ = 0;
                for (int rowsB_ = 0; rowsB_ < rowsB; rowsB_++)
                {
                    for (int colsB_ = 0; colsB_ < colsB; colsB_++)
                    {
                        fread(&temp_, sizeof(temp_), 1, userData);
                        array2[rowsB_][colsB_] = temp_;
                    }
                }
            }
            else
            {
                system(CLS);
                breakLine();
                writePlus(2, "Error reading file...");
                breakLine();
            }
            fclose(userData);
            SLEEP_MS(1000);
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
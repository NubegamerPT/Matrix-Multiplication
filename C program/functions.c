#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MAX_STRING_SIZE 256
#define MAX_ARRAY 64

#define ANSI_COLOR_RED "\x1b[91m"    // Console RED
#define ANSI_COLOR_GREEN "\x1b[32m"  // Console GREEN
#define ANSI_COLOR_YELLOW "\x1b[33m" // Console YELLOW
#define ANSI_COLOR_BLUE "\x1b[34m"   // Console BLUE
#define ANSI_COLOR_WHITE "\x1b[37m"  // Console WHITE
#define ANSI_COLOR_RESET "\x1b[0m"   // Console RESET

void breakLine(void)
{
    printf("\n------------------------------------------------- \n\n");
}

int checkArray(int collomsA, int linesB)
{
    if (collomsA != linesB)
    {
        return -1;
    }
    return 0;
}

int writePlus(int type, const char text[MAX_STRING_SIZE])
{
    // this function allows the programer to easially send printf with color code,
    // for exemple, writePlus(2, Files deleted!), the  output will be: "(in red)[ERROR] Files deleted!"
    int stat = 0;
    switch (type)
    {
    case 0:
        stat = printf("[INFO]    %s", text); // text with no color (white)
        break;
    case 1:
        stat = printf(ANSI_COLOR_YELLOW "[WARNING] %s", text); // text with yellow color
        break;
    case 2:
        stat = printf(ANSI_COLOR_RED "[ERROR]   %s", text); // text with red color
        break;
    case 3:
        stat = printf(ANSI_COLOR_GREEN "[SUCESS]  %s", text); // text with green color
        break;
    case 4:
        stat = printf(ANSI_COLOR_BLUE "[OUTPUT]  %s", text); // text with blue color
        break;
    case 5:
        stat = printf("[INPUT]   %s", text); // text with no color (white)
        break;
    default:
        stat = printf("[INFO]    %s", text); // text with no color (white)
    }
    printf(ANSI_COLOR_RESET "");
    printf("\n");
    return stat;
}

void requestArray(int userArray[MAX_ARRAY][MAX_ARRAY], int arrayRows, int arrayCols)
{
    breakLine();
    writePlus(0, "Enter the Elements of the array:");
    for (int row = 0; row < arrayRows; row++)
    {
        for (int col = 0; col < arrayCols; col++)
        {
            printf("[INPUT]   Element [%d,%d]: ", row + 1, col + 1);
            scanf("%d", &userArray[row][col]);
        }
    }
}

void dysplayArray(int userArray[MAX_ARRAY][MAX_ARRAY], int arrayRows, int arrayCols, char text[MAX_STRING_SIZE])
{
    writePlus(0, text);
    printf("\n\t\t  ");
    for (int i = 0; i < arrayCols; i++)
    {
        printf("---%d---", i + 1);
    }
    printf("\n");
    for (int row = 0; row < arrayRows; row++)
    {
        printf("\t\t%d:", row + 1);
        for (int col = 0; col < arrayCols; col++)
        {
            printf("[%5d]", userArray[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplyArrys(int array1[MAX_ARRAY][MAX_ARRAY], int array2[MAX_ARRAY][MAX_ARRAY], int arrayResult[MAX_ARRAY][MAX_ARRAY], int rowsA, int colsB, int rowsB)
{
    int tempA = 0;
    int tempB = 0;

    for (int rowsA_ = 0; rowsA_ < rowsA; rowsA_++)
    {
        for (int colsB_ = 0; colsB_ < colsB; colsB_++)
        {
            for (int rowsB_ = 0; rowsB_ < rowsB; rowsB_++)
            {
                if (colsB_ == 0 && rowsB_ == 0)
                {
                    tempA = 0;
                }
                else if (colsB_ > 0 && rowsB_ == 0)
                {
                    tempB = tempA;
                    tempA = 0;
                }
                else if (rowsB_ > 0)
                {
                    tempA = rowsB_;
                }
                else if (colsB_ > 0)
                {
                    tempA = colsB_;
                }

                if (colsB_ == 0 && rowsB_ == 0)
                {
                    tempB = 0;
                }
                else if (colsB_ > 0 || rowsB_ > 0)
                {
                    tempB = colsB_;
                }

                arrayResult[rowsA_][colsB_] += array1[rowsA_][rowsB_] * array2[tempA][tempB];

                // used for debugging
                /*printf("Doing: [%d][%d] += [%d][%d] = %2d * [%d][%d] = %2d  ", rowsA_, colsB_, rowsA_, rowsB_, array1[rowsA_][rowsB_], tempA, tempB, array2[tempA][tempB]);
                printf("tempA = [%d] tempB = [%d] || rowsA_ = [%d] colsB_ = [%d] rowsB_ = [%d]\n", tempA, tempB, rowsA_, colsB_, rowsB_);*/
                printf("[INFO]    Doing: [%d][%d] += [%d][%d] = %2d * [%d][%d] = %2d  \n", rowsA_ + 1, colsB_ + 1, rowsA_ + 1, colsB_ + 1, array1[rowsA_][rowsB_], tempA + 1, tempB + 1, array2[tempA][tempB]);
                SLEEP_MS(1);
            }
        }
    }
    breakLine();
}
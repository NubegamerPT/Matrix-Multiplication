#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define ANSI_COLOR_RED "\x1b[91m" // Console RED
#define ANSI_COLOR_GREEN "\x1b[32m" // Console GREEN
#define ANSI_COLOR_YELLOW "\x1b[33m" // Console YELLOW
#define ANSI_COLOR_BLUE "\x1b[34m" // Console BLUE
#define ANSI_COLOR_WHITE "\x1b[37m" // Console WHITE
#define ANSI_COLOR_RESET "\x1b[0m" // Console RESET

#define MAX_STRING_SIZE 256
#define MAX_ARRAY 64

int checkArray(int collomsA, int linesB)
{
    int state = 0;
    if (collomsA != linesB)
    {
        state = -1;
    }
    return state;
}

int writePlus(int type, const char text[MAX_STRING_SIZE])
{
    // this function allows the programer to easially send printf with color code,
    // for exemple, writePlus(2, Files deleted!), the  output will be: "(in red)[ERROR] Files deleted!"
    int stat = 0;
    printf(ANSI_COLOR_RESET "");
    switch (type)
    {
    case 0:
        stat = printf("[INFO] %s", text); // text with no color (white)
        break;
    case 1:
        stat = printf(ANSI_COLOR_YELLOW "[WARNING] %s", text); // text with yellow color
        break;
    case 2:
        stat = printf(ANSI_COLOR_RED "[ERRO] %s", text); // text with red color
        break;
    case 3:
        stat = printf(ANSI_COLOR_GREEN "[SUCESS] %s", text); // text with green color
        break;
    case 4:
        stat = printf(ANSI_COLOR_BLUE "[OUTPUT] %s", text); // text with blue color
        break;
    case 5:
        stat = printf("[INPUT] %s", text); // text with no color (white)
        break;
    default:
        stat = printf("[INFO] %s", text); // text with no color (white)
    }
    printf(ANSI_COLOR_RESET "");
    printf("\n");
    return stat;
}

void requestArray(int userArray[MAX_ARRAY][MAX_ARRAY], int arrayRows, int arrayCols)
{
    printf("[INFO] Insert the elements of array: \n");
    for (int row = 0; row < arrayRows; row++)
    {
        for (int col = 0; col < arrayCols; col++)
        {
            printf("[INPUT] Element [%d,%d]: ", row, col);
            scanf("%d", &userArray[row][col]);
        }
    }
}

void dysplayArray(int userArray[MAX_ARRAY][MAX_ARRAY], int arrayRows, int arrayCols)
{
    writePlus(0, "The array you inserted is:");
    for (int row = 0; row < arrayRows; row++)
    {
        for (int col = 0; col < arrayCols; col++)
        {
            printf("[%d]", userArray[row][col]);
        }
        printf("\n");
    }
}

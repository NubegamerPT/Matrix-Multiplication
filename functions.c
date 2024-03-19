#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define ANSI_COLOR_RED "\033[0;31m"     // Console RED
#define ANSI_COLOR_GREEN "\033[0;32m"   // Console GREEN
#define ANSI_COLOR_YELLOW "\033[0;33m"  // Console YELLOW
#define ANSI_COLOR_BLUE "\033[0;34m"    // Console BLUE
#define ANSI_COLOR_MAGENTA "\033[0;35m" // Console MAGENTA
#define ANSI_COLOR_CYAN "\033[0;36m"    // Console CYAN
#define ANSI_COLOR_RESET "\033[0m"      // Reset to default color

#define MAX_STRING_SIZE 256
#define MAX_ARRAY 64

int verificarMatrizes(int collomsA, int linesB)
{
    int state = 0;
    if (collomsA != linesB)
    {
        state = 1;
    }
    return state;
}

int writePlus(int type, const char text[MAX_STRING_SIZE])
{   
    //this function allows the programer to easially send printf with color code,
    //for exemple, writePlus(2, Files deleted!), the  output will be: "(in red)[ERROR] Files deleted!"

    switch (type)
    {
    case 0:
        printf("[INFO] %s\n", text); // text with no color (white)
        break;
    case 1:
        printf(ANSI_COLOR_YELLOW "[WARNING] %s\n", text); // text with yellow color
        break;
    case 2:
        printf(ANSI_COLOR_RED "[ERRO] %s\n", text); // text with red color
        break;
    case 3:
        printf(ANSI_COLOR_GREEN "[SUCESS] %s\n", text); // text with no color
        break;
    case 4:
        printf(ANSI_COLOR_BLUE "[OUTPUT] %s\n", text); // text with no color
        break;
    default:
        printf("[INFO] %s\n", text); // text with no color (white)
        break;
    }
}
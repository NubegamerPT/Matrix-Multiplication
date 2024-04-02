#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#include "functions.c"

#define MAX_STRING_SIZE 256

int mainMenu()
{
    int option;
    breakLine();
    writePlus(0, "Array Options:");
    writePlus(0, "1 -> Generate Array");
    writePlus(0, "2 -> Custom Array");
    writePlus(0, "3 -> Multiply Arrays");
    breakLine();
    writePlus(0, "Program Options:");
    writePlus(0, "8 -> Write to File Result Array");
    writePlus(0, "9 -> Generate Array");
    writePlus(0, "0 -> Exit");
    breakLine();
    printf("\t\tOption: ");
    scanf("%d", &option);
    fflush(stdin);
    breakLine();
    return option;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

#include "functions.c"

int main()
{
    int arrayCollomA = 3;
    int arrayLinesA = 3;
    int arrayCollomB = 3;
    int arrayLinesB = 3;

    // gives sizes for 2 matrixes used for testting porpuses
    // colloms ->, lines ↓

    int arrayTest1[arrayCollomA][arrayLinesA];
    int arrayTest2[arrayCollomB][arrayLinesB];

    if (verificarMatrizes(arrayCollomA, arrayLinesB) == -1)
    {
        writePlus(2,"Cant multiply! (check colloms and lines)");
    }
    writePlus(3,"Matrixes are sutable!");

    return 0;
}
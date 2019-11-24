#include <stdio.h>

int iBinomialCoeffOn3(int, int);

/**************************************/
/* Calculate the binomial coefficient */
/* Complexity: O(n^3)                 */
/**************************************/
int iBinomialCoeffOn3(int row, int column) 
{ 
    int iReturn;
    iReturn = 1;

    if (column > row - column)
    {
        column = row - column;
    }

    for (int i = 0; i < column; ++i) 
    { 
        iReturn = iReturn * (row - i); 
        iReturn = iReturn / (i + 1); 
    } 

    return iReturn; 
}


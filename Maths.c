#include <stdio.h>

int iBinomialCoeffOn3(int, int);
int iGreatestCommonDivisor(int, int);


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


/*****************************************/
/* Calculate the greatest common divisor */
/* Complexity: O()                   */
/*****************************************/
int iGreatestCommonDivisor(int a, int b)
{
    int ilModulus;
    int ilA, ilB;
    
    if(0 == a)
    {
        return b;
    }
    if(0 == b)
    {
        return a;
    }
    
    ilA = a;
    ilB = b;
    if(a<b){
        ilA = b;
        ilB = a;
    }
    ilModulus = ilA % ilB;
    
    return iGreatestCommonDivisor(ilB, ilModulus);
}

#include <math.h>

#define CREATE_CHAR_ARRAY(SZ) (malloc(SZ * sizeof(unsigned char)))

void vPrintPrimes(unsigned char * ptrIntA, unsigned long long int  iSize)
{
    unsigned char iCount = 0;
    printf("Primes until %lld:\n",MAX_NUM);
    for(unsigned long long int  i=2; i<iSize; i++)
    {
        if(0 != *(ptrIntA+i) )
        {
            printf("%lld\t",i);
            iCount++;
            if(20==iCount)
            {
                iCount = 0;
                printf("\n");
            }
        }
    }
    printf("\n");
}

void vInitArrayWith(unsigned char * ptrIntA, unsigned long long int  iSize, unsigned char iVal)
{
    for(unsigned long long int  i=0; i<iSize; i++)
    {
        *(ptrIntA+i) = iVal;
    }
}

unsigned long long int lliMarkAllPrimesUntilX(unsigned char * aptrIntArray, unsigned long long int aulliX){
    unsigned long long int iTotalPrimes;
    unsigned long long int iStop;
    unsigned long long int iMaxNum;

    iTotalPrimes = aulliX-1;
    aulliX++;
    vInitArrayWith(aptrIntArray, aulliX, 1);

    iStop = (unsigned long long int)(sqrtl(aulliX) + 1);

    for(unsigned long long int  i=2; i<iStop; i++)
    {
        iMaxNum = aulliX/i;
        for(unsigned long long int  j=iMaxNum; j>=i; j--)
        {
            if(1 == *(aptrIntArray+j))
            {
                if(1 == *(aptrIntArray+(j*i)))
                {
                    *(aptrIntArray+(j*i)) = 0;
                    iTotalPrimes--;
                }
            }
        }
    }
    return iTotalPrimes;
}


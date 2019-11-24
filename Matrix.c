#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int rows;
    int columns;
    int ** data;
} sMatrix;


void vDestroyMatrix(sMatrix * matrix)
{
    for (int i = 0; i < (matrix->rows); ++i)
    {
        free(matrix->data[i]);
    }
    free((matrix->data));
    free(matrix);
}


sMatrix * iptrCreateMatrix(int rows, int columns)
{
    sMatrix * sRetMatrix;
    int ** intDataMatrix;
    sRetMatrix = (sMatrix *)malloc(sizeof(sMatrix));
    (sRetMatrix->rows) = rows;
    (sRetMatrix->columns) = columns;

    (sRetMatrix->data) = (int **) (malloc(rows * sizeof(int *)));
    for (int i = 0; i < rows; ++i)
    {
        (sRetMatrix->data)[i] = (int *)malloc(columns * sizeof(int));
    }

    return sRetMatrix;
}


void vInitMatrix(sMatrix * matrix)
{
    for(int i=0; i<(matrix->rows); i++)
    {
        for(int j=0; j<(matrix->columns); j++)
        {
            (matrix->data)[i][j] = 0;
        }
    }
}

int iNumberOfPathsOnlyRightAndDown(int r, int c) 
{
    if ((1 == r) || (1 == c)) 
        return 1; 
    return iNumberOfPathsOnlyRightAndDown(r - 1, c) + iNumberOfPathsOnlyRightAndDown(r, c - 1); 
}

void vPrintMatrix(sMatrix * matrix)
{
    printf("\n");
    for(int i=0; i<(matrix->rows); i++)
    {
        for(int j=0; j<(matrix->columns); j++)
        {
            printf("%d\t",(matrix->data)[i][j]);
        }
        printf("\n");
    }
}

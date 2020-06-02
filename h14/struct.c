#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int *** Malloc(unsigned int framecount, unsigned int widt ,unsigned int height)
{
    int i,m,n;

    i = 0;

    m = 0;

    n = 0;

    int ***array =(int ***) malloc(sizeof(int**)*framecount);

    for(i=0; i<framecount; i++)
    {
        array[i] = (int**)malloc(sizeof(int *)*widt);
    }


    for(i=0 ; i<framecount; i++)
    {
        for(m=0; m<widt; m++)
        {
            array[i][m] = (int*)malloc(sizeof(int)*height);
        }
    }


    for(i=0 ; i<framecount; i++)
    {
        for(m=0; m<widt; m++)
        {
            for(n=0; n<height; n++)
            {
                array[i][m][n] = i+m+n;
            }
        }
    }

    return array;
}

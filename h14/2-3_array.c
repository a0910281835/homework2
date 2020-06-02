#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80
int main(int argc, const char * argv[])
{

    int a[2][3][4] = {{{1,2,3,4},{5,6,7,8},{9,10,11,12}},
                      {{13,14,15,16},{17,18,19,20},{21,22,23,24}}};

    printf("%d\n",a[0][0][0]);


//>>>>>>>>>>
//  [2,4] matrix


    int ***ptr =(int***) malloc(sizeof(int **) *2);

    int i = 0, j = 0 , z = 0;

    for(i=0;i<2;i++)
    {
        ptr[i] = (int**) malloc(sizeof(int*)*3);
    }

    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            ptr[i][j] = (int*) malloc(sizeof(int)*4);
        }

    }

    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            for (z=0; z<4; z++)
            {
                ptr[i][j][z] = i+j+z;

                printf("%d \t",ptr[i][j][z]);
            }
            printf("\n");
        }

        printf("\n");

    }
    printf("Hello\n");


    return 0;
}

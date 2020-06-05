#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int *** Malloc(int framecount, int widt, int height)
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



THREE_ARRAY* load_csv(const char* str)
{

    char line[MAX];

    char *result = NULL;

    THREE_ARRAY *file = (THREE_ARRAY*) malloc(sizeof(THREE_ARRAY));

    FILE * fptr = fopen(str,"r");

    if(fptr != NULL)
    {
        printf("opening the file is successful!\n");


//>>>>>>>>>>>>>>>get the simple information>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.
        //>>>get name;
        fgets(line,MAX,fptr);

        line[strlen(line)-1] = '\0';

        strcpy(file->File_NAME, line);


        //>>get FrameCount

        fgets(line,MAX,fptr);

        result = strtok(line, ",");

        result = strtok(NULL, ",");

        file->FrameCount = atoi(result);

        //>>get  witch
        fgets(line,MAX,fptr);

        result = strtok(line, ",");

        result = strtok(NULL, ",");

        file->Width = atoi(result);

        //>>get height
        fgets(line,MAX,fptr);

        result = strtok(line, ",");

        result = strtok(NULL, ",");

        file->Height = atoi(result);

        //>>get type
        fgets(line,MAX,fptr);

        result = strtok(line, ",");

        result = strtok(NULL, ",");

        result[strlen(result)-1] = '\0';

        strcpy(file->type, result);

//>>>>>>>>>>>>>>>end of get the simple information >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        printf("%s\n",file->File_NAME);

        printf("%d\n",file->FrameCount);

        printf("%d\n",file->Width);

        printf("%d\n",file->Height);

        printf("%s\n",file->type);

        unsigned short int i, m, n;

        i = 0;

        m = 0;

        n = 0;

        file->array = Malloc(file->FrameCount, file->Width, file->Height);

        // get the demension 3 Matrix
        while(i< (file->FrameCount))
        {
            //remove block and first label for every matrix
            do
            {
                fgets(line, MAX, fptr);

//                printf("line:%s",line);

            } while(strcmp(line, "\n") == 0);

            // load the 2-matrix data
            for(m=0; m<(file->Width); m++)
            {
                fgets(line, MAX, fptr);

//                printf("%s>>",line);
                result = strtok(line, ",");

                for(n=0; n<(file->Height); n++)
                {



                    file->array[i][m][n] = atoi(result);

//                    printf("%d ",file->array[i][m][n]);
  //                  printf("y");
                    result = strtok(NULL, ",");
                }
            }

            i++;
        }

        fclose(fptr);

        return file;
    }

    else
    {
        printf("fail");

        exit(-1);
    }
}




void PRINTARRAY(unsigned int num, THREE_ARRAY* file)
{


    int  m, n;

    m = 0;

    n = 0;

    if(num >file->FrameCount)
    {
        printf("error");

        exit(-1);
    }

    printf("%d array>>>>>>>>>>>>>>>>>>>>>>>:\n",num);

    for(m=0; m<file->Width; m++)
    {
        for(n=0; n<file->Height; n++)
        {
            printf("%4d",file->array[num-1][m][n]);
        }
        printf("\n");
    }

    printf("\n");


}



THREE_ARRAY* GetR_from_D(THREE_ARRAY *file)
{
    THREE_ARRAY * Rfile = (THREE_ARRAY*) malloc(sizeof(THREE_ARRAY));

    Rfile->FrameCount = file->FrameCount;

    Rfile->Width = file->Width;

    Rfile->Height = (file->Height+1);


    Rfile->array = Malloc(Rfile->FrameCount, Rfile->Width, Rfile->Height);

    int i, m ,n ;

    i = 0;

    m = 0;

    n = 0;

    int temp = 0;

    int row = 0;

    for(i=0; i<Rfile->FrameCount; i++)
    {
        for(m=0; m<Rfile->Width; m++)
        {
            for(n=0; n<Rfile->Height; n++)
            {
                if(n==0)
                {
                    temp = 0;

                    Rfile->array[i][m][n] = temp;

                    row = temp;
                }

                else
                {
                    Rfile->array[i][m][n] = temp - file->array[i][m][n-1];

                    temp = Rfile->array[i][m][n];

                    row = row + temp;
                }
            }
            // mean
            row = row / (Rfile->Height);

            for(n=0; n<Rfile->Height; n++)
            {
                Rfile->array[i][m][n] = Rfile->array[i][m][n] - row;
            }
        
        }
    } 


    return Rfile;
}


bool EQUALCOORD( const COORDINATE coord1, const COORDINATE coord2)
{
    bool type = true;

    if((coord1.RX != coord2.RX)||(coord1.TX !=coord2.TX))
    {
        type = false;
    }

    return type;
}




COORDINATE Findnextcoord(int **array, int width, int height, COORDINATE coord, int COMP )
{
    int m, n ;

    int weight = 0;
    //remove the edge of array row=0 to width-1 and column 0 to height-1

    COORDINATE nextcoord = {1, 0};

    m = coord.TX;
// remain coloum for this row
    for(n=coord.RX+1; n<height-1;n++)
    {
       if(array[m][n]>COMP)
       {
            if(array[m][n] <= array[m-1][n-1])
                continue;
            if(array[m][n] <= array[m][n-1])
                continue;
            if(array[m][n] <= array[m+1][n-1])
                continue;
            if(array[m][n] <= array[m-1][n])
                continue;
            if(array[m][n] < array[m+1][n])
                continue;
            if(array[m][n] < array[m-1][n+1])
                continue;
            if(array[m][n] < array[m][n+1])
                continue;
            if(array[m][n] < array[m+1][n+1])
                continue;
            
            nextcoord.TX = m;

            nextcoord.RX = n;

            return nextcoord;
       }
    }
// remain all row
   for(m=coord.TX+1; m<width-1; m++)
   {

           for(n=1; n<height-1;n++)
           {
               if(array[m][n]>COMP)
               {
                    if(array[m][n] <= array[m-1][n-1])
                        continue;
                    if(array[m][n] <= array[m][n-1])
                        continue;
                    if(array[m][n] <= array[m+1][n-1])
                        continue;
                    if(array[m][n] <= array[m-1][n])
                        continue;
                    if(array[m][n] < array[m+1][n])
                        continue;
                    if(array[m][n] < array[m-1][n+1])
                        continue;
                    if(array[m][n] < array[m][n+1])
                        continue;
                    if(array[m][n] < array[m+1][n+1])
                        continue;
                    
                    nextcoord.TX = m;

                    nextcoord.RX = n;

                    return nextcoord;
               }
           }
   }


   return nextcoord;
}


void PRINTTHREE(int **array, COORDINATE coord)
{
    int m , n;

    printf("coordinate:[%d, %d] \n",coord.TX, coord.RX);

    for(m=coord.TX-1;m<coord.TX+2;m++)
    {
        for(n=coord.RX-1;n<coord.RX+2;n++)
        {
            printf("%4d ", array[m][n]);
        }
        
        printf("\n");
    }
    
}


void FindMatrix(int **array, int width, int height, int COMP)
{
    const COORDINATE fixcoord = {1, 0};

    COORDINATE nextcoord = {1, 0};

    while(1) 
    {
       nextcoord = Findnextcoord(array, width, height, nextcoord, COMP); 
    
       if(EQUALCOORD(nextcoord, fixcoord) == true)
       {
            break;
       }

       PRINTTHREE(array, nextcoord);

       printf("\n");
    }
}

void FindTHREE_ARRAY(THREE_ARRAY* file, int COMP)
{
   int i = 0;

  for(i=0; i<file->FrameCount; i++)
  {
      printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

      printf("the %d Frame\n",i);

      FindMatrix(file->array[i], file->Width, file->Height, COMP);
  } 

}


static void freearray(int ***array, int framecount, int width)
{
    int i , m;

    for(i=0; i<framecount; i++)
    {
        for(m=0; m<width; m++)
        {
            free(array[i][m]);
        }
    }


    for(i=0; i<framecount; i++)
    {
        free(array[i]);
    }


    free(array);

    array = NULL;
}


void FREE(THREE_ARRAY *file)
{
    freearray(file->array, file->FrameCount, file->Width);

    free(file);

    file = NULL;
}

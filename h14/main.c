#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
int main(int argc, const char * argv[])
{

    /*
    char line[MAX];

    char *result = NULL;

    THREE_ARRAY file;

    FILE *fptr;

    fptr = fopen("test.csv","r");

    if(fptr != NULL)
    {
        printf("opening the file is successful!\n");


//>>>>>>>>>>>>>>>get the simple information>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.
        //>>>get name;
        fgets(line,MAX,fptr);

        line[strlen(line)-1] = '\0';

        strcpy(file.File_NAME, line);


        //>>get FrameCount

        fgets(line,MAX,fptr);

        result = strtok(line, ",");

        result = strtok(NULL, ",");

        file.FrameCount = atoi(result);

        //>>get  witch
        fgets(line,MAX,fptr);

        result = strtok(line, ",");

        result = strtok(NULL, ",");

        file.Width = atoi(result);

        //>>get height
        fgets(line,MAX,fptr);

        result = strtok(line, ",");

        result = strtok(NULL, ",");

        file.Height = atoi(result);

        //>>get type
        fgets(line,MAX,fptr);

        result = strtok(line, ",");

        result = strtok(NULL, ",");

        result[strlen(result)-1] = '\0';

        strcpy(file.type, result);

//>>>>>>>>>>>>>>>end of get the simple information >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        printf("%s\n",file.File_NAME);

        printf("%d\n",file.FrameCount);

        printf("%d\n",file.Width);

        printf("%d\n",file.Height);

        printf("%s\n",file.type);

        unsigned short int i, m, n;

        i = 0;

        m = 0;

        n = 0;

        file.array = Malloc(file.FrameCount, file.Width, file.Height);





        // get the demension 3 Matrix
        while(i<file.FrameCount)
        {
            //remove block and first label for every matrix 
            do
            {
                fgets(line, MAX, fptr);

//                printf("line:%s",line);

            } while(strcmp(line, "\n") == 0);

            // load the 2-matrix data
            for(m=0; m<file.Width; m++)
            {
                fgets(line, MAX, fptr);

//                printf("%s>>",line);
                result = strtok(line, ",");

                for(n=0; n<file.Height; n++)
                {



                    file.array[i][m][n] = atoi(result);

//                    printf("%d ",file.array[i][m][n]);
  //                  printf("y");
                    result = strtok(NULL, ",");
                }
            }

            i++;
        }

    printf("\n");


    }
*/
    THREE_ARRAY *file =  load_csv("test.csv");

    if(strcmp(argv[1], "-fr") == 0)
    {
        PRINTARRAY(atoi(argv[2]), file);
    }
   // PRINTARRAY(0,file);


    return 0;
}

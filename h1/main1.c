#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 120

int main(void)
{
    FILE *fptr;

    FILE *fptr1;

    char ch;

    //using '\0' .then you don't worry about the cover probelm;
    char str[MAX], str1[MAX];

    int count = 0 ,i = 0, index = 0;

    /* fptr = fopen("teplate.h", "r"); */

    fptr = fopen("template.h", "r");

    fptr1 =fopen("out.txt", "w");

    if(fptr != NULL)
    {
        printf("opening the file is succesuful!\n");

            while(fgets(str, MAX, fptr) != NULL)
            {
                // here show the  all word in this file
                //printf("%s",str);

                // here is analysis how to chosen


            if(str[0] =='/' && str[1] =='/' && str[2] == ' ')
            {
                printf("[%d]%s",count,str+3);

                // trans number into string
                sprintf(str1,"[%d]", count++);


                strcat(str1,str+3);

                fwrite(str1, sizeof(char), strlen(str1), fptr1);

            }

            }



        fclose(fptr);

        fclose(fptr1);
    }

    else
    {
        printf("error\n");
    }
    return 0;
}

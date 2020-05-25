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

    int count = 0 ,i = 0, deter = 0;

    int first = 0 ,second = 0;

    /* fptr = fopen("teplate.h", "r"); */

    fptr = fopen("template.h", "r");

    fptr1 =fopen("out.txt", "w");

    if(fptr != NULL)
    {
        printf("opening the file is succesuful!\n");

        while(fgets(str, MAX, fptr) != NULL)
        {
/*            // here show the  all word in this file
            printf("%s",str);

            // here is analysis how to chosen

            //br careful put str1 ='';
            strcpy(str1, "");

            if(str[0] =='/' && str[1] =='/' && str[2] == '#')
            {
                printf("%s",str+10);

                // trans number into string

                strcat(str1,str+10);

                fwrite(str1, sizeof(char), strlen(str1), fptr1);

            }
*/
            i = 0;

            count = 0;

            deter = 0;

            first = 0;

            second = 0;

            while(str[i] != '\0')
            {
                //previous step and  word region
                if(deter == 0)
                {
                    if(str[i] !=' ')
                    {
                        i++;
                    }

                    else
                    {
                        deter=1;

                        count++;

                        i++;
                    }
                }

                // black region
                else
                {
                    if(str[i] == ' ')
                    {
                        i++;
                    }

                    else
                    {
                        deter = 0;

                        if(count == 1)
                        {
                            first = i;
                        }

                        else
                        {
                            second = i;
                        }

                        i++;
                    }
                }

            }

            //printf("%d,%d,%d:%s", count, first, second, str);
            strcpy(str1, "");

            strcat(str1, str+first);

            if((count == 1)&&(str[2]!=' '))
            {
                printf("%s", str+first);

                fwrite(str1 ,sizeof(char), strlen(str1), fptr1);
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

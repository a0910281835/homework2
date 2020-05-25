#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#define MAX 120

int main(void)
{

tree file;

initaltree(&file);
if(file.head->NEXT==file.tail)
    printf("ya\n");

pushQ(&file, "js");



printf("%s\n",file.tail->PREV->I_NAME);

if(file.head->NEXT!=file.tail)
    printf("ya\n");
pushnodeinleft(&file, "yes" ,true);

printf("%s:%d:%d\n",file.tail->PREV->leftend->prev->NAME,file.tail->PREV->leftend->prev->type, file.tail->PREV->leftend->prev->value);


pushnodeinleft(&file, "hello" ,true);

printf("%s:%d:%d\n",file.tail->PREV->leftend->prev->NAME,file.tail->PREV->leftend->prev->type, file.tail->PREV->leftend->prev->value);

pushnodeinright(&file, "no", false, 20);

printf("%s:%d:%d\n",file.tail->PREV->rightend->prev->NAME,file.tail->PREV->rightend->prev->type, file.tail->PREV->rightend->prev->value);

pushnodeinright(&file, "fuck", false, 24);

printf("%s:%d:%d\n",file.tail->PREV->rightend->prev->NAME,file.tail->PREV->rightend->prev->type, file.tail->PREV->rightend->prev->value);
printitemnode(file.tail->PREV);


PRINTFILE(&file);

/*
    FILE *fptr;

    FILE *fptr1;

    char ch;

    //using '\0' .then you don't worry about the cover probelm;
    char str[MAX], str1[MAX];

    int count = 0 ,i = 0, deter = 0;

    int first = 0 ,second = 0 , endmed = 0;

    fptr = fopen("teplate.h", "r");

  //  fptr = fopen("template.h", "r");

    fptr1 =fopen("out.txt", "w");

    if(fptr != NULL)
    {
        printf("opening the file is succesuful!\n");

        while(fgets(str, MAX, fptr) != NULL)
        {
            i = 0;

            count = 0;

            deter = 0;

            first = 0;

            second = 0;

            endmed = 0;

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

                        if(count == 2)
                        {
                            endmed = i;
                        }
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

                        //record where start.
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


            if((count == 2))
            {
                str[endmed]='\n';

                str[endmed+1]='\0';

                printf("%s", str+first);

                strcat(str1, str+first);

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
*/
    return 0;
}

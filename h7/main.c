#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include <unistd.h>
#define MAX 120

int main(int argc, const char *argv[])
{

/*

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

//freenode(file.tail->PREV);
FREE(&file);

if(file.tail ==NULL)
{
    printf("succssful for left free");
}
*/

    tree file;

    initaltree(&file);

    FILE *fptr;

    FILE *fptr1;

    char ch;

    //using '\0' .then you don't worry about the cover probelm;
    char str[MAX], str1[MAX];

    int count = 0 , deter = 0;

    unsigned int i = 0;

    int first = 0 ,second = 0 , endmed = 0;

    bool type;

    unsigned int value = 0;

    if(strcmp(argv[1], "--help") == 0)
    {
        showfunction();

        exit(-1);
    }

    int have = access("config.h",0);


    if((strcmp(argv[1], "-set") == 0 || strcmp(argv[1], "-i") == 0)&& ~have)
    {
        fptr =fopen("config.h","r");
    }

    else if(strcmp(argv[1], "-set") == 0 || strcmp(argv[1], "-i") == 0)
   {
        fptr = fopen("template.h", "r");
   }

   else
    {
        printf("it's wrong\n");

        exit(-1);
    }




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

          //  printf("%d,%d,%d:%s", count, first, second, str);

            // item and str='/' avoid the array in last
            if((count==1)&&(str[2] ==' ')&&str[0] == '/')
            {
                i = strlen(str);
               // printf("%d:%s", i, str+3);
                str[i-1] = '\0';

                pushQ(&file, str+3);
            }

            //open and close
            if((count == 1)&&(str[2]!=' '))
            {

          //      printf("%s", str+first);

                //avoid the '\n'
                str[strlen(str)-1]='\0';
                //open is true
                if(str[0] == '#')
                {
                    type = true;
                }

                else
                {
                    type =false;
                }

                pushnodeinleft(&file, str+first, type);

            }

            if((count == 2))
            {
//                str[endmed]='\n';

//                str[endmed+1]='\0';


                //determine it's Hexadecimal or decimal.then  using strol get the number

               if(str[second] == '0' &&str[second+1] == 'x')
               {
                   type = true;

                   value = strtol(str+second, NULL, 16);
               }

               else
               {
                    type = false;

                    value = strtol(str+second, NULL, 10);
               }

               str[endmed] = '\0';

               pushnodeinright(&file, str+first, type, value);

               //printf("%s %d\n", str+first, value);

            }

        }

       // printf(">>>>>>>\n");

 //      PRINTFILE(&file);

        fclose(fptr);


        itemnode* tempitem = NULL;

        subnode* tempsub = NULL;


    if(argv[2] == NULL)
    {
        printf("the parameter is not enough\n");

        FREE(&file);

        exit(-1);
    }


        //function shell


    // check the argv[2] is word or number

    bool first_check = analysis_word_num(argv[2]);

                                        //true change first_check
    tempitem =  finditem(&file, argv[2], first_check);


    if(strcmp(argv[1], "-i") == 0)
    {
        if(argv[3] == NULL)
        {
            printitemnode(tempitem);
        }

        else if(strcmp(argv[3], "-s") == 0)
        {
            printitemnodeleft(tempitem);
        }

        else if(strcmp(argv[3], "-p") == 0)
        {
            printitemnoderight(tempitem);
        }

        else
        {
            printf("input is wrong\n");

            FREE(&file);

            exit(-1);
        }
    }

    else if(strcmp(argv[1], "-set") == 0)
    {
        // check the second_term
        bool second_check =analysis_word_num(argv[4]);

        bool direction;


        if(strcmp(argv[3], "-s") == 0)
        {
            direction = true;
        }

        else if(strcmp(argv[3], "-p") == 0)
        {
            direction = false;
        }

        else
        {
            printf("you are wrongi\n");

            FREE(&file);

            exit(-1);
        }

        fptr1 =fopen("config.h", "w");

        tempsub = findsub(tempitem, argv[4], direction, second_check);

        modification(tempsub, direction , argv[5]);

        fwritefile(&file,fptr1);

        fclose(fptr1);
    }



        FREE(&file);


    }

    else
    {
        printf("error\n");
    }


    return 0;
}

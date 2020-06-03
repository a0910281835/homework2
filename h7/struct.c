#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"


void showfunction(void)
{
    printf(" -i [index/item_NAME] \t\t\t\t\t diaplay the content of item in this file\n");

    printf(" -i [index/item_NAME] -s \t\t\t\t diaplay the switch of item in this file\n");

    printf(" -i [index/item_NAME] -p \t\t\t\t diaplay the parameter of item in this file\n");

    printf(" -set [index/item] -s [switch name/index] [write status] \n modify the switch from  current status , where write status is 0 or 1 (0 is close and 1 is open),\n then output a new file whose name is config.h \t\t \n");

}

// initalizataion for queue type


void initaltree(tree * file)
{
    file->itemnumber = 0;

    file->head = (itemnode*) malloc(sizeof(itemnode));

    file->tail = (itemnode*) malloc(sizeof(itemnode));

    file->head->NEXT = file->tail;

    file->tail->PREV = file->head;

    file->head->PREV = NULL;

    file->tail->NEXT = NULL;
}


void pushQ(tree * file, char str[MAX])
{
    itemnode* tempitem = (itemnode*) malloc(sizeof(itemnode));

    initalitem(tempitem);

    strcpy(tempitem->I_NAME, str);

    tempitem->PREV = file->tail->PREV; //connect previous

    tempitem->PREV->NEXT= tempitem;   // let previous ptr current

    file->tail->PREV = tempitem;     //connect tial

    tempitem->NEXT = file->tail;

    tempitem->leftnumber = 0;

    tempitem->rightnumber = 0;

    tempitem->index = file->itemnumber++;

    //tempitem have been inserted

}



void initalitem(itemnode *tempitem)
{
    tempitem->index = 0;

    tempitem->leftnumber = 0;

    tempitem->rightnumber = 0;

    strcpy(tempitem->I_NAME, "");

    tempitem->NEXT = NULL;

    tempitem->PREV = NULL;

    tempitem->leftstart = (subnode*) malloc(sizeof(subnode));

    tempitem->leftend = (subnode*) malloc(sizeof(subnode));

    tempitem->leftstart->next = tempitem->leftend;

    tempitem->leftend->prev = tempitem->leftstart;

    tempitem->leftstart->prev = NULL;

    tempitem->leftend->next = NULL;

    tempitem->rightstart = (subnode*) malloc(sizeof(subnode));

    tempitem->rightend = (subnode*) malloc(sizeof(subnode));

    tempitem->rightstart->next = tempitem->rightend;

    tempitem->rightend->prev = tempitem->rightstart;

    tempitem->rightstart->prev = NULL;

    tempitem->rightend->next = NULL;
}


void pushnodeinleft(tree *file, char str[MAX], bool type, unsigned short int pcount)
{

    // avoid there has no itemnode
    if(file->head->NEXT == file->tail)
    {
        return;
    }

    subnode* tempsub =(subnode*) malloc(sizeof(subnode));

    strcpy(tempsub->NAME, str);

    tempsub->type = type;

    tempsub->value = 0;

    tempsub->pindex = pcount;

    // execute the pushleft; and we insert the last itemnode
    subnode* last = file->tail->PREV->leftend;

    tempsub->prev = last->prev;

    tempsub->prev->next = tempsub;

    last->prev = tempsub;

    tempsub->next = last;

    file->tail->PREV->leftnumber++;

    tempsub = NULL;
}

void pushnodeinright(tree *file, char str[MAX], bool type, unsigned int value, unsigned short int pcount)
{

    if(file->head->NEXT == file->tail)
    {
        return;
    }

    subnode* tempsub =(subnode*) malloc(sizeof(subnode));

    strcpy(tempsub->NAME, str);

    tempsub->type = type;

    tempsub->value = value;

    tempsub->pindex = pcount;

    // execute the pushrightt;
    subnode* last = file->tail->PREV->rightend;

    tempsub->prev = last->prev;

    tempsub->prev->next = tempsub;

    last->prev = tempsub;

    tempsub->next = last;

    file->tail->PREV->rightnumber++;

    tempsub = NULL;
}

// only print one itemnode with his all subnode
void printitemnode(itemnode *tempitem)
{
    printf("[%d]%s:\n", tempitem->index, tempitem->I_NAME);
    printf("<Swithch: num = %d>\n", tempitem->leftnumber);

    subnode *tempsub = tempitem->leftstart->next;

    int count = 0;
    // in future ,you can change the loop by leftnumber
   while(tempsub !=tempitem->leftend)
   {
       printf("->[%d]%s %d and order:%d\n",count++, tempsub->NAME, tempsub->value, tempsub->pindex);

       tempsub = tempsub->next;
   }

   count = 0;

   tempsub = tempitem->rightstart->next;

   printf("<Para: num = %d>\n", tempitem->rightnumber);

   while(tempsub != tempitem->rightend)
   {
       if(tempsub->type == true)
       {
            printf("=>[%d]%s 0x%04x and order:%d\n",count++, tempsub->NAME, tempsub->value, tempsub->pindex);
       }

       else
       {
            printf("=>[%d]%s %d and order:%d\n",count++, tempsub->NAME, tempsub->value,tempsub->pindex);
        }

      tempsub = tempsub->next;
   }

   tempsub = NULL;
}


// only print one itemnode with his all subnode
void printitemnodeleft(itemnode *tempitem)
{
    printf("[%d]%s:\n", tempitem->index, tempitem->I_NAME);

    printf("<Swithch: num = %d>\n", tempitem->leftnumber);

    subnode *tempsub = tempitem->leftstart->next;

    int count = 0;
    // in future ,you can change the loop by leftnumber
    while(tempsub !=tempitem->leftend)
    {
        printf("->[%d]%s %d and order:%d\n",count++, tempsub->NAME, tempsub->value,tempsub->pindex);

        tempsub = tempsub->next;
    }

    tempsub = NULL;
}


// only print one itemnode with his all subnode
void printitemnoderight(itemnode *tempitem)
{

    printf("[%d]%s:\n", tempitem->index, tempitem->I_NAME);

    printf("<Para: num = %d>\n", tempitem->rightnumber);

    int count = 0;

    subnode *tempsub = tempitem->rightstart->next;


   while(tempsub != tempitem->rightend)
   {
       if(tempsub->type == true)
       {
            printf("=>[%d]%s 0x%04x and order:%d\n",count++, tempsub->NAME, tempsub->value, tempsub->pindex);
       }

       else
       {
            printf("=>[%d]%s %d and order:%d\n",count++, tempsub->NAME, tempsub->value, tempsub->pindex);
        }

      tempsub = tempsub->next;
   }

   tempsub = NULL;
}


//print one file with his all itemnode
void PRINTFILE(tree *file)
{

    printf("all item number = %d\n",file->itemnumber);
    itemnode* tempitem = file->head->NEXT;

    while(tempitem != file->tail)
    {
        printitemnode(tempitem);

        tempitem = tempitem->NEXT;
    }

    tempitem = NULL;
}


void freenode(itemnode *tempitem)
{
    subnode * tempsub = tempitem->leftstart->next;

    // free all lefsubnode except leftstart and leftend
    while(tempsub != tempitem->leftend)
    {
        tempitem->leftstart->next = tempsub->next;//(1) and (2)

        tempsub->next->prev = tempitem->leftstart;//(3) and (4)

        tempsub->next = NULL;

        tempsub->prev = NULL;

        free(tempsub);

        tempsub =tempitem->leftstart->next;
    }

    // leftstart and leftend
    tempitem->leftend->prev = NULL;

    tempitem->leftstart->next = NULL;

    free(tempitem->leftend);

    free(tempitem->leftstart);

    tempitem->leftstart = NULL;

    tempitem->leftend = NULL;
//>>>>>>>>>>>>>>>>>>>>>>>>>>spilt >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//

    tempsub = tempitem->rightstart->next;

    // free all rightsubnode except rightstart and rightend
    while(tempsub != tempitem->rightend)
    {
        tempitem->rightstart->next = tempsub->next;//(1) and (2)

        tempsub->next->prev = tempitem->rightstart;//(3) and (4)

        tempsub->next = NULL;

        tempsub->prev = NULL;

        free(tempsub);

        tempsub =tempitem->rightstart->next;
    }

    // rightstart and rightend
    tempitem->rightend->prev = NULL;

    tempitem->rightstart->next = NULL;

    free(tempitem->rightend);

    free(tempitem->rightstart);

    tempitem->rightstart = NULL;

    tempitem->rightend = NULL;

    tempsub = NULL;
}


void FREE(tree * file)
{
    itemnode *tempitem = file->head->NEXT;

    while(tempitem != file->tail)
    {
        file->head->NEXT = tempitem->NEXT;

        tempitem->NEXT->PREV = file->head;

        tempitem->NEXT = NULL;

        tempitem->PREV = NULL;

        //release tempitem all subnode
        freenode(tempitem);

        free(tempitem);

        tempitem = file->head->NEXT;
    }

    tempitem = NULL;

    file->head->NEXT = NULL;

    file->tail->PREV = NULL;

    free(file->head);

    free(file->tail);

    file->head = NULL;

    file->tail = NULL;
}

bool analysis_word_num(const char *str)
{
    if(str == NULL)
    {
        printf("NO word");

        exit(-1);
    }
        int i;

        if(48 <= str[0] && str[0] <= 57)
        {
            //determine all is number
            for(i=1; i<strlen(str); i++)
            {
                 if(48>str[i] || str[i]>57)
                 {
                     printf("your input is false, and it's not number");
                 }

            }

            return false;
        }

        else
        {

            return true;

        }

}


itemnode* finditem(tree *file, const char *str , bool type)
{
    itemnode *tempitem = file->head->NEXT;

    unsigned int index = 0, i = 0;

    if(type == false)
    {
        index = atoi(str);

        if(index<0 || index >= file->itemnumber)
        {
            printf("the index is over!\n");

            exit(-1);
        }

        for(i=0 ;i<index; i++)
        {
            tempitem = tempitem->NEXT;
        }

        return tempitem;
    }


    else
    {
        while(tempitem != file->tail)
        {
            // string compare with strcmp because string the first is address
            if(strcmp(str, tempitem->I_NAME) == 0)
            {
                break;
            }

            tempitem = tempitem->NEXT;
        }

        if(tempitem == file->tail)
        {
            printf("the string can't be founded in item-list!\n");

            exit(-1);
        }

        return tempitem;
    }
}


//type =yes => word,  type=false =>number
subnode* findsub(itemnode* tempitem, const char *str , bool direction,  bool type)
{

    unsigned int index = 0, i = 0;
    //left
    if(direction == true)
    {
        subnode* tempsub = tempitem->leftstart->next;

        if(type == false)
        {
            index = atoi(str);

            if(index<0 || index >= tempitem->leftnumber)
            {
                printf("the index is over!\n");

                exit(-1);
            }

            for(i=0 ;i<index; i++)
            {
                tempsub = tempsub->next;
            }

            return tempsub;
        }


        else
        {
            while(tempsub != tempitem->leftend)
            {
                // string compare with strcmp because string the first is address
                if(strcmp(str, tempsub->NAME) == 0)
                {
                    break;
                }

                tempsub = tempsub->next;
            }

            if(tempsub == tempitem->leftend)
            {
                printf("the string can't be founded in subnode-list!\n");

                exit(-1);
            }

            return tempsub;
        }
    }

    else
    {
        subnode* tempsub = tempitem->rightstart->next;

        if(type == false)
        {
            index = atoi(str);

            if(index<0 || index >= tempitem->rightnumber)
            {
                printf("the index is over!\n");

                exit(-1);
            }

            for(i=0 ;i<index; i++)
            {
                tempsub = tempsub->next;
            }

            return tempsub;
        }


        else
        {
            while(tempsub != tempitem->rightend)
            {
                // string compare with strcmp because string the first is address
                if(strcmp(str, tempsub->NAME) == 0)
                {
                    break;
                }

                tempsub = tempsub->next;
            }

            if(tempsub == tempitem->rightend)
            {
                printf("the string can't be founded in subnode-list!\n");

                exit(-1);
            }

            return tempsub;
        }
    }
}

void modification(subnode * tempsub, bool direction , const char* strval)
{
    unsigned int val = 0 ;

    //subnode is switch-left
    if(direction == true)
    {
        val = atoi(strval);

        bool type = val;

        tempsub->type = type;
    }

    else
    {
        if (strval[0] == '0' &&strval[1] == 'x')
        {
            tempsub->type = true;

            tempsub->value = strtol(strval, NULL, 16);
        }

        else
        {
            tempsub->type = false;

            tempsub->value = strtol(strval, NULL, 10);
        }

    }
}


void fwritesub(subnode* tempsub, FILE *fptr, bool type)
{
    char str[MAX];

    char str1[20];

    //leftnode
    if(type == true)
    {

        if(tempsub->type == true)
        {
            strcpy(str,"#define ");

            strcat(str, tempsub->NAME);

            strcat(str, "\n");

            fwrite(str, sizeof(char), strlen(str), fptr);


        }

        else
        {
            strcpy(str,"//#define ");

            strcat(str ,tempsub->NAME);

            strcat(str, "\n");

            fwrite(str, sizeof(char), strlen(str), fptr);

        }

    }

    // rightnode
    else
    {

       if(tempsub->type == true)
       {
            strcpy(str,"#define ");

            strcat(str, tempsub->NAME);

            strcat(str, " 0x");

            sprintf(str1,"%x",tempsub->value);

            strcat(str, str1);

            strcat(str, "\n");

            fwrite(str, sizeof(char), strlen(str), fptr);

       }
       else
       {
            strcpy(str,"#define ");

            strcat(str, tempsub->NAME);

            strcat(str, " ");

            sprintf(str1,"%d",tempsub->value);

            strcat(str, str1);

            strcat(str, "\n");

            fwrite(str, sizeof(char), strlen(str), fptr);

       }
    }

}



void fwriteitem(itemnode* tempitem, FILE *fptr)
{
    char str[MAX];

 //   char str1[20];

    strcpy(str, "//-----------------------------------\n");


    fwrite(str, sizeof(char), strlen(str), fptr);

    strcpy(str,  "// ");

    strcat(str, tempitem->I_NAME);

    strcat(str,"\n");

    fwrite(str,sizeof(char), strlen(str), fptr);

    strcpy(str, "//-----------------------------------\n");

    fwrite(str, sizeof(char), strlen(str), fptr);

    // following below is write left then write right.
    subnode *tempsubleft = tempitem->leftstart->next;

    subnode *tempsubright = tempitem->rightstart->next;

    while((tempsubleft != tempitem->leftend)&&(tempsubright !=tempitem->rightend))
    {
        //switch is open
        if((tempsubleft->pindex) < (tempsubright->pindex))
        {
            fwritesub(tempsubleft, fptr, true);

            tempsubleft = tempsubleft->next;
        }

        else
        {
            fwritesub(tempsubright, fptr, false);

            tempsubright = tempsubright->next;
        }

    }


    while(tempsubleft != tempitem->leftend)
    {
            fwritesub(tempsubleft, fptr, true);

            tempsubleft = tempsubleft->next;
    }

    while(tempsubright != tempitem->rightend)
    {
            fwritesub(tempsubright, fptr, true);

            tempsubright = tempsubright->next;
    }

    tempsubleft = NULL;

    tempsubright = NULL;
}


void fwritefile(tree *file, FILE *fptr)
{
    itemnode *tempitem = file->head->NEXT;

    while(tempitem != file->tail)
    {
        fwriteitem(tempitem, fptr);

        tempitem = tempitem->NEXT;
    }

    tempitem = NULL;
}

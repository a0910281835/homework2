#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

// initalizataion for queue type


void initaltree(tree * file)
{
    (file)->head = (itemnode*) malloc(sizeof(itemnode));

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


}



void initalitem(itemnode *tempitem)
{
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


void pushnodeinleft(tree *file, char str[MAX], bool type)
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

    // execute the pushleft; and we insert the last itemnode
    subnode* last = file->tail->PREV->leftend;

    tempsub->prev = last->prev;

    tempsub->prev->next = tempsub;

    last->prev = tempsub;

    tempsub->next = last;

}

void pushnodeinright(tree *file, char str[MAX], bool type, unsigned int value)
{

    if(file->head->NEXT == file->tail)
    {
        return;
    }

    subnode* tempsub =(subnode*) malloc(sizeof(subnode));

    strcpy(tempsub->NAME, str);

    tempsub->type = type;

    tempsub->value = value;
    // execute the pushrightt;
    subnode* last = file->tail->PREV->rightend;

    tempsub->prev = last->prev;

    tempsub->prev->next = tempsub;

    last->prev = tempsub;

    tempsub->next = last;

}

// only print one itemnode with his all subnode
void printitemnode(itemnode *tempitem)
{
    printf("%s", tempitem->I_NAME);
    printf("Swithch:\n");

    subnode *tempsub = tempitem->leftstart->next;

    int count = 0;
   while(tempsub !=tempitem->leftend)
   {
       printf("->[%d]%s %d\n",count++, tempsub->NAME, tempsub->value);

       tempsub = tempsub->next;
   }

   count = 0;

   tempsub = tempitem->rightstart->next;

   printf("Para:\n");

   while(tempsub != tempitem->rightend)
   {
       if(tempsub->type == true)
       {
            printf("=>[%d]%s 0x%x\n",count++, tempsub->NAME, tempsub->value);
       }

       else
       {
            printf("=>[%d]%s %d\n",count++, tempsub->NAME, tempsub->value);
        }

      tempsub = tempsub->next;
   }
}

//print one file with his all itemnode
void PRINTFILE(tree *file)
{
    int count=0;

    itemnode* tempitem = file->head->NEXT;

    while(tempitem != file->tail)
    {
        printf("[%d]",count++);

        printitemnode(tempitem);

        tempitem = tempitem->NEXT;
    }
}

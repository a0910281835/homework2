#ifndef STRUCT_H
#define STRUCT_H
#include <stdbool.h>
#define MAX 120

//>>>>  struct  >>>>>>

typedef struct subnode{

    char NAME[MAX];

    unsigned int value;
    
    //record ox or de
    bool type;

    struct subnode * next;

    struct subnode * prev;

} subnode;

typedef struct itemnode{

    char I_NAME[MAX];
    
    subnode * leftstart;

    subnode * leftend;

    subnode * rightstart;    

    subnode * rightend;

    struct itemnode * NEXT;

    struct itemnode * PREV;

} itemnode;



typedef struct tree{

    itemnode * head;

    itemnode * tail;

} tree;


//>>>>>> function>>>>.


void initaltree(tree * file);

void pushQ(tree* file, char str[MAX]);


void initalitem(itemnode *tempitem);


void pushnodeinleft(tree *file,char str[MAX], bool type);

void pushnodeinright(tree *file,char str[MAX], bool type, unsigned int value);

void printitemnode(itemnode *tempitem);

void PRINTFILE(tree *file);
#endif

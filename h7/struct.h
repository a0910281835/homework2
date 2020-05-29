#ifndef STRUCT_H
#define STRUCT_H
#include <stdbool.h>
#define MAX 120

//>>>>  struct  >>>>>>

typedef struct subnode{

    char NAME[MAX];

    unsigned int value;

    //record ox or decemail
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

    unsigned short int leftnumber;

    unsigned short int rightnumber;

    unsigned short int index;

} itemnode;



typedef struct tree{

    itemnode * head;

    itemnode * tail;

    unsigned short int itemnumber;

} tree;


//>>>>>> function>>>>.


void initaltree(tree * file);

void pushQ(tree* file, char str[MAX]);


void initalitem(itemnode *tempitem);


void pushnodeinleft(tree *file,char str[MAX], bool type);

void pushnodeinright(tree *file,char str[MAX], bool type, unsigned int value);

void printitemnode(itemnode *tempitem);

void printitemnoderight(itemnode *tempitem);

void printitemnodeleft(itemnode *tempitem);

void PRINTFILE(tree *file);

void freenode(itemnode *tempitem);

void FREE(tree * file);

bool analysis_word_num(const char *str);

itemnode* finditem(tree *file, const char *str , bool type);

subnode* findsub(itemnode* tempitem, const char *str , bool direction,  bool type);

#endif

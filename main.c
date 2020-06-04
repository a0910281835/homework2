#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/io.h>
#include <unistd.h>
void string(const char *str)
{
    printf("%c",str[1]);
}

int main(int argc, const char * argv[])
{

    typedef struct COOR{

        int x;

        int y;
    } COOR;

    char ch[20] = "015";

    char str[20];

    unsigned int value = atoi(ch);

    bool type ;


    type = value;

    printf("%d\n",value);

    printf("%d\n",type);


    sprintf(str,"%x",value);

    /* printf("%s\n",str); */


    printf("%d\n",value);

    int have = access("out.txt",0);

    printf("haveor no %d\n",~have);


    printf(">>>>>>>>>\n");



 unsigned int k=3;
    printf("%d\n",-10/k);



    k=(3>2);

    value =(4>5);

    printf("%d",(4>5));
    if(k&value)
    {
        printf("and");

    }

    if(k|value)
    {
        printf("or");
    }


 int i;
    for(i=0;i<5;i++)
    {
        if(i==2)
            continue;
        printf("%d\n",i);
    }

    COOR coor = {2,3};

    COOR coor1 ={2,4};

    if(coor == coor1)
    {
        printf("that are equal!\n");
    }




    return 0;
}


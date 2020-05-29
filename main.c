#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void string(const char *str)
{
    printf("%c",str[1]);
}

int main(int argc, const char * argv[])
{

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
    return 0;
}


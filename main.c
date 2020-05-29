#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void string(const char *str)
{
    printf("%c",str[1]);
}

int main(int argc, const char * argv[])
{

    char ch[20] = "015";

   unsigned short int k = strtol(ch, NULL,16);

   int n = k;
    printf("%d\n",n);


    printf("0x%x\n",n);

    printf("%c\n",argv[1][2]);

    printf("%lu\n",strlen(argv[1]));


    if(strcmp(argv[1],"ILO") == 0)
    {
        printf("yes\n");
    }

    if(argv[2] == NULL)
    {
        printf("no have argv[2]\n");
    }

    string(argv[1]);


    return 0;
}


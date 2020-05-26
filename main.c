#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main(int argc, const char * argv[])
{

    char ch[20] = "015";

   unsigned  int n = strtol(ch, NULL,16);

    printf("%d\n",n);


    printf("0x%x\n",n);
    return 0;
}


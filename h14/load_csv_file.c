#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{

    char str[100] = ",,";
    char term[] = ",";

    char* result = NULL;

    result = strtok(str,term);

    if(result == NULL)
    {
        printf("ya");
    }

    result = strtok(str,term);

    if(result == NULL)
    {
        printf("ya");
    }

    result = strtok(str,term);

    if(result == NULL)
    {
        printf("ya");
    }


//      printf("%s\n",result);

  //  result = strtok(NULL,term);

  //  printf("%s\n",result);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>
int main(int argc, const char * argv[])
{

    bool bo=true;
    char ch='a';
    int i=2;
    printf("%zu %zu %zu\n",sizeof(bo),sizeof(ch),sizeof(i));
    return 0;
}


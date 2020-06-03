#ifndef STRUCT_H
#define STRUCT_H
#define MAX 500

typedef struct THREE_ARRAY{

    char  File_NAME[MAX];

    unsigned int FrameCount;

    unsigned int Width;

    unsigned int Height;

    char type[MAX];

    int ***array;

} THREE_ARRAY;



THREE_ARRAY* load_csv(const char* str);

int *** Malloc(unsigned int framecount, unsigned int widt ,unsigned int height);

void PRINTARRAY(unsigned int num, THREE_ARRAY* file);

#endif

#ifndef STRUCT_H
#define STRUCT_H
#define MAX 500

typedef struct THREE_ARRAY{

    char  File_NAME[MAX];

    int FrameCount;

    int Width;

    int Height;

    char type[MAX];

    int ***array;

} THREE_ARRAY;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.
typedef struct COORDINATE{

    unsigned short int RX;

    unsigned short int TX;

} COORDINATE;

// compare two coordinate whether they are equal.
bool EQUALCOORD( const COORDINATE coord1, const COORDINATE coord2);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




//load the data_file from some folder
THREE_ARRAY* load_csv(const char* str);

// memollary allocate for 3-demension matrix.
int *** Malloc(int framecount, int widt ,int height);

//display the special Frame(num)  to 2-matrix
void PRINTARRAY(unsigned int num, THREE_ARRAY* file);

// get  raw -diff for average three-demension array.
THREE_ARRAY* GetR_from_D(THREE_ARRAY *file);

//display the  3*3 matrix
void PRINTTHREE(int **array, COORDINATE coord);

//from previous point to find next point.
COORDINATE Findnextcoord(int **array, int width, int height, COORDINATE coord, int COMP);

//find a frame's all 3*3 matrix
void FindMatrix(int **array, int width, int height, int COMP);

//find all frame's matrix
void FindTHREE_ARRAY(THREE_ARRAY* file, int COMP);

static void freearray(int ***array, int framecount, int width);

void FREE(THREE_ARRAY *file);

#endif

#include "define.h"

/*
N S E W C coding

0 - Empty
1 - Wall
2 - Can
*/

struct matrix
{
	int grid[MAT_SIZE][MAT_SIZE];
};

void populateMat(int density,struct matrix *G); //density 0 to 9
void printMat(struct matrix *G);
void sitCode(int i, int j, int arr[], struct matrix *G);	// return situation code of i,j box

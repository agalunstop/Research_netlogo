#include <stdio.h>
#include <stdlib.h>
#include "env.h"
/*
N S E W C coding

0 - Empty
1 - Wall
2 - Can
*/

void populateMat(int density,struct matrix *G)
{
	for (int i=0; i<MAT_SIZE; i++)
	{
		for (int j=0; j<MAT_SIZE; j++)
		{
			if((rand() % 10) < density)
				G->grid[i][j] = 1;
			else
				G->grid[i][j] = 0;
		}
	}
	
}

void sitCode(int i, int j, int arr[], struct matrix *G)
{
	int code = 0;
	//current
	if(G->grid[i][j]==1)	//can
	{
		code+=2*(3^0);
		arr[0] = 2;
	}			

	//west
	if(j==0)			// first column; wall
	{
		code+=1*(3^1);
		arr[1]=1;
	}
	else if(G->grid[i][j-1]==1);	//can
	{
		code+=2*(3^1);
		arr[1]=2;
	}

	//east
	if(j==MAT_SIZE-1)			// last column; wall
	{
		code+=1*(3^2);
		arr[2]=1;
	}	
	else if(G->grid[i][j+1]==1);	//can
	{
		code+=2*(3^2);
		arr[2]=2;
	}

	//south
	if(i==MAT_SIZE-1)			// last row; wall
	{
		code+=1*(3^3);
		arr[3]=1;
	}
	else if(G->grid[i+1][j]==1);	//can
	{
		code+=2*(3^3);
		arr[3]=2;
	}
	
	//north
	if(i==0)			// first row; wall
	{
		code+=1*(3^4);
		arr[4]=1;
	}
	else if(G->grid[i-1][j]==1);	//can
	{
		code+=2*(3^4);
		arr[4]=2;
	}
	arr[5] = code;
}

void printMat(struct matrix *G)
{
	for (int i=0; i<MAT_SIZE; i++)
	{
		for (int j=0; j<MAT_SIZE; j++)
		{
			printf("%d ",G->grid[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

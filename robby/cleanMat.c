#include "cleanMat.h"
/*
4 3 2 1 0
N S E W C coding

0 - Empty
1 - Wall
2 - Can
*/

/*
MoveNorth = 0
MoveSouth = 1
MoveEast = 2
MoveWest = 3
StayPut = 4
PickUpCan = 5
MoveRandom = 6
*/

int cleanMat(int iter, struct matrix *G, struct dna *D)
{
	int i=0,j=0;
	int code,action;
	int arr[6] = {0,0,0,0,0,0};
	int score = 0;

	for (int n=0; n<iter; n++)
	{
		sitCode(i, j, arr, G);
		code = arr[5];
		action = D->gene[code];
	
		if (action == 6)			// move random
			action = rand() % 4;	//random number between 0 to 3

		switch (action)
		{
			case 0:
				if (arr[4] == 1)	//wall
					score -= 5;	
				else	
					i--;
			case 1:
				if (arr[3] == 1)	//wall
					score -= 5;	
				else	
					i++;
			case 2:
				if (arr[2] == 1)	//wall
					score -= 5;	
				else	
					j++;
			case 3:
				if (arr[1] == 1)	//wall
					score -= 5;	
				else	
					j--;
			case 5:
				if (arr[0] == 2)	//can found
					score += 10;	
				else	
					score -= 1;		//tries to pickup empty site
			default:
				;
		}
	}
	return score;
}

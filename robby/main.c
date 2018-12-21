#include <stdio.h>
#include <stdlib.h>
#include "cleanMat.h"

void main()
{
	struct dna D_1;
	struct dna *D = &D_1;

	makenullGene(D);

	struct matrix G_1;
	struct matrix *G = &G_1;
	
	int score[200];

	for (int i=0; i<200; i++)
	{
		genRand(7,D);		//Random genetic person
		score[i]=0;
		for (int j=0; j<10; j++)
		{
			populateMat(5,G);	//Random can config
			score[i] += cleanMat(3,G,D);
		}
		score[i] = score[i]/10;	//averaging
		printf("%d, ",score[i]);
	}
	printf("\n");

	//picking parents
	
}

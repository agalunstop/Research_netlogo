#include <stdio.h>
#include <stdlib.h>
#include "dna.h"

/*
MoveNorth = 0
MoveSouth = 1
MoveEast = 2
MoveWest = 3
StayPut = 4
PickUpCan = 5
MoveRandom = 6
*/
void makenullGene(struct dna *D)
{
	D->len = GENE_LENGTH;
}

void genRand(int end, struct dna *D)
{
	for (int i=0; i<D->len; i++)
	{
		D->gene[i] = rand() % end;
	}
}

void printGene(struct dna *D)
{
	for(int i=0; i<D->len; i++)
	{
		printf("%d",D->gene[i]);
	}
	printf("\n\n");
}


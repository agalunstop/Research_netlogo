#include "define.h"
struct dna
{
	int gene[GENE_LENGTH];
	int len;
};

void makenullGene(struct dna *D);
void genRand(int end, struct dna *D);
void printGene(struct dna *D);

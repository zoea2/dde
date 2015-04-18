#ifndef _POPULATION_H
#define _POPULATION_H

#include "genotype.h"

class Population{
public:
	Population();
	~Population();
	Population(const Population&);
	Population(int num,double crossRate, double scale,double arrayLow[],double arratUpper[],int func);
	Population(int num,int mutationType,double crossRate, double scale,double arrayLow[],double arratUpper[],int func);
	Genotype* genes;
	Genotype bestgene;
	Genotype worstgene;
	int num;
	int mutationType;
	int maxNum;
	double mutaRate;
	double crossRate;
	double preFit;
	double meanFit;
	double scale;
	int func;
	int findWorstIdx();	
	void mutation(int i);
	void mutationRand(int i);
	void calMeanFit();
	void mutationBest(int i);
	void mutationRandToBest(int i);
	void init();
	int keepBest();
	Genotype genNewGeno();
};

#endif

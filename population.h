#ifndef _POPULATION_H
#define _POPULATION_H

#include "genotype.h"

class Population{
public:
	Population();
	~Population();
	Population(const Population&);
	Population(int num,double crossRate, double scale,double arrayLow[],double arratUpper[],int func);
	Genotype* genes;
	Genotype bestgene;
	int num;
	double mutaRate;
	double crossRate;
	double preFit;
	double meanFit;
	double scale;
	int func;
	int findWorstIdx();	
	void mutationRand(int i);
	void calMeanFit();
	void mutationBest(int i);
	void init();
	void keepBest();
};

#endif

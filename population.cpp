#include "population.h"
#include <string.h>
#include <iostream>
#include "general.h"
#include <stdlib.h>
using namespace std;
Population::Population(){
	genes = NULL;

}
Population::Population(int num,double crossRate,double scale,double arrayLow[],double arrayUpper[],int func){
	this->num = num;
	genes = new Genotype[num];
	this->func = func;
//	cout<<this->func<<endl;
	//this->mutaRate = mutaRate;
	this->crossRate = crossRate;
	this->scale = scale;
	for(int i = 0;i < num;i++){
		//cout<<genes[i].low<<endl;
		memcpy(genes[i].low,arrayLow,sizeof(genes[i].low));
		memcpy(genes[i].upper,arrayUpper,sizeof(genes[i].upper));
		//cout<<genes[i].low[0]<<endl;
		//cout<<arrayLow[0]<<endl;
	}
	init();
}

Population::Population(int num,int mutationType,double crossRate,double scale,double arrayLow[],double arrayUpper[],int func){
	this->num = num;
	this->mutationType = mutationType;
	genes = new Genotype[num];
	this->func = func;
//	cout<<this->func<<endl;
	//this->mutaRate = mutaRate;
	this->crossRate = crossRate;
	this->scale = scale;
	for(int i = 0;i < num;i++){
		//cout<<genes[i].low<<endl;
		memcpy(genes[i].low,arrayLow,sizeof(genes[i].low));
		memcpy(genes[i].upper,arrayUpper,sizeof(genes[i].upper));
		//cout<<genes[i].low[0]<<endl;
		//cout<<arrayLow[0]<<endl;
	}
	init();
}

Population::Population(const Population &population){ 
	num = population.num;
	mutaRate = population.mutaRate;
	crossRate = population.crossRate;
	mutationType = population.mutationType;
	meanFit = population.meanFit;
	scale = population.scale;
	func = population.func;
	bestgene = Genotype(population.bestgene);
//	if(genes != NULL)
//		delete [] genes;
	genes = new Genotype[num];
	for(int i = 0;i < population.num;i++){
		genes[i] = Genotype(population.genes[i]);
	}
}
Population::~Population(){
//	if(genes != NULL)
//		delete [] genes;
	genes = NULL;
}
void Population::mutation(int i){
	switch(mutationType){
		case 1:
			mutationRand(i);
			break;
		case 2:
			mutationBest(i);
			break;
		case 3:
			mutationRandToBest(i);
			break;
	}
}
void Population::mutationRand(int i){
		int r1 = randomNumber() * num;
		while(r1 == num)
			r1 = randomNumber() * num;
		int r2 = randomNumber() * num;
		while(r2 == r1 || r2 == num)
			r2 = randomNumber() * num;
		int r3 = randomNumber() * num;
		while(r3 == r1 || r3 == r2 || r3 == num )
			r3 = randomNumber() * num;
		for(int j = 0;j < vars;j++){
			genes[i].tmpGene[j] = genes[r1].gene[j] + scale * (genes[r2].gene[j] - genes[r3].gene[j]);
			if(genes[i].tmpGene[j] > genes[i].upper[j] || genes[i].tmpGene[j] < genes[i].low[j])
				genes[i].tmpGene[j] = genes[i].low[j] + randomNumber() * (genes[i].upper[j] - genes[i].low[j]);
		}
}

void Population::jDEmutation(int i){
		int r1 = randomNumber() * num;
		while(r1 == num)
			r1 = randomNumber() * num;
		int r2 = randomNumber() * num;
		while(r2 == r1 || r2 == num)
			r2 = randomNumber() * num;
		int r3 = randomNumber() * num;
		while(r3 == r1 || r3 == r2 || r3 == num )
			r3 = randomNumber() * num;
		for(int j = 0;j < vars;j++){
			genes[i].tmpGene[j] = genes[r1].gene[j] + genes[i].genoScale * (genes[r2].gene[j] - genes[r3].gene[j]);
			if(genes[i].tmpGene[j] > genes[i].upper[j] || genes[i].tmpGene[j] < genes[i].low[j])
				genes[i].tmpGene[j] = genes[i].low[j] + randomNumber() * (genes[i].upper[j] - genes[i].low[j]);
		}
}

void Population::JADEmutation(double p,int i,vector<Genotype> vGeno){
		int bestIdx = randomNumber(0,100 * p);
		while(bestIdx >= 100 * p)
			bestIdx = randomNumber(0,100 * p);
		//cout<<bestIdx<<endl;
		int r1 = randomNumber() * num;
		while(r1 == num && r1 == i)
			r1 = randomNumber() * num;
		int aNum = vGeno.size();
		int r2 = randomNumber() * (num + aNum); 
		while(r2 == r1 || r2 == num + aNum || r2 == i)
			r2 = randomNumber() * (num = aNum);
		for(int j = 0;j < vars;j++){
			if(r2 < num)
				genes[i].tmpGene[j] = genes[i].gene[j] + genes[i].genoScale * (genes[r1].gene[j] - genes[r2].gene[j]) + genes[i].genoScale * (genes[bestIdx].gene[j] - genes[i].gene[j]);
			else
				genes[i].tmpGene[j] = genes[i].gene[j] + genes[i].genoScale * (genes[r1].gene[j] - vGeno[r2-num].gene[j]) + genes[i].genoScale * (genes[bestIdx].gene[j] - genes[i].gene[j]);
			if(genes[i].tmpGene[j] > genes[i].upper[j] || genes[i].tmpGene[j] < genes[i].low[j])
				genes[i].tmpGene[j] = genes[i].low[j] + randomNumber() * (genes[i].upper[j] - genes[i].low[j]);
		}
}
void Population::mutationBest(int i){
	int r1 = randomNumber() * num;
	while(r1 == num)
		r1 = randomNumber() * num;
	int r2 = randomNumber() * num;
	while(r2 == r1 || r2 == num)
		r2 = randomNumber() * num;
	for(int j = 0;j < vars;j++){
		genes[i].tmpGene[j] = bestgene.gene[j] + scale * (genes[r1].gene[j] - genes[r2].gene[j]);
		if(genes[i].tmpGene[j] > genes[i].upper[j] || genes[i].tmpGene[j] < genes[i].low[j])
			genes[i].tmpGene[j] = genes[i].low[j] + randomNumber() * (genes[i].upper[j] - genes[i].low[j]);
	}
}

void Population::mutationRandToBest(int i){
	int r1 = randomNumber() * num;
	while(r1 == num)
		r1 = randomNumber() * num;
	int r2 = randomNumber() * num;
	while(r2 == r1 || r2 == num)
		r2 = randomNumber() * num;
	for(int j = 0;j < vars;j++){
		genes[i].tmpGene[j] = genes[i].gene[j] + scale * (bestgene.gene[j] - genes[i].gene[j]) + scale * (genes[r1].gene[j] - genes[r2].gene[j]);
		if(genes[i].tmpGene[j] > genes[i].upper[j] || genes[i].tmpGene[j] < genes[i].low[j])
			genes[i].tmpGene[j] = genes[i].low[j] + randomNumber() * (genes[i].upper[j] - genes[i].low[j]);
	}
}

void Population::init(){
	for(int i = 0;i < num;i++){
		for(int j = 0;j < vars;j++){
			genes[i].tmpGene[j] = genes[i].low[j] + randomNumber() * (genes[i].upper[j] - genes[i].low[j]);
//			cout<<genes[i].tmpGene[j]<<endl;
		}
		genes[i].evaluate(func);
		genes[i].fitness = D_MAX;
		genes[i].selection();
	}
	bestgene.fitness = D_MAX;
	keepBest();
	preFit = bestgene.fitness;
}
int Population::keepBest(){
	double minFit = D_MAX;
	int minIndex = -1;
	for(int i = 0;i < num;i++){
		if(minFit >= genes[i].fitness){
			minFit = genes[i].fitness;
			minIndex = i;
		}
				
	}
	if(minIndex >= 0)
		bestgene = Genotype(genes[minIndex]);
	return minIndex;
}
void Population::calMeanFit(){
	if(num > 0){
		int tmpMeanFit = 0;
		for(int i = 0; i < num ;i++){
			tmpMeanFit += (genes[i].fitness - tmpMeanFit) / (i + 1);
		}
		meanFit = tmpMeanFit;
	}
	else
		meanFit = D_MAX;
}
int Population::findWorstIdx(){
	double maxFit = -100000;
	int worstIdx = -1;
	for(int i = 0;i < num;i++){
		if(maxFit < genes[i].fitness){
			worstIdx = i;
			maxFit = genes[i].fitness;
		}
	}
	if(worstIdx > -1)
		worstgene = Genotype(genes[worstIdx]);
	return worstIdx;
}

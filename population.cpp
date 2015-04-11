#include "population.h"
#include <string.h>
#include <iostream>
#include "general.h"
#include <stdlib.h>
using namespace std;
Population::Population(){}
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

Population::Population(const Population &population){ 
	num = population.num;
	mutaRate = population.mutaRate;
	crossRate = population.crossRate;
	meanFit = population.meanFit;
	scale = population.scale;
	func = population.func;
	bestgene = Genotype(population.bestgene);
	genes = new Genotype[num];
	for(int i = 0;i < num;i++){
		genes[i] = Genotype(population.genes[i]);
	}
}
Population::~Population(){
//	delete [] genes;
}
void Population::mutationRand(int i){
		int r1 = randomNumber() * num;
		while(r1 == num)
			r1 = randomNumber() * num;
		int r2 = randomNumber() * num;
		while(r2 == r1 || r2 == num)
			r2 = randomNumber() * num;
		int r3 = randomNumber() * num;
		while(r3 == r1 || r3 == r2 || r3 == num)
			r3 = randomNumber() * num;
		for(int j = 0;j < vars;j++){
			genes[i].tmpGene[j] = genes[r1].gene[j] + scale * (genes[r2].gene[j] - genes[r3].gene[j]);
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
void Population::keepBest(){
	double minFit = bestgene.fitness;
	int minIndex = -1;
	for(int i = 0;i < num;i++){
		if(minFit >= genes[i].fitness){
			minFit = genes[i].fitness;
			minIndex = i;
		}
				
	}
	if(minIndex >= 0)
		bestgene = Genotype(genes[minIndex]);
}
void Population::calMeanFit(){
	for(int i = 0; i < num ;i++){
		meanFit += (genes[i].fitness - meanFit) / (i + 1);
	}
}
int Population::findWorstIdx(){
	double maxFit = genes[0].fitness;
	int worstIdx = 0;
	for(int i = 1;i < num;i++){
		if(maxFit < genes[i].fitness){
			worstIdx = i;
			maxFit = genes[i].fitness;
		}
	}
	return worstIdx;
}
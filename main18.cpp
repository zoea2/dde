/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月24日 星期二 17时38分08秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <stdio.h>
#include "genotype.h"
#include "general.h"
#include "population.h"
#include "test_func.cpp"
using namespace std;
//int fun = 1;
void Genotype::evaluate(int fun){
 //   cout<<5<<endl;
	test_func(tmpGene, &tmpFitness, vars, 1, fun);
//	cout<<tmpFitness<<endl;
}

int cmp(Genotype a,Genotype b){
	return a.fitness < b.fitness;
}	
void updateScaleAndCrRate(Population& population,double meanCr,double meanScale){
	default_random_engine generator0;
	normal_distribution<double> distrubution0(meanCr,0.1);
	default_random_engine generator1;
	cauchy_distribution<double> distrubution1(meanScale,0.1);
	for(int i = 0;i < population.num;i++){
		population.genes[i].genoScale = distrubution1(generator1); 
		while(population.genes[i].genoScale <= 0)
			population.genes[i].genoScale = distrubution1(generator1); 
		if(population.genes[i].genoScale > 1)
			population.genes[i].genoScale = 1;
		population.genes[i].genoCrRate = distrubution0(generator0); 
		if(population.genes[i].genoCrRate > 1)
			population.genes[i].genoCrRate = 1;
		else if(population.genes[i].genoCrRate < 0)
			population.genes[i].genoCrRate = 0;
	}
}

double functionRange[30][2];
void calcRange()
{
    functionRange[1][0] = -100;
    functionRange[1][1] = 100;
    functionRange[2][0] = -10;
    functionRange[2][1] = 10;
    functionRange[3][0] = -100;
    functionRange[3][1] = 100;
    functionRange[4][0] = -100;
    functionRange[4][1] = 100;
    functionRange[5][0] = -30;
    functionRange[5][1] = 30;
    functionRange[6][0] = -100;
    functionRange[6][1] = 100;
    functionRange[7][0] = -1.28;
    functionRange[7][1] = 1.28;
    functionRange[8][0] = -500;
    functionRange[8][1] = 500;
    functionRange[9][0] = -5.12;
    functionRange[9][1] = 5.12;
    functionRange[10][0] = -32;
    functionRange[10][1] = 32;
    functionRange[11][0] = -600;
    functionRange[11][1] = 600;
    functionRange[12][0] = -50;
    functionRange[12][1] = 50;
    functionRange[13][0] = -50;
    functionRange[13][1] = 50;
}

void printGeno(Genotype geno){
	printf("fitness: %e",geno.fitness);
	printf("gene:\n");
	for(int i = 0;i < vars;i++)
		printf("%e ",geno.gene[i]);
	printf("\n");
}
int main(){
	double avgBest = 0;
	setRand();
	int func;
	cin>>func;
	for(int times = 1;times <= ALL_TIMES;times++){
		int num = maxPop;
		double crossRate = 0.3;
		double scale = 0.4;
		double someBest = 0.05;
		double c = 0.1;
		double meanCr = 0.5;
		double meanScale = 0.5;
		calcRange();
		double arrayLow[vars];
		double arrayUpper[vars];
		for(int i = 0;i < vars;i++){
			arrayLow[i] = functionRange[func][0];
			arrayUpper[i] = functionRange[func][1];
		}
		Population pop(num,crossRate,scale,arrayLow,arrayUpper,func);
		vector<Genotype> worseGeno;
		vector<double> successScale;
		vector<double> successCrRate;
		int gen = 0;
		//const int maxGen = 1000;
		for(gen = 0;gen <= maxGen;gen++){
			if(gen % 100 == 0)
				cout<<gen<<endl;
			successScale.clear();
			successCrRate.clear();
			updateScaleAndCrRate(pop,meanCr,meanScale);	
			sort(pop.genes,pop.genes+pop.num,cmp);
			for(int i = 0;i < num;i++){
		//		cout<<pop.genes[i].genoScale<<" "<<pop.genes[i].genoCrRate<<endl;
		//		printGeno(pop.genes[i]);
				pop.JADEmutation(someBest,i,worseGeno);
				//cout<<"mutation complete"<<endl;
				pop.genes[i].crossover(pop.genes[i].genoCrRate);
				//cout<<"crossover complete"<<endl;
				pop.genes[i].evaluate(func);
				//cout<<"evaluate complete"<<endl;
				if(pop.genes[i].isBetter()){
					successScale.push_back(pop.genes[i].genoScale);
					successCrRate.push_back(pop.genes[i].genoCrRate);
					worseGeno.push_back(Genotype(pop.genes[i]));
				}
				pop.genes[i].selection();	
				//cout<<"selection complete"<<endl;
			//	printGeno(pop.genes[i]);
			}
			while(worseGeno.size() > pop.num){
				int randNum = randomNumber(0,worseGeno.size());
				while(randNum >= worseGeno.size())
					randNum = randomNumber(0,worseGeno.size());
				assert(randNum >= 0 && randNum < worseGeno.size());
				worseGeno.erase(worseGeno.begin() + randNum);
			}
			//cout<<"erase complete"<<endl;
			assert(worseGeno.size() <= pop.num);
			double meanScr = 0;
			for(int i = 0; i < successCrRate.size();i++)
				meanScr += successCrRate[i];
			meanScr /= successCrRate.size();
			meanCr = (1-c) * meanCr + c * meanScr;
			double meanSf = 0;
			double meanSff = 0;
			for(int i = 0;i < successScale.size();i++){
				meanSf += successScale[i] * successScale[i];
				meanSff += successScale[i];
			}
			meanSf /= meanSff;
			meanScale = (1-c) * meanScale + c * meanSf;
			pop.keepBest();
		}
		printGeno(pop.bestgene);
		avgBest += (pop.bestgene.fitness - avgBest) / times;
	}
	printf("average best: %e\n",avgBest);
}

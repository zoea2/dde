/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月24日 星期二 17时38分08秒
 ************************************************************************/

#include<iostream>
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
		calcRange();
		double arrayLow[vars];
		double arrayUpper[vars];
		for(int i = 0;i < vars;i++){
			arrayLow[i] = functionRange[func][0];
			arrayUpper[i] = functionRange[func][1];
		}
		Population pop(num,crossRate,scale,arrayLow,arrayUpper,func);
		int gen = 0;
		//const int maxGen = 1000;
		for(gen = 0;gen <= maxGen;gen++){
			for(int i = 0;i < num;i++){
		//		printGeno(pop.genes[i]);
				pop.mutationRand(i);
				pop.genes[i].crossover(pop.crossRate);
				pop.genes[i].evaluate(func);
				pop.genes[i].selection();	
			//	printGeno(pop.genes[i]);
			}
			pop.keepBest();
		}
		printGeno(pop.bestgene);
		avgBest += (pop.bestgene.fitness - avgBest) / times;
	}
	printf("average best: %e\n",avgBest);
}

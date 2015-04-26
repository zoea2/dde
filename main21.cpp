/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月24日 星期二 17时38分08秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include "genotype.h"
#include "general.h"
#include "population.h"
#include "test_func.cpp"
#include <algorithm>
#include <cmath>
#define subPop 4
using namespace std;
//int fun = 1;
void Genotype::evaluate(int fun){
 //   cout<<5<<endl;
	test_func(tmpGene, &tmpFitness, vars, 1, fun);
//	cout<<tmpFitness<<endl;
}

void updateScale(Population pop[],int gen){
	for(int p = 0;p < subPop;p++){
		pop[p].scale = exp(-(2 * gen / maxGen));
	}
}
int cmp(Population a,Population b){
	return a.preFit - a.bestgene.fitness > b.preFit - b.bestgene.fitness;
	//return a.meanFit < b.meanFit;
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
		int num = maxPop / subPop; 
		//double migrantRate = 0.9;
		//double crossRate = 0.3;
		double crossRate1 = 0.1;
		double crossRate2 = 0.9;
		double crossRate3 = 0.5;
		double scale = 0.5;
		double scale1 = 0.1;
		double scale2 = 0.9;
		double scaleSet[] = {0.5,0.5,0.9,0.9};
		double mtSet[] = {1,1,1,1};
		double crossRateSet[] = {0.1,0.9,0.1,0.9};
		calcRange();
		double arrayLow[vars];
		double arrayUpper[vars];
		for(int i = 0;i < vars;i++){
			arrayLow[i] = functionRange[func][0];
			arrayUpper[i] = functionRange[func][1];
		}
		Population pop[subPop];
		//不同的子种群采用不同crossRate的参数,还有不同的变异策略
		for(int i = 0;i < subPop;i++){
			pop[i] = Population(num,mtSet[i],crossRateSet[i],scaleSet[i],arrayLow,arrayUpper,func);
		}
		//cout<<"init complete"<<endl;
		int gen = 0;
		//const int maxGen = 1000;
		Genotype best;
		best.fitness = D_MAX;
		for(gen = 0;gen <= maxGen;gen++){
			//updateScale(pop,gen);
			for(int p = 0;p < subPop;p++){
				//cout<<p<<endl;
				for(int i = 0;i < pop[p].num;i++){
		//		printGeno(pop.genes[i]);
					//cout<<i<<" num "<<pop[p].num<<endl;
					if(pop[p].num > 2)
						pop[p].mutationRand(i);
					//cout<<"mutation complete"<<endl;
					pop[p].genes[i].crossover(pop[p].crossRate);
					//cout<<"crossover complete"<<endl;
					pop[p].genes[i].evaluate(func);
						//cout<<"evalutae complete"<<endl;
					pop[p].genes[i].selection();	
					//cout<<"selection complete"<<endl;
			//	printGeno(pop.genes[i]);
				}
				//cout<<"num: " << pop[p].num<<endl;
				pop[p].preFit = pop[p].bestgene.fitness;
				pop[p].keepBest();
				//cout<<"keepbest complete"<<endl;
				//printGeno(pop[p].bestgene);
				if(best.fitness >= pop[p].bestgene.fitness)
					best = Genotype(pop[p].bestgene);
				//cout<<"best complete"<<endl;
			}
			//cout<<"de complete"<<endl;
			for(int p = 0;p < subPop;p++)
				pop[p].calMeanFit();
			sort(pop,pop+subPop,cmp);
		//	for(int p = 0;p < subPop;p++)
		//		cout<<p<<" "<<pop[p].preFit - pop[p].bestgene.fitness<<endl;
		//迁移策略:将各子种群算出其平均适应值，并且按照从优到差排序，然后好的种群向比他差的种群都迁移一个个体
			for(int p = 0;p < subPop;p++){
				if(pop[p].bestgene.fitness == pop[p].preFit)
					break;
				int q = randomNumber(p,subPop);
				while (q == subPop)
					q = randomNumber(p,subPop);
		//		double survivalRate = 0.01 + 0.99 * (exp(10 * gen / maxGen) - 1) / (exp(10) - 1);
				double survivalRate =  0.4;
				if(pop[q].num > 0 && randomNumber() <= survivalRate){
					//int r = randomNumber() * pop[q].num;
					//while (r == pop[q].num)
					//r = randomNumber() * pop[q].num;
					/*
				//	int worstIdx = pop[q].findWorstIdx();
					//best->random
			//		pop[q].genes[r] = Genotype(pop[p].bestgene);
					//best->worst
				//	pop[q].genes[worstIdx] = Genotype(pop[p].bestgene);	
					*/
					int r = pop[q].findWorstIdx();
					Genotype* tmpGenes = new Genotype[pop[p].num+1];
					for(int indi = 0;indi < pop[p].num;indi++){
						tmpGenes[indi] = Genotype(pop[p].genes[indi]);
					}
					int r1 = randomNumber(0,pop[p].num);
					while(r1 >= pop[p].num)
						r1 = randomNumber(0,pop[p].num);
					tmpGenes[pop[p].num] = Genotype(pop[p].bestgene);
					delete [] pop[p].genes;
					pop[p].genes = tmpGenes;
					tmpGenes = NULL;
					pop[p].num++;
					pop[q].num--;
					assert(pop[q].num >= 0);
					pop[q].genes[r] = Genotype(pop[q].genes[pop[q].num]);
					
				}	
			}
			//cout<<"migrantion complete"<<endl;
			//cout<<gen<<" "<<maxGen<<endl;
			if(gen % (maxGen / point) == 0 )
				fprintf(stderr,"%e\n",best.fitness);
		}
			printGeno(best);
		avgBest += (best.fitness - avgBest) / times;
	}
	printf("average best: %e\n",avgBest);
}

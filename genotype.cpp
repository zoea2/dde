/*************************************************************************
	> File Name: genotype.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月24日 星期二 16时56分51秒
 ************************************************************************/

#include<iostream>
#include "genotype.h"
#include "general.h"
#include <stdlib.h>
#include <string.h>
using namespace std;

Genotype::Genotype() {}
Genotype::Genotype(const Genotype &genotype)
{
	fitness = genotype.fitness;
	tmpFitness = genotype.tmpFitness;
	for(int i = 0;i < vars;i++){
		low[i] = genotype.low[i];
		upper[i] = genotype.upper[i];
		gene[i] = genotype.gene[i];
		tmpGene[i] = genotype.tmpGene[i];
	}
}

Genotype::~Genotype(){}
void Genotype::crossover(double crossRate){
    int jRand = randomNumber(0,vars);
    for (int i = 0;i < vars;i++){
        if(randomNumber() > crossRate && i != jRand){
            tmpGene[i] = gene[i];
        }
   }
}
bool Genotype::isBetter(){
    if(tmpFitness <= fitness)
        return true;
    return false;
}
void Genotype::selection(){
    if(isBetter()){
        fitness = tmpFitness;
        for(int i = 0;i < vars;i++)
            gene[i] = tmpGene[i];
    }
}

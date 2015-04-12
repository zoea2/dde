/*************************************************************************
	> File Name: genotype.h
	> Author: 
	> Mail: 
	> Created Time: 2015年03月24日 星期二 16时25分26秒
 ************************************************************************/

#ifndef _GENOTYPE_H
#define _GENOTYPE_H

#include <vector>
#define vars 30

class Genotype{
public:
		Genotype();
		Genotype(const Genotype &genotype);
		~Genotype();
        double fitness;
        double tmpFitness;
        double low[vars];
        double upper[vars];
        double gene[vars];
        double tmpGene[vars];
       // void mutation(Genotype);
        virtual void crossover(double crossRate);
        virtual void evaluate(int fun);
        void selection();
		virtual bool isBetter();
};


#endif

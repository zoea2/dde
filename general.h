#ifndef _GENERAL_H
#define _GENERAL_H
#include <assert.h>
#define D_MAX 0x7FFFFFFFFFFFFFFF
#define ALL_TIMES 50
#define maxPop 120 
#define maxFEs 300000
#define point 20
#define maxGen maxFEs/maxPop
void setRand();
double randomNumber(double low = 0,double high = 1);
#endif

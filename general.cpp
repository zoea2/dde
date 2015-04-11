/*************************************************************************
	> File Name: general.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月24日 星期二 17时00分29秒
 ************************************************************************/


#include<iostream>
#include <stdlib.h>
#include "general.h"
#include <time.h>
using namespace std;

void setRand(){
    srand(time(0));
}

double randomNumber(double low, double high){
    double randNumber = rand() % RAND_MAX * 1.0 / RAND_MAX * (high - low) + low ;
    return randNumber;
}


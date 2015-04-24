#include <iostream>
#include "general.h"
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <string>
using namespace std;
int main(){
	ofstream output;
	output.open("evolution.csv");
	const int num = 18;
	for(int i = 0;i < num;i++){
		ifstream input;
		string filename = "evolution";
		char cTmp[10];
		sprintf(cTmp,"%d",i);
		filename.append(cTmp);
		filename.append(".txt");
		input.open(filename);
		if(!input.is_open())
			continue;
		string tmp;
		output << "main" << i<<endl;
		double fitness[50][10];
		for(int k = 0; k < 13;k++){
			for(int j = 0;j < ALL_TIMES;j++){
				input>>tmp;
				for(int l = 0;l < 10;l++){
					input>>fitness[j][l];
				}
			}
			for(int j = 0;j < 10;j++){
				double avg = 0;
				for(int l = 0;l < ALL_TIMES;l++){
					avg += fitness[l][j];
				}
				avg /= ALL_TIMES;
				output<<avg<<",";
			}
			output<<endl;
		}
		output<<endl;
		input.close();



	}
	output.close();
	return 0;
}

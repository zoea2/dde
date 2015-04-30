#include <iostream>
#include "general.h"
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <string>
using namespace std;
int main(){
	ofstream output;
	output.open("evolution1.csv");
	const int num = 22;
	for(int i = 0;i < num;i++){
		if(i != 21)
			continue;
		ifstream input;
		string filename = "evolution";
		char cTmp[10];
		sprintf(cTmp,"%d",i);
		filename.append(cTmp);
		filename.append("2.txt");
		input.open(filename);
		if(!input.is_open())
			continue;
		string tmp;
		output << "main" << i<<endl;
		double fitness[50][31];
		for(int k = 0; k < 13;k++){
			if(k != 11)
				continue;
			for(int j = 0;j < ALL_TIMES;j++){
				for(int l = 0;l < 1 + point ;l++){
					input>>fitness[j][l];
				}
			}
			for(int j = 0;j < 1 + point;j++){
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

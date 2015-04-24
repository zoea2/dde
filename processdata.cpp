#include <iostream>
#include "general.h"
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <string>
using namespace std;
int main(){
	ofstream output;
	output.open("data.csv");
	output << "function";
	for(int i = 1;i <= 13;i++)
		output << "," << i;
	output<<endl;
	const int num = 18;
	for(int i = 0;i < num;i++){
		ifstream input;
		string filename = "output";
		char cTmp[10];
		sprintf(cTmp,"%d",i);
		filename.append(cTmp);
		filename.append(".txt");
		input.open(filename);
		string tmp;
		double fitnessSet[ALL_TIMES];
		output << "main" << i;
		for(int k = 0; k < 13;k++){
			for(int j = 0;j < 1+2*ALL_TIMES;j++){
				if(j % 2 == 0)
					getline(input,tmp);

				if(j % 2  == 1){
					input>>tmp;
					input>>fitnessSet[j/2];
				//	cout<<fitnessSet[j/2]<<endl;
					getline(input,tmp);
				}
			}
			input >> tmp;
			input >> tmp;
		//	cout<<tmp<<endl;
			double best;
			input >> best;
			double stdDis = 0;
			for(int t = 0;t < ALL_TIMES;t++)
				stdDis += (fitnessSet[t] - best) * (fitnessSet[t] - best);
			stdDis /= ALL_TIMES;
			stdDis = sqrt(stdDis);
			output << "," << best<<"("<<stdDis<<")";
			input >> tmp;	//读取最后的换行符
		}
		output<<endl;
		input.close();



	}
	output.close();
	return 0;
}

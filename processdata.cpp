#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;
int main(){
	ofstream output;
	output.open("data.csv");
	output << "function";
	for(int i = 1;i <= 13;i++)
		output << "," << i;
	output<<endl;
	const int num = 5;
	for(int i = 0;i < num;i++){
		ifstream input;
		string filename = "output";
		char cTmp[10];
		sprintf(cTmp,"%d",i);
		filename.append(cTmp);
		filename.append(".txt");
		input.open(filename);
		string tmp;
		output << "main" << i;
		for(int k = 0; k < 13;k++){
			for(int j = 0;j < 101;j++)
				getline(input,tmp);
			input >> tmp;
			input >> tmp;
			//cout<<tmp<<endl;
			double best;
			input >> best;
			output << "," << best;
			input >> tmp;	//读取最后的换行符
		}
		output<<endl;
		input.close();



	}
	output.close();
	return 0;
}

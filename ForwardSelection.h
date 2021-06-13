#pragma once
#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class ForwardSelection {
private:
	int num_of_feats;
	vector<double> position;
	vector<double> randomNums;
public:
	void get_feats(int num) {
		num_of_feats = num;
	}
	void Gen_Ran() {
		/* initialize random seed: */
		srand(time(NULL));
		double ranNum;
		for (int i = 0; i < num_of_feats; i++) {
			/* generate secret number between 1 and 10: */
			ranNum = rand() % 1000 + 1;
			randomNums.push_back(ranNum/10);
		}
		for (int j = 0; j < num_of_feats; j++) {
	
			cout << "Using features at " << "{" << j+1 << "}" << " accuracy is " << randomNums[j] << "%" << endl;
		}
		double temp = randomNums[0];
		int pos;
		for (int i = 0; i < num_of_feats; i++) {
			if (temp < randomNums[i]) {
				temp = randomNums[i];
				pos = i;
			}
			if (i == (num_of_feats - 1) && temp == randomNums[0]) {
				position.push_back(1);
			}
			else if (i == (num_of_feats - 1)) {
				position.push_back(pos+1);
			}
		}

		cout << endl << "Feature Set " << "{";
			
			for (int j = 0; j < position.size(); j++) {
				cout << position[j];
			}
			cout << "}" << " was best, accuracy is " << temp << "%" << endl;
	}





};
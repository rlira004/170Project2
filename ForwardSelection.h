#pragma once
#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class ForwardSelection {
private:
	double noFeatures;
	int num_of_features;
	vector<double> position;
	vector<double> output;
	vector<double> randomNums;
	double accuracy;
public:
	void get_feats(int num) {
		num_of_features = num;
	}
	void ForwardSelect() {
		bool proceedSearching;
		double noFeatures = rand() % 1000 + 1;
		double noFeatureReduced = noFeatures/10;
		double temp;
		int pos = 0;
		cout << "Using no features and 'random' evaluation, I get an accuracy of " << noFeatureReduced << "%" << endl;
		cout << "Beginning search." << endl << endl;
		/* initialize random seed: */
		srand(time(NULL));
		double ranNum;
		//This for loop loads up randomNums and position
		for (int i = 0; i < num_of_features; i++) {
			/* generate secret number between 1 and 10: */
			ranNum = rand() % 1000 + 1;
			randomNums.push_back(ranNum/10);
			position.push_back(i+1);
			//checking to make sure NoFeatures isn't the best option
			if(randomNums[i] > noFeatureReduced){
				proceedSearching = true;
			}
			cout << position[i] << ") " << randomNums[i] << endl;

		}
		//if No Features = best, then crap out
		if(proceedSearching == false){
			cout << "Accuracy is best with no features @ " << noFeatureReduced << "%" << endl;
		}
		else{
			temp = 0;
			for(int j = 0; j < randomNums.size(); j++){
				if(randomNums[j]>temp){
					temp = randomNums[j];
					pos = j;
				}
				accuracy = temp;
				randomNums.erase(randomNums.begin()+pos)
					for(int k = 0; k < randomNums.size(); k++){
						cout << "?? " << randomNums[k] << endl;
					}
			}
		}
	}
};



/*for (int j = 0; j < num_of_features; j++) {
	
			cout << "Using features at " << "{" << j+1 << "}" << " accuracy is " << randomNums[j] << "%" << endl;
		}
		double temp = randomNums[0];
		int pos;
		for (int i = 0; i < num_of_features; i++) {
			if (temp < randomNums[i]) {
				temp = randomNums[i];
				pos = i;
			}void Gen_Ran() {
		/* initialize random seed: */
		/*
		srand(time(NULL));
		double ranNum;
		for (int i = 0; i < num_of_features; i++) {
			/* generate secret number between 1 and 10: *//*
			ranNum = rand() % 1000 + 1;
			randomNums.push_back(ranNum/10);
		}
		for (int j = 0; j < num_of_features; j++) {
	
			cout << "Using features at " << "{" << j+1 << "}" << " accuracy is " << randomNums[j] << "%" << endl;
		}
		double temp = randomNums[0];
		int pos;
		for (int i = 0; i < num_of_features; i++) {
			if (temp < randomNums[i]) {
				temp = randomNums[i];
				pos = i;
			}
			if (
			if (i == (num_of_features - 1) && temp == randomNums[0]) {
				position.push_back(1);
			}
			else if (i == (num_of_featurehttps://github.com/rlira004/170Project2.gits - 1)) {
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

*/

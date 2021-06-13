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
		int imTired=0;
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
			cout << "Using feature(s) {" << position[i] << "} accuracy is " << randomNums[i] << "%" << endl;
			//cout << position[i] << ") " << randomNums[i] << endl;

		}
		//if No Features = best, then crap out
		if(proceedSearching == false){
			cout << "Accuracy is best with no features @ " << noFeatureReduced << "%" << endl;
		}
		else{
			temp = 0;
			while(num_of_features != 0){
				for(int j = 0; j < num_of_features; j++){
					if(randomNums[j]>temp){
						temp = randomNums[j];
						pos = j;
					}
				}
			
			output.push_back(position[pos]);
				cout << endl << "Feature set " << output[imTired] << " was best, accuracy is " << temp << "%"<< endl << endl; //testing
				for (int w = 0; w < num_of_features; w++) {
				/* generate secret number between 1 and 10: */
				randomNums.pop_back();
				}
			num_of_features--;
				for (int x = 0; x < num_of_features; x++) {
				/* generate secret number between 1 and 10: */
				ranNum = rand() % 1000 + 1;
				randomNums.push_back(ranNum/10);
					//nummies
					cout << "Using features(s) {" << output[imTired] << ", " << x << "} accuracy is " << randomNums[x] << endl;
				}
					//cout << endl << "Feature set " << output[imTired] << " was best, accuracy is " << temp << "%"<< endl << endl;
					imTired++;


			}
		}
	}
};

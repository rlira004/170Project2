#include <iostream>
#include "ForwardSelection.h"
#include "BackwardElimination.h"
using namespace std;


int main() {
	srand(time(NULL));
	int num_of_features;
	int algo_select;

	cout << "Welcome to Ricardo's and Briana's Feature Selection Algorithm" << endl;
	cout << "Please enter the total number of features: ";
	cin >> num_of_features;
	
	cout << "Type the number of the algorithm you want to run." << endl;
	cout << "	1) Forward Selection" << endl;
	cout << "	2) Backward Elimination" << endl;
	cout << "	3) Special Nonexistant Algo" << endl;
	cin >> algo_select;

	ForwardSelection peanut;
	peanut.get_feats(num_of_features);
	peanut.ForwardSelect();
	
	if(algo_select == 2){
		peanut.get_feats(num_of_features);
		peanut.BackwardElimination();
	}





	return 0;
}

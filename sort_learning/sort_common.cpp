#include <iostream>
#include <vector>
#include <stdlib.h>	//rand
#include "sort_common.h"

//check if vector a is sorted or not
bool isSorted(std::vector<int> &a){
	for(int i=1; i<a.size(); i++)
		if(a[i] < a[i-1])	return false;
	return true;
}

//print a vector and tell if its sorted
void print_vector(std::vector<int> &a){
	for(int i=0; i<a.size(); i++)
		std::cout << a[i] <<" ";
	std::cout <<"    "<< (isSorted(a)?"Sorted" : "Unsorted");
	std::cout << "\n";
}

//return a randomized vector of size (length)
std::vector<int> rand_vector(int length){
	std::vector<int> random_vector;
	for(int i=0; i<length; i++)
		random_vector.push_back(rand()%1000);
	return random_vector;
}

//return a randomized vector of size (length), from 0 to upper-1
std::vector<int> rand_vector(int length, int upper){
	std::vector<int> random_vector;
	for(int i=0; i<length; i++)
		random_vector.push_back(rand()%upper);
	return random_vector;
}

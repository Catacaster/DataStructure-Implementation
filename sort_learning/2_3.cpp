#include <iostream>
#include <vector>
#include <algorithm>	//swap
#include "sort_common.h"
#include "2_3.h"
//functions to be tested
void quick_sort_three_partition(std::vector<int>& a, int low, int high);
void quick_sort(std::vector<int> &a, int low, int high);
int partition(std::vector<int> &a, int low, int high); 

//main function of section 2.3
void quick_sort_main(void){
	//Test classic quick sort
	std::cout << "Test classic quick sort:\n";
	std::vector<int> a(rand_vector(50));
	print_vector(a);
	quick_sort(a, 0, a.size()-1);
	print_vector(a);
	//Test quick sort with three partitions
	std::cout << "Test quick sort with three partitions:\n";
	std::vector<int> b(rand_vector(30, 8));
	print_vector(b);
	quick_sort_three_partition(b, 0, b.size()-1);
	print_vector(b);
	
}
//function that perform quick sort with three partitions
void quick_sort_three_partition(std::vector<int>& a, int low, int high){
	if(low >= high)	return;	//end of recursion
	
	int target = a[low], left=low, right=high, i=low+1;
	while(i <= right){
		if(a[i] < target)		std::swap(a[i++], a[left++]);	//swap a[i] with a[lleft]
		else if(a[i] > target)	std::swap(a[i], a[right--]);	//swap a[i] with a[right]
		else i++;	//continue;
	}
	
	quick_sort_three_partition(a, low, left-1);		//recursion on left part
	quick_sort_three_partition(a, right+1, high);	//recursion on right part
}


//function that perform classic quick sort
void quick_sort(std::vector<int> &a, int low, int high){
	if(low >= high)	return;	//end of recursion
	
	int mid = partition(a, low, high);
	quick_sort(a, low, mid-1);
	quick_sort(a, mid+1, high);
}
//partition the vector, return the middle index
int partition(std::vector<int> &a, int low, int high){
	int mid = low, right = high+1, left = low, target = a[low];
	while(true){
		while(a[++left] < target)	if(left == high) break;	//left++ until meet one greater than target
		while(a[--right] > target)	if(right == low) break;	//right-- until meet one less than target
		if(left >= right) break;	//end condition
		std::swap(a[left], a[right]);
	}
	std::swap(a[low], a[right]);
	return right;
}


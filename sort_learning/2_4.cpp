#include <iostream>
#include <vector>
#include <algorithm>
#include "sort_common.h"
#include "2_4.h"

void heap_sort(std::vector<int> &a);
void sink(std::vector<int> &a, int k);
void sink(std::vector<int> &a, int k, int n);
void swim(std::vector<int> &a, int k);

void heap_sort_main(void){
	std::cout << "Testing heap sort:\n";
	std::vector<int> a(rand_vector(30));
	print_vector(a);
	heap_sort(a);
	print_vector(a);
}
//heap_construct
void heap_sort(std::vector<int> &a){
	a.insert(a.begin(), 0);	
	int n=a.size();
	//heap construction
	for(int i=n/2; i>0; i--)	sink(a, i);	//all children cannot be sink further
	//sort down
	for(int i=n-1; i>1; i--){
		std::swap(a[1], a[i]);	//swap largest to the end
		sink(a, 1, i-1);		//sink new root down
	}	
	a.erase(a.begin());
}
//sink element k 
void sink(std::vector<int> &a, int k){
	int n = a.size()-1;	//n is heap.size
	while(2*k <= n){
		int next = 2*k;
		if(next < n && a[next] < a[next+1])	next++;	//a[next] (and a[next+1] if exists) are a[i]'s children
													//if there is a next+1, and a[next+1] > a[next], use next+1
		if(a[next] > a[k])	std::swap(a[next], a[k]);
		else	break;
		
		k = next;
	}
}
void sink(std::vector<int> &a, int k, int n){
	while(2*k <= n){
		int next = 2*k;
		if(next < n && a[next] < a[next+1])	next++;	//a[next] (and a[next+1] if exists) are a[i]'s children
													//if there is a next+1, and a[next+1] > a[next], use next+1
		if(a[next] > a[k])	std::swap(a[next], a[k]);
		else	break;
		
		k = next;
	}
}
//swim element k
void swim(std::vector<int> &a, int k){
	while(k > 1 && a[k] > a[k/2]){
		std::swap(a[k], a[k/2]);
		k /= 2;
	}
}

#include <iostream>
#include <stdlib.h> 
#include "my_red_black_tree.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	red_black_tree MyTree;
	int x;
	for(int i=0; i<5; i++){
		std::cout << "\nTESTING: \n";
		x = rand()%50;
		std::cout << "insert: " << x;
		MyTree.insert(x);
		MyTree.print();
	}
	return 0;
}

#include <iostream>
#include <vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "my_undirected_graph.h"
#include "my_directed_graph.h"

void print_vector(const std::vector<int> &a);

int main() {
	Digraph G;
	G.set_default_graph(0);
	std::vector<int> dfs = G.get_dfs();
	print_vector(dfs);
	std::cout << (G.hasCycle() ? "Cycle detected!\n" : "Cycle not detected!\n");
	//set default 1
	G.set_default_graph(1);
	std::cout << (G.hasCycle() ? "Cycle detected!\n" : "Cycle not detected!\n");
	std::vector<int> tp = G.topological_sort();
	print_vector(tp);
	G.set_default_graph(0);
	std::vector<std::vector<int>> scc(G.SCC());
	std::cout << "SCC:\n";
	for(int i=0; i<scc.size(); i++){
		print_vector(scc[i]);
	}
	return 0;
}

void print_vector(const std::vector<int> &a){
	int n = a.size();
	for(int i=0; i<n; i++)
		std::cout << a[i] << " ";
	std::cout << "\n";
}

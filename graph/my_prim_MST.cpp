#include <vector>
#include <queue>
#include <iostream>
#include "my_edge.h"
#include "my_prim_MST.h"

//helper function of find_MST
void visit(int i, std::vector<bool> &marked, std::vector<std::vector<Edge>> &graph,
		  std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> wait_list);

Lazyprim::Lazyprim();

Lazyprim::Lazyprim(int v){
	graph.resize(v);
}

void Lazyprim::set_default_graph(int n){
	if(n == 0){
		std::cout << "Loading default graph 0...\n";
		
	}
	else{
		std::cout << "Error!!!";
	}
}

int Lazyprim::V(){
	return graph.size();
}

int Lazyprim::E(){
	return edges;
}

std::vector<Edge> Lazyprim::get_MST(){
	std::vector<bool> marked(V(), false);
	std::vector<Edge> result;
	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> wait_list;
	visit(0, marked, graph, wait_list);	//visit 0
	while(!wait_list.empty()){
		Edge temp = wait_list.top();
		wait_list.pop();	//get edge, pop it out
		int v = temp.either();
		int w = temp.other(v);
		if(!marked(v){
			visit(v, marked, graph, wait_list);
			result.push_back(temp);
		}
		else if(!marked(w)){
			visit(w, marked, graph, wait_list);
			result.push_back(temp);
		}
		//else do nothing (if both vertices are on the tree)
	}
	return result;
}


void visit(int i, std::vector<bool> &marked, std::vector<std::vector<Edge>> &graph,
	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> &wait_list){
	marked[i] = true;	//mark as visited
	for(int j = 0; j<graph[i].size(); j++){
		wait_list.push(graph[i][j]);	//add all edge to it to the priority queue
	}

}

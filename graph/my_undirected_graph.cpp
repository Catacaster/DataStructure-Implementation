#include <iostream>
#include <vector>
#include <queue>
#include "my_undirected_graph.h"

//default constructor
undirected_graph::undirected_graph(){
} 

//constructor, V is number of vertices
undirected_graph::undirected_graph(int V){
	graph.resize(V);
}
//set graph to a given default graph
void undirected_graph::set_graph_default(int n){
	if(n == 0){
		clear();	//clear the old graph
		std::cout << "***load default graph 0***\n";
		graph.resize(6);
		graph[0] = std::vector<int>({2, 1, 5});
		graph[1] = std::vector<int>({0, 2});
		graph[2] = std::vector<int>({0, 1, 3, 4});
		graph[3] = std::vector<int>({5, 4, 2});
		graph[4] = std::vector<int>({3, 2});
		graph[5] = std::vector<int>({3, 0});
		edges = 8;
	}
	else{
		std::cout << "Error: failed to load default graph " << n << "!\n";
	}
}
//get number of vertices
int undirected_graph::V(){
	return graph.size();
}
//get number of edges
int undirected_graph::E(){
	return edges;
}

//add a new vertex
void undirected_graph::add_vertex(){
	graph.push_back(std::vector<int>());
}
//add a new edge
void undirected_graph::add_edge(int v, int w){
	if(v < 0 || w < 0 || v >= V() || w >= V()){
		std::cout << "Error: vertex not found!!!\n";
	}
	else{
		edges++;
		graph[v].push_back(w);
		if(v != w)	graph[w].push_back(v);	//if is the same index only insert once
	}
} 
//clear graph, set edges to 0
void undirected_graph::clear(){
	edges = 0;
	graph.clear();	//vector has a destructor, just clear map	
}
//dfs return a vector of vertices
std::vector<int> undirected_graph::get_dfs(){
	std::vector<int> result;
	if(graph.size() == 0) return result;	//if no vertex, return empty list
	
	int v = V();	//number of vertices
	std::vector<bool> mark(v, false);	//all point not visited at the beginning
	for(int i=0; i < v; i++){
		if(!mark[i]) get_dfs(mark, result, i);	//if not marked visited visit it
	}
	return result;
}
void undirected_graph::get_dfs(std::vector<bool> &mark, std::vector<int>& result, int v){
	if(mark[v])	return;	//this vertex was visited
	
	mark[v] = true;		//mark this vertex as visited
	result.push_back(v);//add it to the result
	for(int i=0; i<graph[v].size(); i++){
		get_dfs(mark, result, graph[v][i]);
	}
}
//bfs returna verctor of vertices
std::vector<int> undirected_graph::get_bfs(){
	std::vector<int> result;
	int v = V();
	std::vector<bool> mark(v, false);
	for(int i=0; i < v; i++){
		if(!mark[i]){	//i not visisted yet
			std::queue<int> wait;
			wait.push(i);
			while(!wait.empty()){
				int vertex = wait.front();
				wait.pop();
				if(!mark[vertex]){
					mark[vertex] = true;	//mark vertex as visited
					result.push_back(vertex);
					for(int j = 0; j < graph[vertex].size(); j++){
						wait.push(graph[vertex][j]);
					}
				}
			}
		}
	}
	return result;
}

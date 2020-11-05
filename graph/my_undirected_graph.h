/*
my_undirected_graph
10-07-2020
*/
#ifndef MY_UNDIRECTED_GRAPH_H
#define MY_UNDIRECTED_GRAPH_H

#include <vector>

class undirected_graph{
private:
	std::vector<std::vector<int>> graph;
	int edges = 0;	//number of edges
	//helper function of get_dfs
	void get_dfs(std::vector<bool> &mark, std::vector<int> &result, int v);
public:
	//default constructor
	undirected_graph();	
	//constructor, V is number of vertices	
	undirected_graph(int V);
	//set graph to one of a default graph, depending on input integer i
	void set_graph_default(int n);
	//get number of vertices
	int V();
	//get number of edges
	int E();
	//add a new vertex
	void add_vertex();
	//add a new edge between v and w
	void add_edge(int v, int w);
	//clear graph, remove all vertices and edges
	void clear();
	//depth first search
	std::vector<int> get_dfs();
	//breath first search
	std::vector<int> get_bfs();
};

#endif

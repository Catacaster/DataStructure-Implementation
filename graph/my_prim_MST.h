/*
 *my_prim_MST.h
 *implement Lazy prim's algorithm	2020-07-22
 */

#ifndef	MY_PRIM_MST_H
#define	MY_PRIM_MST_H

#include <vector>
#include "my_edge.h"

class Lazyprim{
private:
	std::vector<std::vector<Edge>>	graph;
	int edges;
public:
	//constructors
	Lazyprim();
	Lazyprim(int v);
	//set to default graphs
	void set_default_graph(int n);
	//return number of vertices
	int V();
	//return number of edges
	int E();
	//get MST 
	std::vector<Edge> get_MST();
};

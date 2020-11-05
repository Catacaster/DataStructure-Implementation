/*
 *my_edge.h
 *2020-07-22
 */

#ifndef	MY_EDGE_H
#define MY_EDGE_H

class Edge{
private:
	int V;
	int W;
	double Weight;
public:
	//constructor
	Edge(int v, int w, int weight);
	//return weight of this edge
	double weight();
	//return V
	int either();
	//return the vertex other than input v
	int other(int v);
	//compare
	bool operator>(Edge E);
	bool operator<(Edge E);
};

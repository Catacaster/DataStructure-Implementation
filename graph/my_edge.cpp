#include "my_edge.h"

Edge::Edge(int v, int w, double weight){
	V = v;
	W = w;
	Weight = weight;
}

double Edge::weight(){
	return Weight;
}

int Edge::either(){
	return V;
}

int Edge::other(int v){
	if(v == V) return W;
	else	   return V;
}

bool Edge::operator<(Edge E){
	if(Weight < E.weight())	return true;
	else	return false;
}

bool Edge::operator>(Edge E){
	if(Weight > E.weight())	return true;
	else	return false;
}

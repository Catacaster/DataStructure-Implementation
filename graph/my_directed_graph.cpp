#include <vector>
#include <iostream>
#include <stack>
#include "my_directed_graph.h"
//helper function of hasCycle, perform recursion
bool hasCycle_dfs(std::vector<std::vector<int>> &G, std::vector<bool> &mark, std::vector<bool> &onStack, int v);
//helper function of topological sort
//the 2nd one perform reverse post order
void reverse_postorder(const std::vector<std::vector<int>> &graph, std::stack<int> &result);
void reverse_postorder(const std::vector<std::vector<int>> &graph, std::stack<int> &result, std::vector<bool> &mark, int v);
//helper function of SCC
void SCC_dfs(std::vector<std::vector<int>> &graph, std::vector<int> &id, std::vector<bool> &mark, int v, int count);


//default constructor
Digraph::Digraph(){
}

Digraph::Digraph(int V){
	graph.resize(V);
}

//set graph to default graph models
void Digraph::set_default_graph(int n){
	if(n == 0){
		std::cout << "***Set default graph 0***\n";
		graph.clear();
		graph.resize(13);
		graph[0] = std::vector<int>({5, 1});
	    //vertex 1 connects to nothing
		graph[2] = std::vector<int>({0, 3});
		graph[3] = std::vector<int>({5, 2});
		graph[4] = std::vector<int>({3, 2});
		graph[5] = std::vector<int>({4});
		graph[6] = std::vector<int>({9, 4, 8, 0});
		graph[7] = std::vector<int>({6, 9});
		graph[8] = std::vector<int>({6});
		graph[9] = std::vector<int>({11, 10});
		graph[10] = std::vector<int>({12});
		graph[11] = std::vector<int>({4, 12});
		graph[12] = std::vector<int>({9});
		edges = 22;	//set number of edges
	}
	else if(n == 1){
		std::cout << "***Set default graph 1***\n";
		graph.clear();
		graph.resize(13);
		graph[0] = std::vector<int>({5, 1, 6});
		//graph[1] links to nothing
		graph[2] = std::vector<int>({0, 3});
		graph[3] = std::vector<int>({5});
		//graph[4] links to nothing
		graph[5] = std::vector<int>({4});
		graph[6] = std::vector<int>({9, 4});
		graph[7] = std::vector<int>({6});
		graph[8] = std::vector<int>({7});
		graph[9] = std::vector<int>({11, 10, 12});
		//graph[10] links to nothing
		graph[11] = std::vector<int>({12});
		//graph[12] links to nothing
		edges = 15; //set number of edges
	}
	else{
		std::cout << "Failed to load default graph " << n << "\n";
	}
}
//get number of vertices
int Digraph::V(){
	return graph.size();
}
//get number of edges
int Digraph::E(){
	return edges;
}
//add another edge
void Digraph::addEdge(int v, int w){
	graph[v].push_back(w);
	edges++;
}
//get reverse of this graph
Digraph Digraph::reverse(){
	int v = V();
	Digraph Reverse(v);		//construct another digraph Reverse
	for(int i=0; i<v; i++){
		int adj = graph[i].size();
		for(int j=0; j<adj; j++){
			Reverse.addEdge(graph[i][j], i);
		}
	}
	return Reverse;
}
//get dps of this graph
std::vector<int> Digraph::get_dfs(){
	int v = V();
	std::vector<bool> mark(v, false);
	std::vector<int> result;
	for(int i=0; i<v; i++){
		if(!mark[i])	get_dfs(result, mark, i);
	}
	return result;
}

void Digraph::get_dfs(std::vector<int> &result, std::vector<bool> &mark, int v){
	if(mark[v])	return;	//end of recursion
	
	result.push_back(v);//add to result
	mark[v] = true;		//visited
	//recursive call
	for(int i=0; i<graph[v].size(); i++){
		get_dfs(result, mark, graph[v][i]);
	}
}
//check if the graph has any cycle
bool Digraph::hasCycle(){
	int v = V();
	std::vector<bool> mark(v, false), onStack(v, false);
	for(int i=0; i<v; i++){
		//if vertex is not visited, call function on i
		//if function returns a true, return true
		if(!mark[i]	&& hasCycle_dfs(graph, mark, onStack, i)) return true;
	}
	return false;
}
bool hasCycle_dfs(std::vector<std::vector<int>> &G, std::vector<bool> &mark, std::vector<bool> &onStack, int v){
	if(!mark[v]){
		mark[v] = true;		//visited
		onStack[v] = true;	//onStack
		for(int i=0; i<G[v].size(); i++){
			if(hasCycle_dfs(G, mark, onStack, G[v][i]))	return true;	//cycle detected
		}
		onStack[v] = false;	//return from recursion, v is no longer on stack
		return false;
	}
	else if(onStack[v]){
		return true;
	}
	else return false;	//visited but not on stack
}
//topological sort::make sure the graph does not have cycle first
std::vector<int> Digraph::topological_sort(){
	int v = V();
	std::vector<int> result;
	std::stack<int> pool;
	reverse_postorder(graph, pool);
	//transfer stack to vector
	while(!pool.empty()){
		result.push_back(pool.top());
		pool.pop();
	}
	return result;
}


//function perform reverse postorder
void reverse_postorder(const std::vector<std::vector<int>> &graph, std::stack<int> &result){
	int v = graph.size();
	std::vector<bool> mark(v, false);
	for(int i=0; i<v; i++){
		if(!mark[i])	reverse_postorder(graph, result, mark, i);
	}
}
void reverse_postorder(const std::vector<std::vector<int>> &graph, std::stack<int> &result, std::vector<bool> &mark, int v){
	if(mark[v]){
		return; //end of recursion
	}
	mark[v] = true;	//set vertex v as visited
	for(int i=0; i<graph[v].size(); i++){
		reverse_postorder(graph, result, mark, graph[v][i]);	//recursive calls
	}
	
	//put target into the stack after recrusive calls
	result.push(v);
}

//divide graph into strong connect components
std::vector<std::vector<int>> Digraph::SCC(){
	int count = 0;	//number of groups
	Digraph GR = reverse();	//get reverse of this graph
	std::vector<int> reverse_gr(GR.topological_sort());	//no quite a wise act, but feasible
		
	//now dfs through original graph using reverse post-order of G_R
	int v = V();
	std::vector<int> id(v);		//id[i] is group id of the vectex i
	std::vector<bool> mark(v, false);
	for(int i=0; i<v; i++){
		//reverse_gr[i] is the real vertex, not i !!!
		if(!mark[reverse_gr[i]]){	//if not visited
			SCC_dfs(graph, id, mark, reverse_gr[i], count);
			count++;	//new group
		}
	}
	std::vector<std::vector<int>> result(count);	//there are count number of groups
	for(int i=0; i<v; i++){
		result[id[i]].push_back(i);
	}
	return result;
}
void SCC_dfs(std::vector<std::vector<int>> &graph, std::vector<int> &id, std::vector<bool> &mark, int v, int count){
	if(mark[v])	return;	//end of recursion
	
	id[v] = count;	//set vertex v to its group
	mark[v] = true;	//set vertex v as visited
	//recursive calls
	for(int i=0; i<graph[v].size(); i++){
		SCC_dfs(graph, id, mark, graph[v][i], count);
	}
}



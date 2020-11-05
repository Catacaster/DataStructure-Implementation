/*
 * class::my directed graph
 * implement directed map's dfs, bfs	2020-07-14
 * implement topological sort			2020-07-14
 * implement SCC						2020-07-14
 */
 
 #ifndef MY_DIRECTED_GRAPH_H
 #define MY_DIRECTED_GRAPH_H
 
 #include <vector>
 
class Digraph{
private:
	int edges = 0;
	std::vector<std::vector<int>> graph;
	//helper function of get dfs
	void get_dfs(std::vector<int> &result, std::vector<bool> &mark, int v);
public:
	//constructors
	Digraph();
	Digraph(int V);
	//set directed graph to some default graph according to input integer
	void set_default_graph(int n);
	//get number of vertices in this graph
	int V();
	//get number of edges in this graph
	int E();
	//add an edge between vertex v and w
	void addEdge(int v, int w);
 	//get reverse of this graph
 	Digraph reverse();
 	//get dfs of this graph
 	std::vector<int> get_dfs();
 	//check if there is any cycle in the graph, return true if there is any, else false
 	bool hasCycle();
	//topological sort, user should make sure directed graph does not have any cycle to get topological_sort
	std::vector<int> topological_sort();
	//strong connect
	std::vector<std::vector<int>> SCC();
};
 
 #endif

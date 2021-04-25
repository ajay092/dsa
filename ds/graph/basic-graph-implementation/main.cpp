#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	Graph g;
// 	g.insert_edge(0, 1, 1);
// 	g.insert_edge(0, 4, 1);
// 	g.insert_edge(1, 0, 1);
// 	g.insert_edge(1, 4, 1);
// 	g.insert_edge(1, 3, 1);
// 	g.insert_edge(1, 2, 1);
// 	g.insert_edge(2, 1, 1);
// 	g.insert_edge(2, 3, 1);
// 	g.insert_edge(3, 2, 1);
// 	g.insert_edge(3, 1, 1);
// 	g.insert_edge(3, 4, 1);
// 	g.insert_edge(4, 0, 1);
// 	g.insert_edge(4, 1, 1);
// 	g.insert_edge(4, 3, 1);
	
	g.insert_edge(0, 1, 1); 
    g.insert_edge(0, 2, 1); 
    g.insert_edge(1, 2, 1); 
    g.insert_edge(2, 0, 1); 
    g.insert_edge(2, 3, 1); 
    g.insert_edge(3, 3, 1); 
	g.insert_edge(1, 4, 1);
	g.insert_edge(3, 5, 1);
	
	g.display();
	g.bfs(1);
	g.dfs(1);
	
	return 0;
}
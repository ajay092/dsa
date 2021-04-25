#include "graph.h"

using namespace std;

Graph::Graph()
{	
}

void Graph::insert_edge(int src, int dest, double weight = 0)
{
	graph[src][dest] = weight;
	
	if (vertices.find(src) == vertices.end())	vertices.insert(src);

	if (vertices.find(dest) == vertices.end())	vertices.insert(dest);
}

void Graph::remove_edge(int src, int dest)
{
	if(graph[src].find(dest) == graph[src].end())	return;
	
	graph[src].erase(graph[src].find(dest));
}

void Graph::display()
{
	for(auto &vertex_set : graph)
	{
		cout << vertex_set.first << ":";
		
		for(auto &vertex : vertex_set.second)
		{
			cout << "\t(" << vertex.first << "|" << vertex.second << ")";
		}
		cout << endl;
	}
}
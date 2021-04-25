#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "graph.h"

using namespace std;

void bfs(Graph &g, int start);
void dfs(Graph &g, int start);

int main()
{
	Graph g;
	g.insert_edge(0, 1, 0); 
    g.insert_edge(0, 2, 0); 
    g.insert_edge(1, 2, 0); 
    g.insert_edge(2, 0, 0); 
    g.insert_edge(2, 3, 0); 
    g.insert_edge(3, 3, 0); 

	bfs(g, 2);
	
	dfs(g, 2);
	
// 	g.display();
	
	return 0;
}

void bfs(Graph &g, int start)
{
	cout << "bfs: ";
	int v = g.vertices.size();
	
	bool visited[v];
	
	for(int i=0; i<v; i++)
	{
		visited[v] = false;
	}
	
	queue<int> que;
	que.push(start);
	visited[start] = true;
	
	while(!que.empty())
	{
		int vertex = que.front();
		
		que.pop();
		
		cout << vertex << "\t";
		
		for(auto &adj_vertex : g.graph[vertex])
		{
			if(!visited[adj_vertex.first])
			{
				que.push(adj_vertex.first);
				visited[adj_vertex.first] = true;
			}
		}
	}
	cout << endl;
}

void dfs(Graph &g, int start)
{
	cout << "dfs: ";
	int v = g.vertices.size();
	
	bool visited[v];
	
	for(int i=0; i<v; i++)
	{
		visited[v] = false;
	}
	
	stack<int> s;
	s.push(start);
	visited[start] = true;
	
	while(!s.empty())
	{
		int vertex = s.top();
		
		s.pop();
		
		cout << vertex << "\t";
		
		for(auto &adj_vertex : g.graph[vertex])
		{
			if(!visited[adj_vertex.first])
			{
				s.push(adj_vertex.first);
				visited[adj_vertex.first] = true;
			}
		}
	}
	cout << endl;
}
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include "graph.h"

using namespace std;

Graph::Graph()	//default constructor
{
	
}

void Graph::insert_edge(int source, int destination, double weight)
{
	graph[source][destination] = weight;
	
	if(vertices.find(source) == vertices.end())
	{
		vertices.insert(source);
	}
	
	if(vertices.find(destination) == vertices.end())
	{
		vertices.insert(destination);
	}
}

void Graph::remove_edge(int source, int destination)
{
	if(graph.find(source) == graph.end())
	{
		cout<<"source vertex not found<<endl";
		return;
	}
	
	auto it = graph[source].find(destination);
	
	if(it == graph[source].end())
	{
		cout<<"destination vertex is already not linked to source"<<endl;
		return;
	}
	
	graph.find(source)->second.erase(graph.find(source)->second.find(destination) );
}

void Graph::display()
{
	cout<<"\n----Displaying graph as adjacency list----"<<endl;
	
	for(auto i = graph.begin(); i != graph.end(); i++)
	{
		cout<<i->first<<" -> ";
		for(auto j = i->second.begin(); j!=i->second.end(); j++)
		{
			cout<<"("<<j->first<<","<<j->second<<") ";
		}
		cout<<endl;
	}
}

void Graph::bfs(int vertex)
{	
	cout<<"bfs from "<<vertex<<"-> ";
	map<int, bool> status;
	
	for(auto v : vertices)
	{
		status[v] = false;
	}

	queue<int> q;
	q.push(vertex);
	
	
	while(!q.empty())
	{
		vertex = q.front();
		
		if(status[vertex] == false)
		{
			cout<<vertex<<" ";
			status[vertex] = true;
		}
		
		q.pop();	//pop the current node from queue after printing it and push all the non-visited adjacent nodes to the queue.
		
	
		for(auto it = graph[vertex].begin(); it != graph[vertex].end(); it++)
		{
			if(status[it->first] == false)
			{
				q.push(it->first);
			}
		}
	}
	
	cout<<endl;
}

void Graph::dfs(int vertex)
{
	cout<<"dfs from "<<vertex<<"-> ";
	map<int, bool> status;
	for(int v : vertices)
	{
		status[v] = false;
	}
	
	stack<int> s;
	s.push(vertex);
	
	while(!s.empty())
	{
		vertex = s.top();
		
		if(status[vertex] == false)
		{
			cout<<vertex<<" ";
			status[vertex] = true;
			
		}
		s.pop();
		
		for(auto it = graph[vertex].begin(); it !=graph[vertex].end(); it++)
		{
			if(status[it->first] == false)
			{
				s.push(it->first);
			}
		}
	}
	cout<<endl;
}


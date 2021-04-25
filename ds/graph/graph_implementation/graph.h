#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>

class Graph
{
private:
	
public:
	std::unordered_map<int, std::unordered_map<int, double> > graph;
	std::unordered_set<int> vertices;
	
	Graph();
	void insert_edge(int src, int dest, double weight);
	void remove_edge(int src, int dest);
	void display();
// 	void bfs(int src);
};

#endif
/*	Adjacency list implementation of a graph using unordered maps */

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph
{
	private:
		unordered_map<int, unordered_map <int, double> > graph;
		unordered_set<int> vertices;
		
	public:
		Graph();
// 		Graph(unordered_map<int, unordered_map <int, double>> graph);
		void insert_edge(int, int, double);
		void remove_edge(int, int);
		void remove_vertex();
		void display();
		void bfs(int start_vertex);
		void dfs(int start_vertex);
};
#endif
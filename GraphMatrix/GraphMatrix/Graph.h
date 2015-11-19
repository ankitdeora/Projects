#ifndef GRAPH_H
#define GRAPH_H	

#include <iostream>
#include <stack>
#include <queue>

class Graph
{
private:
	int n;
	int **arr;
	bool *visited;
	

public:
	int *neighbourCount;
	Graph(int);
	
	void join(int,int);
	bool isConnected(int,int);
	void BFS(int);
	void DFS(int);
	void displayGraph();
	int count(){return n;}

};

#endif
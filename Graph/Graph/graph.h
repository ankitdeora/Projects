/* 
This is the Adjacency list implementation of graphs
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "node.h"
#include "queue.h"

using namespace std;

class graph
{
private:
	int N;
	node *graph_array; //array to store nodes

public:
	queue myQueue;
	graph();
	bool validNodes;

	void connectNodes(int x, int y);
	void displayGraph();
	bool belongToArray(int z);                     // checks if a node with value z is present in all nodes
	int indexOf(int value);						   // return index of a node
	bool connected(int c, int d);				   // checks if two nodes are connected

	int getCount(){return N;}

	void implementBFS(int srcKey);
	void displayBFS();
	void backTrack(int key);

	~graph();

};


#endif
#ifndef	QUEUE_H
#define QUEUE_H

#include <iostream>
#include "node.h"

using namespace std;


class queue
{
private:
	node *h_node;
	node *currentNode;
	int nodeCount;

public:
	queue();

	node *getHeadNode(){return h_node;}
	void setHeadNode(node *hNode){h_node = hNode;}

	void enqueue(int in_data);
	int dequeue();
	void displayQueue();
	int getCount();
	//node *findNode(string f_str);
	//void deleteNode(string d_str);
	bool hasNext();
	bool empty();
	int next();

	~queue();

};


#endif
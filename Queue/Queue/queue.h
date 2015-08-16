#ifndef	QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

using namespace std;

class node
{

private:
	string m_data;
	node *m_next;
	
public:
	node();
	node(string data);
	node(string data, node *next);

	string getData(){return m_data;}
	node *getNextNode(){return m_next;}
	void setData(string text){m_data = text;}
	void setNextNode(node *newNode){m_next = newNode;}
	
	~node();

};

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

	void enqueue(string in_str);
	void dequeue();
	void displayQueue();
	int getCount();
	//node *findNode(string f_str);
	//void deleteNode(string d_str);
	bool hasNext();
	string next();

	~queue();

};


#endif
#ifndef	STACK_H
#define STACK_H

#include <iostream>
#include <string>

using namespace std;

class node
{

private:
	string m_data;
	int m_key;
	node *m_next;
	
public:
	node();
	node(string data);
	node(string data, node *next);

	string getData(){return m_data;}
	node *getNextNode(){return m_next;}
	int getKey(){return m_key;}
	void setData(string text){m_data = text;}
	void setNextNode(node *newNode){m_next = newNode;}
	void setKey(int key){m_key = key;}

	~node();

};

class stack
{
private:
	node *h_node;
	node *currentNode;
	int nodeCount;

public:
	stack();

	node *getHeadNode(){return h_node;}
	void setHeadNode(node *hNode){h_node = hNode;}

	void push(string in_str);
	void pop();
	void displayStack();
	int getCount();
	//node *findNode(string f_str);
	//void deleteNode(string d_str);
	bool hasNext();
	string next();

	~stack();

};


#endif
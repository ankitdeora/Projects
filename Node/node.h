#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class node
{

private:
	int m_key;
	node* m_next;
	
public:
	node();
	node(int key);
	node(int key, node *next);

	int getKey(){return m_key;}
	node* getNextNode(){return m_next;}
	
	void setKey(int key){m_key = key;}
	void setNextNode(node *newNode){m_next = newNode;}
	
	~node();

};

#endif
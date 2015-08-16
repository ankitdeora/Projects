#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class node
{

private:
	int m_key;
	node* m_next;
	int parentKey;
	int distance;
	
public:
	node();
	node(int key);
	node(int key, node *next);

	int getKey(){return m_key;}
	node* getNextNode(){return m_next;}
	int getParent(){return parentKey;}
	int getDistance(){return distance;}

	void setKey(int key){m_key = key;}
	void setNextNode(node *newNode){m_next = newNode;}
	void setParent(int parentKey){this->parentKey = parentKey;}
	void setDistance(int distance){this->distance = distance;}

	~node();

};

#endif
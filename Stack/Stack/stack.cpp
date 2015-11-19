#include "stack.h"

node::node()
{
	m_next = NULL;
	m_key = 0;
}

node::node(string data)
{
	m_data = data;
	m_next = NULL;
	m_key = 0;
}

node::node(string data, node *next)
{
	m_data = data;
	m_next = next;
	m_key = 0;
}

node::~node()
{
}

stack::stack()
{
	nodeCount = 0;
	h_node = NULL;
	currentNode = NULL;
}

void stack::push(string in_str)
{
	node *ptrNode = new node(in_str);
	node *temp = h_node;
	ptrNode->setNextNode(temp);
	h_node = ptrNode;
	currentNode = h_node;
	nodeCount++;
}

void stack::pop()
{
	node *temp = h_node;
	h_node = h_node->getNextNode();
	delete temp;
	temp = NULL;
	currentNode = h_node;
	nodeCount--;
}

void stack::displayStack()
{
	node *temp = h_node;
	cout<<"<-"<<h_node->getData();

	while(temp->getNextNode()!=NULL)
	{
		temp = temp->getNextNode();
		cout<<"<-"<<temp->getData();
	}
	cout<<endl;
}

int stack::getCount()
{
	return nodeCount;
}

bool stack::hasNext()
{
	return currentNode->getNextNode()!= NULL;
}

string stack::next()
{
	if (hasNext())
	{
		currentNode = currentNode->getNextNode();
		return currentNode->getData();
	}
	else
		return "no next node";
}

stack::~stack()
{
}
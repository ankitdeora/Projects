#include "queue.h"

node::node()
{
	m_next = NULL;
}

node::node(string data)
{
	m_data = data;
	m_next = NULL;
}

node::node(string data, node *next)
{
	m_data = data;
	m_next = next;
}

node::~node()
{
}

queue::queue()
{
	nodeCount = 0;
	h_node = NULL;
	currentNode = NULL;
}

void queue::enqueue(string in_str)
{
	node *ptrNode = new node(in_str);
	node *temp = h_node;

	//ptrNode->m_data = in_str;
	
	if (nodeCount==0)
	{
		h_node = ptrNode;
	}
	else
	{
		ptrNode->setNextNode(temp);
		h_node = ptrNode;
	}
	currentNode = h_node;
	nodeCount++;
}

void queue::dequeue()
{
	node *temp = h_node;
	node *prev = new node;
	while(temp->getNextNode()!=NULL)
	{
		prev =  temp;
		temp = temp->getNextNode();
	}
	delete temp;
	temp = 0;
	prev->setNextNode(NULL);
	//temp = NULL;
	
	currentNode = h_node;
	nodeCount--;
}

void queue::displayQueue()
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

int queue::getCount()
{
	return nodeCount;
}

bool queue::hasNext()
{
	return currentNode->getNextNode()!= NULL;
}

string queue::next()
{
	if (hasNext())
	{
		currentNode = currentNode->getNextNode();
		return currentNode->getData();
	}
	else
		return "no next node";
}

queue::~queue()
{
}
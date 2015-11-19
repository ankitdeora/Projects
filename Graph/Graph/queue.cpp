#include "queue.h"

queue::queue()
{
	nodeCount = 0;
	h_node = NULL;
	currentNode = NULL;
}

void queue::enqueue(int in_data)
{
	node *ptrNode = new node(in_data);
	node *temp = h_node;
	ptrNode->setNextNode(temp);
	h_node = ptrNode;
	currentNode = h_node;
	nodeCount++;
}

int queue::dequeue()
{
	int retval=0;
	node *temp = h_node;
	node *prev = new node;
	while(temp->getNextNode()!=NULL)
	{
		prev =  temp;
		temp = temp->getNextNode();
	}
	retval = temp->getKey();
	delete temp;
	temp = 0;
	prev->setNextNode(NULL);
	//temp = NULL;
	
	currentNode = h_node;
	nodeCount--;
	return retval;
}

void queue::displayQueue()
{
	node *temp = h_node;
	cout<<"<-"<<h_node->getKey();

	while(temp->getNextNode()!=NULL)
	{
		temp = temp->getNextNode();
		cout<<"<-"<<temp->getKey();
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

int queue::next()
{
	if (hasNext())
	{
		currentNode = currentNode->getNextNode();
		return currentNode->getKey();
	}
	else
		return -1;
}

bool queue::empty()
{
	return nodeCount == 0;
}

queue::~queue()
{
}
#include "graph.h"

graph::graph()
{
	validNodes = false;
	cout<<"enter value of N"<<endl;
	cin>>N;

	cout<<"enter values of nodes other than 0 (zero indicates node is empty)"<<endl;
	graph_array = new node[N];

	int n;
	for(int i=0;i<N;i++)
	{
		cin>>n;
		graph_array[i].setKey(n);
	}

}

void graph::connectNodes(int x, int y)
{
	bool valid = false;

	while(!valid)
	{
		while(!(belongToArray(x)&&belongToArray(y)))
		{
			cout<<"either x or y is out of array, enter again"<<endl;
			cin>>x;
			cin>>y;
		}

		valid = true;

		if(connected(x,y))
		{
			valid = false;
			cout<<"already connected, enter again"<<endl;
			cin>>x;
			cin>>y;	
		}
	}
			
	int p = indexOf(x);
	int q = indexOf(y);

	node *entering_node_x = new node(y);
	node *temp_x = graph_array[p].getNextNode();
	graph_array[p].setNextNode(entering_node_x);
	entering_node_x->setNextNode(temp_x);

	node *entering_node_y = new node(x);
	node *temp_y = graph_array[q].getNextNode();
	graph_array[q].setNextNode(entering_node_y);
	entering_node_y->setNextNode(temp_y);

}


void graph::displayGraph()
{
	//cout<<"entered display"<<endl;
	for(int j=0;j<N;j++)
	{
		cout<<graph_array[j].getKey()<<':';
		node *temp = graph_array[j].getNextNode();
		while(temp!=NULL)
		{
			cout<<temp->getKey()<<',';
			temp = temp->getNextNode();
		}
		cout<<endl;
	}
}
	
bool graph::belongToArray(int z)
{
	int index;
	for(index=0;index<N;index++)
	{
		if(z==graph_array[index].getKey()) break;
	}
	return index<N?true:false;
}

int graph::indexOf(int value)
{
	int j=0;
	while(j<N) 
	{
		if(graph_array[j].getKey()==value) return j;
		j++;
	}
	cout<<"index out of range"<<endl;
	return -1;
}

bool graph::connected(int c,int d)
{
	if(c==d) return true;

	int c_id = indexOf(c);
	node *temp = graph_array[c_id].getNextNode();
	while(temp!=NULL)
	{
		if(temp->getKey()==d) break;
		temp = temp->getNextNode();
	}
	return temp==NULL?false:true;

}

void graph::implementBFS(int srcKey)
{
	int src_id = indexOf(srcKey);
	graph_array[src_id].setParent(-100);

	myQueue.enqueue(srcKey);

	while(!myQueue.empty())
	{
		cout<<"queue outflow"<<endl;
		myQueue.displayQueue();
		int visitingKey = myQueue.dequeue();
		int visiting_id = indexOf(visitingKey);
		node* parent = &graph_array[visiting_id];
		node* temp = graph_array[visiting_id].getNextNode();

		while(temp!=NULL)
		{
			int tempKey = temp->getKey();
			int temp_id = indexOf(tempKey);
			int actual_parent = graph_array[temp_id].getParent();

			//cout<<"entered BFS"<<endl;
			if(actual_parent==-1) 
			{
				myQueue.enqueue(temp->getKey());
				int temp_id = indexOf(temp->getKey());
				graph_array[temp_id].setDistance(parent->getDistance()+1);
				graph_array[temp_id].setParent(parent->getKey());
				//cout<<"success"<<endl;
			}
			temp = temp->getNextNode();
		}
	}
}

void graph::backTrack(int key)
{
	int key_id,distance;
	do
	{
		cout<<key<<"->";
		key_id = indexOf(key);
		distance = graph_array[key_id].getDistance();
		key = graph_array[key_id].getParent();

	}while(distance!=0);
	cout<<endl;
}

void graph::displayBFS()
{
	cout<<"displaying BFS"<<endl;
	int k;
	for(k=0;k<N;k++)
	{
		cout<<graph_array[k].getKey()<<":"<<graph_array[k].getParent()<<","<<graph_array[k].getDistance()<<endl;
	}
}

graph::~graph()
{
	cout<<"entered destructor"<<endl;
}
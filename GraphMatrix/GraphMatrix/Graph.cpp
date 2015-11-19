#include "Graph.h"

Graph::Graph(int n)
{
	this->n = n;
	arr = new int*[n];
	visited = new bool[n]();
	neighbourCount = new int[n]();
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
		arr[i] = new int[n]();
	}
}

void Graph::join(int x,int y)
{
	if((x>=n||y>=n)||(x<0||y<0)) std::cout<<"Nodes out of range"<<std::endl;
	else
	{
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
}

bool Graph::isConnected(int x,int y)
{
	return ((arr[x][y]==1)&&(arr[y][x]==1));
}

void Graph::DFS(int src)
{
	std::stack<int> dfs_stack;
	
	dfs_stack.push(src);

	while(!dfs_stack.empty())
	{
		int current = dfs_stack.top();
		dfs_stack.pop();
		std::cout<<current<<"->";
		visited[current] = true;
		for(int i=0;i<n;i++)
		{
			if((!visited[i])&&(isConnected(current,i)))
			{
				neighbourCount[current]++;
				visited[i] = true;
				dfs_stack.push(i);
			}
		}
	}
	std::cout<<std::endl;
}

void Graph::BFS(int src)
{
	std::queue<int> dfs_queue;
	
	dfs_queue.push(src);

	while(!dfs_queue.empty())
	{
		int current = dfs_queue.front();
		dfs_queue.pop();
		visited[current] = true;
		for(int i=0;i<n;i++)
		{
			if((!visited[i])&&(isConnected(current,i)))
			{
				std::cout<<i<<"->";
				visited[i] = true;
				dfs_queue.push(i);
			}
		}
	}
}
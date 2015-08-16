#pragma once

#include "graph.h"

int main()
{
	graph mygraph;
	
	cout<<endl<<"enter no. of edges"<<endl;
	int num_edges;
	cin>>num_edges;

	int a=0;
	int b=0;
	for(int p=0;p<num_edges;p++)
	{
		cout<<endl<<"enter nodes to connect"<<endl;
		cin>>a;
		cin>>b;

		mygraph.connectNodes(a,b);
	}

	cout<<endl;
	mygraph.displayGraph();

	cout<<"enter source key"<<endl;
	int c;
	cin>>c;
	mygraph.implementBFS(c);
	mygraph.displayBFS();

	for(int j = 0;j<5;j++)
	{
		cout<<"enter key to back track"<<endl;
		cin>>c;
		mygraph.backTrack(c);
	}
	cin>>c;

	return 0;
}

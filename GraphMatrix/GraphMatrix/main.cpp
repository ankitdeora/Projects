#include "Graph.h"
#include <conio.h>

int main()
{
	Graph myGraph(13);

	myGraph.join(1,2);
	myGraph.join(1,7);
	myGraph.join(1,8);
	myGraph.join(2,3);
	myGraph.join(2,6);
	myGraph.join(3,4);
	myGraph.join(3,5);
	myGraph.join(8,9);
	myGraph.join(8,12);
	myGraph.join(10,9);
	myGraph.join(11,9);

	myGraph.DFS(1);
	//myGraph.BFS(1);
	for(int j=0;j<myGraph.count();j++) std::cout<<myGraph.neighbourCount[j]<<",";

	_getch();
	return 0;
}
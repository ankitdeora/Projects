#include "UnionFind.h"

UnionFind::UnionFind(int n)
{
	N = n;
	arr = new int[N];
	int i;
	for(i=0;i<N;i++)
	{
		arr[i] = i;
	}
}

void UnionFind::join(int x, int y)
{
	int j;
	int temp_x = arr[x];
	int temp_y = arr[y];

	for(j=0;j<N;j++)
	{
		if (arr[j] == temp_x)
		{
			arr[j] = temp_y;
		}
	}
}

bool UnionFind::connected(int p, int q)
{
	return arr[p] == arr[q];
}

void UnionFind::display_arr()
{
	int i;
	for(i=0;i<N;i++)
	{
		cout << arr[i] << " ";
	}
	cout<<endl;
}
		
		
UnionFind::~UnionFind()
{
	delete[] arr;
	arr = 0;
	cout << "destructor called"<< endl;
}

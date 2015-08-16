#include "QuickUnion.h"

QuickUnion::QuickUnion(int n)
{
	N = n;
	arr = new int[N];
	int i;
	for(i=0;i<N;i++)
	{
		arr[i] = i;
	}
}

int QuickUnion::root(int a)
{
	while(a!=arr[a])
	{
		a = arr[a];
	}
	return a;
}


void QuickUnion::join(int x, int y)
{
	int p = root(x);
	int q = root(y);
	arr[p] = q;
}

bool QuickUnion::connected(int p, int q)
{
	return root(p) == root(q);
}

void QuickUnion::display_arr()
{
	int i;
	for(i=0;i<N;i++)
	{
		cout << arr[i] ;
	}
}
		
		
QuickUnion::~QuickUnion()
{
	delete[] arr;
	arr = 0;
	cout << "destructor called"<< endl;
}

#ifndef QUICK_UNION_H
#define QUICK_UNION_H

#include <iostream>
using namespace std;

class QuickUnion
{
private:
	int N;
	int *arr;
	//int arr[50];
	
public:
	QuickUnion(int n);
	void join(int x, int y);
	bool connected(int p, int q);
	void display_arr();
	int root(int a);
	~QuickUnion();

};

#endif
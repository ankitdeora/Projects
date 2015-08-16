#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <iostream>
//#include <new>
//#include "stdafx.h"
using namespace std;

class UnionFind
{
private:
	int N;
	int *arr;
	//int arr[50];
	
public:
	UnionFind(int n);
	void join(int x, int y);
	bool connected(int p, int q);
	void display_arr();
	~UnionFind();

};

#endif
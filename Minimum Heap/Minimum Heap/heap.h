/* Implementation of MinHeap */

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <conio.h>

using namespace std;

struct heap
{
	int* arr;
	int capacity;
	int heap_size;	
};


heap* newHeap(int);
void insert(heap*,int);
int parentIndex(int);
int leftIndex(int);
int rightIndex(int);
void swapValues(int*,int*);
void printHeap(heap*);
void deleteKey(heap*,int);
void heapify(heap*,int);
int* heapSortedArray(heap*);



#endif
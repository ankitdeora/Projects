#include "heap.h"

heap* newHeap(int cap)
{
	heap* temp = new heap;
	temp->arr = new int[cap];
	temp->capacity = cap;
	temp->heap_size = 0;
	return temp;
}

int parentIndex(int i)
{
	return (i-1)/2;
}

int leftIndex(int parentIndex)
{
	return 2*parentIndex+1;
}

int rightIndex(int parentIndex)
{
	return 2*parentIndex+2;
}

void swapValues(int*a,int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(heap* m_heap,int key)
{
	if(m_heap->heap_size==m_heap->capacity)
	{
		cout<<"heap is full, can't insert more keys"<<endl;
		return;
	}

	m_heap->heap_size++;
	int i = m_heap->heap_size - 1;
	m_heap->arr[i] = key;
	
	while(i!=0)
	{
		if(m_heap->arr[parentIndex(i)]<m_heap->arr[i]) break;
		else
		{
			swapValues(&m_heap->arr[i],&m_heap->arr[parentIndex(i)]);
			i = parentIndex(i);
		}
	}
}

void deleteKey(heap* m_heap,int index)
{
	if(m_heap->heap_size==0) return;
	if(index>=m_heap->heap_size)
	{
		cout<<"index out of range"<<endl;
		return;
	}
	else
	{
		m_heap->arr[index] = m_heap->arr[m_heap->heap_size-1];
		m_heap->heap_size--;
		heapify(m_heap,index);
	}
}

void heapify(heap* m_heap,int index)
{
	if(m_heap->heap_size==0) return;

	int l_index = leftIndex(index);
	int r_index = rightIndex(index);

	int min_index = -1;

	if(l_index<m_heap->heap_size)
	{
		if(r_index<m_heap->heap_size)
		{
			min_index = (m_heap->arr[l_index]<m_heap->arr[r_index]) ? l_index : r_index;
		}
		else min_index = l_index;
	}
	else return;

	swapValues(&m_heap->arr[min_index],&m_heap->arr[index]);
	heapify(m_heap,min_index);

}

int* heapSortedArray(heap* m_heap)
{
	int N = m_heap->heap_size;
	int* a = new int[N];
	int i = 0;

	while(m_heap->heap_size!=0)
	{
		int lastIndex = m_heap->heap_size - 1;
		a[i] = m_heap->arr[0];
		swapValues(&m_heap->arr[0],&m_heap->arr[lastIndex]);
		deleteKey(m_heap,lastIndex);
		heapify(m_heap,0);
		i++;
		printHeap(m_heap);
	}
	return a;
}

void printHeap(heap* m_heap)
{
	for(int i=0;i<m_heap->heap_size;i++)
	{
		cout<<m_heap->arr[i]<<",";
	}
	cout<<endl;
}
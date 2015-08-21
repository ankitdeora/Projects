#include "heap.h"

int main()
{
	heap* MyHeap = newHeap(12);

	insert(MyHeap,1);
	insert(MyHeap,4);
	insert(MyHeap,6);
	insert(MyHeap,10);
	insert(MyHeap,12);
	insert(MyHeap,8);
	insert(MyHeap,11);
	insert(MyHeap,14);
	insert(MyHeap,17);
	insert(MyHeap,15);
	
	printHeap(MyHeap);

	//deleteKey(MyHeap,0);
	//printHeap(MyHeap);

	int size = MyHeap->heap_size;
	int* arr = heapSortedArray(MyHeap);
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<",";
	}
	cout<<endl;

	_getch();
	return 0;
}
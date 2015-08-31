#include "sortArray.h"

int main()
{
	int number;
	cout<<"enter value of n"<<endl;
	cin>>number;

	sortArray Array_object(number);
	//Array_object.insertionSortA();
	//Array_object.selectionSort();
	//Array_object.bubbleSort();
	//Array_object.insertionSortB();
	int size = Array_object.getSize();
	Array_object.mergeSort(0,size-1);
	Array_object.displaySortedArray();
	_getch();

	return 0;
}
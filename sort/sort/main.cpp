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
	Array_object.insertionSortB();
	Array_object.displaySortedArray();
	_getch();

	return 0;
}
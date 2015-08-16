#include "sortArray.h"

int main()
{
	int number;
	cout<<"enter value of n"<<endl;
	cin>>number;

	sortArray Array_object(number);
	//Array_object.insertionSort();
	Array_object.selectionSort();
	Array_object.displaySortedArray();
	cin>>number;

	return 0;
}
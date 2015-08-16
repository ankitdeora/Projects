#include "sortArray.h"


sortArray::sortArray(int n)
{
	N=n;
	arr = new int[N];
	sortedArray = new int[N]; 
	srand (time(NULL));

	for(int i=0;i<N;i++)
	{
		sortedArray[i] = arr[i] = static_cast<int>(rand() % N + 1);
	}

}

void sortArray:: insertionSort()
{
	int i, key, j;
   for (i = 1; i < N; i++)
   {
       key = sortedArray[i];
       j = i-1;
 
       while (j >= 0 && sortedArray[j] > key)
       {
           sortedArray[j+1] = sortedArray[j];
           j = j-1;
       }
       sortedArray[j+1] = key;
   }

}

void sortArray::selectionSort()
{
	int i,j,min_val,min_key;
	for(i=0;i<N;i++)
	{
		min_val = sortedArray[i];
		min_key = i;

		for(j=i;j<N;j++)
		{
			if(sortedArray[j]<min_val)
			{
				min_val = sortedArray[j];
				min_key = j;
			}
		}

		sortedArray[min_key] = sortedArray[i];
		sortedArray[i] = min_val;
	}

}

void sortArray::shellSort()
{

}

void sortArray::mergeSort()
{

}

void sortArray::displaySortedArray()
{
	cout<<"original array:";
	for(int i=0;i<N;i++)
	{
		cout<<arr[i]<<',';
	}
	cout<<endl;

	cout<<"sorted array:";
	for(int i=0;i<N;i++)
	{
		cout<<sortedArray[i]<<',';
	}
	cout<<endl;
}

sortArray::~sortArray(void)
{

}

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

void sortArray::insertionSortB()
{
	for(int i=1;i<N;i++)
	{
		int j = i;
		while(arr[j-1]>arr[j])
		{
			swap(&arr[j],&arr[j-1]);
			j--;
			if(j==0) break;
		}
	}
}

void sortArray:: bubbleSort()
{
	for(int i=N-1;i>=0;i--)
	{
		bool onceSwapped = false;
		for(int j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				onceSwapped = true;
			}
		}
		if(!onceSwapped) break;
	}
}

void sortArray:: swap(int* a,int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}
void sortArray:: insertionSortA()
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

	/*cout<<"sorted array:";
	for(int i=0;i<N;i++)
	{
		cout<<sortedArray[i]<<',';
	}
	cout<<endl;*/
}

sortArray::~sortArray(void)
{

}

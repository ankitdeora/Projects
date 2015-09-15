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

void sortArray:: mergeSort(int l,int r)
{
	 if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}

void sortArray:: merge(int l,int m,int r)
{
	int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
	int* L = new int[n1]; 
	int* R = new int[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int sortArray::partitionIndex(int l,int r)
{
	int lastElement = arr[r];
	int pIndex = l;
	for(int i=l;i<r+1;i++)
	{
		if(arr[i]<=lastElement)
		{
			swap(&arr[i],&arr[pIndex]);
			pIndex++;
		}
	}
	return (pIndex-1);
}

void sortArray::quickSort(int left,int right)
{
	if(left<right)
	{
		int p_index = partitionIndex(left,right);
		quickSort(left,p_index-1);
		quickSort(p_index+1,right);
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

int sortArray::getSize()
{
	return N;
}
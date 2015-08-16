#pragma once

#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <time.h>       /* time */

using namespace std;

class sortArray
{
private:
	int *arr;
	int N;
	int *sortedArray;

public:
	sortArray(int n);

	void insertionSort();
	void selectionSort();
	void shellSort();
	void mergeSort();
	void quickSort();

	void displaySortedArray();

	~sortArray(void);
};


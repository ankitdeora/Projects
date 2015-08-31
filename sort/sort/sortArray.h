#pragma once

#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <time.h>       /* time */
#include <conio.h>

using namespace std;

class sortArray
{
private:
	int *arr;
	int N;
	int *sortedArray;

public:
	sortArray(int n);

	void insertionSortA();
	void insertionSortB();
	void selectionSort();
	void bubbleSort();
	void shellSort();
	void mergeSort(int,int);
	void merge(int,int,int);

	void quickSort();
	void swap(int*,int*);

	void displaySortedArray();
	int getSize();

	~sortArray(void);
};


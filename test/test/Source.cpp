//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int* arr = new int[n];

	for(int i=0;i<n;i++) cin>>arr[i];

	for(int j=0;j<n;j++) cout<<arr[j]<<" ";
	cout<<endl;


	delete[] arr;

	int* num = new int;
	cin>>*num;

	delete num;

  _getch();
  return 0;
}


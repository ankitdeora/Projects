#include <iostream>
#include <stdint.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n=0;
	cin>>n;

	uint64_t* arr;
	arr = new uint64_t[n];

	for(int j=0;j<n;j++)
	{
		cin>>arr[j];
	}

	for(int i=0;i<n;i++)
	{
		uint64_t var = 1;
		int div_count = 0;
		while(div_count<3)
		{
			if(arr[i]%var==0) div_count++;
			var++;
		}

		if(var!=arr[i])
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}

	return 0;
}
#include <iostream>
#include <conio.h>

using namespace std;

int mod(int);
int main()
{
	int t=0;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		char str[10000];
		int size=0;
		cin>>str;
		while(str[size]!='\0') size++;
		
		char *rev_str = new char[size+1];
	
		int j=0;
		while(j!=size)
		{
			rev_str[j]=str[size-j-1];
			j++;
		}
		rev_str[size]='\0';
		//cout<<rev_str<<endl;

		int k=1;
		int str_val=0;
		int rev_str_val=0;
		while(k!=size)
		{
			str_val = mod(int(str[k]) - int(str[k-1]));
			rev_str_val = mod(int(rev_str[k]) - int(rev_str[k-1]));
			if(str_val!=rev_str_val)
			{
				cout<<"Not Funny"<<endl;
				break;
			}
			k++;
		}
		if(k==size) cout<<"Funny"<<endl;
		
	}
	_getch();
	return 0;
}

int mod(int a)
{
	return a>0?a:-a;
}
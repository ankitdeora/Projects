

#include <conio.h>
#include "QuickUnion.h"
//#include "UnionFind.h"

int main()
{
	cout << "enter an integer"<<endl;
	
	int number;
	cin >> number;

	//UnionFind UF(number);
	QuickUnion UF(number);
	UF.display_arr();
	//return 0;

	cout << "doing union and find operations"<< endl;
	UF.join(4,3);
	UF.display_arr();

	UF.join(7,8);
	UF.display_arr();

	UF.join(3,8);
	UF.display_arr();

	cout << UF.connected(4,7);
	_getch();

	return 0;
}


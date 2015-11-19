#include "stack.h"
#include <conio.h>

int main()
{
	stack myStack;

	myStack.push("you");
	myStack.displayStack();
	cout << myStack.getCount()<<endl;

	myStack.push("rock");
	myStack.displayStack();
	cout << myStack.getCount()<<endl;

	myStack.push("at");
	myStack.displayStack();
	cout << myStack.getCount()<<endl;
	
	myStack.push("this");
	myStack.displayStack();
	cout << myStack.getCount()<<endl;
	
	myStack.pop();
	myStack.displayStack();
	cout << myStack.getCount()<<endl;
	
	myStack.pop();
	myStack.displayStack();
	cout << myStack.getCount()<<endl;
	
	myStack.getHeadNode()->setData("it");
	myStack.displayStack();
	cout << myStack.getCount()<<endl;
	
	/*node *helloNode;
	helloNode = new node("ankit");
	
	node *ByeNode;2
	ByeNode = helloNode;
	ByeNode->setData("harsha");*/
	//helloNode = NULL;
	/*
	cout<<myStack.hasNext()<<endl;
	cout<<myStack.next()<<endl;
	cout<<myStack.next()<<endl;
	cout<<myStack.next()<<endl;
	cout<<myStack.hasNext()<<endl;
	*/
	
	_getch();
	return 0;
}

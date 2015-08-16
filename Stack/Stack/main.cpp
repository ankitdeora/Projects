#include "stack.h"

int main()
{
	stack myStack;
	int number;

	myStack.push("you");
	myStack.displayStack();
	cout << myStack.getCount()<<endl;

	myStack.push("suck");
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
	cout<<myStack.hasNext()<<endl;
	cout<<myStack.next()<<endl;
	cout<<myStack.next()<<endl;
	cout<<myStack.next()<<endl;
	cout<<myStack.hasNext()<<endl;


	cin>>number;
	return 0;
}

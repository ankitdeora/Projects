#include "queue.h"

int main()
{
	queue myqueue;
	int number;

	myqueue.enqueue("you");
	myqueue.displayQueue();
	cout << myqueue.getCount()<<endl;

	myqueue.enqueue("suck");
	myqueue.displayQueue();
	cout << myqueue.getCount()<<endl;

	myqueue.enqueue("at");
	myqueue.displayQueue();
	cout << myqueue.getCount()<<endl;
	
	myqueue.enqueue("this");
	myqueue.displayQueue();
	cout << myqueue.getCount()<<endl;
	
	myqueue.dequeue();
	myqueue.displayQueue();
	cout << myqueue.getCount()<<endl;
	
	myqueue.dequeue();
	myqueue.displayQueue();
	cout << myqueue.getCount()<<endl;

	myqueue.getHeadNode()->setData("it");
	myqueue.displayQueue();
	cout << myqueue.getCount()<<endl;

	//node *helloNode;
	//helloNode = new node("ankit");
	
	//node helloNode;
	//helloNode = NULL;
	cout<<myqueue.hasNext()<<endl;
	cout<<myqueue.next()<<endl;
	cout<<myqueue.next()<<endl;
	cout<<myqueue.next()<<endl;
	cout<<myqueue.hasNext()<<endl;


	cin>>number;
	return 0;
}
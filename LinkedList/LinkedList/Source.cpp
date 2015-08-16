#include <iostream>
#include <conio.h>

using namespace std;

struct node
{
	int data;
	node* next;
};

node* newNode(int);
void printList(node*);
void push(int,node**);
void append(node*,int);
void pop(node*);
int length(node*);
void deleteHead(node**);

int main()
{
	node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	node** addr_head = &head;
	push(0,addr_head);
	append(head,4);
	append(head,5);
	printList(head);


	
	/*
	cout<<length(head)<<endl;
	pop(head);
	pop(head);
	printList(head);
	cout<<length(head)<<endl;
	
	deleteHead(&head);
	deleteHead(&head);
	printList(head);
	*/
	_getch();
	return 0;
}

void deleteHead(node** m_node)
{
	node* temp = *m_node;
	*m_node = (*m_node)->next;
	delete temp;
	temp = 0;
}

int length(node* m_node)
{
	if(m_node == NULL) return 0;
	else return 1+length(m_node->next);
}
void pop(node* m_node)
{
	node* prev=NULL;
	while(m_node->next!=NULL)
	{
		prev = m_node;
		m_node = m_node->next;
	}
	delete m_node;
	m_node = 0;
	prev->next = NULL;
}

void append(node* m_node, int data)
{
	node* temp = newNode(data);
	while(m_node->next!=NULL)
	{
		m_node = m_node->next;
	}
	m_node->next = temp;
	temp->next = NULL;
}

node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;
	return temp;	
}

void printList(node* header)
{
	node* temp = header;
	//head->data = 7;
	while(temp!=NULL)
	{
		cout<<temp->data<<",";
		temp = temp->next;
	}
	cout<<endl;
}

void push(int data,node** header)
{
	node* temp = newNode(data);
	temp->next = *header;
	*header = temp;
}

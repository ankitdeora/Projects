#include <iostream>
#include <conio.h>
using namespace std;

struct node
{	
	int data;
	node* left;
	node* right;
};

node* newNode(int);
void insert(int,node*);
void inorder(node*);
node* nodeSearch(int,node*);
void printPredSuc(int,node*);
int maxBST(node*);
int minBST(node*);
bool isBST(node*);
void printLCA(node*,int,int);
int AddLargerValuesToNodes(node*);
void preorder(node*);
void ceilValue(node*,int,int*); //this funciton can return successor as well as ceil value
node* ListToBST(int*,int,int);

int main()
{
	node* root = newNode(18);
	insert(32,root);
	insert(19,root);
	insert(14,root);
	insert(17,root);
	insert(13,root);
	insert(15,root);
	insert(30,root);
	insert(25,root);
	insert(35,root);
	
	/*
	              18
	           /     \
			 /        \
	        14         32
	      /   \        / \
		 13	   17    19   35
		      /		   \
			 15          30
					   /
				      25
	*/
	//int arr[]={10,5,1,7,40,50};
	//cout<<isBST(root)<<endl;
	
	//printLCA(root,25,35);
	inorder(root);
	
	//linked list implementation using BST right nodes only
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	cout<<endl;
	int size = sizeof(arr)/sizeof(arr[0]);
	node *newRoot = ListToBST(arr,0,size-1);
	preorder(newRoot);
	/*int x=-1;
	ceilValue(root,35,&x);
	cout<<endl<<x;*/
	//cout<<maxBST(root->right)<<","<<minBST(root->right);
	/*int n=-1;
	cin>>n;
	while(n!=0)
	{
		printPredSuc(n,root);	
		cin>>n;
	}*/
	
	//cout<<endl<<nodeSearch(100,root)<<endl;
	_getch();
	return 0;
}
node* ListToBST(int* a, int low,int high)
{
	if(low>high) return NULL;
	int mid = (low+high)/2;
	//if(low==high) return newNode(a[low]);
	node* root = newNode(a[mid]);
	/*if(low<=mid-1)*/  root->left = ListToBST(a,low,mid-1);
	/*if(mid+1<=high)*/ root->right = ListToBST(a,mid+1,high);
	return root;
}

void ceilValue(node* m_node,int key,int* ceilVal)
{
	if(m_node==NULL) return ;
	
	ceilValue(m_node->right,key,ceilVal);
	if(m_node->data>=key)// This gives ceil value remove '=' to get successor
	{
		*ceilVal = m_node->data;
		//return;
	}
	
	ceilValue(m_node->left,key,ceilVal);	
	
}
void printLCA(node* m_node,int n1,int n2)
{
	if(m_node==NULL) return;
	if(!(n1>m_node->data)&&!(n2<m_node->data)) cout<<m_node->data<<endl;
	else
	{
		printLCA(m_node->left,n1,n2);
		printLCA(m_node->right,n1,n2);	
	}
	
}

bool isBST(node* m_node)
{
	if(m_node==NULL) return true;
	//bool flag = m_node->left->data<m_node->data&&m_node->right->data>m_node->data;
	bool flagLeft = false;
	bool flagRight = false;
	if(isBST(m_node->left)&&isBST(m_node->right))
	{
		flagLeft = true;
		flagRight = true;
		if(m_node->left!=NULL) flagLeft = maxBST(m_node->left)<m_node->data;
		if(m_node->right!=NULL) flagRight = minBST(m_node->right)>m_node->data;
		return flagLeft&&flagRight;
	}
	return false;
}

int maxBST(node* m_node)
{
	if(m_node==NULL) return -1;
	
	while(m_node->right!=NULL)
	{
		m_node = m_node->right;
	}
	return m_node->data;
}

int minBST(node* m_node)
{
	if(m_node==NULL) return -1;
	
	while(m_node->left!=NULL)
	{
		m_node = m_node->left;
	}
	return m_node->data;
}

void printPredSuc(int key,node* m_node)
{
	int pred = -1;
	int suc = -1;
	
	while(m_node!=NULL)
	{
		if(m_node->data>key)
		{
			suc = m_node->data;
			m_node = m_node->left;
		}
		else if(m_node->data<key)
		{
			pred = m_node->data;
			m_node = m_node->right;
		}
		else if(m_node->data==key)
		{
			node* current = m_node->left;
			while(current!=NULL)
			{
				pred = current->data;
				current = current->right;
			}
			
			current = m_node->right;
			while(current!=NULL)
			{
				suc = current->data;
				current = current->left;
			}
			m_node = NULL;
		}
	}
	cout<<"pred:"<<pred<<", suc:"<<suc<<endl;
}
node* nodeSearch(int key,node* m_node)
{
	if(m_node==NULL) return NULL;
	if(m_node->data==key) return m_node;
	node* RN = nodeSearch(key,m_node->right);
	node* LN = nodeSearch(key,m_node->left);
	if(RN!=NULL) return RN;
	else if(LN!=NULL) return LN;
	return NULL;
}

void insert(int key, node* m_node)
{
	if(m_node->data<key)
	{
		if(m_node->right==NULL)
		{
			node* temp = newNode(key);
			m_node->right = temp;
		}
		else insert(key,m_node->right);
	}
	else 
	{
		if(m_node->left==NULL)
		{
			node* temp = newNode(key);
			m_node->left = temp;
		}
		else insert(key,m_node->left);
	}
}

void inorder(node *m_node)
{
    if (m_node != NULL)
    {
        inorder(m_node->left);
        printf("%d ", m_node->data);
        inorder(m_node->right);
    }
}
void preorder(node *m_node)
{
    if (m_node == NULL) return;
    printf("%d ", m_node->data);
    preorder(m_node->left);
    preorder(m_node->right);
}

node* newNode(int key)
{
	node* temp = new node;
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

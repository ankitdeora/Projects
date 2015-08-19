#include "BST.h"


node* newNode(int key)
{
	node* temp = new node;
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
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

bool sumExist(int* a,int N,int sum)
{
	int i = 0;
	int j = N-1;
	while(i!=j)
	{
		if(a[i]+a[j]==sum) return true;
		else if(a[i]+a[j]<sum) i++;
		else j--;
	}
	return false;

}

void storeToArray(node* m_node,int* a, int* index)
{
	if(m_node==NULL) return;
	storeToArray(m_node->left,a,index);
	
	a[*index] = m_node->data;
	(*index)++;
	
	storeToArray(m_node->right,a,index);
}


int sizeOfBST(node* m_node)
{
	if(m_node==NULL) return 0;
	return 1+sizeOfBST(m_node->left)+sizeOfBST(m_node->right);
}

node* ListToBST(int* a, int low,int high)
{
	if(low>high) return NULL;
	int mid = (low+high)/2;
	node* root = newNode(a[mid]);
	root->left = ListToBST(a,low,mid-1);
	root->right = ListToBST(a,mid+1,high);
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



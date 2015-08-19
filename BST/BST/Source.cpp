#include "BST.h"

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
	cout<<endl<<sizeOfBST(root)<<endl;
	
	/*
	int *arr;
	int count = 0;
	int n = sizeOfBST(root);
	arr = new int[n];
	storeToArray(root,arr,&count);
	cout<<sumExist(arr,n,41)<<endl;
	*/
	
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

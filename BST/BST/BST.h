#ifndef BST_H
#define BST_H

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
bool sumExist(int*,int,int);
int sizeOfBST(node*);
void storeToArray(node*,int*,int*);

#endif
/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node * balancedBST(struct node *root, int *arr, int start, int end);
struct node * SortedArraytoBST_insert(struct node *root, int data);
struct node * SortedArraytoBST_newNode(int data);
struct node * convert_array_to_bst(int *arr, int len){
	if (!arr || len < 1) {
		return NULL;
	}
	struct node *root = NULL;
	root = balancedBST(root, arr, 0, len - 1);
	return root;
}


struct node * SortedArraytoBST_newNode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * SortedArraytoBST_insert(struct node *root, int data) {
	if (!root) {
		return SortedArraytoBST_newNode(data);
	}
	else if (data < root->data) {
		root->left = SortedArraytoBST_insert(root->left, data);
	}
	else {
		root->right = SortedArraytoBST_insert(root->right, data);
	}
	return root;
}

struct node * balancedBST(struct node *root, int *arr, int start, int end) {
	if (start > end) {
		return root;
	}
	int mid = (start + end) / 2;
	root = SortedArraytoBST_insert(root, arr[mid]);
	int leftEnd = mid - 1;
	root = balancedBST(root, arr, start, leftEnd);
	start = mid + 1;
	root = balancedBST(root, arr, start, end);
	return root;
}


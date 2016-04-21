/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int inorder_helper(struct node *root, int *arr, int i)
{
	if (root == NULL)
	{
		return i;
	}
	else
	{
		//
		i=inorder_helper(root->left, arr, i);
		//printf("%d", root->data);
		arr[i++] = root->data; //printf("%d", arr[i]);
		i=inorder_helper(root->right, arr, i);
		return i;
	}

}

void inorder(struct node *root, int *arr){
	if (arr == NULL)
	{
		return;
	}
	int i = 0;
	i=inorder_helper(root, arr, i);
	
}
int preorder_helper(struct node *root, int *arr, int i)
{
	if (root == NULL)
	{
		return i;
	}
	else
	{
		arr[i++] = root->data; //printf("%d", arr[i]);
		printf("%2d", i);
		
		i=preorder_helper(root->left, arr,i);
		i=preorder_helper(root->right, arr,i);
		return i;
	}

}
void preorder(struct node *root, int *arr){
	if (arr == NULL)
	{
		return;
	}
	int i= preorder_helper(root, arr, 0);
}
int postorder_helper(struct node *root, int *arr, int i)
{
	if (root == NULL)
	{
		return i;
	}
	else
	{
		
		i=postorder_helper(root->left, arr, i);
		i=postorder_helper(root->right, arr, i);
		arr[i++] = root->data;  printf("%d", arr[i]);
		return i;
		//printf("%d", root->data);
	}
}
void postorder(struct node *root, int *arr){
	if (arr == NULL)
	{
		return;
	}
int	i=postorder_helper(root, arr, 0);
	
}
struct node * rootexists(struct node *root1, struct node *root2)
{
	if (root1 == NULL)
	{
		return NULL;
	}
	else if (root1->data == root2->data)
	{
		return root1;
	}
	else if (root1->data > root2->data)
	{
		return rootexists(root1->left, root2);
	}
	else
	{
		return rootexists(root1->right, root2);
		
	}

}
int identical_trees(struct node *root1, struct node *root2)
{
	if (root1 == NULL || root2 == NULL)
	{
		return 0;
	}
	else if (root1->data != root2->data)
	{
		return 0;
	}
	else
	{
		int l = identical_trees(root1->left, root2->left);
		int r = identical_trees(root1->right, root2->right);
		if (l == 0 || r == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	

}

int issubtree(struct node *root1, struct node *root2)
{

	struct node*newnode = rootexists(root1, root2);
	return identical_trees(newnode, root2);
}
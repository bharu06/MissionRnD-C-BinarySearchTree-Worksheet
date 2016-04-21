/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void printpath(struct node* root,int arr[],int i)
{
	
	if (root == NULL)
	{
		
		for (int k = 0; k <i; k++)
		{
			printf("%2d", arr[k]);
		}
		return;
	}
	else
	{
		arr[i] = root->data;
		printpath(root->left, arr, i+1);
		if (root->right == NULL)
		{
			return;
		}
		printpath(root->right, arr, i+1);
	}
}


int countNodes(struct node *root) {
	if (!root) {
		return 0;
	}
	int count = 1 + countNodes(root->left) + countNodes(root->right);
	return count;
}

int enqueue(struct node **queue, int rear, struct node *root) {
	if (!root) {
		return rear;
	}
	queue[rear] = root;
	rear++;
	return rear;
}

struct node * dequeue(struct node **queue, int front) {
	return queue[front];
}

int* addData(struct node **queue, int rear, int front, int *BSTRowsArr, int i) {
	while (front < rear) {
		rear = enqueue(queue, rear, (queue[front])->right);
		rear = enqueue(queue, rear, (queue[front])->left);
		struct node *node = dequeue(queue, front);
		BSTRowsArr[i] = node->data;
		i++;
		front++;
	}
	return BSTRowsArr;
}

int* BSTRighttoLeftRows(struct node* root)
{
	if (!root) {
		return NULL;
	}
	int noOfNodes = countNodes(root);
	struct node *queue[100];
	int rear = enqueue(queue, 0, root);
	int front = 0;
	int *BSTRowsArr = (int*)malloc(sizeof(int) * noOfNodes);
	int i = 0;
	BSTRowsArr = addData(queue, rear, front, BSTRowsArr, i);

	return BSTRowsArr;
}

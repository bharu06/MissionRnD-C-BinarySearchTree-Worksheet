/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};


struct node * new_node_spec(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return new_node_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}
void swap_nodes(struct node *a, struct node *b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

int main(){

	//Use it for testing ,Creating BST etc
	
	struct node *root = NULL;
	int nums[20] = { 50, 25, 75, 15, 35,
		90, 5, 17, 45, 120,
		1, 7, 19, 39, 49,
		100, 20, 21, 22, 23
	};

	for (int i = 0; i < 20; i++){
		root = add_node_spec(root, nums[i]);
	}

	int ans = 3;
	int dist = get_closest_leaf_distance(root, root->left->left->right);
	printf("%d", dist);

 	//printf("%d", issubtree(root1, root2));
	

	//fix_bst(root);
	//fix_bst(root)
	//int* a = BSTRighttoLeftRows( root);
	
}

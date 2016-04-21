/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .


  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced


         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void  check_nodes(struct node *root, struct node **first, struct node **second, struct node *top);
int isLeaf(struct node *node);
void fix_bst(struct node *root){
	if (root != NULL){
		struct node *first, *second;
		first = second = NULL;
		check_nodes(root, &first, &second, root);
		int n = first->data;
		first->data = second->data;
		second->data = n;
	}
}
int isLeaf(struct node *node){
	if (node->left == NULL && node->right == NULL){
		return 1;
	}
	else{
		return 0;
	}
}



void  check_nodes(struct node *root, struct node **first, struct node **second, struct node *top){
	if (root->left != NULL){
		if ((root->left)->data < root->data){
			if (root->data > top->data && root != top && *second == NULL && *first != top){
				*second = root->left;
			}
			check_nodes(root->left, first, second, top);
		}
		else{
			if (*first != NULL && *second != NULL){
				*second = root->left;
			}
			else if (isLeaf(root->left)){
				*first = root->left;
			}
			else{
				*first = root;
				check_nodes(root->left, first, second, top);
			}
		}
	}
	if (root->right != NULL){
		if ((root->right)->data > root->data){
			if (((root == top) || root->right->data > top->data) && isLeaf(root->right) && *second == NULL){
				if (*first != NULL && *first == top){
					*second = root->right;
				}
				else{
					*second = root;
				}
			}
			check_nodes(root->right, first, second, top);
		}
		else{
			if (*first == NULL){
				*first = root;
			}
			*second = root->right;
		}
	}
}

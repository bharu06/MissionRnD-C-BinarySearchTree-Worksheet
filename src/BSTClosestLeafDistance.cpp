/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
int get_min_height(struct node *root){
	if (!root) {
		return 0;
	}
	int height1 = get_min_height(root->left);
	height1++;
	int height2 = get_min_height(root->right);
	height2++;
	if (height1 > height2) {
		return height2;
	}
	else {
		return height1;
	}
}
int get_parent_to_root(struct node *root, struct node *temp,int height)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->data == temp->data)
	{
		return height;
	}
	return get_parent_to_root(root->left, temp, height + 1);
	return get_parent_to_root(root->right, temp, height + 1);

}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root==NULL||temp==NULL)
		 return -1;
	int subheight = get_min_height(temp);
	int parentheight = get_min_height(root);
	int parent_root = get_parent_to_root(root, temp,0);
	if ((parent_root + parentheight) >= subheight)
	{
		return subheight;
	}
	else
	{
		return (parent_root + parentheight);
	}
}
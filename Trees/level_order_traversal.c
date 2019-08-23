#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};


/* Function protoypes */
void printGivenLevel(struct node* root, int level); 
int height(struct node* node); 
struct node* newNode(int data); 

/* Function to print level 
order traversal a tree*/
void printLevelOrder(struct node* root) 
{ 
	int h = height(root); 
	int i; 
	for (i = 1; i <= h; i++) 
		printGivenLevel(root, i); 
} 

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level) 
{ 
	if (root == NULL) 
		return; 
	if (level == 1) 
		printf("\n%d",root->data); 
	else if (level > 1) 
	{ 
		printGivenLevel(root->left, level-1); 
		printGivenLevel(root->right, level-1); 
	} 
} 

int height(struct node* node) 
{ 
	if (node == NULL) 
		return 0; 
	else
	{ 

		int lheight = height(node->left); 
		int rheight = height(node->right); 

		/* use the larger one */
		if (lheight > rheight) 
			return(lheight + 1); 
		else return(rheight + 1); 
	} 
} 

struct node* newNode(int data) 
{ 
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node->data = data; 
	Node->left = NULL; 
	Node->right = NULL; 

	return(Node); 
} 

/* Driver code*/
int main() 
{ 
	struct node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

	printf("Level Order traversal of binary tree is \n"); 
	printLevelOrder(root); 

	return 0; 
} 
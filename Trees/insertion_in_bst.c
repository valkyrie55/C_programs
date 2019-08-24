// C program to insert operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 
   
struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 
   
struct node *createnode(int val) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->data = val; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

struct node* insert(struct node* node, int val)
{
    if(node == NULL)
    	return createnode(val);  //root created
    if(val < node->data)
        node->left = insert(node->left ,val);
    else if (val > node->data)
    	node->right = insert(node->right,val);
    return node;
}

void display(struct node* root){
	if(root!= NULL){
		display(root->left);
		printf("\n%d", root->data);
		display(root->right);
	}
}
int main()
{
	struct node* root = NULL;
	root = insert(root,50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
    insert(root, 80);
    printf("\n tree created!");
    display(root);
    return 0;
}

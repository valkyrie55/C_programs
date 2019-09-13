//find minimum value in BST
//Ans: Traverse to the leftmost node
#include<stdio.h>
#include<stdlib.h>
struct node{
	char data;
	struct node* left , *right;
};

struct node* newNode(int data)  
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data  = data; 
  node->left  = NULL; 
  node->right = NULL; 
    
  return(node); 
} 
 
struct node* insert(struct node* node, int data){
	if(node == NULL)
		return(newNode(data));
	else{
		if(data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);
		return node;
	}
} 

int minvalue(struct node* node){
	struct node* curr = node;
	//traverse to the leftmost node
	while(curr->left!= NULL){
		curr = curr->left;
	}
	return(curr->data);
}

 int main(){
 	struct node* root= NULL;
 	root = insert(root,4);
 	insert(root,2);
 	insert(root,1);
 	insert(root,3);
 	insert(root,6);
 	insert(root,5);
 	printf("\nMinimum value: %d ",minvalue(root) );
 	return 0;
 }

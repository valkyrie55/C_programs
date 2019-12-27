#include<stdio.h>
#include<stdlib.h>
int count =0;
struct node{
	int data;
	struct node* left, *right;
};

struct node* create(int val){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->data = val;
	n->left = n->right = NULL;
	return n;
}

struct node* insert(struct node* node, int val){
	if(node == NULL)
		return create(val);
	if(val < node->data)
		node->left = insert(node->left, val);
	else if(val > node->data)
		node->right = insert(node->right, val);
	return node;
}

void display(struct node* node){
	if(node != NULL){
		printf("\n%d",node->data);
		display(node->left);
		display(node->right);
	}
}

int count_leaf(struct node* node){
	if(node == NULL)
		return -1;
	if(node->left == NULL)
		count++;
	else if(node->right == NULL)
		count++;
	else{
		count_leaf(node->left);
		count_leaf(node->right);
	}
	return count;
}

int main(){
	int i, val;
	struct node* root = NULL;
	root = insert(root, 50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,100);
	insert(root,120);
	display(root);
	printf("\n Total no. of leaf nodes: %d", count_leaf(root));
	return 0;
}

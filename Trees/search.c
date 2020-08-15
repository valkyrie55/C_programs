// Search for an element in BST
# include<stdio.h>
# include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
} *root = NULL, *temp;

void display(struct node* node){
	if(node!= NULL){ 	//preorder
		printf("\n%d", node->data);
		display(node->left);
		display(node->right);
	}
}

struct node* create(int val){
	//create new node
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

int search(struct node* node, int val){
	if(node== NULL){
		printf("\nTree is empty");
		return -1;
	}
	else if(val == node->data)
		return 1;
	else if(val < node->data)
		node = node->left;
	else
		node = node->right;

	while(node != NULL){
		if(val == node->data)
			return 1;
		else if(val < node->data)
			node = node->left;
		else
			node = node->right;
	}
	return -1;
}

int main(){
	int x,i;
	root = insert(root, 50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,100);
	display(root);
	printf("\nEnter the value you wanna search!");
	scanf("%d", &x);
	i = search(root, x);
	if(i == -1)
		printf("\n%d doesn't exists",x);
	else
		printf("\n%d exists",x);
	return 0;
}

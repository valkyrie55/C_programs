#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* createnode(int val){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void print_inorder(struct node* node){
	if(node == NULL)
		return;
	print_inorder(node->left);
	printf("%d", node->data);
	print_inorder(node->right);

}

void print_preorder(struct node* node){
	if(node == NULL)
		return;
	printf("%d", node->data);
	print_preorder(node->left);
	print_preorder(node->right);

}

void print_postorder(struct node* node){
	if(node == NULL)
		return;
	print_postorder(node->left);
	print_postorder(node->right);
	printf("%d", node->data);

}

int main(){
	struct node* root = createnode(1);
	root->left = createnode(2);
	root->right = createnode(3);
	root->left->left = createnode(4);
	root->left->right = createnode(5);
	printf("\nInorder tree traversal-----------");
	print_inorder(root);
	printf("\nPreorder tree traversal-----------");
	print_preorder(root);
	printf("\nPostorder tree traversal-----------");
	print_postorder(root);
    return 0;
}
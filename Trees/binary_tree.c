#include<stdio.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* createnode(int val){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
    return node;
}

int main(){
	//create root
    struct node* root = createnode(1); 
    //set left and right nodes
    root-> left = createnode(2);
    root-> right = createnode(3);

    root-> left->left = createnode(4);
    root-> left->right = createnode(5);


	return 0;
}
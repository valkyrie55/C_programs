#include<stdio.h> 
#include<stdlib.h> 
   
struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 
   
int height(struct node* node){
	if(node == NULL)
		return 0;
	else{
		int lh = height(node->left);
		int rh = height(node->right);
		if(lh > rh)
			return (lh+1);
		else
			return (rh+1);
}
}

void printlevel(struct node* node, int level){
	if(node == NULL)
		return;
	if(level == 1)
		printf("%d ", node->data);
	else if(level > 1)
		printlevel(node->left,level-1);
	    printlevel(node->right,level-1);
}

void levelorder(struct node* node){
	int h = height(node);
	printf("\nHeight of tree is: %d\n", h);
	int i;
	for(i=1;i <= h;i++){
		printlevel(node, i);
	}
}

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

void preorder(struct node* root){
	if(root!= NULL){
		printf("\n%d", root->data);
		preorder(root->left);
		preorder(root->right);
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
    preorder(root);
    printf("\n********************\n");
    //printf("%d ", root->data);
    //display(root);
    levelorder(root);
    return 0;
}

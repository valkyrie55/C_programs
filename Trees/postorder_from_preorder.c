#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};


struct node* createnode(int val){
	struct node* root = (struct node*)malloc(sizeof(struct node));
	root->data = val;
	root->left = root->right = NULL;
}

struct node* construct_bst(int arr[], int* p, int low, int high, int n){
	int i;
	if(*p >= n || low> high)
		return NULL;
	//first node is root in preorder traversal so create root node
	struct node* root = createnode(arr[*p]);
	*p = *p+1;

	if(high == low) //no elements
		return root;
	//find index of the first element greater than root
	for(i = low; i<= high; i++){
		if(arr[i] > root->data)
			break;
	} 
	//divide the tree based on i

	root->left = construct_bst(arr, p, *p, i-1, n);
	root->right = construct_bst(arr, p, i, high, n);
	return root;

}

struct node* findpostorder(int arr[], int n){
    int p =0;
    return construct_bst(arr,&p, 0, n-1, n);
}


void display(struct node* root){
	if(root == NULL)
		return;
	display(root->left);
	display(root->right);
    printf("%d\t", root->data);
}


int main()
{
    int pre[] = {40,30,35,80,100};
    int n = sizeof(pre)/sizeof(pre[0]);
    struct node *root = findpostorder(pre,n);
    printf("\n Postorder traversal-----");
    display(root);
	return 0;
}
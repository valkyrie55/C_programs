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

struct node* construct_bst(int arr[], int *p,  int low, int high, int n){
	int i;
	if(low > high || *p >= n)
		return NULL;
	//we know first element in preorder traversal is root
	struct node* root = createnode(arr[*p]);
	*p = *p+1;
     
    if(low == high){
    	return root;
    }

    //search for index of first element greater than root
    for(i=low; i <= high; ++i){
        if(arr[i] > root->data)
        	break;
    }
    //divide the array based on i
    // as arr[low] = root so we'll take elements from  *p
    root->left = construct_bst(arr, p,*p, i-1, n );
    root->right = construct_bst(arr, p, i, high, n);
    return root;

}
struct node* createtree(int arr[], int n){

    int p = 0;
    return construct_bst(arr, &p,0, n-1, n);
}

void display(struct node* root){
	if(root == NULL)
		return;
	display(root->left);
	printf("%d\t", root->data);
	display(root->right);
}


int main()
{
    int pre[] = {10,5,1,7,40,50};
    int n = sizeof(pre)/sizeof(pre[0]);
    struct node *root = createtree(pre,n);
    printf("\nBST is constructed!");
    printf("\n Inorder traversal-----");
    display(root);
	return 0;
}
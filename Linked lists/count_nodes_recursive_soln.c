//c program to count no. of nodes in a linked list through recursion
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}*head = NULL,*temp;
////////
void push(int val){
	struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = val;
    new->next = head;
    head = new;
}
///////////
int getcount(struct node* head){
    //base case
    if(head == NULL){
    	return 0;
    }
    return 1+ getcount(head->next);
}
////////
int  main(){
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	printf("count of nodes: %d",getcount(head));
	return 0;
}
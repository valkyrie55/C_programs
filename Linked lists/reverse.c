#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;	
}*head;
void reverse_ll(struct node* head){
    if(head == NULL)
    	return;
    reverse_ll(head->next);
    printf("%d",head->data);

}

void push(int val){
	struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = val;
    new->next = head;
    head = new;
}
int main(){

	push(5);
	push(4);
	push(3);
	push(2);
	push(1);
	//reverse
	reverse_ll(head);
	printf("\n");
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node* next;
}*head = NULL;

struct node* reverse(struct node* head, int k){
	struct node* curr = head;
	struct node* next = NULL;
	struct node* prev = NULL;

	while(curr != NULL && k != 0){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		k--;
	}
	//recursive call to the function
	if(next != NULL)
		head->next = reverse(next, 3);
	return prev;
}

void push(struct node** head, int new_data) 
{ 
    struct node* new = (struct node*) malloc(sizeof(struct node)); 
    new->data  = new_data; 
    new->next = (*head);     
    (*head)    = new; 
}

void display() 
{ 
	struct node* q = head;
    while (q != NULL) 
    { 
        printf("%d  ", q->data); 
        q = q->next; 
    } 
}

int main(){
    push(&head, 8); 
    push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1);
	printf("List created\n");
	display();
	head = reverse(head, 3);
	printf("Reversed list: \n");
	display();
	return 0;
}

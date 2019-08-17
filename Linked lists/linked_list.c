//c program to implement a singly list list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head, *temp =NULL;
void create_nodes(int n);
void display();
int main(){
	int n;
	printf("\nEnter the num. of nodes:");
	scanf("%d",&n);
    create_nodes(n);
    printf("\nList is created\n");
    display();
    return 0;
}
void create_nodes(int n){
	struct node *new;
	int num,i;
	head =(struct node*)malloc(sizeof(struct node));
	if(head == NULL)
		printf("\nMemory can't be allocated");
	else{
		printf("\nEnter data for first node(head):");
		scanf("%d",&num);
		head->data = num;
		head->next = NULL;
		temp = head;
	}
	// now create n nodes and adding to linked list
	for(i=2;i<=n;i++){
        new =(struct node*)malloc(sizeof(struct node));
        if(new == NULL){
        printf("\nMemory can't be allocated");
        break;
    }
    else{
    	printf("\nEnter data for the node:");
		scanf("%d",&num);
		new->data = num;
		new->next =NULL;
		temp->next = new;
		temp = temp->next;
    }
	}
}
void display(){
	struct node *q;
	if(head ==NULL)
		printf("\nMemory can't be allocated");
	else{
		q = head;
		while(q!=NULL){			
    	printf("%d->",q->data);
    	q=q->next;
		}
	}
}

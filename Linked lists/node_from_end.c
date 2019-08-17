//c program to find nth element from the end of a linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head, *temp =NULL;
void create_nodes(int n);
void display();
void find_node(int x);
int main(){
	int n,x,a;
	printf("\nEnter the num. of nodes:");
	scanf("%d",&n);
	a =n;
    create_nodes(n);
    printf("\nList is created");
    printf("\nEnter the node you want to print from the end");
    scanf("%d",&x);
    find_node(x);
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
void find_node(int x){
	int i,len=0;
	struct node* t = head;
	while(t!=NULL){
	    t = t->next;
	    len++;
	}
	t = head;
	for(i=1;i<len-x+1;i++)
        t = t->next;
	printf("\n",t->data);
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
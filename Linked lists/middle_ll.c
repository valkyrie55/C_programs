//method 1: Traverse the whole list and count the no. of nodes, now traverse 
//again and return the node at count/2
/* method 2: traverse using two pointers. move one pointer by one and other by
 2 when the fast pointer reaches the end slow pointer will reach the middle of
  the linked list
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}*head =NULL, *temp;
///////
void create_node(int n);
void printmiddle();
void display();
////////
int main(){
	int n;
    printf("Enter the number of nodes you want:");
    scanf("%d",&n);
    create_node(n);
    printf("\nList is created");
    display();
    printmiddle();
	return 0;
}
void create_node(int n){
	struct node* new;
	int val,i,num;
	head = (struct node*)malloc(sizeof(struct node));
	if(head ==NULL)
		printf("\nMemory can't be allocated");
	else{
		printf("\nEnter data for first node(head):");
		scanf("%d",&val);
		head->data = val;
		head->next = NULL;
		temp = head;
	}
	//now create the remaining nodes
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
void printmiddle(){
	struct node* fast = head;  //increments by 2
	struct node* slow = head;  //increments by 1
    if(head!= NULL){
    	while(fast!= NULL && fast->next!= NULL){
    		fast = fast->next->next;
    		slow = slow->next;
    	}
    	printf("Middle element is [%d]\n\n",slow->data);
    }
}
//////
void display(){
	struct node* q = head;
    while(q!= NULL){
    	printf("%d->",q->data);
    	q=q->next;
    }
    printf("NULL\n");
}
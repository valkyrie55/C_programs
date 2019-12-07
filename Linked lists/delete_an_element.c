#include<stdio.h>
#include<stdlib.h>

void create_nodes(int n);

struct node{
	int data;
	struct node *next;
}*head,*temp = NULL;

void display(){
	struct node * q;
	int len =0;
	if(head == NULL)
		printf("\nEmpty linked list");
	else{
		q = head;
		while(q!=NULL)
		{
			len++;
			printf("%d ->",q->data);
			q = q->next;
		}
		if(q == NULL)
			printf("NULL\n");
	}
	printf("\nLength of the linked list is: ");
	printf("%d\n",len);
}


void delete_key(int del){
	struct node *q = head;
	if(q->data == del){
		q = head->next;
		free(head);
		head = q;
	}
	else
		while(q!= NULL){
			if(q->next->data == del)
			{
				temp = q->next;
				q->next = q->next ->next;
				printf("%d is deleted",temp->data);
				free(temp);
				break;
			}
			q = q->next;
		}
	printf("Linked list after deletion is:");
	display();
}

int main(){
	int n, del = 0;
	printf("\nEnter no. of nodes you want:");
	scanf("%d", &n);
	create_nodes(n);
	printf("\nNodes created!");
	display();
	printf("\nEnter the key you want to delete");
	scanf("%d",&del);
	delete_key(del);
	return 0;
}

void create_nodes(int n){
	int num,i;
	struct node *new;
	head = (struct node*)malloc(sizeof(struct node));
	if(head == NULL)
		printf("\nMemory can't be allocated!");
	else
	{
		printf("\nEnter data for head:");
		scanf("%d", &num);
		head->data = num;
		head->next = NULL;
		temp = head;
	}
	//create remaining nodes
	for(i = 2; i <= n; i++){
		new = (struct node*)malloc(sizeof(struct node));
		if(new == NULL)
			printf("\nMemory can't be allocated!");
		else{
			printf("\nEnter data for new node:");
			scanf("%d", &num);
			new->data = num;
			temp->next = new;
			temp = temp->next;
		}
		
	}
}

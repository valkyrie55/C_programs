#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head,*temp = NULL;

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

void display(){
	struct node * q;
	if(head == NULL)
		printf("\nEmpty linked list");
	else{
		q = head;
		while(q!=NULL)
		{
			printf("%d ->",q->data);
			q = q->next;
		}
		if(q == NULL)
			printf("NULL\n");
	}
}


void remove_duplicates(){
	struct node *q = head,*cur,*n;
	while(q->next != NULL){
		if(q->data == q->next->data)
			{
				cur = q->next;
				n = q->next->next;
				q->next = n;
				free(cur);
			}
		else
			q = q->next;
		}
	printf("Linked list after removal of duplicates:");
	display();
}

int main(){
	int n, del = 0;
	printf("\nEnter no. of nodes you want:");
	scanf("%d", &n);
	create_nodes(n);
	printf("\nNodes created!");
	display();
	//printf("\nRemoving duplicates from the linked list");
	remove_duplicates();
	return 0;
}

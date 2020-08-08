# include<stdio.h>
# include <stdlib.h>

struct node{
	int data;
	struct node *next;
} *head, *temp;

void createnode(int n){
	struct node *new;
	int i, val, num;
	head = (struct node *)malloc(sizeof(struct node));
	if(head == NULL)
		printf("\nCan't allocate memory!");
	else{
		printf("\nEnter data for the head");
		scanf("%d", &val);
		head->data = val;
		head->next = NULL;
		temp = head;
	}
	//create remaining nodes
	for (i = 2; i<= n ; i++){
		new = (struct node *)malloc(sizeof(struct node));
		if(new == NULL)
			printf("\nCan't allocate memory!");
		else{
			printf("\nEnter data for the node");
			scanf("%d", &num);
			new->data = num;
			new->next = NULL;
			temp->next = new;
			temp = temp->next;
		}
	}
}

void printmiddle(){
	struct node* fast = head;
	struct node* slow = head;
	if(head != NULL){
		while(fast != NULL && fast-> next != NULL){
			fast = fast->next->next;
			slow = slow->next;
		}
		printf("\nMiddle element: %d",slow->data);
	}
}

void display(){
	struct node* q = head;
	while(q!= NULL){
		printf("%d -> ", q->data);
		q = q->next;
	}
	printf(" NULL");
}

int main(){
	int n;
	printf("\nHow many nodes do you want?");
	scanf("%d", &n);
	createnode(n);
	printf("\nNodes created!");
	display();
	printmiddle();
}

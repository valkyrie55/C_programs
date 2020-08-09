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

void rotate_list(int k){
	int i = 1;
	if (k == 0)
		return;
	// traverse q to the rth node
	struct node* q = head;
	while(i < k && q != NULL){
		q = q-> next;
		i++;
	}
	if(q == NULL)  // r is greater than count of nodes in the linked list
		return;
	// temp will point to the kth node i.e q 
	struct node* temp = q;
	// traverse q to the last node
	while(q->next != NULL)
		q = q->next;
	// now q points to the list node;
	// make last node head
	q -> next = head;
	// change head to the (k+1)th node
	head = temp-> next;
	// set k->next as NULL
	temp -> next = NULL;
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
	int n,k;
	printf("\nHow many nodes do you want?");
	scanf("%d", &n);
	createnode(n);
	printf("\nNodes created!");
	display();
	printf("\nEnter k:");
	scanf("%d", &k);
	rotate_list(k);
	display();
}

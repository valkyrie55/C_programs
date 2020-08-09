// Algo: 1. Traverse the linked list to the middle node
//       2. Reverse the first half
//       3. Traverse both the lists and match the nodes
//       4. If any two nodes in the lists are not equal, return the function

# include<stdio.h>
# include <stdlib.h>

struct node{
	char data;
	struct node *next;
} *head, *temp;

void createnode(int n){
	struct node *new;
	int i;
	char val, num;
	head = (struct node *)malloc(sizeof(struct node));
	if(head == NULL)
		printf("\nCan't allocate memory!");
	else{
		printf("\nEnter data for the head");
		scanf(" %c", &val);
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
			scanf(" %c", &num);
			new->data = num;
			new->next = NULL;
			temp->next = new;
			temp = temp->next;
		}
	}
}

int is_palindrome(){
	// int len = get_length(head);
	// printf("\nLength of linked list: %d", len);
	// find middle of the ll
	struct node* slow = head;
	struct node* fast = head;
	struct node* curr = head; 
	struct node* prev = NULL;
	struct node* next = NULL;
	
	if(head != NULL){
		while(fast != NULL && fast->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
	}
}
// we got the middle node
// reverse the first half of the node
	while(curr != slow){
		next = curr-> next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	struct node* l1 = head;
	struct node* l2 = slow-> next;

	while(l1 != NULL){
		if(l1->data != l2->data)
			return 0;
		else
		{
			l1 = l1->next;
			l2 = l2->next;
		}
	}
	return 1;
	}

void display(){
	struct node* q = head;
	while(q!= NULL){
		printf("%c -> ", q->data);
		q = q->next;
	}
	printf(" NULL");
}

int main(){
	int n,i;
	printf("\nHow many nodes do you want?");
	scanf("%d", &n);
	createnode(n);
	printf("\nNodes created!");
	display();
	i = is_palindrome();
	if (i == 1)
		printf("\n Its Palindrome");
	else
		printf("\n Not Palindrome");

	return 0;
}

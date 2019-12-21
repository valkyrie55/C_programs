// Implementation of stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *head = NULL;

void push(int val){
    struct node* new_node =(struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
        printf("\nCan't push the element");
    else{
        new_node->data = val;
        if(head == NULL){  //empty stack
            new_node->next = NULL;
            head = new_node;
        }
        else{
            new_node->next = head;
            head = new_node;
        }
        printf("\n%d pushed", val);
    }
    }

void pop(){
    int i;
    struct node* p;
    if(head == NULL)
        printf("\nStack Underflow");
    else{
        i = head->data;
        p = head;
        head = head->next;
        free(p);
        printf("\n%d popped\n",i);
    }
}
 
void display(){
    struct node* q;
    q = head;
    if(head == NULL)
        printf("Stack empty");
    else{
        while(q!= NULL){
            printf("%d->",q->data);
            q = q->next;
        }
        if(q == NULL)
                printf("NULL\n");
    }

}

int main(){ 
    int ch,val;
    printf("\n---Stack operations---");
    while(ch!= 0){
        printf("\n1. Push \n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("\nEnter value to be pushed:");
                    scanf("%d", &val);
                    push(val);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default:printf("\nInnvalid choice!");
        }
    };
    
    return 0;
}

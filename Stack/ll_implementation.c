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
        printf("\n%d popped",i);
    }
}
 
int main(){ 
    int i;
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    //pop
    pop();
    pop();
    printf("\nTop element is %d",head->data);
    //printf("%d popped", i);
    printf("\nOperations done!");
    return 0;
}

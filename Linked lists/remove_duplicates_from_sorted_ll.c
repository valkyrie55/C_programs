//c program to remove duplicates from an unsorted singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head, *temp =NULL;
void create_nodes(int n);
void display();
void remove_duplicate();
int main(){
    int n;
    printf("\nEnter the num. of nodes:");
    scanf("%d",&n);
    create_nodes(n);
    printf("\nList is created");
    printf("\nBefore removal of duplicates:");
    display();
    remove_duplicates();
    printf("\nAfter removal of duplicates:");
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
void remove_duplicates(){
    struct node* cur = head;
    struct node* cur_next = head;
    if(head == NULL)
        return;
    while(cur->next!= NULL){
        if(cur->data == cur->next->data){
            cur_next = cur->next->next;
            free(cur->next);
            cur->next = cur_next;
        }
        else 
            cur= cur->next;
    }
}

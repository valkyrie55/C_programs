//c program to remove duplicates from an unsorted singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head, *temp =NULL;
void create_nodes(int n);
void display();
void remove_duplicates();
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
    //select an elementand compare it with every other element using 2nd pointer
    struct node* p1, *p2,*val;
    p1 = head;
    while(p1!= NULL && p1->next !=NULL){
        p2 = p1;
        while(p2->next != NULL){
            //data at p1 and p2 are same so comparing it with other nodes
            if(p1->data == p2->next->data){
                val = p2->next;
                p2->next = p2->next->next;
                free(val);
            }
            else{  //if not same
                 p2 = p2->next;
            }

        }
        p1 = p1->next;
   }
}

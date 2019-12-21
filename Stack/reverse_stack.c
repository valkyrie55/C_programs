// Implementation of stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *head = NULL;
struct node*t;
struct node*q;
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

int pop(){
    int i;
    struct node* p;
    if(head == NULL)
        printf("\nStack Underflow");
    else{
        i = head->data;
        p = head;
        head = head->next;
        free(p);
        return i;
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

int count_length(){
    struct node* t;
    int count = 0;
    q = head;
    if(head == NULL)
        printf("Stack empty");
    else{
        while(q!= NULL){
            count++;
            q = q->next;
        }
    }
    return count;

}

void display_array(int arr[], int n){
    int i;
    printf("\nArray elements are:");
    for(i=1;i<=n;i++){
        printf("\n%d", arr[i]);
    }
    printf("\nPushing the elements from array into the empty stack in reverse order");
    while(n!= 0){
        push(arr[n]);
        n--;
    }
    printf("\n---Stack reversed---\n");
    display();
}

void Reverse_stack(){
    printf("\nAll elements will be popped nad head == NULL");
    int n = count_length();
    int count = n;
    printf("\nStack has %d elements", n);
    int val,i =0, arr[n];
    //push all elements
    while(n!=0){
        val = pop();
        arr[n] = val;
        printf("\n%d is added in the array",arr[n]);
        n--;
    }
    printf("\n---Array created---");
    //printf("Last element: %d", arr[3]);
    display_array(arr,count);
}

int main(){ 
    int ch = 1,val,i;
    printf("\n---Stack operations---");
    while(ch!= 0){
        printf("\n1. Push \n2. Pop\n3. Display\n4. Reverse_stack\n5.Exit");
        printf("\nEnter your choice");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("\nEnter value to be pushed:");
                    scanf("%d", &val);
                    push(val);
                    break;
            case 2: i = pop();
                    printf("%d is popped", i);
                    break;
            case 3: display();
                    break;
            case 4: Reverse_stack();
                    break;
            case 5: exit(0);
                    break;
            default:printf("\nInvalid choice!");
        }
    };
    
    return 0;
}

// Implementation of stack
#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int *arr;
    unsigned n;
};

struct stack *s;
void push(struct stack* s, int val){
    if(s->top == s->n-1){
        printf("Stack Overflow");
        return;
    }
    s->arr[++s->top] = val;
}

int pop(struct stack* s){
    int val;
    if(s->top == -1){
        printf("Stack Underflow");
        return -1;
    }
    val = s->arr[s->top];
    s->top--;
    return val;
}

struct stack* initialize_stack(unsigned n){
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->n = n;
    s->top = -1; //NULL
    s->arr = (int*)malloc(s->n * sizeof(int));
    return s;
}
 
int main(){ 
    int i;
    struct stack *s = initialize_stack(10);
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    push(s,60);
    //pop
    i = pop(s);
    printf("\n%d popped", i);
    i = pop(s);
    printf("\n%d popped", i);
    //printf("%d popped", i);
    printf("\nOperations done!");
    return 0;
}

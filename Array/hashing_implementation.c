#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 20

struct node{
    int data;
    int key;
}*harr[n], *d, *item;

// hash fun
int hashcode(int key){
    return key%n;
}

void insert(int key, int data){
    //create a new block
    struct node *item = (struct node*)malloc(sizeof(struct node));
    item->data = data;
    item->key = key;
    //get the hash
    int hashindex = hashcode(key);
    //traverse the array
    while(harr[hashindex] != NULL && harr[hashindex]->key != -1){
        ++hashindex;  //go to next cell
        hashindex %= n;
    }
    harr[hashindex] = item;
}

void display(){
    int i = 0;
    for(i=0;i<n;i++){
        if(harr[i] != NULL)
            printf("(%d, %d)", harr[i]->key, harr[i]->data);
        else
            printf(" -- ");
    }
    printf("\n");
}

struct node* search(int x){
    //get the hash
    int hashindex = hashcode(x);
    //traverse the array
    while(harr[hashindex] != NULL){
        if(harr[hashindex]-> key == x)
            return harr[hashindex];  //return the value
        //else go to next cell
        ++hashindex;
        //update the value
        hashindex %= n;
    }
    return NULL;
}

struct node* delete(struct node* item) {
   int key = item->key;

   //get the hash 
   int hashindex = hashcode(key);

   while(harr[hashindex] != NULL) {
        if(harr[hashindex]->key == key) {
            struct node* temp = harr[hashindex]; 
            //assign a dummy item at deleted position
            harr[hashindex] = d; 
            return temp;
      }
        ++hashindex;
        hashindex %= n;
   }      
    
   return NULL;        
}


int main(){
    d = (struct node*)malloc(sizeof(struct node));
    d->data = -1;
    d->key = -1;
    insert(1,20);
    insert(2,70);
    insert(42,80);
    insert(4,25);
    insert(12,44);
    insert(14,32);
    insert(17,11);
    insert(13,78);
    insert(37,97);
    display();
    //search a value
    item = search(37);
    if(item != NULL)
        printf("Element found at: %d\n",item->data);
    else
        printf("Element not found!\n");
    delete(item);
    item = search(37);

    if(item != NULL) 
        printf("Element found: %d\n", item->data);
    else
      printf("Element not found\n");
    return 0;
    }
